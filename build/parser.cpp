/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <memory>   
#include <string>   
#include <iostream>
#include <algorithm>
#include "AST.h"

using namespace std;

extern int yylex(void); 

unique_ptr<ASTNode> root = nullptr;
void yyerror(const char* s);
int countOrderNo = 0;
int tableLineNo = 0;
int tableColumnCount = 0;


#line 90 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SECTION = 3,                    /* SECTION  */
  YYSYMBOL_SUBSECTION = 4,                 /* SUBSECTION  */
  YYSYMBOL_SUBSUBSECTION = 5,              /* SUBSUBSECTION  */
  YYSYMBOL_NEWLINE = 6,                    /* NEWLINE  */
  YYSYMBOL_CONTENT = 7,                    /* CONTENT  */
  YYSYMBOL_ITALICS = 8,                    /* ITALICS  */
  YYSYMBOL_BOLD = 9,                       /* BOLD  */
  YYSYMBOL_HORIZONTALLINE = 10,            /* HORIZONTALLINE  */
  YYSYMBOL_PARAGRAPH = 11,                 /* PARAGRAPH  */
  YYSYMBOL_ENDBRACE = 12,                  /* ENDBRACE  */
  YYSYMBOL_STARTBRACE = 13,                /* STARTBRACE  */
  YYSYMBOL_CODEBLOCKSTART = 14,            /* CODEBLOCKSTART  */
  YYSYMBOL_CODEBLOCKEND = 15,              /* CODEBLOCKEND  */
  YYSYMBOL_HYPERLINK = 16,                 /* HYPERLINK  */
  YYSYMBOL_START = 17,                     /* START  */
  YYSYMBOL_TITLE = 18,                     /* TITLE  */
  YYSYMBOL_PACKAGES = 19,                  /* PACKAGES  */
  YYSYMBOL_DOCUMENT = 20,                  /* DOCUMENT  */
  YYSYMBOL_DATE = 21,                      /* DATE  */
  YYSYMBOL_IMAGESTART = 22,                /* IMAGESTART  */
  YYSYMBOL_STARTSQUAREBRACE = 23,          /* STARTSQUAREBRACE  */
  YYSYMBOL_ENDSQUAREBRACE = 24,            /* ENDSQUAREBRACE  */
  YYSYMBOL_TEXTWIDTH = 25,                 /* TEXTWIDTH  */
  YYSYMBOL_END = 26,                       /* END  */
  YYSYMBOL_UNORDEREDLIST = 27,             /* UNORDEREDLIST  */
  YYSYMBOL_ENDUNORDEREDLIST = 28,          /* ENDUNORDEREDLIST  */
  YYSYMBOL_ITEM = 29,                      /* ITEM  */
  YYSYMBOL_ORDEREDLIST = 30,               /* ORDEREDLIST  */
  YYSYMBOL_ENDORDEREDLIST = 31,            /* ENDORDEREDLIST  */
  YYSYMBOL_TABLEBEGIN = 32,                /* TABLEBEGIN  */
  YYSYMBOL_TABLECOLUMNS = 33,              /* TABLECOLUMNS  */
  YYSYMBOL_TABLELINE = 34,                 /* TABLELINE  */
  YYSYMBOL_BACKSLASH = 35,                 /* BACKSLASH  */
  YYSYMBOL_TABLEEND = 36,                  /* TABLEEND  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_page = 38,                      /* page  */
  YYSYMBOL_sentences = 39,                 /* sentences  */
  YYSYMBOL_sentence = 40,                  /* sentence  */
  YYSYMBOL_headings = 41,                  /* headings  */
  YYSYMBOL_fonts = 42,                     /* fonts  */
  YYSYMBOL_commonPart = 43,                /* commonPart  */
  YYSYMBOL_code = 44,                      /* code  */
  YYSYMBOL_sametext = 45,                  /* sametext  */
  YYSYMBOL_link = 46,                      /* link  */
  YYSYMBOL_lists = 47,                     /* lists  */
  YYSYMBOL_unorderedListItems = 48,        /* unorderedListItems  */
  YYSYMBOL_orderedListItems = 49,          /* orderedListItems  */
  YYSYMBOL_image = 50,                     /* image  */
  YYSYMBOL_table = 51,                     /* table  */
  YYSYMBOL_countTableColumn = 52,          /* countTableColumn  */
  YYSYMBOL_tablerows = 53,                 /* tablerows  */
  YYSYMBOL_ignore = 54,                    /* ignore  */
  YYSYMBOL_linkfirsthalf = 55,             /* linkfirsthalf  */
  YYSYMBOL_linksecondhalf = 56,            /* linksecondhalf  */
  YYSYMBOL_imagefirsthalf = 57,            /* imagefirsthalf  */
  YYSYMBOL_imagesecondhalf = 58            /* imagesecondhalf  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    62,    63,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    83,    87,    91,    97,   101,
     105,   108,   111,   116,   122,   126,   131,   136,   142,   146,
     154,   163,   170,   174,   178,   181,   187,   195,   199,   207,
     212,   219,   224,   234,   239,   246,   251,   262,   270,   276,
     282,   290,   302,   309,   324,   325,   326,   327,   328,   329,
     333,   337,   341,   345
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SECTION",
  "SUBSECTION", "SUBSUBSECTION", "NEWLINE", "CONTENT", "ITALICS", "BOLD",
  "HORIZONTALLINE", "PARAGRAPH", "ENDBRACE", "STARTBRACE",
  "CODEBLOCKSTART", "CODEBLOCKEND", "HYPERLINK", "START", "TITLE",
  "PACKAGES", "DOCUMENT", "DATE", "IMAGESTART", "STARTSQUAREBRACE",
  "ENDSQUAREBRACE", "TEXTWIDTH", "END", "UNORDEREDLIST",
  "ENDUNORDEREDLIST", "ITEM", "ORDEREDLIST", "ENDORDEREDLIST",
  "TABLEBEGIN", "TABLECOLUMNS", "TABLELINE", "BACKSLASH", "TABLEEND",
  "$accept", "page", "sentences", "sentence", "headings", "fonts",
  "commonPart", "code", "sametext", "link", "lists", "unorderedListItems",
  "orderedListItems", "image", "table", "countTableColumn", "tablerows",
  "ignore", "linkfirsthalf", "linksecondhalf", "imagefirsthalf",
  "imagesecondhalf", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -89,    32,    -3,   -89,    15,    44,    50,   -89,   -89,    61,
      65,   -89,   -89,    68,    54,    76,    77,    78,    79,    80,
      81,    83,    84,    85,    59,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,    74,    82,    86,    87,    88,    22,
      89,    41,    89,    68,    68,    90,    91,   -89,   -89,   -89,
     -89,   -89,    69,   -89,    94,    95,   -89,    98,    99,   -89,
     100,   -89,   -89,   -89,   -89,    89,   -89,    96,    18,    89,
     -89,    28,   -89,   -89,   -89,   -89,    73,    21,    14,    47,
      13,     5,    97,   101,    34,   -89,   102,   -89,    40,   103,
     -89,   -89,   104,   105,    42,   -89,   109,   111,    49,   -89,
      58,   112,     2,   -89,   -89,   107,   -89,   -89,   108,   -89,
     -89,    94,   115,   116,   117,   119,    95,   120,   122,   106,
     -89,   110,   123,   -89,   -89,   -89,   124,   -89,    94,   126,
     -89,   127,   129,    95,   130,   113,   -89,    27,   131,   -89,
      29,   -89,   132,   -89,   134,   136,    35,   137,    36,   -89,
     -89,   138,   -89,   140,   -89,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,    13,    14,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    34,     0,     0,    54,    58,    55,
      57,    56,     0,    59,     0,     0,    49,     0,     0,    36,
       0,    47,    15,    16,    17,     0,    19,     0,     0,     0,
      18,     0,    32,    33,    31,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,    28,     0,     0,
      24,    62,     0,     0,     0,    37,     0,     0,     0,    38,
       0,     0,     0,    61,    63,     0,    26,    29,     0,    22,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,    48,    27,    23,     0,    41,     0,     0,
      45,     0,     0,     0,     0,     0,    51,     0,     0,    39,
       0,    43,     0,    52,     0,     0,     0,     0,     0,    50,
      42,     0,    46,     0,    40,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,   -89,   -32,   -89,    37,   -89,
     -89,   -85,   -88,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    25,    26,    27,    68,    28,    45,    29,
      30,    78,    80,    31,    32,    57,   102,    33,    34,    59,
      35,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,     5,     6,     7,     8,     9,    10,    11,    12,   121,
      71,    13,   100,    14,    15,    16,    17,    18,    19,    20,
      98,    94,    36,    21,    22,    86,   126,    23,   131,    24,
      87,    65,     3,    84,    66,    89,   122,    88,   123,   101,
      90,   105,    95,   138,    99,   142,   106,   108,    92,    69,
      93,    37,   109,    70,   113,   145,   114,    38,   117,   118,
     147,    46,   113,   151,   114,   117,   118,   153,    39,   113,
      40,   114,    41,    42,    43,    44,    96,    97,   117,   118,
      72,    73,    47,    48,    49,    50,    51,    58,    52,    53,
      54,    55,    56,   119,    76,    60,    67,    91,    62,    63,
      64,    77,    79,    75,    81,    74,    82,    83,    85,   103,
     111,     0,   112,   104,   107,   110,   115,   116,   120,   124,
     125,   127,   128,     0,   129,   130,     0,   132,   133,   136,
       0,   137,   139,     0,   140,   141,   143,     0,   146,   148,
     149,   134,   150,   152,   154,   135,   155,     0,   144
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    10,    11,     7,
      42,    14,     7,    16,    17,    18,    19,    20,    21,    22,
       7,     7,     7,    26,    27,     7,   111,    30,   116,    32,
      12,     9,     0,    65,    12,     7,    34,    69,    36,    34,
      12,     7,    28,   128,    31,   133,    12,     7,    27,     8,
      29,     7,    12,    12,    27,    28,    29,     7,    29,    30,
      31,     7,    27,    28,    29,    29,    30,    31,     7,    27,
       9,    29,     7,     8,     6,     7,    29,    30,    29,    30,
      43,    44,     6,     6,     6,     6,     6,    13,     7,     6,
       6,     6,    33,    35,    25,    13,     7,    24,    12,    12,
      12,     7,     7,    12,     6,    15,     7,     7,    12,    12,
       6,    -1,     7,    12,    12,    12,     7,     6,     6,    12,
      12,     6,     6,    -1,     7,     6,    -1,     7,     6,     6,
      -1,     7,     6,    -1,     7,     6,     6,    -1,     7,     7,
       6,    35,     6,     6,     6,    35,     6,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    14,    16,    17,    18,    19,    20,    21,
      22,    26,    27,    30,    32,    40,    41,    42,    44,    46,
      47,    50,    51,    54,    55,    57,     7,     7,     7,     7,
       9,     7,     8,     6,     7,    45,     7,     6,     6,     6,
       6,     6,     7,     6,     6,     6,    33,    52,    13,    56,
      13,    58,    12,    12,    12,     9,    12,     7,    43,     8,
      12,    43,    45,    45,    15,    12,    25,     7,    48,     7,
      49,     6,     7,     7,    43,    12,     7,    12,    43,     7,
      12,    24,    27,    29,     7,    28,    29,    30,     7,    31,
       7,    34,    53,    12,    12,     7,    12,    12,     7,    12,
      12,     6,     7,    27,    29,     7,     6,    29,    30,    35,
       6,     7,    34,    36,    12,    12,    48,     6,     6,     7,
       6,    49,     7,     6,    35,    35,     6,     7,    48,     6,
       7,     6,    49,     6,    35,    28,     7,    31,     7,     6,
       6,    28,     6,    31,     6,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    41,    41,    41,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      43,    44,    45,    45,    45,    45,    46,    47,    47,    48,
      48,    48,    48,    49,    49,    49,    49,    50,    51,    52,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      55,    56,    57,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     5,     6,     4,     5,     5,     6,     4,     5,
       2,     3,     2,     2,     1,     1,     2,     4,     4,     5,
       8,     4,     7,     5,     8,     4,     7,     2,     5,     1,
       5,     3,     4,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* page: sentences  */
