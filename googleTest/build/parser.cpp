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
#line 1 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"

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


#line 88 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"

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
  YYSYMBOL_code = 43,                      /* code  */
  YYSYMBOL_sametext = 44,                  /* sametext  */
  YYSYMBOL_link = 45,                      /* link  */
  YYSYMBOL_lists = 46,                     /* lists  */
  YYSYMBOL_unorderedListItems = 47,        /* unorderedListItems  */
  YYSYMBOL_orderedListItems = 48,          /* orderedListItems  */
  YYSYMBOL_image = 49,                     /* image  */
  YYSYMBOL_table = 50,                     /* table  */
  YYSYMBOL_countTableColumn = 51,          /* countTableColumn  */
  YYSYMBOL_tablerows = 52,                 /* tablerows  */
  YYSYMBOL_ignore = 53,                    /* ignore  */
  YYSYMBOL_linkfirsthalf = 54,             /* linkfirsthalf  */
  YYSYMBOL_linksecondhalf = 55,            /* linksecondhalf  */
  YYSYMBOL_imagefirsthalf = 56,            /* imagefirsthalf  */
  YYSYMBOL_imagesecondhalf = 57            /* imagesecondhalf  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

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
       0,    53,    53,    60,    61,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    81,    85,    89,    96,   100,
     104,   107,   113,   120,   124,   128,   131,   137,   145,   149,
     157,   162,   170,   176,   185,   193,   199,   205,   213,   225,
     232,   247,   248,   249,   250,   251,   252,   256,   260,   264,
     268
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
  "$accept", "page", "sentences", "sentence", "headings", "fonts", "code",
  "sametext", "link", "lists", "unorderedListItems", "orderedListItems",
  "image", "table", "countTableColumn", "tablerows", "ignore",
  "linkfirsthalf", "linksecondhalf", "imagefirsthalf", "imagesecondhalf", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -17,    28,    -3,   -17,    23,    24,    25,   -17,   -17,    27,
      32,   -17,   -17,    15,    33,    29,    35,    36,    37,    39,
      40,    42,    43,    44,    18,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,    41,    45,    34,    47,    48,    49,
      50,    15,    15,    38,    51,   -17,   -17,   -17,   -17,   -17,
      30,   -17,    57,    58,   -17,    46,    59,   -17,    60,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,    52,
      53,     5,    54,    13,     3,    56,    61,   -17,    62,    55,
     -17,    63,    64,   -17,    21,    65,     2,   -17,   -17,    66,
      67,    69,    70,    22,   -17,    68,    72,   -17,   -17,    73,
     -17,    74,    75,    71,   -17,   -17,   -17,   -17,    79,   -17
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
       0,    26,    25,     0,     0,    41,    45,    42,    44,    43,
       0,    46,     0,     0,    36,     0,     0,    27,     0,    34,
      15,    16,    17,    19,    18,    23,    24,    22,    47,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
      28,     0,     0,    29,     0,     0,     0,    48,    50,     0,
       0,     0,     0,     0,    40,     0,     0,    35,    31,     0,
      33,     0,     0,     0,    38,    30,    32,    39,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -16,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    25,    26,    27,    28,    43,    29,    30,
      71,    73,    31,    32,    55,    86,    33,    34,    57,    35,
      59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       4,     5,     6,     7,     8,     9,    10,    11,    12,    95,
      84,    13,    79,    14,    15,    16,    17,    18,    19,    20,
      82,    41,    42,    21,    22,    65,    66,    23,     3,    24,
      36,    37,    38,    80,    39,    45,    96,    85,    97,    40,
      44,    46,    47,    48,    83,    49,    60,    50,    51,    52,
      53,    54,    74,    67,    56,    69,    93,   102,    58,    61,
      62,    63,    64,    68,    70,    72,    75,    76,    87,    89,
      91,    94,    98,    88,    99,   100,    77,   101,   104,   105,
     106,   107,    78,    81,    90,   109,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,   108
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    10,    11,     7,
       7,    14,     7,    16,    17,    18,    19,    20,    21,    22,
       7,     6,     7,    26,    27,    41,    42,    30,     0,    32,
       7,     7,     7,    28,     7,     6,    34,    34,    36,     7,
       7,     6,     6,     6,    31,     6,    12,     7,     6,     6,
       6,    33,     6,    15,    13,    25,    35,    35,    13,    12,
      12,    12,    12,    12,     7,     7,     7,     7,    12,     7,
       7,     6,     6,    12,     7,     6,    24,     7,     6,     6,
       6,     6,    29,    29,    29,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    14,    16,    17,    18,    19,    20,    21,
      22,    26,    27,    30,    32,    40,    41,    42,    43,    45,
      46,    49,    50,    53,    54,    56,     7,     7,     7,     7,
       7,     6,     7,    44,     7,     6,     6,     6,     6,     6,
       7,     6,     6,     6,    33,    51,    13,    55,    13,    57,
      12,    12,    12,    12,    12,    44,    44,    15,    12,    25,
       7,    47,     7,    48,     6,     7,     7,    24,    29,     7,
      28,    29,     7,    31,     7,    34,    52,    12,    12,     7,
      29,     7,    29,    35,     6,     7,    34,    36,     6,     7,
       6,     7,    35,    35,     6,     6,     6,     6,    35,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    41,    41,    41,    42,    42,
      42,    42,    43,    44,    44,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    50,    51,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    55,    56,
      57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     3,     2,     2,     1,     1,     2,     4,     4,
       5,     4,     5,     4,     2,     5,     1,     5,     3,     4,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     4,
       3
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
#line 53 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                { 
        root = make_unique<ASTNode>("page", "");
        root->addChild(unique_ptr<ASTNode>((yyvsp[0].node)));
    }
#line 1204 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 3: /* sentences: %empty  */
#line 60 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                { (yyval.node) = new ASTNode("sentences", ""); }
#line 1210 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 4: /* sentences: sentences sentence  */
#line 61 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                         { 
        (yyval.node) = (yyvsp[-1].node);
        (yyval.node)->children.push_back(unique_ptr<ASTNode>((yyvsp[0].node))); // Add at the end
    }
