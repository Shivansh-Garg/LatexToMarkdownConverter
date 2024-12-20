/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MNT_C_USERS_GARG_DESKTOP_PROJECT_GOOGLEDOC_LATEXTOMARKDOWNCONVERTER_GOOGLETEST_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_MNT_C_USERS_GARG_DESKTOP_PROJECT_GOOGLEDOC_LATEXTOMARKDOWNCONVERTER_GOOGLETEST_BUILD_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 28 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"

    #include <string>
    #include <algorithm>
    #include "AST.h"
    using namespace std;

#line 56 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SECTION = 258,                 /* SECTION  */
    SUBSECTION = 259,              /* SUBSECTION  */
    SUBSUBSECTION = 260,           /* SUBSUBSECTION  */
    NEWLINE = 261,                 /* NEWLINE  */
    CONTENT = 262,                 /* CONTENT  */
    ITALICS = 263,                 /* ITALICS  */
    BOLD = 264,                    /* BOLD  */
    HORIZONTALLINE = 265,          /* HORIZONTALLINE  */
    PARAGRAPH = 266,               /* PARAGRAPH  */
    ENDBRACE = 267,                /* ENDBRACE  */
    STARTBRACE = 268,              /* STARTBRACE  */
    CODEBLOCKSTART = 269,          /* CODEBLOCKSTART  */
    CODEBLOCKEND = 270,            /* CODEBLOCKEND  */
    HYPERLINK = 271,               /* HYPERLINK  */
    START = 272,                   /* START  */
    TITLE = 273,                   /* TITLE  */
    PACKAGES = 274,                /* PACKAGES  */
    DOCUMENT = 275,                /* DOCUMENT  */
    DATE = 276,                    /* DATE  */
    IMAGESTART = 277,              /* IMAGESTART  */
    STARTSQUAREBRACE = 278,        /* STARTSQUAREBRACE  */
    ENDSQUAREBRACE = 279,          /* ENDSQUAREBRACE  */
    TEXTWIDTH = 280,               /* TEXTWIDTH  */
    END = 281,                     /* END  */
    UNORDEREDLIST = 282,           /* UNORDEREDLIST  */
    ENDUNORDEREDLIST = 283,        /* ENDUNORDEREDLIST  */
    ITEM = 284,                    /* ITEM  */
    ORDEREDLIST = 285,             /* ORDEREDLIST  */
    ENDORDEREDLIST = 286,          /* ENDORDEREDLIST  */
    TABLEBEGIN = 287,              /* TABLEBEGIN  */
    TABLECOLUMNS = 288,            /* TABLECOLUMNS  */
    TABLELINE = 289,               /* TABLELINE  */
    BACKSLASH = 290,               /* BACKSLASH  */
    TABLEEND = 291                 /* TABLEEND  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"

    ASTNode* node;
    string* stringValue;
    int intValue;

#line 115 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MNT_C_USERS_GARG_DESKTOP_PROJECT_GOOGLEDOC_LATEXTOMARKDOWNCONVERTER_GOOGLETEST_BUILD_PARSER_HPP_INCLUDED  */
