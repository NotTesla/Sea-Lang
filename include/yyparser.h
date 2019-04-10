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
    WORD = 271,
    CSTR = 272,
    BOOL = 273,
    TRUE = 274,
    FALSE = 275,
    PSIZE = 276,
    VOID = 277,
    CAP = 278,
    MUT = 279,
    RET = 280,
    IF = 281,
    ELSE = 282,
    VARGS = 283,
    IS_EQ = 284,
    NOT_EQ = 285,
    LESS_EQ = 286,
    MORE_EQ = 287,
    ADD_EQ = 288,
    SUB_EQ = 289,
    MUL_EQ = 290,
    DIV_EQ = 291,
    MOD_EQ = 292,
    SHL_EQ = 293,
    SHR_EQ = 294,
    AND_EQ = 295,
    XOR_EQ = 296,
    OR_EQ = 297
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
#define WORD 271
#define CSTR 272
#define BOOL 273
#define TRUE 274
#define FALSE 275
#define PSIZE 276
#define VOID 277
#define CAP 278
#define MUT 279
#define RET 280
#define IF 281
#define ELSE 282
#define VARGS 283
#define IS_EQ 284
#define NOT_EQ 285
#define LESS_EQ 286
#define MORE_EQ 287
#define ADD_EQ 288
#define SUB_EQ 289
#define MUL_EQ 290
#define DIV_EQ 291
#define MOD_EQ 292
#define SHL_EQ 293
#define SHR_EQ 294
#define AND_EQ 295
#define XOR_EQ 296
#define OR_EQ 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "sea.y" /* yacc.c:1909  */

    struct SeaNode* node;

#line 142 "./include/yyparser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_YYPARSER_H_INCLUDED  */