#line 1219 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 5: /* sentence: headings  */
#line 68 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1225 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 6: /* sentence: fonts  */
#line 69 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1231 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 7: /* sentence: code  */
#line 70 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1237 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 8: /* sentence: link  */
#line 71 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1243 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 9: /* sentence: lists  */
#line 72 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1249 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 10: /* sentence: image  */
#line 73 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1255 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 11: /* sentence: table  */
#line 74 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1261 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 12: /* sentence: ignore  */
#line 75 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = new ASTNode("ignore", ""); }
#line 1267 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 13: /* sentence: NEWLINE  */
#line 76 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = new ASTNode("newline", "\n"); }
#line 1273 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 14: /* sentence: CONTENT  */
#line 77 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { (yyval.node) = new ASTNode("content", *(yyvsp[0].stringValue)); delete (yyvsp[0].stringValue); }
#line 1279 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 15: /* headings: SECTION CONTENT ENDBRACE  */
#line 81 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                   { 
            (yyval.node) = new ASTNode("heading", *(yyvsp[-1].stringValue));
            delete (yyvsp[-1].stringValue);
        }
#line 1288 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 16: /* headings: SUBSECTION CONTENT ENDBRACE  */
#line 85 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                      { 
            (yyval.node) = new ASTNode("subheading", *(yyvsp[-1].stringValue));
            delete (yyvsp[-1].stringValue);
        }
#line 1297 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 17: /* headings: SUBSUBSECTION CONTENT ENDBRACE  */
#line 89 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                         { 
            (yyval.node) = new ASTNode("subsubheading", *(yyvsp[-1].stringValue));
            delete (yyvsp[-1].stringValue);
        }
#line 1306 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 18: /* fonts: BOLD CONTENT ENDBRACE  */
#line 96 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                { 
            (yyval.node) = new ASTNode("bold", *(yyvsp[-1].stringValue)); 
            delete (yyvsp[-1].stringValue); 
        }
