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
#define D(x) if (!VIPER_COMPILER_DIAGNOSE) ; else x

const int TOKEN_TABLE_SIZE = 4096;
const int VIPER_COMPILER_DIAGNOSE = 1;
ofstream fout_diag("PROCESS.log", ios::out);
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
void PrintTokens(TokenTable * T);
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

#line 155 "Viper.tab.c" /* yacc.c:339  */

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

#line 298 "Viper.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  340
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  536

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
       0,   187,   187,   189,   190,   192,   193,   195,   196,   198,
     199,   201,   202,   204,   205,   206,   207,   208,   210,   211,
     212,   214,   215,   217,   219,   220,   221,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   238,   239,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   255,   257,   258,   259,
     261,   262,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   274,   275,   276,   277,   279,   280,   282,   283,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     297,   299,   300,   301,   303,   304,   305,   307,   308,   310,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   325,   326,   327,   328,   329,   331,   332,   333,
     334,   335,   337,   338,   340,   341,   343,   344,   346,   347,
     348,   349,   356,   357,   358,   360,   361,   363,   364,   366,
     367,   369,   370,   372,   373,   374,   375,   377,   378,   379,
     381,   382,   383,   384,   386,   387,   388,   390,   391,   392,
     393,   394,   396,   397,   399,   400,   402,   403,   405,   406,
     408,   409,   411,   412,   414,   415,   416,   418,   419,   421,
     423,   424,   426,   427,   428,   430,   431,   433,   434,   436,
     437,   439,   440,   442,   443,   445,   446,   448,   450,   451,
     453,   454,   455,   457,   458,   460,   461,   462,   464,   465,
     467,   468,   474,   475,   477,   478,   479,   480,   481,   482,
     483,   484,   486,   488,   489,   491,   492,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   504,   505,   507,   508,
     510,   511,   513,   514,   516,   517,   518,   519,   520,   521,
     523,   524,   525,   527,   528,   530,   531,   532,   534,   535,
     537,   538,   540,   541,   542,   543,   545,   546,   548,   549,
     551,   552,   554,   555,   556,   557,   559,   560,   562,   563,
     564,   565,   566,   568,   569,   571,   572,   573,   574,   575,
     576,   577,   578,   580,   581,   582,   584,   585,   586,   587,
     588,   589,   590,   591,   593,   594,   595,   597,   598,   599,
     600,   601,   603,   604,   605,   606,   607,   609,   610,   611,
     613,   614,   615,   616,   618,   619,   621,   623,   624,   626,
     627,   629,   631,   632,   634,   635,   637,   638,   640,   641,
     643
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
  "$accept", "file_input", "and_expr", "and_test", "annassign", "arglist",
  "arglist_sub", "argument", "arith_expr", "assert_stmt", "async_funcdef",
  "async_stmt", "atom", "atom_expr", "augassign", "break_stmt", "classdef",
  "comparison", "compound_stmt", "comp_for", "comp_if", "comp_iter",
  "comp_op", "continue_stmt", "decorated", "decorator", "decorators",
  "del_stmt", "dictorsetmaker", "dictorsetmaker_sub",
  "dictorsetmaker_lsub", "dotted_as_name", "dotted_as_names",
  "dotted_name", "dot_plus", "except_clause", "exprlist", "exprlist_es",
  "exprlist_sub", "expr", "expr_stmt", "expr_stmt_sub_sub", "factor",
  "file_input_sub", "flow_stmt", "for_stmt", "funcdef", "global_stmt",
  "if_stmt", "if_stmt_sub", "import_as_name", "import_as_names",
  "import_from", "import_name", "import_stmt", "import_sub", "lambdef",
  "lambdef_nocond", "nonlocal_stmt", "not_test", "or_test", "parameters",
  "pass_stmt", "power", "raise_stmt", "return_stmt", "shift_expr",
  "simple_stmt", "simple_stmt_sub", "sliceop", "small_stmt", "star_expr",
  "stmt", "string_plus", "subscript", "subscriptlist", "subscriptlist_sub",
  "suite", "suite_sub", "term", "test", "testlist", "testlist_comp",
  "testlist_comp_sub_co", "testlist_comp_sub_ts", "testlist_star_expr",
  "testlist_sub", "test_nocond", "tfpdef", "trailer", "trailer_star",
  "try_stmt", "try_stmt_sub", "typedargslist", "typedargslist_ct",
  "typedargslist_long", "typedargslist_sub", "varargslist",
  "varargslist_another_sub", "varargslist_sub", "varargslist_sub_sub",
  "varargslist_sub_sub_sub", "vfpdef", "while_stmt", "with_item",
  "with_stmt", "with_stmt_sub", "xor_expr", "yield_arg", "yield_expr",
  "yield_stmt", YY_NULL
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

