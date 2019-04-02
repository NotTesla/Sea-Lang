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
    CSTR = 271,
    BOOL = 272,
    PSIZE = 273,
    VOID = 274,
    MUT = 275,
    RET = 276,
    IF = 277,
    ELSE = 278,
    VARGS = 279,
    IS_EQ = 280,
    NOT_EQ = 281,
    LESS_EQ = 282,
    MORE_EQ = 283,
    ADD_EQ = 284,
    SUB_EQ = 285,
    MUL_EQ = 286,
    DIV_EQ = 287,
    SHL_EQ = 288,
    SHR_EQ = 289
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
#define CSTR 271
#define BOOL 272
#define PSIZE 273
#define VOID 274
#define MUT 275
#define RET 276
#define IF 277
#define ELSE 278
#define VARGS 279
#define IS_EQ 280
#define NOT_EQ 281
#define LESS_EQ 282
#define MORE_EQ 283
#define ADD_EQ 284
#define SUB_EQ 285
#define MUL_EQ 286
#define DIV_EQ 287
#define SHL_EQ 288
#define SHR_EQ 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 8 "sea.y" /* yacc.c:1909  */

    int tok;
    char* str;
    struct SeaNode* node;

#line 128 "./include/yyparser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_YYPARSER_H_INCLUDED  */