#line 1315 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 19: /* fonts: ITALICS CONTENT ENDBRACE  */
#line 100 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                   { 
            (yyval.node) = new ASTNode("italics", *(yyvsp[-1].stringValue)); 
            delete (yyvsp[-1].stringValue); 
        }
#line 1324 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 20: /* fonts: HORIZONTALLINE  */
#line 104 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                         { 
            (yyval.node) = new ASTNode("horizontal_line", "---");
        }
#line 1332 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 21: /* fonts: PARAGRAPH  */
#line 107 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                    { 
            (yyval.node) = new ASTNode("paragraph", "\n");
        }
#line 1340 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 22: /* code: CODEBLOCKSTART sametext CODEBLOCKEND  */
#line 113 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                         {
        (yyval.node) = new ASTNode("codeblock", *(yyvsp[-1].stringValue));
        delete (yyvsp[-1].stringValue);
    }
#line 1349 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 23: /* sametext: NEWLINE sametext  */
#line 120 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                     {
        (yyval.stringValue) = new std::string("\n" + *(yyvsp[0].stringValue));
        delete (yyvsp[0].stringValue);
    }
#line 1358 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 24: /* sametext: CONTENT sametext  */
#line 124 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                       {
        (yyval.stringValue) = new std::string(*(yyvsp[-1].stringValue) + *(yyvsp[0].stringValue));
        delete (yyvsp[0].stringValue);
    }
#line 1367 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 25: /* sametext: CONTENT  */
#line 128 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
              {
        (yyval.stringValue) = new std::string(*(yyvsp[0].stringValue));
    }
#line 1375 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 26: /* sametext: NEWLINE  */
#line 131 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
              {
        (yyval.stringValue) = new std::string("\n");
    }
#line 1383 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 27: /* link: linkfirsthalf linksecondhalf  */
#line 137 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                     {
            (yyval.node) = new ASTNode("link", "[" + (yyvsp[0].node)->value + "](" + (yyvsp[-1].node)->value + ")");
            delete (yyvsp[-1].node);
            delete (yyvsp[0].node);
        }
#line 1393 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 28: /* lists: UNORDEREDLIST NEWLINE unorderedListItems ENDUNORDEREDLIST  */
#line 145 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                                                  {
            (yyval.node) = new ASTNode("unordered_list", "");
            (yyval.node)->addChild(unique_ptr<ASTNode>((yyvsp[-1].node)));
        }
#line 1402 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 29: /* lists: ORDEREDLIST NEWLINE orderedListItems ENDORDEREDLIST  */
#line 149 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                                              {
            countOrderNo = 0;
            (yyval.node) = new ASTNode("ordered_list", "");
            (yyval.node)->addChild(unique_ptr<ASTNode>((yyvsp[-1].node)));
        }
#line 1412 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 30: /* unorderedListItems: unorderedListItems CONTENT ITEM CONTENT NEWLINE  */
#line 157 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                                       {
            (yyval.node) = (yyvsp[-4].node);
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", "-" + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1422 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 31: /* unorderedListItems: CONTENT ITEM CONTENT NEWLINE  */
#line 162 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                      {
            (yyval.node) = new ASTNode("list_items");
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", "-" + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1432 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 32: /* orderedListItems: orderedListItems CONTENT ITEM CONTENT NEWLINE  */
#line 170 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                                       {
            countOrderNo++;
            (yyval.node) = (yyvsp[-4].node);
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", to_string(countOrderNo) + "." + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1443 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 33: /* orderedListItems: CONTENT ITEM CONTENT NEWLINE  */
#line 176 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                       {
            countOrderNo++;
            (yyval.node) = new ASTNode("list_items");
            (yyval.node)->addChild(make_unique<ASTNode>("list_item", to_string(countOrderNo) + "." + *(yyvsp[-1].stringValue)));
            delete (yyvsp[-1].stringValue);
        }
#line 1454 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 34: /* image: imagefirsthalf imagesecondhalf  */
#line 185 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                         { 
            (yyval.node) = new ASTNode("image", (yyvsp[-1].node)->value + (yyvsp[0].node)->value);
            delete (yyvsp[-1].node);
            delete (yyvsp[0].node);
        }
