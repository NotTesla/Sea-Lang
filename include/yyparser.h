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
    I8 = 260,
    I16 = 261,
    I32 = 262,
    I64 = 263,
    U8 = 264,
    U16 = 265,
    U32 = 266,
    U64 = 267,
    F32 = 268,
    F64 = 269,
    CSTR = 270,
    BOOL = 271,
    PSIZE = 272,
    VOID = 273,
    MUT = 274,
    RET = 275,
    IF = 276,
    ELSE = 277,
    VARGS = 278,
    IS_EQ = 279,
    NOT_EQ = 280,
    LESS_EQ = 281,
    MORE_EQ = 282,
    ADD_EQ = 283,
    SUB_EQ = 284,
    MUL_EQ = 285,
    DIV_EQ = 286,
    SHL_EQ = 287,
    SHR_EQ = 288
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define QSTRING 259
#define I8 260
#define I16 261
#define I32 262
#define I64 263
#define U8 264
#define U16 265
#define U32 266
#define U64 267
#define F32 268
#define F64 269
#define CSTR 270
#define BOOL 271
#define PSIZE 272
#define VOID 273
#define MUT 274
#define RET 275
#define IF 276
#define ELSE 277
#define VARGS 278
#define IS_EQ 279
#define NOT_EQ 280
#define LESS_EQ 281
#define MORE_EQ 282
#define ADD_EQ 283
#define SUB_EQ 284
#define MUL_EQ 285
#define DIV_EQ 286
#define SHL_EQ 287
#define SHR_EQ 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 6 "sea.y" /* yacc.c:1909  */

    const char* s;
    struct SeaNode* n;

#line 125 "./include/yyparser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_YYPARSER_H_INCLUDED  */
