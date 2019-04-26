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
    I8 = 261,
    I16 = 262,
    I32 = 263,
    I64 = 264,
    U8 = 265,
    U16 = 266,
    U32 = 267,
    U64 = 268,
    F32 = 269,
    F64 = 270,
    UWORD = 271,
    WORD = 272,
    CSTR = 273,
    BOOL = 274,
    TRUE = 275,
    FALSE = 276,
    PSIZE = 277,
    VOID = 278,
    FN = 279,
    CAP = 280,
    DEF = 281,
    VAR = 282,
    RET = 283,
    IF = 284,
    ELSE = 285,
    VARGS = 286,
    NAMESPACE = 287,
    INC_SEA_DEP = 288,
    INC_C_DEP = 289,
    IS_EQ = 290,
    NOT_EQ = 291,
    LESS_EQ = 292,
    MORE_EQ = 293,
    ADD_EQ = 294,
    SUB_EQ = 295,
    MUL_EQ = 296,
    DIV_EQ = 297,
    MOD_EQ = 298,
    SHL_EQ = 299,
    SHR_EQ = 300,
    AND_EQ = 301,
    XOR_EQ = 302,
    OR_EQ = 303
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define QSTRING 259
#define NUMBER 260
#define I8 261
#define I16 262
#define I32 263
#define I64 264
#define U8 265
#define U16 266
#define U32 267
#define U64 268
#define F32 269
#define F64 270
#define UWORD 271
#define WORD 272
#define CSTR 273
#define BOOL 274
#define TRUE 275
#define FALSE 276
#define PSIZE 277
#define VOID 278
#define FN 279
#define CAP 280
#define DEF 281
#define VAR 282
#define RET 283
#define IF 284
#define ELSE 285
#define VARGS 286
#define NAMESPACE 287
#define INC_SEA_DEP 288
#define INC_C_DEP 289
#define IS_EQ 290
#define NOT_EQ 291
#define LESS_EQ 292
#define MORE_EQ 293
#define ADD_EQ 294
#define SUB_EQ 295
#define MUL_EQ 296
#define DIV_EQ 297
#define MOD_EQ 298
#define SHL_EQ 299
#define SHR_EQ 300
#define AND_EQ 301
#define XOR_EQ 302
#define OR_EQ 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "sea.y" /* yacc.c:1909  */

    struct SeaStr str;

#line 161 "./include/yyparser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_YYPARSER_H_INCLUDED  */
