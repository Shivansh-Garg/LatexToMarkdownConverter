%{
    #include <stdio.h>
    #include <string.h>

    extern int yylex();
    void token(const char* s);
%}

ALPHABET            [a-zA-Z]
NUMBER              [0-9]
PUNCTUATION         [.,\-()]
SPECIAL             [\#\$\%\&\~\_\^]
STARTBRACE          \{
ENDBRACE            \}
SPACE               " "
TAB                 \t
LETTER              ({ALPHABET}|{NUMBER}|{SPECIAL}|{PUNCTUATION})
WORD                {ALPHABET}+
TEXT                ({LETTER})+
SENTENCE            ({TEXT}|{SPACE}|{TAB})+
BACKSLASH           \\
NEWLINE             \n

%%
{BACKSLASH}section{STARTBRACE}{SENTENCE}{ENDBRACE}                  {token("SECTION");}
{BACKSLASH}subsection{STARTBRACE}{SENTENCE}{ENDBRACE}               {token("SUBSECTION"); }
{BACKSLASH}subsubsection{STARTBRACE}{SENTENCE}{ENDBRACE}            {token("SUBSUBSECTION");}
{BACKSLASH}textit{STARTBRACE}{SENTENCE}{ENDBRACE}                   {token("ITALICS");}
{BACKSLASH}textbf{STARTBRACE}{SENTENCE}{ENDBRACE}                   {token("BOLD");}


{SENTENCE}                           {token("SENTENCE"); }
{NEWLINE}                            {token("NEWLINE"); }
.                                    {token("OTHER"); }

%%

int yywrap() {
    return 1;
}

int main(){
    yylex();
    return 0;
}
void token(const char* s) {
    printf("%s\n", s);
    return;
}
