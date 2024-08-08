%{
    #include <stdio.h>
    #include <string.h>
    #include "parser.tab.h"
    #include <stdlib.h>


    extern int yylex();
    void printTokenDetails(const char* s);
%}

ALPHABET            [a-zA-Z]
NUMBER              [0-9]
PUNCTUATION         [.,\-()"':/]
SPECIAL             [\#\$\%\&\~\_\^]
STARTBRACE          \{
ENDBRACE            \}
SPACE               [ ]
TAB                 \t
LETTER              ({ALPHABET}|{NUMBER}|{SPECIAL}|{PUNCTUATION})
WORD                {ALPHABET}+
TEXT                {LETTER}+
CONTENT            ({TEXT}|{SPACE}|{TAB})+
BACKSLASH           \\
ENDLINE             [\n]
            

%%
{BACKSLASH}begin{STARTBRACE}document{ENDBRACE}      {printTokenDetails("BEGIN");}
{BACKSLASH}title{STARTBRACE}{CONTENT}{ENDBRACE}     {printTokenDetails("TITLE");}
{BACKSLASH}section{STARTBRACE}                      {printTokenDetails("SECTION"); return SECTION;}
{BACKSLASH}subsection{STARTBRACE}                   {printTokenDetails("SUBSECTION"); return SUBSECTION;}
{BACKSLASH}subsubsection{STARTBRACE}                {printTokenDetails("SUBSUBSECTION"); return SUBSUBSECTION;}
{BACKSLASH}textit{STARTBRACE}                       {printTokenDetails("ITALICS"); return ITALICS;}
{BACKSLASH}textbf{STARTBRACE}                       {printTokenDetails("BOLD"); return BOLD;}
{BACKSLASH}begin{STARTBRACE}verbatim{ENDBRACE}      {printTokenDetails("CODEBLOCKSTART"); return CODEBLOCKSTART;}
{BACKSLASH}href{STARTBRACE}                         {printTokenDetails("HYPERLINK"); return HYPERLINK;}
{BACKSLASH}end{STARTBRACE}verbatim{ENDBRACE}        {printTokenDetails("CODEBLOCKEND");return CODEBLOCKEND;}
{BACKSLASH}hrule                                    {printTokenDetails("HORIZONTALLINE");return HORIZONTALLINE;}
{BACKSLASH}par                                      {printTokenDetails("PARAGRAPH");return PARAGRAPH;}

{STARTBRACE}                                                 {printTokenDetails("STARTBRACE"); return STARTBRACE;}
{ENDBRACE}                                                   {printTokenDetails("ENDBRACE"); return ENDBRACE;}
{CONTENT}                                                    {printTokenDetails("CONTENT"); yylval.stringValue = new std::string(yytext); return CONTENT;}
[\t\r]                                                       {}
[\n]                                                         {printTokenDetails("NEWLINE");return NEWLINE;}
.                                                            {fprintf(stderr,"ERROR %c",*yytext);}



%%

int yywrap() {
    return 1;
}

/*
int main(){
    yylex();
    return 0;
}*/


void printTokenDetails(const char* s) {
    if (s != NULL) {
        size_t length = strlen(yytext);  // Compute the length of the text holding
        printf("token is %s, length: %zu\n", s, length);
    } else {
        printf("token is nullptr\n");
    }
}

