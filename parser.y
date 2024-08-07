%{
#include <string>
#include <iostream>

static std::string* outputString = nullptr;

extern int yylex(void);

void yyerror(const char* s);
%}

%code requires {
    #include <cstdio>
    #include <string>
    extern int yylex(void);
    std::string* printMarkdown(void);
}

%union {
    std::string* strValue;
}

%token SECTION SUBSECTION SUBSUBSECTION NEWLINE CONTENT  
%token ITALICS BOLD HORIZONTALLINE PARAGRAPH ENDBRACE

%start page

%type <strValue> page
%type <strValue> sentences
%type <strValue> sentence
%type <strValue> SECTION SUBSECTION SUBSUBSECTION
%type <strValue> headings fonts ITALICS BOLD CONTENT 

%%

page: sentences { outputString = $1; }
    ;

sentences:  
        { $$ = new std::string(); }
        | sentence sentences { 
            $$ = new std::string(*$1 + *$2); 
            delete $1; 
            delete $2; 
        }
        ;

sentence: headings  { $$ = $1; }
          | fonts   { $$ = $1; }
          | NEWLINE { $$ = new std::string("\n"); }
          | CONTENT { $$ = $1; }
          ;

headings: SECTION CONTENT ENDBRACE { 
        $$ = new std::string("# " + *$2 + "\n");
        delete $2;
    } 
        | SUBSECTION CONTENT ENDBRACE { 
        $$ = new std::string("## " + *$2 + "\n");
        delete $2;
    } 
        | SUBSUBSECTION CONTENT ENDBRACE { 
        $$ = new std::string("### " + *$2 + "\n");
        delete $2;
    }
        ;

fonts:   BOLD CONTENT ENDBRACE{ 
            $$ = new std::string("**" + *$2 + "**"); 
            delete $2; 
        }
        | ITALICS CONTENT ENDBRACE{ 
            $$ = new std::string("*" + *$2 + "*"); 
            delete $2; 
        }
        ;

%%

void yyerror(const char* s) {
    std::cerr << "Error: " << s << std::endl;
}

std::string* printMarkdown() {
    return outputString;
}

int main() {
    if (yyparse() == 0) {
        std::string* result = printMarkdown();
        if (result != nullptr) {
            std::cout << *result << std::endl;
            delete result;
        }
    }
    return 0;
}
