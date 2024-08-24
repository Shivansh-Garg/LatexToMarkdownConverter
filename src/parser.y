%{
#include <memory>   
#include <string>   
#include <iostream>
#include <algorithm>
#include "AST.h"

using namespace std;

extern int yylex(void); 

unique_ptr<ASTNode> root = nullptr;
int indentLevel = -4;
void yyerror(const char* s);
int countOrderNo = 0;
int tableLineNo = 0;
int tableColumnCount = 0;
int countOrderNestedNo = 0;

%}

%union {
    ASTNode* node;
    string* stringValue;
    int intValue;
}

%code requires{
    #include <string>
    #include <algorithm>
    #include "AST.h"
    using namespace std;
}

%token SECTION SUBSECTION SUBSUBSECTION NEWLINE CONTENT  
%token ITALICS BOLD HORIZONTALLINE PARAGRAPH ENDBRACE
%token STARTBRACE CODEBLOCKSTART CODEBLOCKEND HYPERLINK
%token START TITLE PACKAGES DOCUMENT DATE IMAGESTART
%token STARTSQUAREBRACE ENDSQUAREBRACE TEXTWIDTH END
%token UNORDEREDLIST ENDUNORDEREDLIST ITEM
%token ORDEREDLIST ENDORDEREDLIST TABLEBEGIN TABLECOLUMNS
%token TABLELINE BACKSLASH TABLEEND 

%type <node> page
%type <node> sentences
%type <node> sentence code headings fonts link lists commonPart
%type <node> unorderedListItems orderedListItems image
%type <node> linkfirsthalf linksecondhalf imagefirsthalf imagesecondhalf ignore
%type <node> table tablerows countTableColumn

%type<stringValue> CONTENT sametext TABLECOLUMNS

%start page

%%

page: sentences { 
        root = make_unique<ASTNode>("page", "");
        root->addChild(unique_ptr<ASTNode>($1));
    }
    ;

sentences: 
     { $$ = new ASTNode("sentences", ""); }
    | sentences sentence { 
        $$ = $1;
        $$->children.push_back(unique_ptr<ASTNode>($2)); 
    }
;

sentence: 
          headings  { $$ = $1; }
        | fonts     { $$ = $1; }
        | code      { $$ = $1; }
        | link      { $$ = $1; }
        | lists     { $$ = $1; }
        | image     { $$ = $1; }
        | table     { $$ = $1; }
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
    | BOLD CONTENT ITALICS commonPart ENDBRACE {
        $$ = new ASTNode("bold_italics", " **" + *$2 + "**" + $4->value);
        delete $2;
        delete $4;
    }
    | BOLD CONTENT ITALICS commonPart CONTENT ENDBRACE {
        $$ = new ASTNode("bold_italics", " **" + *$2 + "**" + $4->value + " **" + *$5 + "**");
        delete $2;
        delete $4;
        delete $5;
    }
    | BOLD ITALICS commonPart ENDBRACE {
        $$ = new ASTNode("bold_italics", $3->value);
        delete $3;
    }
    | BOLD ITALICS commonPart CONTENT ENDBRACE {
        $$ = new ASTNode("bold_italics", $3->value + " **" + *$4 + "**");
        delete $3;
        delete $4;
    }
    | ITALICS CONTENT BOLD commonPart ENDBRACE {
        $$ = new ASTNode("italics_bold", " *" + *$2 + "*" + $4->value);
        delete $2;
        delete $4;
    }
    | ITALICS CONTENT BOLD commonPart CONTENT ENDBRACE {
        $$ = new ASTNode("italics_bold", " *" + *$2 + "*" + $4->value + " *" + *$5 + "*");
        delete $2;
        delete $4;
        delete $5;
    }
    | ITALICS BOLD commonPart ENDBRACE {
        $$ = new ASTNode("italics_bold", $3->value);
        delete $3;
    }
    | ITALICS BOLD commonPart CONTENT ENDBRACE {
        $$ = new ASTNode("italics_bold", $3->value + " *" + *$4 + "*");
        delete $3;
        delete $4;
    }
    ;

