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
const int SIZE = 4096;
const int DIAGNOSE = 0;
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
		t = new Token[SIZE];
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

#line 152 "Viper.tab.c" /* yacc.c:339  */

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
    PRINT = 290,
    WHILE = 291,
    BREAK = 292,
    CONTINUE = 293,
    GLOBAL = 294,
    ELIF = 295,
    ELSE = 296,
    PASS = 297,
    RETURN = 298,
    IN = 299,
    FOR = 300,
    CLASS = 301,
    NOT = 302,
    AND = 303,
    OR = 304,
    IF = 305,
    DEF = 306,
    DOUBLESTAR = 307,
    DOUBLESLASH = 308,
    LESS = 309,
    LESSEQUAL = 310,
    EQEQUAL = 311,
    NOTEQUAL = 312,
    GREATEREQUAL = 313,
    GREATER = 314,
    PLUS = 315,
    MINUS = 316,
    STAR = 317,
    SLASH = 318,
    PERCENT = 319,
    COMMA = 320,
    DOT = 321,
    LPAR = 322,
    RPAR = 323,
    LSQB = 324,
    RSQB = 325,
    PLUSEQUAL = 326,
    MINEQUAL = 327,
    STAREQUAL = 328,
    SLASHEQUAL = 329,
    VBAREQUAL = 330,
    AMPEREQUAL = 331,
    CIRCUMFLEXEQUAL = 332,
    ATEQUAL = 333,
    DOUBLESLASHEQUAL = 334,
    PERCENTEQUAL = 335,
    DOUBLESTAREQUAL = 336,
    NONLOCAL = 337,
    VBAR = 338,
    AMPER = 339,
    CIRCUMFLEX = 340,
    TILDE = 341,
    LEFTSHIFT = 342,
    LEFTSHIFTEQUAL = 343,
    RIGHTSHIFT = 344,
    RIGHTSHIFTEQUAL = 345,
    RARROW = 346,
    NEG = 347
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

#line 296 "Viper.tab.c" /* yacc.c:358  */

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
#define YYFINAL  125
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  125
/* YYNRULES -- Number of rules.  */
#define YYNRULES  344
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  560

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

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
      95,    96
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   187,   200,   201,   202,   204,   205,
     206,   207,   208,   209,   210,   211,   213,   214,   215,   217,
     218,   219,   221,   222,   223,   224,   225,   226,   227,   228,
     230,   231,   233,   234,   236,   238,   239,   240,   242,   243,
     245,   246,   247,   249,   250,   252,   253,   255,   256,   258,
     259,   261,   262,   263,   264,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   298,   299,   301,   302,   304,
     305,   306,   307,   308,   310,   311,   313,   314,   316,   317,
     318,   319,   320,   321,   322,   323,   325,   326,   328,   329,
     331,   332,   333,   334,   335,   336,   337,   338,   340,   341,
     342,   344,   345,   346,   347,   349,   351,   352,   354,   355,
     357,   359,   360,   362,   363,   365,   366,   367,   368,   370,
     371,   373,   374,   376,   377,   379,   380,   382,   383,   384,
     385,   387,   388,   390,   391,   393,   394,   396,   397,   399,
     400,   401,   402,   403,   404,   406,   407,   409,   410,   412,
     413,   414,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   441,   442,   444,   445,
     447,   449,   450,   452,   453,   454,   455,   456,   458,   460,
     461,   463,   465,   466,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   540,   541,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   553,   554,   555,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   569,
     570,   571,   572,   573,   574,   576,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     593,   594,   595,   596,   598,   599,   601,   603,   604,   606,
     607,   608,   610,   612,   613
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
  "\"lambda\"", "\"yield\"", "\"import\"", "\"print\"", "\"while\"",
  "\"break\"", "\"continue\"", "\"global\"", "\"elif\"", "\"else\"",
  "\"pass\"", "\"return\"", "\"in\"", "\"for\"", "\"class\"", "\"not\"",
  "\"and\"", "\"or\"", "\"if\"", "\"def\"", "\"**\"", "\"//\"", "\"<\"",
  "\"<=\"", "\"==\"", "\"!=\"", "\">=\"", "\">\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"%\"", "\",\"", "\".\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"|=\"", "\"&=\"",
  "\"^=\"", "\"@=\"", "\"//=\"", "\"%=\"", "\"**=\"", "\"nonlocal\"",
  "\"|\"", "\"&\"", "\"^\"", "\"~\"", "\"<<\"", "\"<<=\"", "\">>\"",
  "\">>=\"", "\"->\"", "NEG", "\"None\"", "\"True\"", "\"False\"",
  "\"<>\"", "$accept", "single_input", "classdef", "typedargslist_long",
  "typedargslist_sub", "typedargslist_ct", "typedargslist", "parameters",
  "funcdef", "async_funcdef", "decorator", "decorators", "decorated",
  "tfpdef", "suite_sub", "suite", "stmt", "simple_stmt_sub", "simple_stmt",
  "varargslist_another_sub", "varargslist_sub_sub_sub",
  "varargslist_sub_sub", "varargslist_sub", "varargslist", "sliceop",
  "subscript", "subscriptlist_sub", "subscriptlist", "argument",
  "arglist_sub", "arglist", "trailer", "testlist_sub", "testlist",
  "yield_arg", "yield_expr", "small_stmt", "expr_sub_sub", "expr_sub",
  "expr_stmt", "annassign", "testlist_star_expr", "star_expr",
  "exprlist_es", "exprlist_sub", "exprlist", "test_nocond",
  "lambdef_nocond", "comp_if", "comp_iter", "comp_for",
  "testlist_comp_sub_ts", "dictorsetmaker_sub", "dictorsetmaker_tt",
  "dictorsetmaker_tt_sub", "dictorsetmaker", "lambdef",
  "testlist_comp_sub_co", "testlist_comp", "string_plus", "atom_sub_yt",
  "atom_sub_t", "atom_sub_d", "atom", "trailer_star", "except_clause",
  "while_stmt", "for_stmt", "try_stmt_sub_sub", "try_stmt_sub_plus",
  "try_stmt_sub", "try_stmt", "with_stmt_sub", "with_stmt", "with_item",
  "atom_expr", "power", "factor", "term_sub", "term", "arith_expr_sub",
  "arith_expr", "shift_expr_sub", "shift_expr", "and_expr_sub", "and_expr",
  "xor_expr_sub", "xor_expr", "expr", "augassign", "comp_op",
  "comparison_sub", "comparison", "not_test", "and_test_sub", "and_test",
  "or_test_sub", "or_test", "test", "assert_stmt", "compound_stmt",
  "async_stmt", "if_stmt_sub", "if_stmt", "global_stmt", "nonlocal_stmt",
  "dotted_name", "vfpdef", "continue_stmt", "flow_stmt", "del_stmt",
  "break_stmt", "pass_stmt", "import_as_name", "dotted_as_name",
  "import_as_names", "dotted_as_names", "import_sub", "dot_plus",
  "import_from", "import_name", "import_stmt", "raise_stmt", "yield_stmt",
  "return_stmt", YY_NULL
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
     345,   346,   347,   348,   349,   350,   351
};
# endif

