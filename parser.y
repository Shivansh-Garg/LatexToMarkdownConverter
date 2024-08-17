%{
#include <string>
#include <iostream>
#include <fstream>

static std::string* outputString = nullptr;

extern int yylex(void);

int countOrderNo = 0;

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
    int intValue;
}

%token SECTION SUBSECTION SUBSUBSECTION NEWLINE CONTENT  
%token ITALICS BOLD HORIZONTALLINE PARAGRAPH ENDBRACE
%token STARTBRACE CODEBLOCKSTART CODEBLOCKEND HYPERLINK
%token START TITLE PACKAGES DOCUMENT DATE IMAGESTART
%token STARTSQUAREBRACE ENDSQUAREBRACE TEXTWIDTH END
%token UNORDEREDLIST ENDUNORDEREDLIST ITEM
%token ORDEREDLIST ENDORDEREDLIST


%start page

%type <stringValue> page
%type <stringValue> sentences
%type <stringValue> sentence code
%type <stringValue> SECTION SUBSECTION SUBSUBSECTION
%type <stringValue> headings fonts ITALICS BOLD CONTENT 
%type <stringValue> HYPERLINK link linkfirsthalf linksecondhalf
%type <stringValue> ignore image imagefirsthalf imagesecondhalf
%type <stringValue> lists unorderedListItems orderedListItems

%type <countOrderNo> ORDEREDLIST

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
          | lists   { $$ = $1;}
          | image   { $$ = $1; }
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

code:   CODEBLOCKSTART NEWLINE CONTENT {
        $$ = new std::string("```python\n" + *$3 );
        delete $3;
        }
        | CODEBLOCKEND {$$ = new std::string("\n```");}
        ; 

link:   linkfirsthalf linksecondhalf {
            $$ = new std::string("[" + *$2 + "]" + "(" + *$1 + ")");
            delete $1;
            delete $2;
        }
        ;

lists:  UNORDEREDLIST NEWLINE unorderedListItems {$$ = $3;}
        | ORDEREDLIST NEWLINE orderedListItems {
            countOrderNo = 0;
            $$ = $3;
            }
        ;

unorderedListItems : ENDUNORDEREDLIST {$$ = new std::string("");}
        | CONTENT ITEM CONTENT NEWLINE unorderedListItems{
            $$ = new std::string("-" + *$3 + "\n" + *$5);
            delete $3;
            delete $5;
        }
        ;

orderedListItems : ENDORDEREDLIST {
            $$ = new std::string("");
        } 
        |CONTENT ITEM CONTENT NEWLINE orderedListItems {
         countOrderNo++;
         $$ = new std::string(std::to_string(countOrderNo) + "." + *$3 + "\n" + *$5);
         delete $3;
         delete $5;
        } 
        ;

image:  imagefirsthalf imagesecondhalf { 
        $$ = new std::string(*$1 + *$2);
        delete $1;
        delete $2;
        }
        ;

        

ignore: START NEWLINE {}
        | PACKAGES NEWLINE {}
        | DATE NEWLINE {}
        | DOCUMENT NEWLINE {}
        | TITLE NEWLINE {}
        | END   NEWLINE{}
        ;

linkfirsthalf: HYPERLINK CONTENT ENDBRACE {$$ = $2;};

linksecondhalf: STARTBRACE CONTENT ENDBRACE {$$ = $2;};

imagefirsthalf: IMAGESTART CONTENT TEXTWIDTH ENDSQUAREBRACE {$$ = new std::string("![IMAGE]");};

imagesecondhalf: STARTBRACE CONTENT ENDBRACE {
                 $$ = new std::string("(" + *$2 + ")");
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
