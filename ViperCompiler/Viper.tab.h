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
