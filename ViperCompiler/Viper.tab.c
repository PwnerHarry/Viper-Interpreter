/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Viper.y" /* yacc.c:339  */

using namespace std;
#include "ctype.h"
#include "string.h"
#include "iostream"
#include "fstream"
#include "math.h"
#define D(x) if (!VIPER_COMPILER_DIAGNOSE); else x

const int TOKEN_TABLE_SIZE = 4096;
const int VIPER_COMPILER_DIAGNOSE = 1;
class Token {
public:
	int lineno;
	int type;
	int layer;
	int availability;
	union {
		double D;
		int I;
		char * S;
		char C;
	} value;
	Token(){
		layer = 0;
		availability = 0;
		lineno = 0;
		type = 0;
		value.D = 0;
		value.C = 0;
		value.S = 0;
		value.I = 0;
	};
};
class TokenTable {
public:
	int Pointer;
	int Size;
	Token * t;
	TokenTable() {
		Size = 0;
		t = new Token[TOKEN_TABLE_SIZE];
		Pointer = 0;
	}
};
typedef union {
	int Int;
	double Double;
	char * String;
	char Char;
} Arg;
class Function {
	char * name;
	Arg * Arguments;
	TokenTable * Definations;
	char * Return;
};
int yylex();
int ReadTokens(ifstream &f, TokenTable * T);
void DispTokens(TokenTable * T);
void yyerror(char *s);
TokenTable * T = new TokenTable;
class function {
public:
	char * name;
	union {
		int ret_int;
		int ret_double;
		int ret_void;
	} Return;
	function() {
		name = 0;
		Return.ret_int = 0;
		Return.ret_double = 0;
		Return.ret_void = 1;
	}
};
union YYSTYPE{
	int Int;
	double Double;
	char * String;
	char * Name;
	char Char;
	bool Bool;
	function * Function;
};

#line 154 "Viper.tab.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Viper.tab.h".  */
#ifndef YY_YY_VIPER_TAB_H_INCLUDED
# define YY_YY_VIPER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    CHAR = 259,
    NAME = 260,
    STRING = 261,
    INDENT = 262,
    DEDENT = 263,
    ENDMARKER = 264,
    UNKNOWN = 265,
    ASYNC = 266,
    AWAIT = 267,
    ELLIPSIS = 268,
    LBRACE = 269,
    RBRACE = 270,
    COLON = 271,
    EQUAL = 272,
    AT = 273,
    SEMI = 274,
    NEWLINE = 275,
    FROM = 276,
    EXEC = 277,
    WITH = 278,
    RAISE = 279,
    TRY = 280,
    DEL = 281,
    AS = 282,
    ASSERT = 283,
    IS = 284,
    EXCEPT = 285,
    FINALLY = 286,
    LAMBDA = 287,
    YIELD = 288,
    IMPORT = 289,
    WHILE = 290,
    BREAK = 291,
    CONTINUE = 292,
    GLOBAL = 293,
    ELIF = 294,
    ELSE = 295,
    PASS = 296,
    RETURN = 297,
    IN = 298,
    FOR = 299,
    CLASS = 300,
    NOT = 301,
    AND = 302,
    OR = 303,
    IF = 304,
    DEF = 305,
    DOUBLESTAR = 306,
    DOUBLESLASH = 307,
    LESS = 308,
    LESSEQUAL = 309,
    EQEQUAL = 310,
    NOTEQUAL = 311,
    GREATEREQUAL = 312,
    GREATER = 313,
    PLUS = 314,
    MINUS = 315,
    STAR = 316,
    SLASH = 317,
    PERCENT = 318,
    COMMA = 319,
    DOT = 320,
    LPAR = 321,
    RPAR = 322,
    LSQB = 323,
    RSQB = 324,
    PLUSEQUAL = 325,
    MINEQUAL = 326,
    STAREQUAL = 327,
    SLASHEQUAL = 328,
    VBAREQUAL = 329,
    AMPEREQUAL = 330,
    CIRCUMFLEXEQUAL = 331,
    ATEQUAL = 332,
    DOUBLESLASHEQUAL = 333,
    PERCENTEQUAL = 334,
    DOUBLESTAREQUAL = 335,
    NONLOCAL = 336,
    VBAR = 337,
    AMPER = 338,
    CIRCUMFLEX = 339,
    TILDE = 340,
    LEFTSHIFT = 341,
    LEFTSHIFTEQUAL = 342,
    RIGHTSHIFT = 343,
    RIGHTSHIFTEQUAL = 344,
    RARROW = 345,
    NEG = 346
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_VIPER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 297 "Viper.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  128
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1099

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  343
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  563

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   350

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   186,   186,   192,   193,   194,   201,   202,   203,   205,
     206,   207,   208,   209,   210,   211,   212,   214,   215,   216,
     218,   219,   220,   222,   223,   224,   225,   226,   227,   228,
     229,   231,   232,   234,   235,   237,   239,   240,   241,   243,
     244,   246,   247,   248,   250,   251,   253,   254,   256,   257,
     259,   260,   262,   263,   264,   265,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   299,   300,   302,   303,
     305,   306,   307,   308,   309,   311,   312,   314,   315,   317,
     318,   319,   320,   321,   322,   323,   324,   326,   327,   329,
     330,   332,   333,   334,   335,   336,   337,   338,   339,   341,
     342,   343,   345,   346,   347,   348,   350,   352,   353,   355,
     356,   358,   360,   361,   363,   364,   366,   367,   368,   369,
     371,   372,   374,   375,   377,   378,   380,   381,   382,   383,
     385,   386,   388,   389,   391,   392,   394,   395,   397,   398,
     399,   400,   401,   402,   404,   405,   407,   408,   410,   411,
     412,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   439,   440,   442,   443,   445,
     447,   448,   450,   451,   452,   453,   454,   456,   458,   459,
     461,   463,   464,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   527,   528,   530,   531,   533,   535,   536,   538,
     540,   541,   542,   544,   545,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   557,   558,   559,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   579,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   596,
     597,   598,   599,   601,   602,   604,   606,   607,   609,   610,
     611,   613,   615,   616
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "CHAR", "NAME", "STRING",
  "INDENT", "DEDENT", "ENDMARKER", "UNKNOWN", "\"async\"", "\"await\"",
  "\"...\"", "\"}\"", "\"{\"", "\":\"", "\"=\"", "\"@\"", "\";\"",
  "\"\\n\"", "\"from\"", "\"exec\"", "\"with\"", "\"raise\"", "\"try\"",
  "\"del\"", "\"as\"", "\"assert\"", "\"is\"", "\"except\"", "\"finally\"",
  "\"lambda\"", "\"yield\"", "\"import\"", "\"while\"", "\"break\"",
  "\"continue\"", "\"global\"", "\"elif\"", "\"else\"", "\"pass\"",
  "\"return\"", "\"in\"", "\"for\"", "\"class\"", "\"not\"", "\"and\"",
  "\"or\"", "\"if\"", "\"def\"", "\"**\"", "\"//\"", "\"<\"", "\"<=\"",
  "\"==\"", "\"!=\"", "\">=\"", "\">\"", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\",\"", "\".\"", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"|=\"", "\"&=\"", "\"^=\"",
  "\"@=\"", "\"//=\"", "\"%=\"", "\"**=\"", "\"nonlocal\"", "\"|\"",
  "\"&\"", "\"^\"", "\"~\"", "\"<<\"", "\"<<=\"", "\">>\"", "\">>=\"",
  "\"->\"", "NEG", "\"None\"", "\"True\"", "\"False\"", "\"<>\"",
  "$accept", "file_input", "file_input_sub", "classdef",
  "typedargslist_long", "typedargslist_sub", "typedargslist_ct",
  "typedargslist", "parameters", "funcdef", "async_funcdef", "decorator",
  "decorators", "decorated", "tfpdef", "suite_sub", "suite", "stmt",
  "simple_stmt_sub", "simple_stmt", "varargslist_another_sub",
  "varargslist_sub_sub_sub", "varargslist_sub_sub", "varargslist_sub",
  "varargslist", "sliceop", "subscript", "subscriptlist_sub",
  "subscriptlist", "argument", "arglist_sub", "arglist", "trailer",
  "testlist_sub", "testlist", "yield_arg", "yield_expr", "small_stmt",
  "expr_sub_sub", "expr_sub", "expr_stmt", "annassign",
  "testlist_star_expr", "star_expr", "exprlist_es", "exprlist_sub",
  "exprlist", "lambdef_nocond", "test_nocond", "comp_if", "comp_iter",
  "comp_for", "testlist_comp_sub_ts", "dictorsetmaker_sub",
  "dictorsetmaker_tt", "dictorsetmaker_tt_sub", "dictorsetmaker",
  "lambdef", "testlist_comp_sub_co", "testlist_comp", "string_plus",
  "atom_sub_yt", "atom_sub_t", "atom_sub_d", "atom", "trailer_star",
  "except_clause", "while_stmt", "for_stmt", "try_stmt_sub_sub",
  "try_stmt_sub_plus", "try_stmt_sub", "try_stmt", "with_stmt_sub",
  "with_stmt", "with_item", "atom_expr", "power", "factor", "term_sub",
  "term", "arith_expr_sub", "arith_expr", "shift_expr_sub", "shift_expr",
  "and_expr_sub", "and_expr", "xor_expr_sub", "xor_expr", "expr",
  "augassign", "comp_op", "comparison_sub", "comparison", "not_test",
  "and_test_sub", "and_test", "or_test_sub", "or_test", "test",
  "assert_stmt", "compound_stmt", "async_stmt", "if_stmt_sub", "if_stmt",
  "global_stmt", "nonlocal_stmt", "dotted_name", "vfpdef", "continue_stmt",
  "flow_stmt", "del_stmt", "break_stmt", "pass_stmt", "import_as_name",
  "dotted_as_name", "import_as_names", "dotted_as_names", "import_sub",
  "dot_plus", "import_from", "import_name", "import_stmt", "raise_stmt",
  "yield_stmt", "return_stmt", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350
};
# endif

