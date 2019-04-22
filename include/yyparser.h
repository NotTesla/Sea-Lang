/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_INCLUDE_YYPARSER_H_INCLUDED
# define YY_YY_INCLUDE_YYPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 9 "sea.y" /* yacc.c:1909  */


#include "sea_str.h"

#line 49 "./include/yyparser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    QSTRING = 259,
    NUMBER = 260,
    CINCLUDE = 261,
    I8 = 262,
    I16 = 263,
    I32 = 264,
    I64 = 265,
    U8 = 266,
    U16 = 267,
    U32 = 268,
    U64 = 269,
    F32 = 270,
    F64 = 271,
    WORD = 272,
    CSTR = 273,
    BOOL = 274,
    TRUE = 275,
    FALSE = 276,
    PSIZE = 277,
    VOID = 278,
    CAP = 279,
    MUT = 280,
    RET = 281,
    IF = 282,
    ELSE = 283,
    VARGS = 284,
    IS_EQ = 285,
    NOT_EQ = 286,
    LESS_EQ = 287,
    MORE_EQ = 288,
    ADD_EQ = 289,
    SUB_EQ = 290,
    MUL_EQ = 291,
    DIV_EQ = 292,
    MOD_EQ = 293,
    SHL_EQ = 294,
    SHR_EQ = 295,
    AND_EQ = 296,
    XOR_EQ = 297,
    OR_EQ = 298
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define QSTRING 259
#define NUMBER 260
#define CINCLUDE 261
#define I8 262
#define I16 263
#define I32 264
#define I64 265
#define U8 266
#define U16 267
#define U32 268
#define U64 269
#define F32 270
#define F64 271
#define WORD 272
#define CSTR 273
#define BOOL 274
#define TRUE 275
#define FALSE 276
#define PSIZE 277
#define VOID 278
#define CAP 279
#define MUT 280
#define RET 281
#define IF 282
#define ELSE 283
#define VARGS 284
#define IS_EQ 285
#define NOT_EQ 286
#define LESS_EQ 287
#define MORE_EQ 288
#define ADD_EQ 289
#define SUB_EQ 290
#define MUL_EQ 291
#define DIV_EQ 292
#define MOD_EQ 293
#define SHL_EQ 294
#define SHR_EQ 295
#define AND_EQ 296
#define XOR_EQ 297
#define OR_EQ 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "sea.y" /* yacc.c:1909  */

    struct SeaStr str;

#line 151 "./include/yyparser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_YYPARSER_H_INCLUDED  */