#define YYPACT_NINF -491

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-491)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     965,   203,    51,  -491,    30,   787,   787,    53,    23,   787,
     583,    51,   787,  -491,  -491,    67,  -491,   787,    23,   134,
     787,   136,   626,   155,   172,  -491,  -491,   152,   167,  -491,
    -491,  -491,   171,  -491,   885,   146,  -491,  -491,  -491,  -491,
    -491,   196,  -491,  -491,   149,  -491,  -491,  -491,  -491,  -491,
    -491,  -491,  -491,  -491,  -491,  -491,  -491,  -491,  -491,  -491,
    -491,   143,    30,    30,    47,  -491,  -491,   213,   194,  -491,
     465,    72,   823,   108,   108,   516,   626,   108,  -491,  -491,
    -491,  -491,  -491,   189,   159,   179,  -491,   180,    89,    -9,
     153,   162,   885,   329,  -491,   192,   202,   207,   235,   243,
    1036,   108,  -491,   206,  -491,  -491,   211,   787,  -491,  -491,
     214,   147,  -491,   216,   279,  -491,  -491,   252,    59,   283,
     233,  -491,   146,  -491,  -491,  -491,  -491,   253,  -491,  -491,
    -491,  1056,   142,   787,    14,  -491,  -491,  -491,  -491,  -491,
    -491,  -491,  -491,  -491,  -491,  -491,   108,  -491,  -491,  -491,
    -491,  -491,   642,   240,  -491,   301,  -491,   303,   310,  -491,
    -491,    36,    17,  -491,   189,   108,    80,    86,  -491,   297,
     298,  -491,   787,   312,    45,   302,    28,  -491,  -491,  -491,
    -491,   141,  -491,   251,  -491,   250,  -491,   316,   396,   701,
     189,  -491,   787,   308,   108,   108,   108,   108,   108,   108,
    -491,   108,   108,  -491,   108,   108,  -491,   108,  -491,   108,
    -491,  -491,   280,  -491,   287,  -491,  -491,  -491,  -491,  -491,
    -491,  -491,   108,  -491,   823,  -491,   823,  -491,   823,   108,
     787,   325,   197,  -491,  -491,    23,   269,   787,  -491,   787,
     270,   332,    51,  1036,   787,  1036,   447,  1036,    37,    16,
    -491,  -491,   171,   318,  -491,   323,   324,   324,   885,  -491,
    -491,  -491,  -491,  -491,   787,   787,   326,   278,   276,   178,
     320,  -491,   340,   284,  -491,  -491,    36,  -491,  -491,   305,
      23,  -491,   286,   719,  -491,   288,  -491,   787,  -491,   289,
     312,  -491,  -491,   290,   295,   787,   787,  -491,   296,   626,
    -491,   299,  -491,  -491,  -491,  -491,   300,   737,   309,   282,
     347,  -491,   159,  1036,  -491,   180,   180,   180,   180,   180,
      89,    89,    -9,    -9,   153,   162,  -491,  -491,   329,   192,
     202,   334,  -491,  -491,  1003,   787,   351,   365,  -491,    22,
    -491,   206,  -491,  -491,   214,  -491,  -491,  -491,   341,   373,
    -491,   374,   338,   353,   375,   389,    68,  -491,   339,    57,
    1036,   787,  -491,  -491,   787,  -491,  -491,  -491,  -491,  -491,
    -491,   532,   335,   377,   787,  -491,   405,   344,   340,  -491,
      23,   369,  -491,   349,   298,  -491,  -491,  -491,    70,   364,
    -491,  -491,   295,     6,   352,  -491,  -491,   787,  -491,   402,
     701,   354,  -491,   737,  -491,  -491,  -491,  -491,  -491,  -491,
    -491,  -491,  -491,  -491,  -491,  -491,  -491,  -491,  -491,  -491,
     787,   412,   902,  -491,  -491,   394,  1036,  1036,   406,  -491,
    -491,  -491,   407,  1036,  1036,   410,   787,   386,   787,   367,
     389,   370,   371,  -491,   787,   372,  -491,   413,  -491,   278,
    -491,  -491,  -491,  -491,  -491,  -491,   390,   823,  -491,   787,
    -491,   312,  -491,   312,    45,  -491,  -491,  -491,   309,  -491,
    -491,   402,  -491,  -491,  -491,   425,  -491,   408,  1036,  1036,
     399,  -491,  1036,   426,   428,  -491,  -491,    77,   393,   376,
     371,    85,  -491,  1036,  -491,   823,   170,   295,   381,   382,
    -491,  -491,  -491,  -491,  -491,   418,  -491,   435,  -491,  1036,
    1036,   787,  -491,   389,  -491,   393,   372,   389,    68,  -491,
     170,   805,  -491,  -491,  -491,  -491,  -491,  -491,  -491,  1036,
     353,  -491,   371,   401,  -491,  -491,   404,   409,   371,  -491,
     114,   170,  -491,  -491,  -491,  -491,  -491,  -491,  -491,   393,
     411,   805,   439,  -491,  -491,   393,  -491,   805,  -491,  -491
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     153,     0,     0,     2,     0,     0,   339,     0,     0,     0,
     108,     0,     0,   316,   309,     0,   317,   343,     0,     0,
       0,     0,     0,     0,     0,   292,   291,    38,     0,   293,
       3,   342,    51,   110,   118,   153,   287,   288,   289,   290,
     117,     0,   294,   286,   115,   116,   311,   113,   111,   310,
     112,   338,   337,   114,   313,   314,   312,   295,   297,   296,
     306,     0,   331,   330,     0,   186,   185,   172,     0,   181,
     179,     0,     0,     0,     0,   174,   177,     0,   182,   183,
     184,   283,   187,   191,   209,   216,   218,   222,   229,   233,
     237,   240,   118,   270,   274,   275,   278,   281,   212,   340,
     153,     0,   132,   133,   315,   131,   284,     0,   107,   109,
     102,   320,   325,   336,     0,   302,   344,     0,     0,     0,
       0,   152,   153,   151,   304,     1,    39,     0,    40,    41,
      42,   153,     0,     0,   153,   246,   247,   248,   250,   253,
     252,   254,   249,   258,   251,   257,     0,   255,   256,   124,
     125,   121,     0,   128,     4,     0,    35,     0,     0,   333,
     332,     0,     0,   173,   191,     0,   153,   157,   180,     0,
     151,   308,     0,     0,    66,     0,    66,   273,   219,   220,
     175,   167,   176,     0,   178,     0,   221,     0,     0,     0,
     191,   214,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,     0,   232,     0,     0,   236,     0,   239,     0,
     242,   245,   268,   266,     0,   259,   263,   261,   265,   262,
     260,   264,     0,   272,     0,   277,     0,   280,     0,     0,
       0,     0,     0,    47,   130,     0,   135,     0,   106,     0,
     104,     0,     0,   153,     0,   153,     0,   153,     0,     0,
     154,    34,    51,     0,    53,   126,   118,   118,   118,   123,
     122,   129,   303,   307,     0,     0,     0,    94,     0,    89,
     318,   327,     0,   322,   329,   335,     0,   215,   156,     0,
       0,   162,   163,     0,   159,   160,   190,     0,   166,    72,
       0,    71,    61,    62,    66,     0,     0,    70,    55,     0,
     169,   170,   188,   189,   101,    98,     0,    77,    85,     0,
      76,   192,   209,   153,   217,   222,   222,   222,   222,   222,
     229,   229,   233,   233,   237,   240,   269,   267,   270,   275,
     278,     0,   213,   341,   153,   193,     0,     0,   207,   203,
     208,   133,   136,   285,   102,   105,   321,   326,   196,     0,
       5,     0,     0,   298,    43,     0,    19,    30,     0,    19,
     153,     0,    52,    54,     0,   119,   120,   244,    92,    93,
      36,     0,    96,     0,     0,    90,     0,     0,   323,   334,
       0,     0,   164,   157,     0,   161,   155,    73,    66,    63,
      60,   165,    66,    56,   167,   171,    99,    74,    78,    79,
       0,    87,   100,    81,   210,   211,   224,   227,   223,   225,
     226,   230,   231,   234,   235,   238,   241,   271,   276,   279,
       0,     0,   153,    49,    50,   194,   153,   153,     0,   204,
     134,   103,     0,   153,   153,     0,     0,   300,     0,    28,
       0,    24,    19,    31,     0,     8,    32,     0,   127,    94,
      97,    37,    91,   319,   328,   324,     0,     0,   158,     0,
      67,     0,    69,     0,    66,   168,    75,    80,    85,    88,
      82,    83,   282,    48,    46,     0,   200,   201,   153,   153,
     198,     6,   153,     0,     0,    44,    29,    19,    16,    26,
      19,     9,    22,   153,    95,     0,   147,    66,    64,    58,
      57,    86,    84,   195,   202,   205,   197,     0,     7,   153,
     153,     0,    20,     0,    25,    16,     8,     0,    19,    33,
     149,     0,   146,   148,   145,    68,    65,    59,   206,   153,
     298,   301,    19,    17,    27,    23,    14,    10,    19,   150,
       0,   143,   138,   137,   199,   299,    21,    18,    15,    16,
      12,     0,     0,   144,    11,    16,   139,     0,    13,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -491,  -491,   433,   -44,  -319,  -347,  -491,  -491,    21,  -491,
    -491,   440,  -491,  -325,    61,  -181,  -491,   221,     2,    83,
      20,   187,  -171,   -55,  -359,    87,    18,  -491,   117,    43,
    -140,  -491,   151,    -6,  -491,   -48,   362,    -7,   -78,  -491,
    -491,   366,   -16,   261,   157,   -15,  -490,  -491,  -491,  -465,
    -142,   -13,   -22,   218,   119,  -491,  -491,   109,   429,   437,
    -491,  -491,  -491,   442,   -26,  -491,  -491,   510,  -323,    41,
    -491,  -491,   201,   519,   331,  -491,  -491,   -40,   -49,    71,
     -46,  -491,   -38,   317,   212,   321,   225,   397,     0,  -491,
    -491,   224,  -491,   -51,   210,   327,   226,  -218,    -5,  -491,
     546,  -491,    24,  -491,  -491,  -491,    44,  -154,  -491,  -491,
    -491,  -491,  -491,  -491,   313,  -249,  -491,   281,   230,  -491,
    -491,  -491,  -491,  -491,  -491
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,   492,   514,   441,   358,   249,    26,   130,
      27,    28,    29,   359,   421,   232,   422,   132,   233,   297,
     291,   292,   293,   175,   398,   308,   401,   309,   267,   372,
     268,   190,   240,   108,   109,    31,    32,   149,   150,    33,
     151,    34,   102,   103,   236,   104,   541,   542,   522,   523,
     524,   181,    35,   167,   285,   168,    81,   301,   182,    82,
     183,   185,   169,    83,   191,   337,    36,    37,   338,   339,
     340,    38,   193,    39,    84,    85,    86,    87,   200,    88,
     203,    89,   206,    90,   208,    91,   210,    92,    93,   152,
     222,   223,    94,    95,   225,    96,   227,    97,   110,    40,
     424,    42,   437,    43,    44,    45,   111,   176,    46,    47,
      48,    49,    50,   273,   112,   274,   113,   275,    64,    51,
      52,    53,    54,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    99,    30,   117,   106,   298,   121,   114,   105,   122,
     331,   116,   445,   153,   211,   119,   429,   123,   105,   289,
     294,   177,    57,   377,   281,   284,    65,   180,    66,    67,
     439,   442,   360,   178,   179,    68,    69,   186,    70,   300,
     467,   270,   354,    62,   470,   296,    61,    10,   306,   129,
     171,   276,    60,   336,   121,   539,    60,   166,   463,   121,
     121,   556,   348,   428,   350,   170,   353,   559,   464,   100,
     123,   123,   115,   354,   444,   245,   553,   171,   204,    22,
     205,   161,   157,    73,    74,   101,   256,   459,   172,   355,
      75,   279,    76,   290,   511,   489,    63,   279,   271,   356,
     250,   234,   238,   272,   260,   357,   352,   361,   162,    77,
     290,    65,   502,    66,    67,   487,    78,    79,    80,   171,
      68,    69,   440,    70,   173,   280,   246,   375,   255,   455,
     551,   280,   405,   440,   174,   290,   388,   517,   277,   118,
     512,   120,   440,   516,   282,    22,   259,   518,   251,   201,
     202,   283,   279,   269,   314,   315,   316,   317,   318,   319,
     124,   253,   254,   156,   311,   278,   173,   288,    73,    74,
       2,   537,   125,   329,   241,    75,   174,    76,   127,   446,
     367,   279,   528,   269,   310,   546,   280,    98,   533,   279,
     131,   550,   536,   538,    77,   374,   534,    65,   195,    66,
      67,    78,    79,    80,   322,   323,   299,    69,   157,    70,
     158,    22,   157,    19,   155,   280,   154,   460,    21,    67,
     521,   298,   328,   280,   192,   333,     5,   335,   336,   332,
     554,   194,   343,   196,   344,   105,   558,   207,   349,   496,
     224,   269,   197,   198,   199,   476,   477,   209,    18,   365,
     366,   226,   480,   481,    21,   187,   188,   228,   189,   368,
     369,    75,   229,    76,   230,   381,   406,   407,   408,   409,
     410,   235,   320,   321,   411,   412,   237,   520,   384,   239,
     105,   242,   386,   121,   413,   414,   394,    78,    79,    80,
     391,   392,   159,   160,   123,   243,   244,   505,   506,   247,
     248,   508,   399,   543,    21,   261,   262,   498,   263,   499,
     294,   286,   519,    65,   287,    66,    67,   171,   295,   302,
     303,   304,    68,    69,   313,    70,   525,   326,   530,   531,
     425,   327,   334,   543,   342,   345,   423,   346,   363,   543,
     364,   134,    71,   371,   373,   270,   370,   376,   544,   378,
     380,   382,   402,   385,   387,   389,   447,    72,   212,   448,
     290,   393,   264,   403,   395,   456,   269,   426,   396,   452,
      73,    74,   265,   213,   400,   420,   214,    75,   266,    76,
     105,   427,   432,   215,   216,   217,   218,   219,   220,   433,
     434,   438,   466,   436,   354,   310,    77,   451,   471,    65,
     450,    66,    67,    78,    79,    80,   435,   443,    68,    69,
     453,    70,   454,   457,   283,   472,   461,   299,   397,   469,
     473,   475,   478,   479,   423,   221,   482,   484,    71,   493,
     503,   483,   486,   485,   495,   488,   440,   491,   335,   490,
     507,   515,   509,    72,   510,   513,   526,   527,   264,   336,
      65,   529,    66,    67,   497,   557,    73,    74,   265,    68,
      69,   128,    70,    75,   305,    76,   547,   126,    65,   548,
      66,    67,   535,   362,   549,   462,   555,    68,    69,    71,
      70,   390,    77,   474,   500,   552,   501,   468,   449,    78,
      79,    80,   494,   252,    72,   431,   341,    71,   430,   264,
     257,   383,   458,   465,   163,   184,   532,    73,    74,   265,
     164,    58,    72,   404,    75,   351,    76,   165,   504,    65,
      59,    66,    67,   312,   324,    73,    74,   101,    68,    69,
     325,    70,    75,    77,    76,    65,   415,    66,    67,   418,
      78,    79,    80,   258,    68,    69,    41,    70,    71,    10,
     416,    77,   417,   330,   545,   347,   419,   379,    78,    79,
      80,     0,     0,    72,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,   101,    72,
       0,     0,     0,    75,   264,    76,    65,     0,    66,    67,
       0,     0,    73,    74,   265,    68,    69,     0,    70,    75,
       0,    76,    77,     0,   107,     0,     0,     0,     0,    78,
      79,    80,     0,     0,     0,    71,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    78,    79,    80,     0,    65,
      72,    66,    67,     0,     0,     0,     0,     0,    68,    69,
       0,    70,     0,    73,    74,    65,     0,    66,    67,     0,
      75,     0,    76,     0,    68,    69,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,    72,    71,    10,    78,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    73,    74,   101,    72,
       0,     0,     0,    75,     0,    76,     0,     0,     0,     0,
       0,     0,    73,    74,    65,     0,    66,    67,     0,    75,
       0,    76,    77,    68,    69,     0,    70,   307,     0,    78,
      79,    80,    65,     0,    66,    67,     0,     0,    77,     0,
       0,    68,    69,    71,    70,    78,    79,    80,     0,     0,
      65,     0,    66,    67,     0,     0,     0,     0,    72,    68,
      69,    71,    70,   397,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,     0,    72,     0,    75,    71,
      76,   165,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,     0,     0,    72,     0,    75,    77,    76,     0,
      65,     0,    66,    67,    78,    79,    80,    73,    74,    68,
      69,     0,    70,     0,    75,    77,    76,     0,    65,     0,
      66,    67,    78,    79,    80,     0,     0,    68,    69,    71,
      70,     0,     0,    77,     0,     0,    65,     0,    66,    67,
      78,    79,    80,     0,    72,    68,    69,   540,    70,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,     0,    72,     0,    75,     0,    76,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,     0,
      72,     0,    75,    77,    76,     0,     0,     0,     0,     0,
      78,    79,    80,    73,    74,     0,     0,     0,     0,     0,
      75,    77,    76,     0,     0,     0,     0,     0,    78,    79,
      80,   133,   134,     0,     0,     0,     0,     0,     0,    77,
     -45,     0,     0,     1,     0,     0,    78,    79,    80,     0,
       2,     0,     0,     4,     0,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,    10,    11,     0,    12,    13,
      14,    15,     0,     0,    16,    17,     0,    18,    19,     0,
       0,     0,    20,    21,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    22,   146,     0,
       0,     0,     0,   147,     0,   148,     1,     0,     0,     0,
       0,     0,     0,     2,    23,     3,     4,     0,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,    10,    11,
       0,    12,    13,    14,    15,     0,     0,    16,    17,     0,
      18,    19,     0,     0,     1,    20,    21,     0,     0,     0,
       0,     2,     0,     0,     4,     0,     5,     6,     7,     8,
      22,     9,     0,     0,     0,     0,    10,    11,     0,    12,
      13,    14,    15,     0,     0,    16,    17,    23,    18,    19,
       0,     0,     0,    20,    21,     0,   231,     4,     0,     0,
       6,     0,     8,     0,     9,     0,     0,     0,    22,    10,
      11,     0,     0,    13,    14,    15,     0,     4,    16,    17,
       6,     0,     8,     0,     9,    23,     0,     0,     0,    10,
      11,     0,     0,    13,    14,    15,     0,     0,    16,    17,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
       5,     6,     0,    18,     9,   176,    22,    12,     8,    22,
     228,    17,   359,    35,    92,    20,   339,    22,    18,   173,
     174,    72,     1,   272,   166,   167,     3,    75,     5,     6,
     355,   356,    16,    73,    74,    12,    13,    77,    15,   181,
     399,     5,     5,    13,   403,    17,     2,    33,   188,    28,
       5,    34,     5,    31,    70,   520,     5,    70,    52,    75,
      76,   551,   243,    41,   245,    70,   247,   557,    62,    16,
      75,    76,     5,     5,    17,    16,   541,     5,    87,    65,
      89,    34,    65,    60,    61,    62,   134,    17,    16,    52,
      67,    11,    69,    65,    17,   442,    66,    11,    62,    62,
     122,   101,   107,    67,   152,    68,   246,    91,    64,    86,
      65,     3,   471,     5,     6,   440,    93,    94,    95,     5,
      12,    13,    65,    15,    52,    45,    67,   269,   133,   378,
      16,    45,   313,    65,    62,    65,   290,    52,   164,     5,
     487,     5,    65,   490,   166,    65,   152,    62,   127,    60,
      61,    65,    11,   158,   194,   195,   196,   197,   198,   199,
       5,    19,    20,    20,   190,   165,    52,   172,    60,    61,
      18,   518,     0,   224,    27,    67,    62,    69,    11,   360,
     258,    11,   505,   188,   189,   532,    45,   192,   513,    11,
      19,   538,   517,   518,    86,    17,   515,     3,    18,     5,
       6,    93,    94,    95,   204,   205,    65,    13,    65,    15,
      67,    65,    65,    46,    65,    45,    20,   388,    51,     6,
      50,   392,   222,    45,    65,   230,    23,    30,    31,   229,
     549,    52,   237,    53,   239,   235,   555,    84,   244,   457,
      48,   246,    62,    63,    64,   426,   427,    85,    45,   256,
     257,    49,   433,   434,    51,    66,    67,    50,    69,   264,
     265,    67,    27,    69,    21,   280,   315,   316,   317,   318,
     319,    65,   201,   202,   320,   321,    65,   495,   283,    65,
     280,    65,   287,   299,   322,   323,   299,    93,    94,    95,
     295,   296,    62,    63,   299,    16,    44,   478,   479,    16,
      67,   482,   307,   521,    51,    65,     5,   461,     5,   463,
     464,    14,   493,     3,    16,     5,     6,     5,    16,    68,
      70,     5,    12,    13,    16,    15,   497,    47,   509,   510,
     335,    44,     7,   551,    65,    65,   334,     5,    20,   557,
      17,    17,    32,    65,    68,     5,    20,    27,   529,    65,
      45,    65,    70,    65,    65,    65,   361,    47,    29,   364,
      65,    65,    52,    16,    65,   380,   371,    16,    68,   374,
      60,    61,    62,    44,    65,    41,    47,    67,    68,    69,
     380,    16,    41,    54,    55,    56,    57,    58,    59,    16,
      16,    16,   397,    40,     5,   400,    86,    20,   403,     3,
      65,     5,     6,    93,    94,    95,    68,    68,    12,    13,
       5,    15,    68,    44,    65,   420,    52,    65,    16,    65,
       8,    27,    16,    16,   422,    96,    16,    41,    32,    16,
       5,   436,    65,   438,    44,    65,    65,    65,    30,   444,
      41,    65,    16,    47,    16,    52,    65,    65,    52,    31,
       3,    16,     5,     6,   459,    16,    60,    61,    62,    12,
      13,    28,    15,    67,    68,    69,    65,    27,     3,    65,
       5,     6,   516,   252,    65,   392,    65,    12,    13,    32,
      15,   294,    86,   422,   464,   540,   468,   400,   371,    93,
      94,    95,   449,   131,    47,   344,   235,    32,   341,    52,
     134,   283,   383,   394,    67,    76,   511,    60,    61,    62,
      68,     1,    47,   312,    67,    68,    69,    52,   477,     3,
       1,     5,     6,   192,   207,    60,    61,    62,    12,    13,
     209,    15,    67,    86,    69,     3,   324,     5,     6,   329,
      93,    94,    95,   146,    12,    13,     0,    15,    32,    33,
     325,    86,   328,   226,   530,   242,   330,   276,    93,    94,
      95,    -1,    -1,    47,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    47,
      -1,    -1,    -1,    67,    52,    69,     3,    -1,     5,     6,
      -1,    -1,    60,    61,    62,    12,    13,    -1,    15,    67,
      -1,    69,    86,    -1,    21,    -1,    -1,    -1,    -1,    93,
      94,    95,    -1,    -1,    -1,    32,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    -1,     3,
      47,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    15,    -1,    60,    61,     3,    -1,     5,     6,    -1,
      67,    -1,    69,    -1,    12,    13,    -1,    15,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    47,    32,    33,    93,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    47,
      -1,    -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,     3,    -1,     5,     6,    -1,    67,
      -1,    69,    86,    12,    13,    -1,    15,    16,    -1,    93,
      94,    95,     3,    -1,     5,     6,    -1,    -1,    86,    -1,
      -1,    12,    13,    32,    15,    93,    94,    95,    -1,    -1,
       3,    -1,     5,     6,    -1,    -1,    -1,    -1,    47,    12,
      13,    32,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    47,    -1,    67,    32,
      69,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    47,    -1,    67,    86,    69,    -1,
       3,    -1,     5,     6,    93,    94,    95,    60,    61,    12,
      13,    -1,    15,    -1,    67,    86,    69,    -1,     3,    -1,
       5,     6,    93,    94,    95,    -1,    -1,    12,    13,    32,
      15,    -1,    -1,    86,    -1,    -1,     3,    -1,     5,     6,
      93,    94,    95,    -1,    47,    12,    13,    32,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    47,    -1,    67,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      47,    -1,    67,    86,    69,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    86,    69,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    86,
       8,    -1,    -1,    11,    -1,    -1,    93,    94,    95,    -1,
      18,    -1,    -1,    21,    -1,    23,    24,    25,    26,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    42,    43,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    65,    83,    -1,
      -1,    -1,    -1,    88,    -1,    90,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    82,    20,    21,    -1,    23,    24,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    -1,    -1,    42,    43,    -1,
      45,    46,    -1,    -1,    11,    50,    51,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    21,    -1,    23,    24,    25,    26,
      65,    28,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    43,    82,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    20,    21,    -1,    -1,
      24,    -1,    26,    -1,    28,    -1,    -1,    -1,    65,    33,
      34,    -1,    -1,    37,    38,    39,    -1,    21,    42,    43,
      24,    -1,    26,    -1,    28,    82,    -1,    -1,    -1,    33,
      34,    -1,    -1,    37,    38,    39,    -1,    -1,    42,    43,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    18,    20,    21,    23,    24,    25,    26,    28,
      33,    34,    36,    37,    38,    39,    42,    43,    45,    46,
      50,    51,    65,    82,    98,    99,   105,   107,   108,   109,
     115,   132,   133,   136,   138,   149,   163,   164,   168,   170,
     196,   197,   198,   200,   201,   202,   205,   206,   207,   208,
     209,   216,   217,   218,   219,   220,   221,   105,   164,   170,
       5,   203,    13,    66,   215,     3,     5,     6,    12,    13,
      15,    32,    47,    60,    61,    67,    69,    86,    93,    94,
      95,   153,   156,   160,   171,   172,   173,   174,   176,   178,
     180,   182,   184,   185,   189,   190,   192,   194,   195,   195,
      16,    62,   139,   140,   142,   185,   195,    21,   130,   131,
     195,   203,   211,   213,   195,     5,   130,   142,     5,   195,
       5,   139,   148,   195,     5,     0,   108,    11,    99,   105,
     106,    19,   114,    16,    17,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    83,    88,    90,   134,
     135,   137,   186,   149,    20,    65,    20,    65,    67,   215,
     215,    34,   203,   156,   160,    52,   148,   150,   152,   159,
     195,     5,    16,    52,    62,   120,   204,   190,   174,   174,
     132,   148,   155,   157,   155,   158,   174,    66,    67,    69,
     128,   161,    65,   169,    52,    18,    53,    62,    63,    64,
     175,    60,    61,   177,    87,    89,   179,    84,   181,    85,
     183,   135,    29,    44,    47,    54,    55,    56,    57,    58,
      59,    96,   187,   188,    48,   191,    49,   193,    50,    27,
      21,    20,   112,   115,   185,    65,   141,    65,   195,    65,
     129,    27,    65,    16,    44,    16,    67,    16,    67,   104,
     149,   105,   133,    19,    20,   195,   132,   138,   184,   130,
     132,    65,     5,     5,    52,    62,    68,   125,   127,   195,
       5,    62,    67,   210,   212,   214,    34,   161,   185,    11,
      45,   147,   149,    65,   147,   151,    14,    16,   195,   204,
      65,   117,   118,   119,   204,    16,    17,   116,   119,    65,
     147,   154,    68,    70,     5,    68,   127,    16,   122,   124,
     195,   161,   171,    16,   174,   174,   174,   174,   174,   174,
     176,   176,   185,   185,   180,   182,    47,    44,   185,   190,
     192,   194,   185,   195,     7,    30,    31,   162,   165,   166,
     167,   140,    65,   195,   195,    65,     5,   211,   112,   130,
     112,    68,   127,   112,     5,    52,    62,    68,   103,   110,
      16,    91,   114,    20,    17,   134,   134,   135,   195,   195,
      20,    65,   126,    68,    17,   147,    27,   212,    65,   214,
      45,   142,    65,   150,   195,    65,   195,    65,   204,    65,
     118,   195,   195,    65,   148,    65,    68,    16,   121,   195,
      65,   123,    70,    16,   169,   112,   175,   175,   175,   175,
     175,   177,   177,   179,   179,   181,   183,   188,   191,   193,
      41,   111,   113,   115,   197,   195,    16,    16,    41,   165,
     141,   129,    41,    16,    16,    68,    40,   199,    16,   110,
      65,   102,   110,    68,    17,   102,   112,   195,   195,   125,
      65,    20,   195,     5,    68,   212,   142,    44,   151,    17,
     119,    52,   116,    52,    62,   154,   195,   121,   122,    65,
     121,   195,   195,     8,   111,    27,   112,   112,    16,    16,
     112,   112,    16,   195,    41,   195,    65,   110,    65,   102,
     195,    65,   100,    16,   126,    44,   194,   195,   204,   204,
     117,   123,   121,     5,   166,   112,   112,    41,   112,    16,
      16,    17,   102,    52,   101,    65,   102,    52,    62,   112,
     194,    50,   145,   146,   147,   119,    65,    65,   165,    16,
     112,   112,   195,   110,   101,   100,   110,   102,   110,   146,
      32,   143,   144,   194,   112,   199,   102,    65,    65,    65,
     102,    16,   120,   146,   101,    65,   143,    16,   101,   143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    98,    98,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   105,   105,   106,   107,   107,   107,   108,   108,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   118,   118,   118,   118,   119,   119,   119,   120,
     120,   120,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   125,   125,   125,   126,   126,   127,   127,   128,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   135,   135,   135,   135,   136,   137,   137,   138,   138,
     139,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   143,   143,   145,   145,   146,   146,   147,   147,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   152,   152,   152,   152,   153,   153,   154,   154,   155,
     155,   155,   156,   156,   157,   157,   157,   158,   158,   159,
     159,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   161,   161,   162,   162,   162,   163,   163,   164,   164,
     165,   166,   166,   167,   167,   167,   167,   167,   168,   169,
     169,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     174,   174,   175,   175,   175,   175,   175,   175,   176,   177,
     177,   177,   178,   179,   179,   179,   180,   181,   181,   182,
     183,   183,   184,   135,   135,   185,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     188,   188,   189,   190,   190,   191,   191,   192,   193,   193,
     194,   195,   195,   195,   196,   196,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   198,   198,   198,   199,   199,
     200,   200,   201,   201,   202,   202,   203,   203,   204,   205,
     206,   206,   206,   206,   206,   207,   208,   209,   210,   210,
     211,   211,   212,   212,   212,   213,   213,   214,   214,   214,
     215,   215,   215,   215,   216,   216,   217,   218,   218,   219,
     219,   219,   220,   221,   221
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     6,     7,     0,     1,
       3,     5,     4,     6,     3,     4,     0,     2,     3,     0,
       3,     5,     3,     5,     2,     4,     3,     5,     2,     3,
       2,     3,     5,     7,     2,     3,     5,     6,     1,     2,
       2,     2,     2,     1,     3,     1,     2,     1,     4,     1,
       1,     0,     3,     3,     4,     1,     2,     4,     4,     5,
       2,     1,     1,     2,     4,     5,     0,     3,     5,     4,
       2,     2,     2,     3,     1,     2,     1,     1,     2,     2,
       3,     2,     3,     3,     4,     0,     3,     2,     3,     1,
       2,     3,     2,     2,     0,     3,     2,     3,     2,     3,
       3,     2,     0,     3,     2,     3,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       3,     1,     2,     2,     1,     2,     2,     4,     2,     3,
       2,     1,     1,     0,     3,     2,     3,     1,     1,     3,
       4,     1,     1,     2,     3,     1,     1,     4,     5,     5,
       6,     1,     1,     0,     3,     3,     2,     0,     3,     2,
       2,     3,     2,     2,     3,     4,     3,     0,     3,     2,
       2,     3,     1,     2,     0,     1,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     0,     2,     1,     2,     4,     4,     7,     6,     9,
       3,     3,     4,     1,     2,     4,     5,     1,     4,     0,
       3,     5,     1,     3,     2,     3,     1,     3,     1,     2,
       2,     2,     0,     3,     3,     3,     3,     3,     2,     0,
       3,     3,     2,     0,     3,     3,     2,     0,     3,     2,
       0,     3,     2,     0,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       0,     3,     2,     2,     1,     0,     3,     2,     0,     3,
       2,     1,     5,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     0,     5,
       5,     8,     2,     3,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     3,
       1,     3,     1,     2,     3,     1,     3,     1,     3,     1,
       1,     1,     2,     2,     5,     4,     2,     1,     1,     1,
       2,     4,     1,     1,     2
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
      