#define YYPACT_NINF -478

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-478)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     951,   190,    82,   951,    49,   797,   797,   128,   815,   797,
     596,    82,   797,  -478,  -478,   151,  -478,   797,   815,   162,
     797,   170,   638,   191,   212,    45,  -478,  -478,   144,    40,
    -478,   951,  -478,  -478,   203,  -478,   248,   163,  -478,  -478,
    -478,  -478,  -478,  -478,  -478,  -478,   187,   189,  -478,  -478,
    -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,
    -478,  -478,  -478,    87,  -478,    49,    49,    58,  -478,  -478,
     224,    32,  -478,   480,    66,    43,   748,   748,   530,   638,
     748,  -478,  -478,  -478,  -478,  -478,   149,   199,   217,  -478,
     143,    10,   164,   186,   188,   248,  -478,  -478,   223,   226,
     222,   249,   257,  1018,   748,  -478,   215,  -478,  -478,   216,
     797,  -478,  -478,   227,   123,  -478,   228,   274,  -478,  -478,
     250,    64,   278,   229,  -478,   163,  -478,  -478,  -478,  -478,
    -478,   246,  -478,  -478,  -478,  -478,   352,   154,   797,    17,
    -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,
    -478,   748,  -478,  -478,  -478,  -478,  -478,   654,   236,   298,
     299,  -478,   300,   345,  -478,  -478,    35,     8,  -478,   149,
     748,    20,    75,  -478,   292,   291,  -478,   797,   304,    48,
     294,    74,  -478,  -478,  -478,  -478,    88,  -478,   244,  -478,
     243,  -478,   308,   412,   712,   149,  -478,   797,   301,   748,
     748,   748,   748,   748,   748,  -478,   748,   748,  -478,   748,
     748,  -478,   748,  -478,   748,  -478,  -478,   841,    43,  -478,
      43,  -478,    43,   748,   797,   309,   206,  -478,  -478,   815,
     268,   797,  -478,   797,   272,   335,    82,  1018,   797,  1018,
     462,  1018,    27,    18,  -478,  -478,   203,   321,  -478,   325,
     326,   326,   248,  -478,  -478,  -478,  -478,  -478,  -478,   797,
     797,   327,   281,   279,   138,   322,  -478,   347,   289,  -478,
    -478,    35,  -478,  -478,   310,   815,  -478,   297,   730,  -478,
     302,  -478,   797,  -478,   303,   304,  -478,  -478,   306,   307,
     797,   797,  -478,   311,   638,  -478,   315,  -478,  -478,  -478,
    -478,   288,   779,   317,   287,   348,  -478,   199,  1018,  -478,
     143,   143,   143,   143,   143,    10,    10,   164,   164,   186,
     188,   319,  -478,   320,  -478,  -478,  -478,  -478,  -478,  -478,
    -478,   748,   223,   226,   334,  -478,  -478,   986,   797,   366,
     368,  -478,   185,  -478,   215,  -478,  -478,   227,  -478,  -478,
    -478,   357,   371,  -478,   376,   332,   361,   386,   398,    54,
    -478,   340,   104,  1018,   797,  -478,  -478,   797,  -478,  -478,
    -478,  -478,  -478,  -478,   546,   344,   389,   797,  -478,   405,
     354,   347,  -478,   815,   379,  -478,   350,   291,  -478,  -478,
    -478,   114,   372,  -478,  -478,   307,   157,   355,  -478,  -478,
     797,  -478,   410,   712,   364,  -478,   779,  -478,  -478,  -478,
    -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,
    -478,  -478,  -478,  -478,  -478,   797,   423,   909,   408,  1018,
    1018,   416,  -478,  -478,  -478,   424,  1018,  1018,   425,   797,
     403,   797,   381,   398,   382,   383,  -478,   797,   384,  -478,
     433,  -478,   281,  -478,  -478,  -478,  -478,  -478,  -478,   407,
      43,  -478,   797,  -478,   304,  -478,   304,    48,  -478,  -478,
    -478,   317,  -478,  -478,   410,  -478,  -478,  -478,   446,  -478,
     422,  1018,  1018,   413,  -478,  1018,   438,   439,  -478,  -478,
     130,   409,   392,   383,   160,  -478,  1018,  -478,    43,   137,
     307,   395,   397,  -478,  -478,  -478,  -478,  -478,   431,  -478,
     448,  -478,  1018,  1018,   797,  -478,   398,  -478,   409,   384,
     398,    54,  -478,   137,   846,  -478,  -478,  -478,  -478,  -478,
    -478,  -478,  1018,   361,  -478,   383,   402,  -478,  -478,   406,
     417,   383,  -478,   129,  -478,   137,  -478,  -478,  -478,  -478,
    -478,  -478,   409,   418,   846,   453,  -478,  -478,   409,  -478,
     846,  -478,  -478
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     152,     0,     0,   152,     0,     0,   338,     0,     0,     0,
     109,     0,     0,   315,   308,     0,   316,   342,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   290,    39,     0,
     292,   152,    50,   341,    52,   111,   119,   152,   286,   287,
     288,   289,   118,    51,   293,   285,   116,   117,   310,   114,
     112,   309,   113,   337,   336,   115,   312,   313,   311,   294,
     296,   295,   305,     0,     4,   330,   329,     0,   185,   184,
     171,     0,   180,   178,     0,     0,     0,     0,   173,   176,
       0,   181,   182,   183,   282,   186,   190,   208,   215,   217,
     221,   228,   232,   236,   239,   119,   269,   273,   274,   277,
     280,   211,   339,   152,     0,   133,   134,   314,   132,   283,
       0,   108,   110,   103,   319,   324,   335,     0,   301,   343,
       0,     0,     0,     0,   151,   152,   150,   303,     1,     2,
      40,     0,    41,    42,    43,     5,   152,     0,     0,   152,
     245,   246,   247,   249,   252,   251,   253,   248,   257,   250,
     256,     0,   254,   255,   125,   126,   122,     0,   129,     0,
       0,    36,     0,     0,   332,   331,     0,     0,   172,   190,
       0,   152,   156,   179,     0,   150,   307,     0,     0,    67,
       0,    67,   272,   218,   219,   174,   166,   175,     0,   177,
       0,   220,     0,     0,     0,   190,   213,     0,     0,     0,
       0,     0,     0,     0,     0,   227,     0,     0,   231,     0,
       0,   235,     0,   238,     0,   241,   244,   271,     0,   276,
       0,   279,     0,     0,     0,     0,     0,    48,   131,     0,
     136,     0,   107,     0,   105,     0,     0,   152,     0,   152,
       0,   152,     0,     0,   153,    35,    52,     0,    54,   127,
     119,   119,   119,   124,   123,   130,   302,   304,   306,     0,
       0,     0,    95,     0,    90,   317,   326,     0,   321,   328,
     334,     0,   214,   155,     0,     0,   161,   162,     0,   158,
     159,   189,     0,   165,    73,     0,    72,    62,    63,    67,
       0,     0,    71,    56,     0,   168,   169,   187,   188,   102,
      99,     0,    78,    86,     0,    77,   191,   208,   152,   216,
     221,   221,   221,   221,   221,   228,   228,   232,   232,   236,
     239,   267,   265,     0,   258,   262,   260,   264,   261,   259,
     263,     0,   274,   277,     0,   212,   340,   152,   192,     0,
       0,   206,   202,   207,   134,   137,   284,   103,   106,   320,
     325,   195,     0,     6,     0,     0,   297,    44,     0,    20,
      31,     0,    20,   152,     0,    53,    55,     0,   120,   121,
     243,    93,    94,    37,     0,    97,     0,     0,    91,     0,
       0,   322,   333,     0,     0,   163,   156,     0,   160,   154,
      74,    67,    64,    61,   164,    67,    57,   166,   170,   100,
      75,    79,    80,     0,    88,   101,    82,   209,   210,   223,
     226,   222,   224,   225,   229,   230,   233,   234,   237,   240,
     268,   266,   270,   275,   278,     0,     0,   152,   193,   152,
     152,     0,   203,   135,   104,     0,   152,   152,     0,     0,
     299,     0,    29,     0,    25,    20,    32,     0,     9,    33,
       0,   128,    95,    98,    38,    92,   318,   327,   323,     0,
       0,   157,     0,    68,     0,    70,     0,    67,   167,    76,
      81,    86,    89,    83,    84,   281,    49,    47,     0,   199,
     200,   152,   152,   197,     7,   152,     0,     0,    45,    30,
      20,    17,    27,    20,    10,    23,   152,    96,     0,   146,
      67,    65,    59,    58,    87,    85,   194,   201,   204,   196,
       0,     8,   152,   152,     0,    21,     0,    26,    17,     9,
       0,    20,    34,   148,     0,   145,   147,   144,    69,    66,
      60,   205,   152,   297,   300,    20,    18,    28,    24,    15,
      11,    20,   149,     0,   141,   142,   140,   198,   298,    22,
      19,    16,    17,    13,     0,     0,   143,    12,    17,   138,
       0,    14,   139
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -478,  -478,   166,   447,   -35,  -395,  -350,  -478,  -478,    23,
    -478,  -478,   459,  -478,  -337,    61,  -198,  -311,   245,     2,
      94,    29,   209,  -171,   -53,  -345,    96,    30,  -478,   126,
      51,   -47,  -478,   155,     3,  -478,   -42,   374,    -8,   -76,
    -478,  -478,   375,   -13,   282,   171,   -15,  -478,  -477,  -478,
    -381,  -142,    -6,   -12,   238,   121,  -478,  -478,   120,   440,
     450,  -478,  -478,  -478,   454,    38,  -478,  -478,   517,  -331,
      44,  -478,  -478,   220,   531,   337,  -478,  -478,    -1,   -65,
      50,   -57,  -478,   -56,   338,   218,   324,   233,   393,     0,
    -478,  -478,  -478,  -478,   -52,   225,   346,   231,  -216,    -5,
    -478,  -478,  -478,    34,  -478,  -478,  -478,    26,  -165,  -478,
    -478,  -478,  -478,  -478,  -478,   333,  -240,  -478,   312,   201,
    -478,  -478,  -478,  -478,  -478,  -478
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,   495,   517,   444,   361,   243,    27,
     134,    28,    29,    30,   362,   426,   226,    31,   137,   227,
     292,   286,   287,   288,   180,   401,   303,   404,   304,   262,
     375,   263,   195,   234,   111,   112,    33,    34,   154,   155,
      35,   156,    36,   105,   106,   230,   107,   544,   545,   525,
     526,   527,   186,    37,   172,   280,   173,    84,   296,   187,
      85,   188,   190,   174,    86,   196,   340,    38,    39,   341,
     342,   343,    40,   198,    41,    87,    88,    89,    90,   205,
      91,   208,    92,   211,    93,   213,    94,   215,    95,    96,
     157,   331,   217,    97,    98,   219,    99,   221,   100,   113,
      42,    43,    44,   440,    45,    46,    47,   114,   181,    48,
      49,    50,    51,    52,   268,   115,   269,   116,   270,    67,
      53,    54,    55,    56,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   102,    32,   120,   109,    32,   334,   117,   108,   124,
     293,   432,   448,   284,   289,   122,   125,   126,   108,   216,
     119,   442,   445,   182,    59,   158,   427,   380,    63,   276,
     279,   274,   357,    32,   363,    68,   185,    69,    70,   351,
     265,   353,   271,   356,   295,    72,    68,    73,    69,    70,
      10,   131,   133,   176,   129,    71,    72,   470,    73,   357,
     124,   473,    65,    62,   275,   124,   124,   171,   175,   206,
     207,   176,   162,   126,   126,   183,   184,   559,   358,   191,
     239,    22,   177,   562,    22,    19,   274,    62,   359,    75,
      21,   291,   166,   167,   360,   492,   266,   250,    78,   274,
      79,   267,    76,    77,   228,   232,   490,   161,   364,    78,
     408,    79,   285,   244,    66,   254,   427,   178,   443,   275,
     391,   447,   378,   537,    81,    82,    83,   179,    80,   505,
     240,   462,   275,   249,   176,    81,    82,    83,   285,   278,
     515,   458,   542,   519,   103,   554,   301,   514,   274,   274,
     235,   162,   294,   163,   245,   377,   118,   557,   264,   277,
     253,   200,     2,   561,   556,   449,   332,   121,   443,    64,
     273,   540,   283,   247,   248,   123,   370,   531,   285,   536,
     178,   275,   275,   539,   541,   549,   524,   162,   264,   305,
     179,   553,   101,   355,   443,   201,   127,   135,   309,   310,
     311,   312,   313,   314,   202,   203,   204,   272,   466,   317,
     318,   520,   128,     5,   192,   193,   339,   194,   467,   336,
     463,   521,   136,   335,   293,   431,   346,    22,   347,   108,
      70,   479,   480,   306,    18,   264,   338,   339,   483,   484,
      21,   352,   368,   369,   499,   409,   410,   411,   412,   413,
     209,   159,   210,   160,   371,   372,   315,   316,   414,   415,
     384,   416,   417,   197,   138,   139,   164,   165,   199,   212,
     218,   222,   214,   387,   220,   108,   223,   389,   224,   229,
     231,   124,   523,   508,   509,   394,   395,   511,   397,   126,
     237,   233,   236,   238,   241,   242,    21,   402,   522,   501,
     255,   502,   289,   256,   257,   258,   281,   282,   546,   176,
     290,   297,   298,   299,   533,   534,   337,   308,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   528,
     151,   422,   345,   428,   547,   152,   348,   153,   546,    32,
     349,   366,   367,   139,   546,   374,   376,   373,    68,   379,
      69,    70,   265,   381,   383,   399,   405,    71,    72,   450,
      73,   385,   451,   421,   406,   420,   388,   390,   459,   264,
     392,   285,   455,     4,   425,   396,     6,    74,     8,   398,
       9,   403,   429,   108,   430,    10,    11,   436,    13,    14,
      15,    75,   437,    16,    17,   469,   259,   435,   305,   438,
     439,   474,   441,   357,    76,    77,   260,   446,   453,   454,
     456,    78,   261,    79,   278,    68,    22,    69,    70,   294,
     475,   457,   460,   464,    71,    72,   400,    73,   472,    32,
      80,   476,   481,    23,   486,   478,   488,    81,    82,    83,
     482,   485,   493,   487,    74,   489,   491,   443,   494,   496,
     498,   506,   338,   510,   512,   513,   518,   500,    75,   529,
     516,   530,   339,   259,   532,    68,   550,    69,    70,   560,
     551,    76,    77,   260,    71,    72,   132,    73,    78,   300,
      79,   552,   558,    68,   538,    69,    70,   130,   477,   465,
     555,   365,    71,    72,    74,    73,   503,    80,   393,   471,
     452,   504,   434,   497,    81,    82,    83,   461,    75,   535,
     246,   344,    74,   259,   251,   433,   386,   468,    60,   189,
     168,    76,    77,   260,   507,   169,    75,   407,    78,   354,
      79,   170,    61,    68,   307,    69,    70,   418,   320,    76,
      77,   104,    71,    72,   252,    73,    78,    80,    79,    68,
     319,    69,    70,   419,    81,    82,    83,   423,    71,    72,
       0,    73,    74,    10,   424,    80,   333,   548,     0,   350,
       0,     0,    81,    82,    83,     0,    75,     0,    74,     0,
       0,     0,     0,   382,     0,     0,     0,     0,     0,    76,
      77,   104,    75,     0,     0,     0,    78,   259,    79,    68,
       0,    69,    70,     0,     0,    76,    77,   260,    71,    72,
       0,    73,    78,     0,    79,    80,     0,   110,     0,     0,
       0,     0,    81,    82,    83,     0,     0,     0,    74,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    68,    75,    69,    70,     0,     0,     0,     0,     0,
      71,    72,     0,    73,     0,    76,    77,    68,     0,    69,
      70,     0,    78,     0,    79,     0,    71,    72,     0,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    75,     0,    74,    10,    81,    82,
      83,     0,     0,     0,     0,     0,     0,    76,    77,   104,
      75,     0,     0,     0,    78,     0,    79,     0,     0,     0,
       0,     0,     0,    76,    77,    68,     0,    69,    70,     0,
      78,     0,    79,    80,    71,    72,     0,    73,   302,     0,
      81,    82,    83,    68,     0,    69,    70,     0,     0,    80,
       0,     0,    71,    72,    74,    73,    81,    82,    83,     0,
       0,    68,     0,    69,    70,     0,     0,     0,    75,     0,
      71,    72,    74,    73,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,    75,     0,    78,     0,
      79,   170,    68,     0,    69,    70,     0,     0,     0,    76,
      77,    71,    72,     0,    73,   400,    78,    80,    79,     0,
      68,     0,    69,    70,    81,    82,    83,    76,    77,    71,
      72,    74,    73,     0,    78,    80,    79,     0,    68,     0,
      69,    70,    81,    82,    83,    75,     0,    71,    72,    74,
      73,     0,     0,    80,     0,     0,     0,     0,    76,    77,
      81,    82,    83,    75,     0,    78,     0,    79,     0,    68,
       0,    69,    70,     0,     0,     0,    76,    77,    71,    72,
       0,    73,     0,    78,    80,    79,     0,     0,     0,     0,
     321,    81,    82,    83,    76,    77,   104,     0,   543,     0,
       0,    78,    80,    79,   322,     0,     0,   323,     0,    81,
      82,    83,    75,     0,   324,   325,   326,   327,   328,   329,
      80,     0,     0,     0,     0,    76,    77,    81,    82,    83,
       0,     0,    78,     0,    79,     0,     0,   -46,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       4,    80,     5,     6,     7,     8,   330,     9,    81,    82,
      83,     0,    10,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,    18,    19,     0,     0,     0,    20,    21,
      -3,     0,     1,     0,     0,     0,     0,     0,     0,     2,
       0,     3,     4,    22,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
      23,     0,    16,    17,     0,    18,    19,     1,     0,     0,
      20,    21,     0,     0,     2,     0,     0,     4,     0,     5,
       6,     7,     8,     0,     9,    22,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
      18,    19,    23,     0,     0,    20,    21,     0,   225,     4,
       0,     0,     6,     0,     8,     0,     9,     0,     0,     0,
      22,    10,    11,     0,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
       5,     6,     0,    18,     9,     3,   222,    12,     8,    22,
     181,   342,   362,   178,   179,    20,    22,    22,    18,    95,
      17,   358,   359,    75,     1,    37,   337,   267,     2,   171,
     172,    11,     5,    31,    16,     3,    78,     5,     6,   237,
       5,   239,    34,   241,   186,    13,     3,    15,     5,     6,
      33,    11,    29,     5,     9,    12,    13,   402,    15,     5,
      73,   406,    13,     5,    44,    78,    79,    73,    73,    59,
      60,     5,    64,    78,    79,    76,    77,   554,    51,    80,
      16,    64,    16,   560,    64,    45,    11,     5,    61,    46,
      50,    17,    34,    67,    67,   445,    61,   139,    66,    11,
      68,    66,    59,    60,   104,   110,   443,    20,    90,    66,
     308,    68,    64,   125,    65,   157,   427,    51,    64,    44,
     285,    17,   264,   518,    92,    93,    94,    61,    85,   474,
      66,    17,    44,   138,     5,    92,    93,    94,    64,    64,
     490,   381,   523,   493,    16,    16,   193,    17,    11,    11,
      27,    64,    64,    66,   131,    17,     5,   552,   163,   171,
     157,    18,    18,   558,   545,   363,   218,     5,    64,     3,
     170,   521,   177,    19,    20,     5,   252,   508,    64,   516,
      51,    44,    44,   520,   521,   535,    49,    64,   193,   194,
      61,   541,   197,   240,    64,    52,     5,    31,   199,   200,
     201,   202,   203,   204,    61,    62,    63,   169,    51,   209,
     210,    51,     0,    23,    65,    66,    31,    68,    61,   224,
     391,    61,    19,   223,   395,    40,   231,    64,   233,   229,
       6,   429,   430,   195,    44,   240,    30,    31,   436,   437,
      50,   238,   250,   251,   460,   310,   311,   312,   313,   314,
      86,    64,    88,    64,   259,   260,   206,   207,   315,   316,
     275,   317,   318,    64,    16,    17,    65,    66,    51,    83,
      47,    49,    84,   278,    48,   275,    27,   282,    21,    64,
      64,   294,   498,   481,   482,   290,   291,   485,   294,   294,
      16,    64,    64,    43,    16,    66,    50,   302,   496,   464,
      64,   466,   467,     5,     5,     5,    14,    16,   524,     5,
      16,    67,    69,     5,   512,   513,     7,    16,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   500,
      82,   331,    64,   338,   532,    87,    64,    89,   554,   337,
       5,    20,    17,    17,   560,    64,    67,    20,     3,    27,
       5,     6,     5,    64,    44,    67,    69,    12,    13,   364,
      15,    64,   367,    43,    16,    46,    64,    64,   383,   374,
      64,    64,   377,    21,    40,    64,    24,    32,    26,    64,
      28,    64,    16,   383,    16,    33,    34,    16,    36,    37,
      38,    46,    16,    41,    42,   400,    51,    40,   403,    67,
      39,   406,    16,     5,    59,    60,    61,    67,    64,    20,
       5,    66,    67,    68,    64,     3,    64,     5,     6,    64,
     425,    67,    43,    51,    12,    13,    16,    15,    64,   427,
      85,     8,    16,    81,   439,    27,   441,    92,    93,    94,
      16,    16,   447,    40,    32,    64,    64,    64,    64,    16,
      43,     5,    30,    40,    16,    16,    64,   462,    46,    64,
      51,    64,    31,    51,    16,     3,    64,     5,     6,    16,
      64,    59,    60,    61,    12,    13,    29,    15,    66,    67,
      68,    64,    64,     3,   519,     5,     6,    28,   427,   395,
     543,   246,    12,    13,    32,    15,   467,    85,   289,   403,
     374,   471,   347,   452,    92,    93,    94,   386,    46,   514,
     136,   229,    32,    51,   139,   344,   278,   397,     1,    79,
      70,    59,    60,    61,   480,    71,    46,   307,    66,    67,
      68,    51,     1,     3,   197,     5,     6,   319,   214,    59,
      60,    61,    12,    13,   151,    15,    66,    85,    68,     3,
     212,     5,     6,   320,    92,    93,    94,   332,    12,    13,
      -1,    15,    32,    33,   333,    85,   220,   533,    -1,   236,
      -1,    -1,    92,    93,    94,    -1,    46,    -1,    32,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    46,    -1,    -1,    -1,    66,    51,    68,     3,
      -1,     5,     6,    -1,    -1,    59,    60,    61,    12,    13,
      -1,    15,    66,    -1,    68,    85,    -1,    21,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    32,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,     3,    46,     5,     6,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    15,    -1,    59,    60,     3,    -1,     5,
       6,    -1,    66,    -1,    68,    -1,    12,    13,    -1,    15,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    46,    -1,    32,    33,    92,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      46,    -1,    -1,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,     3,    -1,     5,     6,    -1,
      66,    -1,    68,    85,    12,    13,    -1,    15,    16,    -1,
      92,    93,    94,     3,    -1,     5,     6,    -1,    -1,    85,
      -1,    -1,    12,    13,    32,    15,    92,    93,    94,    -1,
      -1,     3,    -1,     5,     6,    -1,    -1,    -1,    46,    -1,
      12,    13,    32,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    46,    -1,    66,    -1,
      68,    51,     3,    -1,     5,     6,    -1,    -1,    -1,    59,
      60,    12,    13,    -1,    15,    16,    66,    85,    68,    -1,
       3,    -1,     5,     6,    92,    93,    94,    59,    60,    12,
      13,    32,    15,    -1,    66,    85,    68,    -1,     3,    -1,
       5,     6,    92,    93,    94,    46,    -1,    12,    13,    32,
      15,    -1,    -1,    85,    -1,    -1,    -1,    -1,    59,    60,
      92,    93,    94,    46,    -1,    66,    -1,    68,    -1,     3,
      -1,     5,     6,    -1,    -1,    -1,    59,    60,    12,    13,
      -1,    15,    -1,    66,    85,    68,    -1,    -1,    -1,    -1,
      29,    92,    93,    94,    59,    60,    61,    -1,    32,    -1,
      -1,    66,    85,    68,    43,    -1,    -1,    46,    -1,    92,
      93,    94,    46,    -1,    53,    54,    55,    56,    57,    58,
      85,    -1,    -1,    -1,    -1,    59,    60,    92,    93,    94,
      -1,    -1,    66,    -1,    68,    -1,    -1,     8,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    85,    23,    24,    25,    26,    95,    28,    92,    93,
      94,    -1,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    42,    -1,    44,    45,    -1,    -1,    -1,    49,    50,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    64,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      81,    -1,    41,    42,    -1,    44,    45,    11,    -1,    -1,
      49,    50,    -1,    -1,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    -1,    28,    64,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    -1,
      44,    45,    81,    -1,    -1,    49,    50,    -1,    20,    21,
      -1,    -1,    24,    -1,    26,    -1,    28,    -1,    -1,    -1,
      64,    33,    34,    -1,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    18,    20,    21,    23,    24,    25,    26,    28,
      33,    34,    35,    36,    37,    38,    41,    42,    44,    45,
      49,    50,    64,    81,    97,    98,    99,   105,   107,   108,
     109,   113,   115,   132,   133,   136,   138,   149,   163,   164,
     168,   170,   196,   197,   198,   200,   201,   202,   205,   206,
     207,   208,   209,   216,   217,   218,   219,   220,   221,   105,
     164,   170,     5,   203,    98,    13,    65,   215,     3,     5,
       6,    12,    13,    15,    32,    46,    59,    60,    66,    68,
      85,    92,    93,    94,   153,   156,   160,   171,   172,   173,
     174,   176,   178,   180,   182,   184,   185,   189,   190,   192,
     194,   195,   195,    16,    61,   139,   140,   142,   185,   195,
      21,   130,   131,   195,   203,   211,   213,   195,     5,   130,
     142,     5,   195,     5,   139,   148,   195,     5,     0,     9,
     108,    11,    99,   105,   106,    98,    19,   114,    16,    17,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    82,    87,    89,   134,   135,   137,   186,   149,    64,
      64,    20,    64,    66,   215,   215,    34,   203,   156,   160,
      51,   148,   150,   152,   159,   195,     5,    16,    51,    61,
     120,   204,   190,   174,   174,   132,   148,   155,   157,   155,
     158,   174,    65,    66,    68,   128,   161,    64,   169,    51,
      18,    52,    61,    62,    63,   175,    59,    60,   177,    86,
      88,   179,    83,   181,    84,   183,   135,   188,    47,   191,
      48,   193,    49,    27,    21,    20,   112,   115,   185,    64,
     141,    64,   195,    64,   129,    27,    64,    16,    43,    16,
      66,    16,    66,   104,   149,   105,   133,    19,    20,   195,
     132,   138,   184,   130,   132,    64,     5,     5,     5,    51,
      61,    67,   125,   127,   195,     5,    61,    66,   210,   212,
     214,    34,   161,   185,    11,    44,   147,   149,    64,   147,
     151,    14,    16,   195,   204,    64,   117,   118,   119,   204,
      16,    17,   116,   119,    64,   147,   154,    67,    69,     5,
      67,   127,    16,   122,   124,   195,   161,   171,    16,   174,
     174,   174,   174,   174,   174,   176,   176,   185,   185,   180,
     182,    29,    43,    46,    53,    54,    55,    56,    57,    58,
      95,   187,   190,   192,   194,   185,   195,     7,    30,    31,
     162,   165,   166,   167,   140,    64,   195,   195,    64,     5,
     211,   112,   130,   112,    67,   127,   112,     5,    51,    61,
      67,   103,   110,    16,    90,   114,    20,    17,   134,   134,
     135,   195,   195,    20,    64,   126,    67,    17,   147,    27,
     212,    64,   214,    44,   142,    64,   150,   195,    64,   195,
      64,   204,    64,   118,   195,   195,    64,   148,    64,    67,
      16,   121,   195,    64,   123,    69,    16,   169,   112,   175,
     175,   175,   175,   175,   177,   177,   179,   179,   181,   183,
      46,    43,   185,   191,   193,    40,   111,   113,   195,    16,
      16,    40,   165,   141,   129,    40,    16,    16,    67,    39,
     199,    16,   110,    64,   102,   110,    67,    17,   102,   112,
     195,   195,   125,    64,    20,   195,     5,    67,   212,   142,
      43,   151,    17,   119,    51,   116,    51,    61,   154,   195,
     121,   122,    64,   121,   195,   195,     8,   111,    27,   112,
     112,    16,    16,   112,   112,    16,   195,    40,   195,    64,
     110,    64,   102,   195,    64,   100,    16,   126,    43,   194,
     195,   204,   204,   117,   123,   121,     5,   166,   112,   112,
      40,   112,    16,    16,    17,   102,    51,   101,    64,   102,
      51,    61,   112,   194,    49,   145,   146,   147,   119,    64,
      64,   165,    16,   112,   112,   195,   110,   101,   100,   110,
     102,   110,   146,    32,   143,   144,   194,   112,   199,   102,
      64,    64,    64,   102,    16,   120,   146,   101,    64,   144,
      16,   101,   144
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    98,    98,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105,   105,   106,   107,   107,   107,   108,
     108,   109,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   118,   118,   119,   119,   119,
     120,   120,   120,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   133,   133,   133,   133,   133,   134,
     134,   134,   135,   135,   135,   135,   136,   137,   137,   138,
     138,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   147,   147,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     152,   152,   152,   152,   153,   153,   154,   154,   155,   155,
     155,   156,   156,   157,   157,   157,   158,   158,   159,   159,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     161,   161,   162,   162,   162,   163,   163,   164,   164,   165,
     166,   166,   167,   167,   167,   167,   167,   168,   169,   169,
     170,   171,   171,   172,   172,   173,   173,   174,   174,   174,
     174,   175,   175,   175,   175,   175,   175,   176,   177,   177,
     177,   178,   179,   179,   179,   180,   181,   181,   182,   183,
     183,   184,   135,   135,   185,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   188,
     188,   189,   190,   190,   191,   191,   192,   193,   193,   194,
     195,   195,   195,   196,   196,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   198,   198,   198,   199,   199,   200,
     200,   201,   201,   202,   202,   203,   203,   204,   205,   206,
     206,   206,   206,   206,   207,   208,   209,   210,   210,   211,
     211,   212,   212,   212,   213,   213,   214,   214,   214,   215,
     215,   215,   215,   216,   216,   217,   218,   218,   219,   219,
     219,   220,   221,   221
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     4,     6,     7,     0,
       1,     3,     5,     4,     6,     3,     4,     0,     2,     3,
       0,     3,     5,     3,     5,     2,     4,     3,     5,     2,
       3,     2,     3,     5,     7,     2,     3,     5,     6,     1,
       2,     2,     2,     2,     1,     3,     1,     2,     1,     4,
       1,     1,     0,     3,     3,     4,     1,     2,     4,     4,
       5,     2,     1,     1,     2,     4,     5,     0,     3,     5,
       4,     2,     2,     2,     3,     1,     2,     1,     1,     2,
       2,     3,     2,     3,     3,     4,     0,     3,     2,     3,
       1,     2,     3,     2,     2,     0,     3,     2,     3,     2,
       3,     3,     2,     0,     3,     2,     3,     2,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     3,     1,     2,     2,     1,     2,     2,     4,     2,
       3,     2,     1,     1,     0,     3,     2,     3,     3,     4,
       1,     1,     2,     3,     1,     1,     4,     5,     5,     6,
       1,     1,     0,     3,     3,     2,     0,     3,     2,     2,
       3,     2,     2,     3,     4,     3,     0,     3,     2,     2,
       3,     1,     2,     0,     1,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       0,     2,     1,     2,     4,     4,     7,     6,     9,     3,
       3,     4,     1,     2,     4,     5,     1,     4,     0,     3,
       5,     1,     3,     2,     3,     1,     3,     1,     2,     2,
       2,     0,     3,     3,     3,     3,     3,     2,     0,     3,
       3,     2,     0,     3,     3,     2,     0,     3,     2,     0,
       3,     2,     0,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     0,
       3,     2,     2,     1,     0,     3,     2,     0,     3,     2,
       1,     5,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     0,     5,     5,
       8,     2,     3,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     2,     3,     1,     3,     1,     3,     1,     1,
       1,     2,     2,     5,     4,     2,     1,     1,     1,     2,
       4,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 186 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tfile_input : file_input_sub ENDMARKER\n"));}
