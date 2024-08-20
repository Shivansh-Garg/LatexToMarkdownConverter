%{
#include <memory>   
#include <string>   
#include <iostream>
#include "AST.h"
using namespace std;
extern int yylex(void); 

static unique_ptr<ASTNode> root = nullptr;
void yyerror(const char* s);
int countOrderNo = 0;
%}

%union {
    ASTNode* node;
    string* stringValue;
    int intValue;
}

%code requires{
    #include <string>
    #include "AST.h"
    using namespace std;
}

%token SECTION SUBSECTION SUBSUBSECTION NEWLINE CONTENT  
%token ITALICS BOLD HORIZONTALLINE PARAGRAPH ENDBRACE
%token STARTBRACE CODEBLOCKSTART CODEBLOCKEND HYPERLINK
%token START TITLE PACKAGES DOCUMENT DATE IMAGESTART
%token STARTSQUAREBRACE ENDSQUAREBRACE TEXTWIDTH END
%token UNORDEREDLIST ENDUNORDEREDLIST ITEM
%token ORDEREDLIST ENDORDEREDLIST

%type <node> page
%type <node> sentences
%type <node> sentence code headings fonts link lists
%type <node> unorderedListItems orderedListItems image
%type <node> linkfirsthalf linksecondhalf imagefirsthalf imagesecondhalf ignore

%type<stringValue> CONTENT sametext

%start page

%%

page: sentences { 
        root = make_unique<ASTNode>("page", "");
        root->addChild(unique_ptr<ASTNode>($1));
    }
    ;

sentences: 
        /* Empty */ { $$ = new ASTNode("sentences", ""); }
        | sentence sentences { 
            $$ = $2;
            $$->children.insert($$->children.begin(), unique_ptr<ASTNode>($1)); // Insert at the beginning
        }
        ;

sentence: 
          headings  { $$ = $1; }
        | fonts     { $$ = $1; }
        | code      { $$ = $1; }
        | link      { $$ = $1; }
        | lists     { $$ = $1; }
        | image     { $$ = $1; }
        | ignore    { $$ = new ASTNode("ignore", ""); }
        | NEWLINE   { $$ = new ASTNode("newline", "\n"); }
        | CONTENT   { $$ = new ASTNode("content", *$1); delete $1; }
        ;

headings: 
          SECTION CONTENT ENDBRACE { 
            $$ = new ASTNode("heading", *$2);
            delete $2;
        } 
        | SUBSECTION CONTENT ENDBRACE { 
            $$ = new ASTNode("subheading", *$2);
            delete $2;
        } 
        | SUBSUBSECTION CONTENT ENDBRACE { 
            $$ = new ASTNode("subsubheading", *$2);
            delete $2;
        }
        ;

fonts: 
          BOLD CONTENT ENDBRACE { 
            $$ = new ASTNode("bold", *$2); 
            delete $2; 
        }
        | ITALICS CONTENT ENDBRACE { 
            $$ = new ASTNode("italics", *$2); 
            delete $2; 
        }
        | HORIZONTALLINE { 
            $$ = new ASTNode("horizontal_line", "---");
        }
        | PARAGRAPH { 
            $$ = new ASTNode("paragraph", "\n");
        }
        ;

code:
    CODEBLOCKSTART sametext CODEBLOCKEND {
        $$ = new ASTNode("codeblock", *$2);
        delete $2;
    }
    ;

sametext:
    NEWLINE sametext {
        $$ = new std::string("\n" + *$2);
        delete $2;
    }
    | CONTENT sametext {
        $$ = new std::string(*$1 + *$2);
        delete $2;
    }
    | CONTENT {
        $$ = new std::string(*$1);
    }
    | NEWLINE {
        $$ = new std::string("\n");
    }
    ;

link: 
          linkfirsthalf linksecondhalf {
            $$ = new ASTNode("link", "[" + $2->value + "](" + $1->value + ")");
            delete $1;
            delete $2;
        }
        ;

lists: 
          UNORDEREDLIST NEWLINE unorderedListItems {
            $$ = new ASTNode("unordered_list", "");
            $$->addChild(unique_ptr<ASTNode>($3));
        }
        | ORDEREDLIST NEWLINE orderedListItems {
            countOrderNo = 0;
            $$ = new ASTNode("ordered_list", "");
            $$->addChild(unique_ptr<ASTNode>($3));
        }
        ;

unorderedListItems: 
        ENDUNORDEREDLIST { $$ = new ASTNode("unordered_list_end", ""); }
        | CONTENT ITEM CONTENT NEWLINE unorderedListItems {
            $$ = $5;
            $$->addChild(make_unique<ASTNode>("list_item", "-" + *$3));
            delete $3;
        }
        ;

orderedListItems: 
          ENDORDEREDLIST { $$ = new ASTNode("ordered_list_end", ""); }
        | CONTENT ITEM CONTENT NEWLINE orderedListItems {
            countOrderNo++;
            $$ = $5;
            $$->addChild(make_unique<ASTNode>("list_item", to_string(countOrderNo) + ". " + *$3));
            delete $3;
        }
        ;

image: 
          imagefirsthalf imagesecondhalf { 
            $$ = new ASTNode("image", $1->value + $2->value);
            delete $1;
            delete $2;
        }
        ;

ignore: 
          START NEWLINE { $$ = new ASTNode("ignore", ""); }
        | PACKAGES NEWLINE { $$ = new ASTNode("ignore", ""); }
        | DATE NEWLINE { $$ = new ASTNode("ignore", ""); }
        | DOCUMENT NEWLINE { $$ = new ASTNode("ignore", ""); }
        | TITLE NEWLINE { $$ = new ASTNode("ignore", ""); }
        | END NEWLINE { $$ = new ASTNode("ignore", ""); }
        ;

linkfirsthalf: 
          HYPERLINK CONTENT ENDBRACE { $$ = new ASTNode("hyperlink", *$2); delete $2; }
        ;

linksecondhalf: 
          STARTBRACE CONTENT ENDBRACE { $$ = new ASTNode("link_text", *$2); delete $2; }
        ;

imagefirsthalf: 
          IMAGESTART CONTENT TEXTWIDTH ENDSQUAREBRACE { $$ = new ASTNode("image_desc", "![IMAGE]"); }
        ;

imagesecondhalf: 
          STARTBRACE CONTENT ENDBRACE { $$ = new ASTNode("image_url", "(" + *$2 + ")"); delete $2; }
        ;

%%

void yyerror(const char* s) {
    cerr << "Error: " << s << endl;
}

int main() {
    if (yyparse() == 0 && root) {
        // Print the AST to a file
        ofstream outFile("ast_output.txt");
        if (outFile.is_open()) {
            printASTToFile(root.get(), outFile);
            outFile.close();
        } else {
            cerr << "Error opening file to write AST." << endl;
        }

        // Print markdown conversion to the console
        string markdown = convertASTToMarkdown(root.get());
        cout << markdown << endl;
    }
    return 0;
}