#define YYPACT_NINF -469

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-469)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -469,    65,   432,  -469,  -469,  -469,    69,  -469,   205,  1203,
    -469,   824,   130,  -469,    22,  1234,  1234,   114,   257,  1234,
      25,   984,   130,  1234,  -469,  -469,   166,  -469,  1234,   257,
     179,  1270,  1234,   192,  1136,  1136,  1136,   100,   892,   195,
    1136,  -469,  -469,  -469,   131,   162,    80,  -469,  -469,  -469,
     169,  -469,  -469,     0,  -469,  -469,  -469,  -469,   226,  -469,
     143,  -469,  -469,  -469,  -469,  -469,   163,  -469,  -469,  -469,
    -469,  -469,   174,  -469,    99,  -469,  -469,  -469,  -469,    48,
    -469,  -469,   184,  -469,  -469,   284,   184,  1297,  -469,  -469,
    -469,   149,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    1136,   245,   111,    36,  -469,   138,  -469,  -469,   115,   234,
    -469,    52,   247,   691,  -469,  -469,   143,  -469,   200,  -469,
    1234,   269,   269,   261,   271,  1234,  -469,  -469,   227,  -469,
    -469,   231,    13,   293,  -469,  -469,   268,   122,  -469,   306,
     262,  -469,  -469,   143,  -469,  -469,  -469,   233,    38,   260,
    -469,   264,  -469,  -469,  1136,  1270,  1136,  1136,   147,  1136,
     285,  -469,   287,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    1136,   288,  -469,  -469,  -469,  -469,  1136,   329,   330,  1270,
    1270,  1136,  1136,   150,  1026,   277,  1136,  1136,  1136,  1136,
    1136,   290,  1234,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  1042,   338,  1136,
     147,    28,  -469,   312,   257,  -469,   295,  1234,  -469,   296,
    -469,   352,   675,  -469,    23,  -469,    17,  1136,   691,  1234,
    1234,   354,  -469,   220,   301,  1234,  -469,   302,   303,  -469,
    -469,  -469,  1234,  1234,  -469,   304,  -469,  1234,   130,   364,
     691,  1234,   691,   758,   691,    32,    18,  -469,  -469,   307,
    -469,  -469,    48,  -469,   284,   284,   365,   874,  1100,  -469,
    -469,  -469,  -469,   143,  -469,   149,  -469,  -469,   162,    19,
      80,    80,   774,  -469,  -469,  -469,  1026,  -469,  -469,  -469,
    -469,  -469,  1026,   358,  -469,  -469,    58,   131,  1118,  -469,
     314,   257,   333,  1026,   118,  1026,  -469,  1234,  1234,   359,
     313,   319,  -469,   178,   357,  -469,   380,   322,  -469,  -469,
      23,   143,  -469,  -469,  -469,   608,  1234,   371,   372,   177,
     257,  -469,  -469,   139,  -469,  -469,  -469,    37,  -469,  -469,
    -469,   349,   375,  -469,   376,   326,  -469,   379,   391,   391,
    -469,   382,   334,   691,  1234,  1026,  -469,  -469,   336,  1167,
    -469,   328,   346,   384,  1234,  -469,  -469,  -469,  -469,  1234,
    -469,  -469,  1136,   395,  1185,   369,  1270,  -469,   351,  -469,
    -469,  -469,   396,   942,  1234,  -469,   412,   353,   380,  -469,
    -469,   524,   392,   691,   691,   405,   406,   408,  -469,   269,
     409,  -469,   269,   269,   411,   691,   691,   413,   243,  1234,
     361,  -469,   366,  1234,   367,  -469,  -469,   417,  -469,  -469,
    1234,  -469,   418,  -469,  1100,  1167,  -469,  -469,   143,  1234,
    1136,   420,  1270,   236,  1185,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,   423,  -469,  -469,   691,   691,   691,   378,
    1234,   385,  -469,   691,   400,  -469,   691,  1234,   435,  -469,
    -469,   390,   159,  -469,   102,  -469,   691,  -469,  -469,  -469,
    -469,   418,  -469,   143,  1234,   236,  1252,  -469,  -469,  -469,
    -469,  -469,   428,  -469,  -469,  -469,  -469,  -469,   445,  -469,
     446,   691,   159,   391,   431,  -469,   367,   391,   391,  -469,
    -469,  -469,  -469,   126,  -469,   424,   134,   455,   691,   691,
    -469,  -469,   415,  1234,  -469,   416,  -469,   419,  1252,   459,
    -469,   691,  -469,  -469,  -469,  -469,  -469,   421,   159,  -469,
    1252,  -469,   159,  -469,  -469,  -469
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     154,     0,     0,     1,    32,    31,   225,     2,     0,     0,
      27,     0,     0,   155,     0,     0,   200,     0,     0,     0,
       0,   338,     0,     0,    56,    90,     0,   197,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,   334,   193,   205,   221,    70,   276,
     198,   157,    68,   192,   224,   158,    69,    97,     0,   215,
      60,   214,   244,   217,    64,    67,   219,    62,   181,   180,
     218,   252,   220,     5,   250,   216,   150,   160,   159,     3,
     223,   210,   117,   156,    33,    18,   117,   147,    65,    63,
      66,   141,   340,   161,   226,    26,    24,    25,   276,    39,
       0,     0,   117,   117,   126,     0,   129,   128,     0,   329,
     332,     0,   201,     0,    99,   139,   137,   138,    21,   326,
       0,     0,   317,     0,   317,     0,   266,   337,   253,   339,
     124,   179,   122,     0,   166,   204,     0,     0,   191,     0,
       0,   151,   152,   222,    34,   261,   260,     0,   258,     0,
      37,     0,   189,   153,     0,     0,     0,     0,    41,     0,
      88,    86,     0,    79,    83,    81,    85,    82,    80,    84,
       0,     0,    93,    91,    98,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,     0,
       0,   262,     0,    43,    44,    45,    47,    50,    49,    51,
      46,    55,    48,    54,    52,    53,   143,     0,   146,     0,
      42,   112,    40,     0,     0,   109,   110,     0,   106,   107,
      94,     0,     0,   131,     0,   130,     0,     0,     0,     0,
       0,     0,   240,     0,   135,     0,   186,   310,   320,   324,
     309,   317,     0,     0,   308,   312,   336,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,   255,   256,
      35,    38,     4,     6,    19,    20,     0,     0,     0,   277,
     199,    89,    87,    61,    23,   142,   167,   190,   194,     0,
     206,   207,     0,   208,   119,   118,   265,   246,   249,   245,
     247,   248,   263,     7,   145,   144,     0,   335,     0,   103,
     104,     0,     0,   111,   112,   108,   127,     0,     0,     0,
       0,     9,    11,    13,   172,   182,     0,   174,   184,   178,
       0,   330,   331,   333,   202,     0,   132,     0,     0,   278,
     136,    22,   311,   321,   325,   185,   317,   313,   267,   125,
     123,   327,     0,    57,     0,     0,   170,   270,     0,   293,
     195,   293,     0,     0,     0,   257,   275,   272,     0,   228,
     238,     0,   236,   227,     0,   209,   211,   121,   120,     0,
     149,   148,     0,     0,   105,     0,     0,   100,   101,    16,
      17,    95,     0,    10,     0,    14,     0,     0,   175,   177,
     242,     0,   133,     0,     0,     0,     0,     0,   140,     0,
     318,   307,     0,   317,     0,     0,     0,     0,   168,     0,
     291,   293,   287,     0,   296,   196,   164,     0,   259,   273,
     212,   229,   230,   274,   237,   232,   251,     8,   114,     0,
       0,     0,     0,    71,   102,    96,    12,    15,   173,   183,
     176,   241,   243,     0,   282,   283,     0,     0,     0,   322,
       0,   315,   314,     0,   162,    58,     0,     0,     0,   271,
     292,   289,   304,   293,   297,   285,     0,   213,   231,   239,
     233,   234,   113,   116,     0,    73,     0,    77,    78,    72,
     134,   279,   280,   284,   323,   319,   316,   328,     0,    59,
       0,     0,   304,     0,   294,   288,   296,     0,   293,   165,
     235,   115,    74,     0,   269,   268,    75,     0,     0,     0,
     169,   290,   305,     0,   286,   302,   293,   298,     0,     0,
      76,     0,   163,   171,   306,   295,   303,   300,   304,   187,
       0,   281,   304,   299,   188,   301
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -469,  -469,   275,   308,  -469,  -193,  -469,   103,   125,  -469,
    -469,  -469,   479,  -469,  -469,  -469,   436,  -469,  -469,   -70,
    -469,  -427,  -469,  -469,  -469,   437,  -469,  -469,  -469,   185,
     187,   242,  -469,     3,  -469,   167,   -15,   171,  -469,     2,
    -469,  -469,   218,  -469,  -469,   489,     8,  -469,  -469,  -469,
    -469,  -294,  -469,  -469,  -469,   183,  -469,  -469,  -469,   -18,
    -178,  -469,  -469,  -469,  -469,  -469,   345,    -1,  -469,  -268,
     222,     7,  -306,   499,    82,  -469,  -469,  -127,  -469,   157,
     -11,   -21,   469,  -469,   153,   213,  -469,  -468,  -252,  -469,
     414,  -469,  -469,  -469,  -342,    14,  -327,    11,   175,  -113,
     274,   113,   -98,  -469,   289,   511,  -469,   344,  -469,   -31,
    -469
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    44,    45,   206,   310,   311,   312,    46,    47,
     172,    48,    49,    50,   207,    51,    52,    53,    54,   477,
     478,   479,   170,    55,    56,    57,    58,    59,   101,   300,
     185,   130,   131,   132,   108,   328,   114,   115,   234,    60,
      61,   208,    62,     2,    63,    64,    65,    66,    67,   408,
     317,   318,    68,    69,    70,   319,    71,   504,    72,    73,
      74,   256,    75,    76,    77,    78,    79,   232,   183,   421,
      81,    82,    83,    84,   360,   361,   362,   233,   391,    85,
      86,   127,   147,   259,   148,    87,   128,   506,   494,   269,
     158,    88,   329,   352,   412,   465,   495,   123,   244,   238,
     239,   240,   124,    89,   110,    90,   111,    91,   129,    92,
      93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     103,    80,   279,   351,   109,   112,   149,   135,   118,   414,
     126,   245,   133,   138,   136,   105,    96,   126,   102,   390,
     116,   139,   387,   237,   241,   117,   146,   146,   314,   160,
     119,   116,   215,   218,   353,   106,   117,   347,   143,   213,
     249,   120,   119,   161,   145,   145,   162,   213,   502,   213,
     529,   320,   217,   163,   164,   165,   166,   167,   168,   364,
     345,     4,   534,     5,     6,     3,   175,   179,   228,   461,
       9,    10,   214,    11,   358,     6,   121,   221,   258,   520,
     214,   221,   214,   348,   315,   442,   122,   107,   402,   316,
      20,    21,   298,   349,   440,   169,   410,   411,   403,   350,
     184,   322,   211,     4,    31,     5,     6,   347,   354,   236,
     176,   226,     9,    10,   246,    11,   229,    34,    35,    36,
     104,   496,   213,   341,    37,   343,    38,   346,   223,   213,
     113,   119,    20,    21,   181,   104,   182,   263,   252,   156,
     157,   299,   518,    40,   119,   213,    31,   179,   180,   224,
      41,    42,    43,   497,   468,   214,   517,   470,   220,    34,
      35,    36,   214,   498,   347,   511,    37,   144,    38,   282,
     283,   134,   273,   285,   527,   184,   295,   121,   214,   274,
     225,   293,   298,   476,   137,    40,   294,   122,   253,   213,
     399,   284,    41,    42,    43,   384,   126,   140,   433,   302,
     152,   533,   221,   500,   222,   535,   304,   326,   395,   155,
     493,   313,   266,   267,   154,   268,   116,   396,   109,   324,
     159,   117,   214,   245,   331,   176,   416,   177,    15,   321,
     342,   335,   336,   209,   377,   400,   338,   171,   178,   400,
     126,   512,   313,   385,    12,   515,   516,   213,   184,    29,
     326,   327,   141,   142,   475,    33,   313,   363,   153,   212,
       4,   227,     5,     6,   235,   371,   444,   445,   230,     9,
      10,    30,    11,   191,   119,   368,    33,   242,   454,   455,
     214,   368,   457,   458,   179,   476,   375,   373,   243,   216,
     219,   247,   368,   367,   368,   248,   379,   380,   505,   367,
     257,   449,   186,   116,   451,   241,   280,   281,   117,   250,
     367,   251,   367,   264,   265,   392,    34,    35,    36,   481,
     482,   483,   254,    37,    80,    38,   487,   260,   255,   489,
     272,   271,   116,   261,   276,   277,   187,   117,    33,   499,
     505,   286,    40,   417,   146,   188,   189,   190,   422,    41,
      42,    43,   505,   426,   292,   296,   301,   306,   427,   303,
     305,   325,   145,   431,   510,   330,   332,   333,   337,   340,
     356,   355,   313,   437,   428,   369,   376,   270,   374,   381,
     382,   522,   523,   383,   386,   314,   388,   393,   394,   404,
      80,   405,   406,   407,   531,   409,   347,   423,   459,   413,
     425,   415,   463,   419,   287,   288,   289,   290,   291,   467,
     424,   429,   432,   363,   471,   434,   435,   438,   472,   443,
     439,   446,   447,   431,   448,   460,   450,   453,   480,   456,
     462,   464,   473,   466,   420,     4,   474,     5,     6,   485,
     488,     7,   484,     8,     9,    10,   490,    11,   513,   486,
      12,   491,    13,    14,   492,    15,    16,    17,    18,   507,
      19,   508,   509,   501,    20,    21,    22,    23,    24,    25,
      26,   521,   179,    27,    28,   530,    29,    30,    31,   524,
     526,    32,    33,   528,   297,   532,   436,   278,    98,   378,
     339,    34,    35,    36,   173,   174,   397,    95,    37,   262,
      38,   398,   525,   389,   366,    94,   469,   151,   418,   370,
     514,   401,   210,    39,   519,   334,   452,    40,   323,    97,
     275,     0,     0,     0,    41,    42,    43,     4,     0,     5,
       6,     0,   441,     0,     0,     8,     9,    10,     0,    11,
       0,     0,    12,     0,     0,    14,     0,    15,    16,    17,
      18,     0,    19,     0,     0,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,    28,     0,    29,    30,
      31,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,     0,     0,
      37,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,    40,
       0,     4,     0,     5,     6,     0,    41,    42,    43,     8,
       9,    10,     0,    11,     0,     0,    12,     0,     0,    14,
       0,    15,    16,    17,    18,     0,    19,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
      28,     0,    29,    30,    31,     0,     0,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,     0,     0,    37,     0,    38,     0,     4,     0,
       5,     6,     0,     0,     0,     0,     0,     9,    10,    39,
      11,     0,     0,    40,     4,     0,     5,     6,     0,     0,
      41,    42,    43,     9,    10,     0,    11,    20,     0,     0,
       0,   231,    14,     0,     0,    16,     0,    18,     0,    19,
       0,    31,     0,    20,    21,    22,   307,    24,    25,    26,
       0,     0,    27,    28,    34,    35,   308,    31,     0,     0,
       0,    37,   309,    38,     0,     0,     0,     0,     0,     0,
      34,    35,    36,     0,     0,     0,     0,    37,     0,    38,
      40,     4,     0,     5,     6,     0,     0,    41,    42,    43,
       9,    10,    39,    11,     0,     0,    40,     4,     0,     5,
       6,     0,     0,    41,    42,    43,     9,    10,     0,    11,
      20,     0,     0,     0,   365,    14,     0,     0,    16,     0,
      18,     0,    19,     0,    31,     0,    20,    21,    22,   307,
      24,    25,    26,     0,     0,    27,    28,    34,    35,   308,
      31,     0,     0,     0,    37,   344,    38,     4,     0,     5,
       6,     0,     0,    34,    35,    36,     9,    10,    99,    11,
      37,     0,    38,    40,     0,     0,     0,     0,     0,     0,
      41,    42,    43,     0,     0,    39,    20,     0,     0,    40,
       0,     0,     0,     0,     0,     0,    41,    42,    43,     0,
      31,     0,     0,     0,     0,   100,     0,     4,     0,     5,
       6,     0,     0,    34,    35,    36,     9,    10,     0,    11,
      37,     0,    38,     0,     0,     4,     0,     5,     6,     0,
       0,     0,     0,     0,     9,    10,    20,    11,     0,    40,
       0,     0,     0,     0,     0,     0,    41,    42,    43,     0,
      31,     0,     0,     0,    20,   307,     0,     0,     0,     0,
       0,     0,     0,    34,    35,   308,     0,     0,    31,     0,
      37,   357,    38,     0,     0,     4,     0,     5,     6,     0,
       0,    34,    35,    36,     9,    10,     0,    11,    37,    40,
      38,   150,     0,     0,     0,     0,    41,    42,    43,     0,
       0,     0,     0,     0,    20,     0,     0,    40,     0,     0,
       0,     0,     0,     0,    41,    42,    43,     4,    31,     5,
       6,     0,     0,   307,     0,     0,     9,    10,     0,    11,
       0,    34,    35,   308,     0,   125,     0,     0,    37,     0,
      38,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     4,
      31,     5,     6,     0,    41,    42,    43,     0,     9,    10,
       0,    11,     0,    34,    35,     4,     0,     5,     6,     0,
      37,     0,    38,     0,     9,    10,     0,    11,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,    31,     0,    20,    21,    41,    42,    43,     0,
       0,     0,     0,     0,     0,    34,    35,    36,    31,     0,
       0,     0,    37,     0,    38,     0,     0,     0,     0,     0,
       0,    34,    35,     4,     0,     5,     6,     0,    37,     0,
      38,    40,     9,    10,     0,    11,   359,     0,    41,    42,
      43,     4,     0,     5,     6,     0,     0,    40,     0,     0,
       9,    10,    20,    11,    41,    42,    43,     0,     0,     4,
       0,     5,     6,     0,     0,     0,    31,     0,     9,    10,
      20,    11,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,     0,     0,    31,     0,    37,     0,    38,   372,
       4,     0,     5,     6,     0,     0,     0,    34,    35,     9,
      10,     0,    11,   420,    37,    40,    38,     0,     4,     0,
       5,     6,    41,    42,    43,    34,    35,     9,    10,    20,
      11,     0,    37,    40,    38,     0,     4,     0,     5,     6,
      41,    42,    43,    31,     0,     0,    10,    20,    11,     0,
       0,    40,     0,     0,     0,     0,    34,    35,    41,    42,
      43,    31,     0,    37,     0,    38,   430,     4,     0,     5,
       6,     0,     0,     0,    34,    35,     9,    10,     0,    11,
       0,    37,    40,    38,     0,     4,     0,     5,     6,    41,
      42,    43,     0,     0,     9,    10,    20,    11,     0,    37,
      40,    38,     0,     4,     0,     5,     6,    41,    42,    43,
      31,     0,     9,    10,   503,    11,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    41,    42,    43,    31,     0,
      37,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,   192,     0,     0,    31,     0,    37,    40,
      38,     0,     0,     0,     0,     0,    41,    42,    43,    34,
      35,     0,     0,     0,     0,     0,    37,    40,    38,     0,
       0,     0,     0,     0,    41,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,    41,    42,    43,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,     0,   204,     0,   205
};