commonPart: 
      CONTENT ENDBRACE {
        $$ = new ASTNode("italics_and_bold", " **_" + *$1 + "_**");
        delete $1;
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
        $$ = new string("\n" + *$2);
        delete $2;
    }
    | CONTENT sametext {
        $$ = new string(*$1 + *$2);
        delete $2;
    }
    | CONTENT {
        $$ = new string(*$1);
    }
    | NEWLINE {
        $$ = new string("\n");
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
        UNORDEREDLIST NEWLINE unorderedListItems ENDUNORDEREDLIST {
            indentLevel = -4;
            $$ = new ASTNode("unordered_list", "");
            $$->addChild(unique_ptr<ASTNode>($3));
        }
        | ORDEREDLIST NEWLINE orderedListItems ENDORDEREDLIST {
            countOrderNo = 0;
            indentLevel = -4;
            $$ = new ASTNode("ordered_list", "");
            $$->addChild(unique_ptr<ASTNode>($3));
        }
        ;

unorderedListItems: 
        unorderedListItems CONTENT ITEM CONTENT NEWLINE {
            $$ = $1;
            $$->addChild(make_unique<ASTNode>("list_item", string(indentLevel, ' ') + "-" + *$4));
            delete $4;
        }
        | unorderedListItems CONTENT UNORDEREDLIST NEWLINE unorderedListItems CONTENT ENDUNORDEREDLIST NEWLINE {
            $$ = $1;
            auto nestedList = make_unique<ASTNode>("nested_unordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>($5));
            $$->addChild(make_unique<ASTNode>("nested_list_item", ""));
            $$->children.back()->addChild(move(nestedList));
            indentLevel -= 4;
        }
        | CONTENT ITEM CONTENT NEWLINE {
            indentLevel += 4;
            $$ = new ASTNode("list_items");
            $$->addChild(make_unique<ASTNode>("list_item", string(indentLevel, ' ') + "-" + *$3));
            delete $3;
        }
        | CONTENT UNORDEREDLIST NEWLINE unorderedListItems CONTENT ENDUNORDEREDLIST NEWLINE {
            $$ = new ASTNode("list_items");
            auto nestedList = make_unique<ASTNode>("unordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>($4));
            $$->addChild(make_unique<ASTNode>("nested_list_item", ""));
            $$->children.back()->addChild(move(nestedList));
            indentLevel -= 4;
        }
    ;


orderedListItems:
        orderedListItems CONTENT ITEM CONTENT NEWLINE {
            $$ = $1;
            $$->addChild(make_unique<ASTNode>("list_item",string(indentLevel, ' ') + to_string(++countOrderNo) + "." + *$4));
            delete $4;
        }
        | orderedListItems CONTENT ORDEREDLIST NEWLINE orderedListItems CONTENT ENDORDEREDLIST NEWLINE {
            $$ = $1;
            auto nestedList = make_unique<ASTNode>("nested_ordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>($5));
            $$->addChild(make_unique<ASTNode>("nested_list_item", ""));
            $$->children.back()->addChild(move(nestedList));
            indentLevel -= 4;
            countOrderNestedNo = 0;
        }
        | CONTENT ITEM CONTENT NEWLINE {
            indentLevel += 4;
            $$ = new ASTNode("list_items");
            $$->addChild(make_unique<ASTNode>("list_item", string(indentLevel, ' ') + to_string(++countOrderNo) + "." + *$3));
            delete $3;
        }
        | CONTENT ORDEREDLIST NEWLINE orderedListItems CONTENT ENDORDEREDLIST NEWLINE {
            $$ = new ASTNode("list_items");
            auto nestedList = make_unique<ASTNode>("ordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>($4));
            $$->addChild(make_unique<ASTNode>("list_item", ""));
            $$->children.back()->addChild(move(nestedList));
            indentLevel -= 4;
        }
    ;


image: 
          imagefirsthalf imagesecondhalf { 
            $$ = new ASTNode("image", $1->value + $2->value);
            delete $1;
            delete $2;
        }
        ;

table:  
        TABLEBEGIN countTableColumn NEWLINE tablerows TABLEEND{
            $$ = new ASTNode("table", "");
            $$->addChild(unique_ptr<ASTNode>($4));
        }

countTableColumn:
     TABLECOLUMNS {
        tableColumnCount = count($1->begin(), $1->end(), 'c') ;  
    }
    ;

tablerows : 
        tablerows CONTENT BACKSLASH BACKSLASH NEWLINE {
        string modifiedContent = *$2;
        replace(modifiedContent.begin(), modifiedContent.end(), '&', '|');

        $$ = $1;
        $$->addChild(make_unique<ASTNode>("table_item", "|" +  modifiedContent + "|"));
        delete $2;
    }
    | tablerows TABLELINE NEWLINE {
        $$ = $1;
        tableLineNo++;
        if (tableLineNo == 2) {
            string separatorLine = "|";
            for(int i = 0; i < tableColumnCount; ++i) {
                separatorLine += "----------------------|";
            }
            $$->addChild(make_unique<ASTNode>("table_separator", separatorLine));  
        }
        
    }
    | CONTENT BACKSLASH BACKSLASH NEWLINE {
        string modifiedContent = *$1;
        replace(modifiedContent.begin(), modifiedContent.end(), '&', '|');
        $$ = new ASTNode("table_items");
        $$->addChild(make_unique<ASTNode>("table_item", "|" +  modifiedContent + "|"));
        delete $1;
    }
    | TABLELINE NEWLINE{
        $$ = new ASTNode("table_container");
        tableLineNo++;
        if (tableLineNo == 2) {
            string separatorLine = "|";
            for(int i = 0; i < tableColumnCount; ++i) {
                separatorLine += "----------------------|";
            }
            $$->addChild(make_unique<ASTNode>("table_separator", separatorLine));  
        }
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

/*
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
*/