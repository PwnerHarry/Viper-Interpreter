/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