#line 1464 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 35: /* table: TABLEBEGIN countTableColumn NEWLINE tablerows TABLEEND  */
#line 193 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                                              {
            (yyval.node) = new ASTNode("table", "");
            (yyval.node)->addChild(unique_ptr<ASTNode>((yyvsp[-1].node)));
        }
#line 1473 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 36: /* countTableColumn: TABLECOLUMNS  */
#line 199 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                  {
        tableColumnCount = count((yyvsp[0].stringValue)->begin(), (yyvsp[0].stringValue)->end(), 'c') ;  
    }
#line 1481 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 37: /* tablerows: tablerows CONTENT BACKSLASH BACKSLASH NEWLINE  */
#line 205 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                                      {
        string modifiedContent = *(yyvsp[-3].stringValue);
        replace(modifiedContent.begin(), modifiedContent.end(), '&', '|');

        (yyval.node) = (yyvsp[-4].node);
        (yyval.node)->addChild(make_unique<ASTNode>("table_item", "|" +  modifiedContent + "|"));
        delete (yyvsp[-3].stringValue);
    }
#line 1494 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 38: /* tablerows: tablerows TABLELINE NEWLINE  */
#line 213 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
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
#line 1511 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 39: /* tablerows: CONTENT BACKSLASH BACKSLASH NEWLINE  */
#line 225 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                          {
        string modifiedContent = *(yyvsp[-3].stringValue);
        replace(modifiedContent.begin(), modifiedContent.end(), '&', '|');
        (yyval.node) = new ASTNode("table_items");
        (yyval.node)->addChild(make_unique<ASTNode>("table_item", "|" +  modifiedContent + "|"));
        delete (yyvsp[-3].stringValue);
    }
#line 1523 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 40: /* tablerows: TABLELINE NEWLINE  */
#line 232 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
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
#line 1539 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 41: /* ignore: START NEWLINE  */
#line 247 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                        { (yyval.node) = new ASTNode("ignore", ""); }
#line 1545 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 42: /* ignore: PACKAGES NEWLINE  */
#line 248 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                           { (yyval.node) = new ASTNode("ignore", ""); }
#line 1551 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 43: /* ignore: DATE NEWLINE  */
#line 249 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                       { (yyval.node) = new ASTNode("ignore", ""); }
#line 1557 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 44: /* ignore: DOCUMENT NEWLINE  */
#line 250 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                           { (yyval.node) = new ASTNode("ignore", ""); }
#line 1563 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 45: /* ignore: TITLE NEWLINE  */
#line 251 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                        { (yyval.node) = new ASTNode("ignore", ""); }
#line 1569 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 46: /* ignore: END NEWLINE  */
#line 252 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                      { (yyval.node) = new ASTNode("ignore", ""); }
#line 1575 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 47: /* linkfirsthalf: HYPERLINK CONTENT ENDBRACE  */
#line 256 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                     { (yyval.node) = new ASTNode("hyperlink", *(yyvsp[-1].stringValue)); delete (yyvsp[-1].stringValue); }
#line 1581 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 48: /* linksecondhalf: STARTBRACE CONTENT ENDBRACE  */
#line 260 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                      { (yyval.node) = new ASTNode("link_text", *(yyvsp[-1].stringValue)); delete (yyvsp[-1].stringValue); }
#line 1587 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 49: /* imagefirsthalf: IMAGESTART CONTENT TEXTWIDTH ENDSQUAREBRACE  */
#line 264 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                                      { (yyval.node) = new ASTNode("image_desc", "![IMAGE]"); }
#line 1593 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;

  case 50: /* imagesecondhalf: STARTBRACE CONTENT ENDBRACE  */
#line 268 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"
                                      { (yyval.node) = new ASTNode("image_url", "(" + *(yyvsp[-1].stringValue) + ")"); delete (yyvsp[-1].stringValue); }
#line 1599 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"
    break;


#line 1603 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/build/parser.cpp"

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

#line 271 "/mnt/c/Users/Garg/Desktop/project/GoogleDoc/LatexToMarkdownConverter/googleTest/../src/parser.y"


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