#line 1918 "Viper.tab.c" /* yacc.c:1646  */
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
#line 615 "Viper.y" /* yacc.c:1906  */


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
	DispTokens(T);
	return yyparse();
};
void DispTokens(TokenTable * T) {
	//system("CLS");
	for (int i = 0; i < SIZE && T->t[i].availability != 0; i++) {
		cout << T->t[i].lineno << "\t" << T->t[i].layer << "\t" << T->t[i].type << "\t";
		switch (T->t[i].type) {
			case STRING:{
				cout << T->t[i].value.S;
				break;
			}
			case NUMBER:{
				cout << T->t[i].value.D;
				break;
			}
			case CHAR:{
				cout << T->t[i].value.C;
				break;
			}
			case NAME:{
				cout << T->t[i].value.S;
				break;
			}
			case INDENT:{
				cout << T->t[i].value.S;
				break;
			}
			case DEDENT:{
				cout << T->t[i].value.S;
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
	for (; i < SIZE; i++) {
		if (f.eof()){
			cout << "EOF" << endl;
			break;
		}
		f >> T->t[i].lineno;
		f >> T->t[i].type;
		T->t[i].layer = layer;
		switch (T->t[i].type) {
			case STRING:{
				cout << "STRING" << endl;
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
	printf("TOKENS READ SUCCESSFULLY\n");
	return 0;
};
int yylex() {
	int i = T->Pointer;
	if (T->t[i].availability == 0)
		return 0;
	switch (T->t[i].type) {
		case STRING:{
			yylval.String = T->t[i].value.S;
			break;
		}
		case NUMBER:{
			yylval.Double = T->t[i].value.D;
			break;
		}
		case CHAR:{
			yylval.Char = T->t[i].value.C;
			break;
		}
		case NAME:{
			yylval.Name = T->t[i].value.S;
			break;
		}
		case INDENT:{
			break;
		}
		case DEDENT:{
			break;
		}
		default:{
			yylval.Name = T->t[i].value.S;
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}