#line 55 "src/parser.y"
                { 
        root = make_unique<ASTNode>("page", "");
        root->addChild(unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1234 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 3: /* sentences: %empty  */
#line 62 "src/parser.y"
                { (yyval.node) = new ASTNode("sentences", ""); }
#line 1240 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 4: /* sentences: sentences sentence  */
#line 63 "src/parser.y"
                         { 
        (yyval.node) = (yyvsp[-1].node);
        (yyval.node)->children.push_back(unique_ptr<ASTNode>((yyvsp[0].node))); 
    }
#line 1249 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 5: /* sentence: headings  */
#line 70 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1255 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 6: /* sentence: fonts  */
#line 71 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1261 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 7: /* sentence: code  */
#line 72 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1267 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 8: /* sentence: link  */
#line 73 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1273 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 9: /* sentence: lists  */
#line 74 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1279 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 10: /* sentence: image  */
#line 75 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1285 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 11: /* sentence: table  */
#line 76 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1291 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 12: /* sentence: ignore  */
#line 77 "src/parser.y"
                    { (yyval.node) = new ASTNode("ignore", ""); }
#line 1297 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 13: /* sentence: NEWLINE  */
#line 78 "src/parser.y"
                    { (yyval.node) = new ASTNode("newline", "\n"); }
#line 1303 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 14: /* sentence: CONTENT  */
#line 79 "src/parser.y"
                    { (yyval.node) = new ASTNode("content", *(yyvsp[0].stringValue)); delete (yyvsp[0].stringValue); }
#line 1309 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 15: /* headings: SECTION CONTENT ENDBRACE  */
#line 83 "src/parser.y"
                                   { 
            (yyval.node) = new ASTNode("heading", *(yyvsp[-1].stringValue));
            delete (yyvsp[-1].stringValue);
        }
#line 1318 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 16: /* headings: SUBSECTION CONTENT ENDBRACE  */
#line 87 "src/parser.y"
                                      { 
            (yyval.node) = new ASTNode("subheading", *(yyvsp[-1].stringValue));
            delete (yyvsp[-1].stringValue);
        }
#line 1327 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 17: /* headings: SUBSUBSECTION CONTENT ENDBRACE  */
#line 91 "src/parser.y"
                                         { 
            (yyval.node) = new ASTNode("subsubheading", *(yyvsp[-1].stringValue));
            delete (yyvsp[-1].stringValue);
        }
#line 1336 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 18: /* fonts: BOLD CONTENT ENDBRACE  */
#line 97 "src/parser.y"
                          { 
        (yyval.node) = new ASTNode("bold", *(yyvsp[-1].stringValue)); 
        delete (yyvsp[-1].stringValue); 
    }
#line 1345 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 19: /* fonts: ITALICS CONTENT ENDBRACE  */
#line 101 "src/parser.y"
                               { 
        (yyval.node) = new ASTNode("italics", *(yyvsp[-1].stringValue)); 
        delete (yyvsp[-1].stringValue); 
    }
#line 1354 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 20: /* fonts: HORIZONTALLINE  */
#line 105 "src/parser.y"
                     { 
        (yyval.node) = new ASTNode("horizontal_line", "---");
    }
#line 1362 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 21: /* fonts: PARAGRAPH  */
#line 108 "src/parser.y"
                { 
        (yyval.node) = new ASTNode("paragraph", "\n");
    }
#line 1370 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 22: /* fonts: BOLD CONTENT ITALICS commonPart ENDBRACE  */
#line 111 "src/parser.y"
                                               {
        (yyval.node) = new ASTNode("bold_italics", "**" + *(yyvsp[-3].stringValue) + "** " + (yyvsp[-1].node)->value);
        delete (yyvsp[-3].stringValue);
        delete (yyvsp[-1].node);
    }
#line 1380 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 23: /* fonts: BOLD CONTENT ITALICS commonPart CONTENT ENDBRACE  */
#line 116 "src/parser.y"
                                                       {
        (yyval.node) = new ASTNode("bold_italics", "**" + *(yyvsp[-4].stringValue) + "** " + (yyvsp[-2].node)->value + "**" + *(yyvsp[-1].stringValue) + "** ");
        delete (yyvsp[-4].stringValue);
        delete (yyvsp[-2].node);
        delete (yyvsp[-1].stringValue);
    }
#line 1391 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 24: /* fonts: BOLD ITALICS commonPart ENDBRACE  */
#line 122 "src/parser.y"
                                       {
        (yyval.node) = new ASTNode("bold_italics", (yyvsp[-1].node)->value);
        delete (yyvsp[-1].node);
    }
#line 1400 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 25: /* fonts: BOLD ITALICS commonPart CONTENT ENDBRACE  */
#line 126 "src/parser.y"
                                               {
        (yyval.node) = new ASTNode("bold_italics", (yyvsp[-2].node)->value + "**" + *(yyvsp[-1].stringValue) + "** ");
        delete (yyvsp[-2].node);
        delete (yyvsp[-1].stringValue);
    }
#line 1410 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 26: /* fonts: ITALICS CONTENT BOLD commonPart ENDBRACE  */
#line 131 "src/parser.y"
                                               {
        (yyval.node) = new ASTNode("italics_bold", "*" + *(yyvsp[-3].stringValue) + "* " + (yyvsp[-1].node)->value);
        delete (yyvsp[-3].stringValue);
        delete (yyvsp[-1].node);
    }
#line 1420 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 27: /* fonts: ITALICS CONTENT BOLD commonPart CONTENT ENDBRACE  */
#line 136 "src/parser.y"
                                                       {
        (yyval.node) = new ASTNode("italics_bold", "*" + *(yyvsp[-4].stringValue) + "* " + (yyvsp[-2].node)->value + "*" + *(yyvsp[-1].stringValue) + "* ");
        delete (yyvsp[-4].stringValue);
        delete (yyvsp[-2].node);
        delete (yyvsp[-1].stringValue);
    }
#line 1431 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 28: /* fonts: ITALICS BOLD commonPart ENDBRACE  */
#line 142 "src/parser.y"
                                       {
        (yyval.node) = new ASTNode("italics_bold", (yyvsp[-1].node)->value);
        delete (yyvsp[-1].node);
    }
#line 1440 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 29: /* fonts: ITALICS BOLD commonPart CONTENT ENDBRACE  */
#line 146 "src/parser.y"
                                               {
        (yyval.node) = new ASTNode("italics_bold", (yyvsp[-2].node)->value + "*" + *(yyvsp[-1].stringValue) + "* ");
        delete (yyvsp[-2].node);
        delete (yyvsp[-1].stringValue);
    }
#line 1450 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 30: /* commonPart: CONTENT ENDBRACE  */
#line 154 "src/parser.y"
                       {
        (yyval.node) = new ASTNode("italics_and_bold", "***" + *(yyvsp[-1].stringValue) + "*** ");
        delete (yyvsp[-1].stringValue);
    }
#line 1459 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 31: /* code: CODEBLOCKSTART sametext CODEBLOCKEND  */
#line 163 "src/parser.y"
                                         {
        (yyval.node) = new ASTNode("codeblock", *(yyvsp[-1].stringValue));
        delete (yyvsp[-1].stringValue);
    }
#line 1468 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 32: /* sametext: NEWLINE sametext  */
#line 170 "src/parser.y"
                     {
        (yyval.stringValue) = new std::string("\n" + *(yyvsp[0].stringValue));
        delete (yyvsp[0].stringValue);
    }
#line 1477 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 33: /* sametext: CONTENT sametext  */
#line 174 "src/parser.y"
                       {
        (yyval.stringValue) = new std::string(*(yyvsp[-1].stringValue) + *(yyvsp[0].stringValue));
        delete (yyvsp[0].stringValue);
    }
#line 1486 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 34: /* sametext: CONTENT  */
#line 178 "src/parser.y"
              {
        (yyval.stringValue) = new std::string(*(yyvsp[0].stringValue));
    }
#line 1494 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 35: /* sametext: NEWLINE  */
#line 181 "src/parser.y"
              {
        (yyval.stringValue) = new std::string("\n");
    }
#line 1502 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 36: /* link: linkfirsthalf linksecondhalf  */
#line 187 "src/parser.y"
                                     {
            (yyval.node) = new ASTNode("link", "[" + (yyvsp[0].node)->value + "](" + (yyvsp[-1].node)->value + ")");
            delete (yyvsp[-1].node);
            delete (yyvsp[0].node);
        }
#line 1512 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 37: /* lists: UNORDEREDLIST NEWLINE unorderedListItems ENDUNORDEREDLIST  */
#line 195 "src/parser.y"
                                                                  {
            (yyval.node) = new ASTNode("unordered_list", "");
            (yyval.node)->addChild(unique_ptr<ASTNode>((yyvsp[-1].node)));
        }
#line 1521 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 38: /* lists: ORDEREDLIST NEWLINE orderedListItems ENDORDEREDLIST  */
#line 199 "src/parser.y"
                                                              {
            countOrderNo = 0;
            (yyval.node) = new ASTNode("ordered_list", "");
            (yyval.node)->addChild(unique_ptr<ASTNode>((yyvsp[-1].node)));
        }
#line 1531 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 39: /* unorderedListItems: unorderedListItems CONTENT ITEM CONTENT NEWLINE  */
#line 207 "src/parser.y"
                                                       {
            (yyval.node) = (yyvsp[-4].node);
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", "-" + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1541 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 40: /* unorderedListItems: unorderedListItems CONTENT UNORDEREDLIST NEWLINE unorderedListItems CONTENT ENDUNORDEREDLIST NEWLINE  */
#line 212 "src/parser.y"
                                                                                                               {
            (yyval.node) = (yyvsp[-7].node);
            auto nestedList = make_unique<ASTNode>("nested_unordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>((yyvsp[-3].node)));
            (yyval.node)->addChild(make_unique<ASTNode>("nested_list_item", ""));
            (yyval.node)->children.back()->addChild(move(nestedList));
        }
#line 1553 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 41: /* unorderedListItems: CONTENT ITEM CONTENT NEWLINE  */
#line 219 "src/parser.y"
                                      {
            (yyval.node) = new ASTNode("list_items");
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", "-" + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1563 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 42: /* unorderedListItems: CONTENT UNORDEREDLIST NEWLINE unorderedListItems CONTENT ENDUNORDEREDLIST NEWLINE  */
#line 224 "src/parser.y"
                                                                                            {
            (yyval.node) = new ASTNode("list_items");
            auto nestedList = make_unique<ASTNode>("unordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>((yyvsp[-3].node)));
            (yyval.node)->addChild(make_unique<ASTNode>("nested_list_item", ""));
            (yyval.node)->children.back()->addChild(move(nestedList));
        }
#line 1575 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 43: /* orderedListItems: orderedListItems CONTENT ITEM CONTENT NEWLINE  */
#line 234 "src/parser.y"
                                                      {
            (yyval.node) = (yyvsp[-4].node);
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", to_string(++countOrderNo) + "." + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1585 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 44: /* orderedListItems: orderedListItems CONTENT ORDEREDLIST NEWLINE orderedListItems CONTENT ENDORDEREDLIST NEWLINE  */
#line 239 "src/parser.y"
                                                                                                        {
            (yyval.node) = (yyvsp[-7].node);
            auto nestedList = make_unique<ASTNode>("nested_ordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>((yyvsp[-3].node)));
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", ""));
            (yyval.node)->children.back()->addChild(move(nestedList));
        }
#line 1597 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 45: /* orderedListItems: CONTENT ITEM CONTENT NEWLINE  */
#line 246 "src/parser.y"
                                       {
            (yyval.node) = new ASTNode("list_items");
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", to_string(++countOrderNo) + "." + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1607 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 46: /* orderedListItems: CONTENT ORDEREDLIST NEWLINE orderedListItems CONTENT ENDORDEREDLIST NEWLINE  */
#line 251 "src/parser.y"
                                                                                      {
            (yyval.node) = new ASTNode("list_items");
            auto nestedList = make_unique<ASTNode>("ordered_list", "");
            nestedList->addChild(unique_ptr<ASTNode>((yyvsp[-3].node)));
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", ""));
            (yyval.node)->children.back()->addChild(move(nestedList));
        }
#line 1619 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 47: /* image: imagefirsthalf imagesecondhalf  */
#line 262 "src/parser.y"
                                         { 
            (yyval.node) = new ASTNode("image", (yyvsp[-1].node)->value + (yyvsp[0].node)->value);
            delete (yyvsp[-1].node);
            delete (yyvsp[0].node);
        }
#line 1629 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 48: /* table: TABLEBEGIN countTableColumn NEWLINE tablerows TABLEEND  */
#line 270 "src/parser.y"
                                                              {
            (yyval.node) = new ASTNode("table", "");
            (yyval.node)->addChild(unique_ptr<ASTNode>((yyvsp[-1].node)));
        }
#line 1638 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 49: /* countTableColumn: TABLECOLUMNS  */
#line 276 "src/parser.y"
                  {
        tableColumnCount = count((yyvsp[0].stringValue)->begin(), (yyvsp[0].stringValue)->end(), 'c') ;  
    }
#line 1646 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 50: /* tablerows: tablerows CONTENT BACKSLASH BACKSLASH NEWLINE  */
#line 282 "src/parser.y"
                                                      {
        string modifiedContent = *(yyvsp[-3].stringValue);
        replace(modifiedContent.begin(), modifiedContent.end(), '&', '|');

        (yyval.node) = (yyvsp[-4].node);
        (yyval.node)->addChild(make_unique<ASTNode>("table_item", "|" +  modifiedContent + "|"));
        delete (yyvsp[-3].stringValue);
    }
#line 1659 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 51: /* tablerows: tablerows TABLELINE NEWLINE  */
#line 290 "src/parser.y"
                                  {
        (yyval.node) = (yyvsp[-2].node);
        tableLineNo++;
        if (tableLineNo == 2) {
            string separatorLine = "|";
            for(int i = 0; i < tableColumnCount; ++i) {
                separatorLine += "----------------------|";
            }
            (yyval.node)->addChild(make_unique<ASTNode>("table_separator", separatorLine));  
        }
        
    }
#line 1676 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 52: /* tablerows: CONTENT BACKSLASH BACKSLASH NEWLINE  */
#line 302 "src/parser.y"
                                          {
        string modifiedContent = *(yyvsp[-3].stringValue);
        replace(modifiedContent.begin(), modifiedContent.end(), '&', '|');
        (yyval.node) = new ASTNode("table_items");
        (yyval.node)->addChild(make_unique<ASTNode>("table_item", "|" +  modifiedContent + "|"));
        delete (yyvsp[-3].stringValue);
    }
#line 1688 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 53: /* tablerows: TABLELINE NEWLINE  */
#line 309 "src/parser.y"
                       {
        (yyval.node) = new ASTNode("table_header");
        tableLineNo++;
        if (tableLineNo == 2) {
            string separatorLine = "|";
            for(int i = 0; i < tableColumnCount; ++i) {
                separatorLine += "----------------------|";
            }
            (yyval.node)->addChild(make_unique<ASTNode>("table_separator", separatorLine));  
        }
    }
#line 1704 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 54: /* ignore: START NEWLINE  */
#line 324 "src/parser.y"
                        { (yyval.node) = new ASTNode("ignore", ""); }
#line 1710 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 55: /* ignore: PACKAGES NEWLINE  */
#line 325 "src/parser.y"
                           { (yyval.node) = new ASTNode("ignore", ""); }
#line 1716 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 56: /* ignore: DATE NEWLINE  */
#line 326 "src/parser.y"
                       { (yyval.node) = new ASTNode("ignore", ""); }
#line 1722 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 57: /* ignore: DOCUMENT NEWLINE  */
#line 327 "src/parser.y"
                           { (yyval.node) = new ASTNode("ignore", ""); }
#line 1728 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 58: /* ignore: TITLE NEWLINE  */
#line 328 "src/parser.y"
                        { (yyval.node) = new ASTNode("ignore", ""); }
#line 1734 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 59: /* ignore: END NEWLINE  */
#line 329 "src/parser.y"
                      { (yyval.node) = new ASTNode("ignore", ""); }
#line 1740 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 60: /* linkfirsthalf: HYPERLINK CONTENT ENDBRACE  */
#line 333 "src/parser.y"
                                     { (yyval.node) = new ASTNode("hyperlink", *(yyvsp[-1].stringValue)); delete (yyvsp[-1].stringValue); }
#line 1746 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 61: /* linksecondhalf: STARTBRACE CONTENT ENDBRACE  */
#line 337 "src/parser.y"
                                      { (yyval.node) = new ASTNode("link_text", *(yyvsp[-1].stringValue)); delete (yyvsp[-1].stringValue); }
#line 1752 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 62: /* imagefirsthalf: IMAGESTART CONTENT TEXTWIDTH ENDSQUAREBRACE  */
#line 341 "src/parser.y"
                                                      { (yyval.node) = new ASTNode("image_desc", "![IMAGE]"); }
#line 1758 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;

  case 63: /* imagesecondhalf: STARTBRACE CONTENT ENDBRACE  */
#line 345 "src/parser.y"
                                      { (yyval.node) = new ASTNode("image_url", "(" + *(yyvsp[-1].stringValue) + ")"); delete (yyvsp[-1].stringValue); }
#line 1764 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"
    break;


#line 1768 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/build/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 348 "src/parser.y"


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