#line 1916 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 192 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tfile_input_sub : \n"));}
#line 1922 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 193 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tfile_input_sub : NEWLINE file_input_sub\n"));}
#line 1928 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 194 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tfile_input_sub : stmt file_input_sub\n"));}
#line 1934 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 201 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tclassdef : \"class\" NAME : suite\n"));}
#line 1940 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 231 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tparameters : \"(\" \")\"\n"));}
#line 1946 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 232 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tparameters : \"(\" typedargslist \")\"\n"));}
#line 1952 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 234 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tfuncdef : \"def\" NAME parameters \":\" suite\n"));}
#line 1958 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 235 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tfuncdef : \"def\" NAME parameters \"->\" test \":\" suite\n"));}
#line 1964 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 253 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsuite_sub : stmt\n"));}
#line 1970 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 254 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsuite_sub : stmt suite_sub\n"));}
#line 1976 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 256 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsuite : simple_stmt\n"));}
#line 1982 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 257 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsuite : NEWLINE INDENT suite_sub DEDENT\n"));}
#line 1988 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 259 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tstmt : simple_stmt\n"));}
#line 1994 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 260 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tstmt : compound_stmt\n"));}
#line 2000 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 262 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsimple_stmt_sub : \n"));}
#line 2006 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 264 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsimple_stmt : small_stmt simple_stmt_sub NEWLINE\n"));}
#line 2012 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 321 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\ttestlist_sub : \n"));}
#line 2018 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 323 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\ttestlist : test testlist_sub\n"));}
#line 2024 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 332 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsmall_stmt : expr_stmt\n"));}
#line 2030 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 335 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tsmall_stmt : flow_stmt\n"));}
#line 2036 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 428 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tatom : NUMBER\n"));}
#line 2042 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 523 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tcomparison_sub : \n"));}
#line 2048 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 524 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tcomparison_sub : comparison_sub comp_op expr\n"));}
#line 2054 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 525 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tcomparison : expr comparison_sub\n"));}
#line 2060 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 528 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tnot_test : comparison\n"));}
#line 2066 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 530 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tand_test_sub : \n"));}
#line 2072 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 533 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tand_test : not_test and_test_sub\n"));}
#line 2078 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 535 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tor_test_sub : \n"));}
#line 2084 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 538 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tor_test : and_test or_test_sub\n"));}
#line 2090 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 540 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\ttest : or_test\n"));}
#line 2096 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 542 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\ttest : lambdef\n"));}
#line 2102 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 552 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tcompound_stmt : funcdef\n"));}
#line 2108 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 575 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\tflow_stmt : return_stmt\n"));}
#line 2114 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 615 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\treturn_stmt : \"return\"\n"));}
#line 2120 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 616 "Viper.y" /* yacc.c:1646  */
    {D(printf("REDUCE:\treturn_stmt : \"return\" testlist\n"));}
