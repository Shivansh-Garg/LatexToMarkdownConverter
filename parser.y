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
    std::string* stringValue;
}

%token SECTION SUBSECTION SUBSUBSECTION NEWLINE CONTENT  
%token ITALICS BOLD HORIZONTALLINE PARAGRAPH ENDBRACE
%token STARTBRACE CODEBLOCKSTART CODEBLOCKEND HYPERLINK
%token START TITLE PACKAGES DOCUMENT DATE 


%start page

%type <stringValue> page
%type <stringValue> sentences
%type <stringValue> sentence code
%type <stringValue> SECTION SUBSECTION SUBSUBSECTION
%type <stringValue> headings fonts ITALICS BOLD CONTENT 
%type <stringValue> HYPERLINK link linkfirsthalf linksecondhalf
%type <stringValue> ignore

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
          | code    { $$ = $1; }
          | link    { $$ = $1;}
          | ignore  { $$ = new std::string("");}
          | NEWLINE { $$ = new std::string("\n"); }
          | CONTENT { $$ = $1; }
          ;

headings: SECTION CONTENT ENDBRACE { 
        $$ = new std::string("# " + *$2);
        delete $2;
    } 
        | SUBSECTION CONTENT ENDBRACE { 
        $$ = new std::string("## " + *$2);
        delete $2;
    } 
        | SUBSUBSECTION CONTENT ENDBRACE { 
        $$ = new std::string("### " + *$2);
        delete $2;
    }
        ;

fonts:   BOLD CONTENT ENDBRACE { 
            $$ = new std::string("**" + *$2 + "**"); 
            delete $2; 
        }
        | ITALICS CONTENT ENDBRACE{ 
            $$ = new std::string("*" + *$2 + "*"); 
            delete $2; 
        }
        | HORIZONTALLINE {
            $$ = new std::string("---");
        }
        | PARAGRAPH{
            $$ = new std::string("\n");
        }
        ;

code:   CODEBLOCKSTART NEWLINE CONTENT {$$ = new std::string("```python\n" + *$3 );}
        | CODEBLOCKEND {$$ = new std::string("\n```");}
        ; 

link:   linkfirsthalf linksecondhalf {
            $$ = new std::string("[" + *$2 + "]" + "(" + *$1 + ")");
        }
        ;

ignore: START NEWLINE {}
        | PACKAGES NEWLINE {}
        | DATE NEWLINE {}
        | DOCUMENT NEWLINE {}
        | TITLE NEWLINE {}
        ;

linkfirsthalf: HYPERLINK CONTENT ENDBRACE {$$ = $2;};

linksecondhalf: STARTBRACE CONTENT ENDBRACE {$$ = $2;};


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