static const yytype_int16 yycheck[] =
{
      11,     2,   180,   255,    15,    16,    37,    28,    19,   351,
      21,   124,    23,    31,    29,    12,     8,    28,    11,   325,
      18,    32,   316,   121,   122,    18,    37,    38,     5,    29,
       5,    29,   102,   103,    16,    13,    29,     5,    36,    11,
      27,    16,     5,    43,    37,    38,    46,    11,   475,    11,
     518,    34,    16,    53,    54,    55,    56,    57,    58,    40,
     253,     3,   530,     5,     6,     0,    58,    48,    16,   411,
      12,    13,    44,    15,   267,     6,    51,    64,   148,   506,
      44,    64,    44,    51,    61,   391,    61,    65,    51,    66,
      32,    33,    64,    61,   388,    95,   348,   349,    61,    67,
      64,   228,   100,     3,    46,     5,     6,     5,    90,   120,
      82,   108,    12,    13,   125,    15,    64,    59,    60,    61,
       5,   463,    11,   250,    66,   252,    68,   254,    13,    11,
      16,     5,    32,    33,    86,     5,    88,   155,    16,    59,
      60,   211,    16,    85,     5,    11,    46,    48,    49,    34,
      92,    93,    94,    51,   422,    44,   498,   425,    20,    59,
      60,    61,    44,    61,     5,   492,    66,    67,    68,    19,
      20,     5,   170,   184,   516,    64,   207,    51,    44,   171,
      65,   192,    64,    49,     5,    85,   207,    61,    66,    11,
      51,   184,    92,    93,    94,    17,   207,     5,   376,   214,
       5,   528,    64,   471,    66,   532,   217,    30,    31,    47,
      51,   222,    65,    66,    83,    68,   214,    40,   229,   230,
      51,   214,    44,   336,   235,    82,   353,    64,    23,   227,
     251,   242,   243,    84,   304,   333,   247,    11,    64,   337,
     251,   493,   253,   313,    18,   497,   498,    11,    64,    44,
      30,    31,    34,    35,   432,    50,   267,   268,    40,    14,
       3,    27,     5,     6,    64,   296,   393,   394,    21,    12,
      13,    45,    15,    86,     5,   286,    50,    16,   405,   406,
      44,   292,    39,    40,    48,    49,   301,   298,    17,   102,
     103,    64,   303,   286,   305,    64,   307,   308,   476,   292,
      67,   399,    18,   301,   402,   403,   181,   182,   301,    16,
     303,    43,   305,   156,   157,   326,    59,    60,    61,   446,
     447,   448,    16,    66,   325,    68,   453,    67,    66,   456,
      43,    46,   330,    69,     5,     5,    52,   330,    50,   466,
     518,    64,    85,   354,   355,    61,    62,    63,   359,    92,
      93,    94,   530,   364,    64,    17,    44,     5,   369,    64,
      64,     7,   355,   374,   491,    64,    64,    64,    64,     5,
       5,    64,   383,   384,   372,    17,    43,   159,    64,    20,
      67,   508,   509,    64,    27,     5,    64,    16,    16,    40,
     391,    16,    16,    67,   521,    16,     5,    69,   409,    17,
      16,    67,   413,    67,   186,   187,   188,   189,   190,   420,
      64,    16,    43,   424,   425,    64,    20,     5,   429,    27,
      67,    16,    16,   434,    16,    64,    17,    16,     5,    16,
      64,    64,   430,    16,    16,     3,    16,     5,     6,   450,
      40,     9,    64,    11,    12,    13,   457,    15,    17,    64,
      18,    16,    20,    21,    64,    23,    24,    25,    26,    31,
      28,    16,    16,   474,    32,    33,    34,    35,    36,    37,
      38,    16,    48,    41,    42,    16,    44,    45,    46,    64,
      64,    49,    50,    64,   209,    64,   383,   179,     9,   304,
     248,    59,    60,    61,    58,    58,   329,     8,    66,   154,
      68,   330,   513,   320,   282,     6,   424,    38,   355,   296,
     496,   336,    98,    81,   503,   241,   403,    85,   229,     8,
     176,    -1,    -1,    -1,    92,    93,    94,     3,    -1,     5,
       6,    -1,     8,    -1,    -1,    11,    12,    13,    -1,    15,
      -1,    -1,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    -1,    28,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    42,    -1,    44,    45,
      46,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      -1,     3,    -1,     5,     6,    -1,    92,    93,    94,    11,
      12,    13,    -1,    15,    -1,    -1,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      42,    -1,    44,    45,    46,    -1,    -1,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    68,    -1,     3,    -1,
       5,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,    81,
      15,    -1,    -1,    85,     3,    -1,     5,     6,    -1,    -1,
      92,    93,    94,    12,    13,    -1,    15,    32,    -1,    -1,
      -1,    20,    21,    -1,    -1,    24,    -1,    26,    -1,    28,
      -1,    46,    -1,    32,    33,    34,    51,    36,    37,    38,
      -1,    -1,    41,    42,    59,    60,    61,    46,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    68,
      85,     3,    -1,     5,     6,    -1,    -1,    92,    93,    94,
      12,    13,    81,    15,    -1,    -1,    85,     3,    -1,     5,
       6,    -1,    -1,    92,    93,    94,    12,    13,    -1,    15,
      32,    -1,    -1,    -1,    20,    21,    -1,    -1,    24,    -1,
      26,    -1,    28,    -1,    46,    -1,    32,    33,    34,    51,
      36,    37,    38,    -1,    -1,    41,    42,    59,    60,    61,
      46,    -1,    -1,    -1,    66,    67,    68,     3,    -1,     5,
       6,    -1,    -1,    59,    60,    61,    12,    13,    14,    15,
      66,    -1,    68,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    -1,    -1,    81,    32,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      46,    -1,    -1,    -1,    -1,    51,    -1,     3,    -1,     5,
       6,    -1,    -1,    59,    60,    61,    12,    13,    -1,    15,
      66,    -1,    68,    -1,    -1,     3,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    13,    32,    15,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      46,    -1,    -1,    -1,    32,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    46,    -1,
      66,    67,    68,    -1,    -1,     3,    -1,     5,     6,    -1,
      -1,    59,    60,    61,    12,    13,    -1,    15,    66,    85,
      68,    69,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,     3,    46,     5,
       6,    -1,    -1,    51,    -1,    -1,    12,    13,    -1,    15,
      -1,    59,    60,    61,    -1,    21,    -1,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,     3,
      46,     5,     6,    -1,    92,    93,    94,    -1,    12,    13,
      -1,    15,    -1,    59,    60,     3,    -1,     5,     6,    -1,
      66,    -1,    68,    -1,    12,    13,    -1,    15,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    46,    -1,    32,    33,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    46,    -1,
      -1,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,     3,    -1,     5,     6,    -1,    66,    -1,
      68,    85,    12,    13,    -1,    15,    16,    -1,    92,    93,
      94,     3,    -1,     5,     6,    -1,    -1,    85,    -1,    -1,
      12,    13,    32,    15,    92,    93,    94,    -1,    -1,     3,
      -1,     5,     6,    -1,    -1,    -1,    46,    -1,    12,    13,
      32,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    46,    -1,    66,    -1,    68,    51,
       3,    -1,     5,     6,    -1,    -1,    -1,    59,    60,    12,
      13,    -1,    15,    16,    66,    85,    68,    -1,     3,    -1,
       5,     6,    92,    93,    94,    59,    60,    12,    13,    32,
      15,    -1,    66,    85,    68,    -1,     3,    -1,     5,     6,
      92,    93,    94,    46,    -1,    -1,    13,    32,    15,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    59,    60,    92,    93,
      94,    46,    -1,    66,    -1,    68,    51,     3,    -1,     5,
       6,    -1,    -1,    -1,    59,    60,    12,    13,    -1,    15,
      -1,    66,    85,    68,    -1,     3,    -1,     5,     6,    92,
      93,    94,    -1,    -1,    12,    13,    32,    15,    -1,    66,
      85,    68,    -1,     3,    -1,     5,     6,    92,    93,    94,
      46,    -1,    12,    13,    32,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    92,    93,    94,    46,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    16,    -1,    -1,    46,    -1,    66,    85,
      68,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    59,
      60,    -1,    -1,    -1,    -1,    -1,    66,    85,    68,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,   139,     0,     3,     5,     6,     9,    11,    12,
      13,    15,    18,    20,    21,    23,    24,    25,    26,    28,
      32,    33,    34,    35,    36,    37,    38,    41,    42,    44,
      45,    46,    49,    50,    59,    60,    61,    66,    68,    81,
      85,    92,    93,    94,    98,    99,   104,   105,   107,   108,
     109,   111,   112,   113,   114,   119,   120,   121,   122,   123,
     135,   136,   138,   140,   141,   142,   143,   144,   148,   149,
     150,   152,   154,   155,   156,   158,   159,   160,   161,   162,
     163,   166,   167,   168,   169,   175,   176,   181,   187,   199,
     201,   203,   205,   206,   169,   141,   142,   201,   108,    14,
      51,   124,   167,   176,     5,   129,    13,    65,   130,   176,
     200,   202,   176,    16,   132,   133,   135,   167,   176,     5,
      16,    51,    61,   193,   198,    21,   176,   177,   182,   204,
     127,   128,   129,   176,     5,   177,   132,     5,   155,   176,
       5,   138,   138,   135,    67,   167,   176,   178,   180,   205,
      69,   178,     5,   138,    83,    47,    59,    60,   186,    51,
      29,    43,    46,    53,    54,    55,    56,    57,    58,    95,
     118,    11,   106,   112,   121,   142,    82,    64,    64,    48,
      49,    86,    88,   164,    64,   126,    18,    52,    61,    62,
      63,   126,    16,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    87,    89,   100,   110,   137,    84,
     186,   135,    14,    11,    44,   115,   126,    16,   115,   126,
      20,    64,    66,    13,    34,    65,   129,    27,    16,    64,
      21,    20,   163,   173,   134,    64,   176,   198,   195,   196,
     197,   198,    16,    17,   194,   195,   176,    64,    64,    27,
      16,    43,    16,    66,    16,    66,   157,    67,   115,   179,
      67,    69,   162,   155,   175,   175,    65,    66,    68,   185,
     138,    46,    43,   135,   142,   203,     5,     5,    99,   156,
     104,   104,    19,    20,   167,   176,    64,   138,   138,   138,
     138,   138,    64,   176,   177,   205,    17,    98,    64,   115,
     125,    44,   132,    64,   176,    64,     5,    51,    61,    67,
     101,   102,   103,   176,     5,    61,    66,   146,   147,   151,
      34,   135,   173,   200,   176,     7,    30,    31,   131,   188,
      64,   176,    64,    64,   196,   176,   176,    64,   176,   127,
       5,   173,   177,   173,    67,   101,   173,     5,    51,    61,
      67,   184,   189,    16,    90,    64,     5,    67,   101,    16,
     170,   171,   172,   176,    40,    20,   166,   167,   176,    17,
     181,   205,    51,   176,    64,   132,    43,   115,   125,   176,
     176,    20,    67,    64,    17,   115,    27,   147,    64,   151,
     168,   174,   176,    16,    16,    31,    40,   131,   133,    51,
     198,   194,    51,    61,    40,    16,    16,    67,   145,    16,
     184,   184,   190,    17,   190,    67,   173,   176,   180,    67,
      16,   165,   176,    69,    64,    16,   176,   176,   135,    16,
      51,   176,    43,   156,    64,    20,   103,   176,     5,    67,
     147,     8,   168,    27,   173,   173,    16,    16,    16,   198,
      17,   198,   197,    16,   173,   173,    16,    39,    40,   176,
      64,   190,    64,   176,    64,   191,    16,   176,   165,   170,
     165,   176,   176,   135,    16,   156,    49,   115,   116,   117,
       5,   173,   173,   173,    64,   176,    64,   173,    40,   173,
     176,    16,    64,    51,   184,   192,   190,    51,    61,   173,
     165,   176,   117,    32,   153,   156,   183,    31,    16,    16,
     173,   192,   184,    17,   191,   184,   184,   190,    16,   193,
     117,    16,   173,   173,    64,   176,    64,   190,    64,   183,
      16,   173,    64,   192,   183,   192
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     104,   105,   105,   106,   107,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   112,   112,   112,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   115,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   120,   120,   120,   121,   121,   121,   122,   122,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   126,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   131,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   136,   136,   137,   137,   137,
     138,   138,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   147,   147,   147,   148,   148,   149,
     150,   150,   151,   151,   151,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   157,   157,   158,   159,   159,
     160,   160,   160,   161,   161,   162,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   166,   167,   168,   168,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   177,   177,   178,   178,   178,   179,   179,
     180,   180,   181,   181,   181,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   185,   185,   186,   186,   187,   187,
     187,   187,   187,   188,   188,   189,   189,   189,   189,   189,
     189,   189,   189,   190,   190,   190,   191,   191,   191,   191,
     191,   191,   191,   191,   192,   192,   192,   193,   193,   193,
     193,   193,   194,   194,   194,   194,   194,   195,   195,   195,
     196,   196,   196,   196,   197,   197,   198,   199,   199,   200,
     200,   201,   202,   202,   203,   203,   204,   204,   205,   205,
     206
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     1,     3,     2,     4,     1,
       2,     1,     3,     1,     2,     3,     2,     2,     1,     3,
       3,     2,     4,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     2,     3,     2,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     7,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     5,     6,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     2,     2,     3,     5,     6,     1,     2,     2,
       4,     4,     5,     3,     3,     4,     2,     2,     3,     2,
       2,     3,     0,     4,     3,     5,     4,     0,     2,     2,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       2,     2,     1,     2,     4,     2,     3,     1,     1,     0,
       3,     1,     3,     2,     3,     3,     2,     0,     3,     3,
       1,     2,     2,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     6,     9,     5,     7,     2,     3,     5,     8,
       0,     5,     1,     3,     1,     2,     3,     5,     4,     2,
       1,     1,     1,     3,     1,     4,     3,     3,     4,     2,
       3,     2,     1,     1,     3,     2,     3,     1,     1,     3,
       1,     2,     4,     1,     2,     1,     3,     3,     3,     4,
       0,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     2,     1,     1,     2,
       2,     3,     2,     3,     3,     4,     1,     2,     1,     3,
       1,     4,     1,     2,     1,     3,     3,     3,     3,     3,
       1,     5,     1,     1,     2,     2,     2,     3,     0,     3,
       1,     1,     2,     3,     2,     3,     1,     3,     1,     1,
       1,     3,     2,     3,     3,     2,     0,     2,     4,     7,
       7,    10,     6,     3,     4,     3,     5,     2,     4,     3,
       5,     2,     3,     0,     3,     5,     0,     1,     3,     5,
       4,     6,     3,     4,     0,     2,     3,     4,     2,     2,
       2,     3,     1,     2,     4,     4,     5,     0,     3,     5,
       1,     2,     4,     5,     1,     2,     1,     4,     7,     1,
       3,     4,     1,     3,     1,     3,     2,     1,     1,     2,
       1
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
#line 187 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfile_input : file_input_sub ENDMARKER\n");}
#line 1960 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 189 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tand_expr : shift_expr\n");}
#line 1966 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 190 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tand_expr : and_expr \"&\" shift_expr\n");}
#line 1972 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 192 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tand_test : not_test\n");}
#line 1978 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 193 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tand_test : and_test \"and\" not_test\n");}
#line 1984 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 204 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\targument : test\n");}
#line 1990 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 210 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tarith_expr : term\n");}
#line 1996 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 211 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tarith_expr : arith_expr \"+\" term\n");}
#line 2002 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 212 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tarith_expr : arith_expr \"-\" term\n");}
#line 2008 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 228 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tatom : NUMBER\n");}
#line 2014 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tatom_expr : atom trailer_star\n");}
#line 2020 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 257 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tclassdef : \"class\" NAME : suite\n");}
#line 2026 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 261 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomparison : expr\n");}
#line 2032 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 262 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomparison : comparison comp_op expr\n");}
#line 2038 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 269 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcompound_stmt : funcdef\n");}
#line 2044 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 285 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"<\"\n");}
#line 2050 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 286 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \">\"\n");}
#line 2056 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 287 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"==\"\n");}
#line 2062 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 288 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \">=\"\n");}
#line 2068 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 289 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"<=\"\n");}
#line 2074 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 290 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"<>\"\n");}
#line 2080 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 291 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"!=\"\n");}
#line 2086 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 292 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"in\"\n");}
#line 2092 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 293 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"not\" \"in\"\n");}
#line 2098 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 294 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"is\"\n");}
#line 2104 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 295 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tcomp_op : \"is\" \"not\"\n");}
#line 2110 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 369 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\texpr : xor_expr\n");}
#line 2116 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 370 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\texpr : expr \"|\" xor_expr\n");}
#line 2122 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 381 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfactor : power\n");}
#line 2128 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 382 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfactor : \"+\" factor\n");}
#line 2134 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 383 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfactor : \"-\" factor\n");}
#line 2140 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 384 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfactor : \"~\" factor\n");}
#line 2146 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 386 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfile_input_sub : \n");}
#line 2152 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 387 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfile_input_sub : file_input_sub NEWLINE\n");}
#line 2158 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 388 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfile_input_sub : file_input_sub stmt\n");}
#line 2164 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 392 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tflow_stmt : return_stmt\n");}
#line 2170 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 399 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfuncdef : \"def\" NAME parameters \":\" suite\n");}
#line 2176 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 400 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tfuncdef : \"def\" NAME parameters \"->\" test \":\" suite\n");}
#line 2182 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 440 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tnot_test : comparison\n");}
#line 2188 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 442 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tor_test : and_test\n");}
#line 2194 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 443 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tor_test : or_test \"or\" and_test\n");}
#line 2200 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 445 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tparameters : \"(\" \")\"\n");}
#line 2206 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 446 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tparameters : \"(\" typedargslist \")\"\n");}
#line 2212 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 450 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tpower : atom_expr\n");}
#line 2218 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 457 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\treturn_stmt : \"return\"\n");}
#line 2224 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 458 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\treturn_stmt : \"return\" testlist\n");}
#line 2230 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 460 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tshift_expr : arith_expr\n");}
#line 2236 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 461 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tshift_expr : shift_expr \"<<\" arith_expr\n");}
#line 2242 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 462 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tshift_expr : shift_expr \">>\" arith_expr\n");}
#line 2248 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 464 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsimple_stmt : small_stmt simple_stmt_sub NEWLINE\n");}
#line 2254 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 467 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsimple_stmt_sub : \n");}
#line 2260 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 477 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsmall_stmt : expr_stmt\n");}
#line 2266 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 480 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsmall_stmt : flow_stmt\n");}
#line 2272 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 488 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tstmt : simple_stmt\n");}
#line 2278 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 489 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tstmt : compound_stmt\n");}
#line 2284 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 510 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsuite : simple_stmt\n");}
#line 2290 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 511 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsuite : NEWLINE INDENT suite_sub DEDENT\n");}
#line 2296 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 513 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsuite_sub : stmt\n");}
#line 2302 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 514 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tsuite_sub : suite_sub stmt\n");}
#line 2308 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 516 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tterm : factor\n");}
#line 2314 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 517 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tterm : term \"*\" factor\n"); /*$$ = $1 * $3*/}
#line 2320 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 518 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tterm : term \"@\" factor\n");}
#line 2326 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 519 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tterm : term \"/\" factor\n"); /*$$ = $1 / $3*/}
#line 2332 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 520 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tterm : term \"%\" factor\n"); /*$$ = $1 % $3*/}
#line 2338 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 521 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\tterm : term \"//\" factor\n"); /*$$ = int($1 / $3)*/}
#line 2344 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 523 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttest : or_test\n");}
#line 2350 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 525 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttest : lambdef\n");}
#line 2356 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 527 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttestlist : test testlist_sub\n");}
#line 2362 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 545 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttestlist_sub : \n");}
#line 2368 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 554 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttrailer : \"(\" \")\"\n");}
#line 2374 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 555 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttrailer : \"(\" arglist \")\"\n"); /*$$ = $2*/}
#line 2380 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 556 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttrailer : \"[\" subscriptlist \"]\"\n"); /*$$ = $2*/}
#line 2386 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 557 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttrailer : \".\" NAME\n");}
#line 2392 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 559 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttrailer_star : \n");}
#line 2398 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 560 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\ttrailer_star : trailer_star trailer\n");}
#line 2404 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 634 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\txor_expr : and_expr\n");}
#line 2410 "Viper.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 635 "Viper.y" /* yacc.c:1646  */
    {D(fout_diag << "YACC:\txor_expr : xor_expr \"^\" and_expr\n");}
#line 2416 "Viper.tab.c" /* yacc.c:1646  */
    break;


#line 2420 "Viper.tab.c" /* yacc.c:1646  */
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
#line 645 "Viper.y" /* yacc.c:1906  */


int main(int argc, char * argv[]) {
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
	D(PrintTokens(T));
	yyparse();
	fout_diag.close();
	return 0;
};
void PrintTokens(TokenTable * T) {
	system("CLS");
	for (int i = 0; i < TOKEN_TABLE_SIZE && T->t[i].availability != 0; i++) {
		fout_diag << T->t[i].lineno << "\t" << T->t[i].layer << "\t";
		switch (T->t[i].type) {
			case STRING:{
				fout_diag << "STRING" << "\t" << T->t[i].value.S;
				break;
			}
			case NUMBER:{
				fout_diag << "NUMBER" << "\t" << T->t[i].value.D;
				break;
			}
			case CHAR:{
				fout_diag << "CHAR" << "\t" << T->t[i].value.C;
				break;
			}
			case NAME:{
				fout_diag << "NAME" << "\t" << T->t[i].value.S;
				break;
			}
			case INDENT:{
				fout_diag << "INDENT";
				break;
			}
			case DEDENT:{
				fout_diag << "DEDENT";
				break;
			}
			default:{
				fout_diag << T->t[i].value.S;
				break;
			}
		}
		fout_diag << endl;
	}
	fout_diag << endl;
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
			D(fout_diag << "LEX:\tSTRING\t" << yylval.String << endl);
			break;
		}
		case NUMBER:{
			yylval.Double = T->t[i].value.D;
			D(fout_diag << "LEX:\tNUMBER\t" << yylval.Double << endl);
			break;
		}
		case CHAR:{
			yylval.Char = T->t[i].value.C;
			D(fout_diag << "LEX:\tCHAR\t" << yylval.Char << endl);
			break;
		}
		case NAME:{
			yylval.Name = T->t[i].value.S;
			D(fout_diag << "LEX:\tNAME\t" << yylval.Name << endl);
			break;
		}
		case INDENT:{
			D(fout_diag << "LEX:\tINDENT" << endl);
			break;
		}
		case DEDENT:{
			D(fout_diag << "LEX:\tDEDENT" << endl);
			break;
		}
		case NEWLINE:{
			D(fout_diag << "LEX:\tNEWLINE" << endl);
			break;
		}
		default:{
			yylval.Name = T->t[i].value.S;
			D(fout_diag << "LEX:\t" << yylval.Name << endl);
			break;
		}
	}
	T->Pointer++;
	return T->t[i].type;
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}