#line 2126 "Viper.tab.c" /* yacc.c:1646  */
    break;


#line 2130 "Viper.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 618 "Viper.y" /* yacc.c:1906  */


int main(int argc, char * argv[]) {
	ofstream fout;
	if (argc != 2) {
		fprintf(stderr, "1 argument required!");
		exit(1);
	}
	ifstream fin(argv[1], ios::in);
	if (fin.fail() || fin.bad()) {
		fprintf(stderr, "Destination Error");
		exit(1);
	}
	ReadTokens(fin, T);
	D(DispTokens(T));
	D(printf("START PARSING\n"));
	return yyparse();
};
void DispTokens(TokenTable * T) {
	system("CLS");
	for (int i = 0; i < TOKEN_TABLE_SIZE && T->t[i].availability != 0; i++) {
		cout << T->t[i].lineno << "\t" << T->t[i].layer << "\t";
		switch (T->t[i].type) {
			case STRING:{
				cout << "STRING" << "\t" << T->t[i].value.S;
				break;
			}
			case NUMBER:{
				cout << "NUMBER" << "\t" << T->t[i].value.D;
				break;
			}
			case CHAR:{
				cout << "CHAR" << "\t" << T->t[i].value.C;
				break;
			}
			case NAME:{
				cout << "NAME" << "\t" << T->t[i].value.S;
				break;
			}
			case INDENT:{
				cout << "INDENT";
				break;
			}
			case DEDENT:{
				cout << "DEDENT";
				break;
			}
			default:{
				cout << T->t[i].value.S;
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
};
int ReadTokens(ifstream &f, TokenTable * T) {
	int layer = 0;
	int Break = 0;
	int i = 0;
	for (; i < TOKEN_TABLE_SIZE; i++) {
		if (f.eof()){
			cout << "EOF" << endl;
			break;
		}
		f >> T->t[i].lineno;
		f >> T->t[i].type;
		T->t[i].layer = layer;
		switch (T->t[i].type) {
			case STRING:{
				char temp;
				f.get(temp);
				f.get(temp);
				T->t[i].value.S = new char[1024];
				f.getline(T->t[i].value.S, 1024);
				for (int j = 0; j < 1024; j++)
					if (T->t[i].value.S[j] == '\0')
						T->t[i].value.S[j - 1] = '\0';
				break;
			}
			case NUMBER:{
				f >> T->t[i].value.D;
				break;
			}
			case CHAR:{
				char temp;
				f.get(temp);
				f.get(temp);
				f.get(T->t[i].value.C);
				f.get(temp);
				break;
			}
			case NAME:{
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			case INDENT:{
				layer++;
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			case DEDENT:{
				T->t[i].layer = --layer;
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			case ENDMARKER:{
				Break = 1;
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
			default:{
				T->t[i].value.S = new char[1024];
				f >> T->t[i].value.S;
				break;
			}
		}
		if (!f.eof()){
			T->t[i].availability = 1;
		}
		if (Break)
			break;
		if (T->t[i].type == UNKNOWN) {
			i = (i == 0)? 0: i - 1;
			continue;
		}
	}
	T->Size = i;
	f.close();
	D(printf("TOKENS READ SUCCESSFULLY\n"));
	return 0;
};
int yylex() {
	int i = T->Pointer;
	if (i == TOKEN_TABLE_SIZE)
		return -1;
	if (T->t[i].availability == 0)
		return 0;
	switch (T->t[i].type) {
		case STRING:{
			yylval.String = T->t[i].value.S;
			D(printf("lex:\tSTRING\t%s\n", yylval.String));
			break;
		}
		case NUMBER:{
			yylval.Double = T->t[i].value.D;
			D(printf("lex:\tNUMBER\t%lf\n", yylval.Double));
			break;
		}
		case CHAR:{
			yylval.Char = T->t[i].value.C;
			D(printf("lex:\tCHAR\t%c\n", yylval.Char));
			break;
		}
		case NAME:{
			yylval.Name = T->t[i].value.S;
			D(printf("lex:\tNAME\t%s\n", yylval.Name));
			break;
		}
		case INDENT:{
			D(printf("lex:\tINDENT\n"));
			break;
		}
		case DEDENT:{
			D(printf("lex:\tDEDENT\n"));
			break;
		}
		case NEWLINE:{
			D(printf("lex:\tNEWLINE\n"));
			break;
		}
		default:{
			yylval.Name = T->t[i].value.S;
			D(printf("lex:\tDEFAULT\t%s\n", yylval.Name));
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}
