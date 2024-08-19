%{
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

extern int yylex(void);
int countOrderNo = 0;
void yyerror(const char* s);
%}

%code requires{
    #include <string>
    #include <memory>
    #include <vector>
    #include <iostream>
    #include <fstream>
    using namespace std;

    struct ASTNode {
        string type;  // Node type (e.g., "section", "content", etc.)
        string value; // Node value (e.g., actual content text)
        vector<unique_ptr<ASTNode>> children; // Child nodes

        ASTNode(const string& type, const string& value = "")
            : type(type), value(value) {}

        void addChild(unique_ptr<ASTNode> child) {
            children.push_back(move(child));
        }
    };

    void printASTToFile(const ASTNode* node, ofstream& outFile, int indent = 0);
    string convertASTToMarkdown(const ASTNode* node);
    static unique_ptr<ASTNode> root = nullptr;

}


%code{
void printASTToFile(const ASTNode* node, ofstream& outFile, int indent ) {
    if (!node) return;
    for (int i = 0; i < indent; ++i) outFile << "  "; 
    outFile << node->type << ": " << node->value << endl;
    for (const auto& child : node->children) {
        printASTToFile(child.get(), outFile, indent + 1);
    }
}

string convertASTToMarkdown(const ASTNode* node) {
    if (!node) return "";
    string markdown;
    
    if (node->type == "heading") {
        markdown += "# " + node->value + "\n";
    } else if (node->type == "subheading") {
        markdown += "## " + node->value + "\n";
    } else if (node->type == "subsubheading") {
        markdown += "### " + node->value + "\n";
    } else if (node->type == "bold") {
        markdown += "**" + node->value + "**";
    } else if (node->type == "italics") {
        markdown += "*" + node->value + "*";
    } else if (node->type == "horizontal_line") {
        markdown += "---\n";
    } else if (node->type == "paragraph") {
        markdown += "\n";
    } else if (node->type == "codeblock") {
        markdown += "```python\n" + node->value + "\n```";
    } else if (node->type == "link") {
        markdown += node->value;
    } else if (node->type == "unordered_list" || node->type == "ordered_list") {
        /*for (const auto& child : node->children) {
            markdown += convertASTToMarkdown(child.get());
        }*/
    } else if (node->type == "list_item") {
        markdown += node->value + "\n";
    } else if (node->type == "image") {
        markdown += node->value + "\n";
    } else if (node->type == "content") {
        markdown += node->value;
    } else if (node->type == "newline"){
        markdown += "\n";
    }

    for (const auto& child : node->children) {
        markdown += convertASTToMarkdown(child.get());
    }

    return markdown;
}
}

%union {
    ASTNode* node;
    string* stringValue;
    int intValue;
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

%type<stringValue> CONTENT

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
          CODEBLOCKSTART NEWLINE CONTENT {
            $$ = new ASTNode("codeblock", *$3);
            delete $3;
        }
        | CODEBLOCKEND {
            $$ = new ASTNode("codeblock_end", "```");
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
            $$->addChild(make_unique<ASTNode>("list_item", *$3));
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
        ofstream outFile("ast_output.txt");
        if (outFile.is_open()) {
            printASTToFile(root.get(), outFile);
            outFile.close();
        } else {
            cerr << "Error opening file to write AST." << endl;
        }

        string markdown = convertASTToMarkdown(root.get());
        cout << markdown << endl;
    }
    return 0;
}
