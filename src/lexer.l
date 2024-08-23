%{
    #include <stdio.h>
    #include <string.h>
    #include "parser.hpp"
    #include <stdlib.h>


    extern int yylex();
    void printTokenDetails(const char* s);
%}

ALPHABET            [a-zA-Z]
NUMBER              [0-9]
PUNCTUATION         [.,\-()"':/!=]
SPECIAL             [\#\$\&\~\_\^]
STARTBRACE          \{
ENDBRACE            \}
STARTSQUAREBRACE    \[
ENDSQUAREBRACE      \]
SPACE               [ ]
TAB                 \t
LETTER              ({ALPHABET}|{NUMBER}|{SPECIAL}|{PUNCTUATION})
WORD                {ALPHABET}+
TEXT                {LETTER}+
CONTENT            ({TEXT}|{SPACE}|{TAB})+
BACKSLASH           \\
ENDLINE             [\n]
PERCENTAGE          [\%]
TABLECOLUMNS        [ |c]+

%%
{BACKSLASH}begin{STARTBRACE}document{ENDBRACE}               {printTokenDetails("START"); return START;}
{BACKSLASH}title{STARTBRACE}{CONTENT}{ENDBRACE}              {printTokenDetails("TITLE"); return TITLE;}
{BACKSLASH}usepackage{STARTBRACE}{CONTENT}{ENDBRACE}         {printTokenDetails("PACKAGES"); return PACKAGES;}
{BACKSLASH}documentclass{STARTBRACE}{CONTENT}{ENDBRACE}      {printTokenDetails("DOCUMENT"); return DOCUMENT;}
{BACKSLASH}date{STARTBRACE}{CONTENT}{ENDBRACE}               {printTokenDetails("DATE"); return DATE;}
{BACKSLASH}end{STARTBRACE}document{ENDBRACE}                 {printTokenDetails("END"); return END;}

{BACKSLASH}section{STARTBRACE}                               {printTokenDetails("SECTION"); return SECTION;}
{BACKSLASH}subsection{STARTBRACE}                            {printTokenDetails("SUBSECTION"); return SUBSECTION;}
{BACKSLASH}subsubsection{STARTBRACE}                         {printTokenDetails("SUBSUBSECTION"); return SUBSUBSECTION;}
{BACKSLASH}textit{STARTBRACE}                                {printTokenDetails("ITALICS"); return ITALICS;}
{BACKSLASH}textbf{STARTBRACE}                                {printTokenDetails("BOLD"); return BOLD;}

{BACKSLASH}begin{STARTBRACE}verbatim{ENDBRACE}               {printTokenDetails("CODEBLOCKSTART"); return CODEBLOCKSTART;}
{BACKSLASH}href{STARTBRACE}                                  {printTokenDetails("HYPERLINK"); return HYPERLINK;}
{BACKSLASH}end{STARTBRACE}verbatim{ENDBRACE}                 {printTokenDetails("CODEBLOCKEND");return CODEBLOCKEND;}
{BACKSLASH}includegraphics{STARTSQUAREBRACE}                 {printTokenDetails("IMAGESTART"); return IMAGESTART;}
{BACKSLASH}textwidth                                         {printTokenDetails("TEXTWIDTH"); return TEXTWIDTH;}

{BACKSLASH}hrule                                             {printTokenDetails("HORIZONTALLINE");return HORIZONTALLINE;}
{BACKSLASH}par                                               {printTokenDetails("PARAGRAPH");return PARAGRAPH;}

{BACKSLASH}begin{STARTBRACE}itemize{ENDBRACE}                {printTokenDetails("UNORDEREDLIST");return UNORDEREDLIST;}
{BACKSLASH}item                                              {printTokenDetails("ITEM");return ITEM;}
{BACKSLASH}end{STARTBRACE}itemize{ENDBRACE}                  {printTokenDetails("ENDUNORDEREDLIST");return ENDUNORDEREDLIST;}
{BACKSLASH}begin{STARTBRACE}enumerate{ENDBRACE}              {printTokenDetails("ORDEREDLIST"); return ORDEREDLIST;}
{BACKSLASH}end{STARTBRACE}enumerate{ENDBRACE}                {printTokenDetails("ENDORDEREDLIST"); return ENDORDEREDLIST;}   
{BACKSLASH}begin{STARTBRACE}tabular{ENDBRACE}                {printTokenDetails("TABLEBEGIN"); return TABLEBEGIN;}
{STARTBRACE}{TABLECOLUMNS}{ENDBRACE}                         {printTokenDetails("TABLECOLUMNS");yylval.stringValue = new std::string(yytext); return TABLECOLUMNS;}
{BACKSLASH}hline                                             {printTokenDetails("TABLELINE"); return TABLELINE;}
{BACKSLASH}end{STARTBRACE}tabular{ENDBRACE}                  {printTokenDetails("TABLEEND"); return TABLEEND;}   

{STARTBRACE}                                                 {printTokenDetails("STARTBRACE"); return STARTBRACE;}
{ENDBRACE}                                                   {printTokenDetails("ENDBRACE"); return ENDBRACE;}
{STARTSQUAREBRACE}                                           {printTokenDetails("STARTSQUAREBRACE");return STARTSQUAREBRACE;}
{ENDSQUAREBRACE}                                             {printTokenDetails("ENDSQUAREBRACE"); return ENDSQUAREBRACE;}
[ \r]                                                      {/*ignore these characters */};
{PERCENTAGE}{CONTENT}                                        {printTokenDetails("COMMENT");}
{CONTENT}                                                    {printTokenDetails("CONTENT"); yylval.stringValue = new std::string(yytext); return CONTENT;}
[\n]                                                         {printTokenDetails("NEWLINE");return NEWLINE;}
{BACKSLASH}                                                  {printTokenDetails("BACKSLASH"); return BACKSLASH;}
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
       /* size_t length = strlen(yytext);  // Compute the length of the text holding
       printf("token is %s, length: %zu\n", s, length);*/
    } else {
        printf("token is nullptr\n");
    }
}

