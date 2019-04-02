%{
#include "sea.h"
#include <stdio.h>
%}

%union {
    const char* s;
    struct SeaNode* n;
};

%token <s> IDENTIFIER QSTRING

%token I8 I16 I32 I64 U8 U16 U32 U64 F32 F64

%token CSTR BOOL PSIZE VOID
%token MUT RET IF ELSE VARGS

%token IS_EQ NOT_EQ LESS_EQ MORE_EQ
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ
%token SHL_EQ SHR_EQ

%left '+' '-'
%left '*' '/'
%left ELSE

%start program

%%

program
    : global program
    | global
    ;

global
    : func_def
    | func_decl
    ;

type
    : IDENTIFIER
    | I8
    | I16
    | I32
    | I64
    | U8
    | U16
    | U32
    | U64
    | F32
    | F64
    | CSTR
    | BOOL
    | PSIZE
    | VOID
    ;

func
    : type IDENTIFIER '(' params ')' { printf("|%s|\n", $2); }
    ;

func_def
    : func block
    ;

func_decl
    : func ';'
    ;

params
    : param _params
    | param VARGS
    | /* EPSILON */
    ;

_params
    : ',' param _params
    | /* EPSILON */
    ;

param
    : type IDENTIFIER
    | type
    ;

block
    : '{' _statement '}'
    ;

_statement
    : statement _statement
    |
    ;

statement
    : func_decl
    | func_def
    | func_call
    | return_stmt
    | block
    ;

func_call
    : IDENTIFIER '(' call_params ')' ';'
    ;

call_params
    : expression _call_params
    | /* EPSILON */
    ;

_call_params
    : ',' expression _call_params
    | /* EPSILON */
    ;

return_stmt
    : RET ';'
    | RET expression ';'
    ;

expression
    : IDENTIFIER
    | QSTRING
    | func_call
    ;

%%
