%{
#include "sea.h"
#include <stdio.h>

#define EPSILON sn_epsilon()
%}

%union {
    int tok;
    char* str;
    struct SeaNode* node;
}

%token <str> IDENTIFIER QSTRING NUMBER

%token I8 I16 I32 I64 U8 U16 U32 U64 F32 F64

%token CSTR BOOL PSIZE VOID
%token MUT RET IF ELSE VARGS

%token IS_EQ NOT_EQ LESS_EQ MORE_EQ
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ
%token SHL_EQ SHR_EQ

%type <node> program global type
%type <node> func func_def func_decl
%type <node> params _params param
%type <node> block _statement statement
%type <node> func_call call_params _call_params
%type <node> return_stmt expression

%left '+' '-'
%left '*' '/'
%left ELSE

%start program

%%

program
    : global program    { $$ = sn_alloc(SNT_PROGRAM, $1, $2, SNNULL); }
    |                   { $$ = EPSILON; } 
    ;

global
    : func_def  { $$ = sn_alloc(SNT_GLOBAL, $1, SNNULL); }
    | func_decl { $$ = sn_alloc(SNT_GLOBAL, $1, SNNULL); }
    ;

type
    : IDENTIFIER    { $$ = sn_alloc_wstr(SNT_TYPE, $1); }
    | I8            { $$ = sn_alloc_wtok(SNT_TYPE, I8); }
    | I16           { $$ = sn_alloc_wtok(SNT_TYPE, I16); }
    | I32           { $$ = sn_alloc_wtok(SNT_TYPE, I32); }
    | I64           { $$ = sn_alloc_wtok(SNT_TYPE, I64); }
    | U8            { $$ = sn_alloc_wtok(SNT_TYPE, U8); }
    | U16           { $$ = sn_alloc_wtok(SNT_TYPE, U16); }
    | U32           { $$ = sn_alloc_wtok(SNT_TYPE, U32); }
    | U64           { $$ = sn_alloc_wtok(SNT_TYPE, U64); }
    | F32           { $$ = sn_alloc_wtok(SNT_TYPE, F32); }
    | F64           { $$ = sn_alloc_wtok(SNT_TYPE, F64); }
    | CSTR          { $$ = sn_alloc_wtok(SNT_TYPE, CSTR); }
    | BOOL          { $$ = sn_alloc_wtok(SNT_TYPE, BOOL); }
    | PSIZE         { $$ = sn_alloc_wtok(SNT_TYPE, PSIZE); }
    | VOID          { $$ = sn_alloc_wtok(SNT_TYPE, VOID); }
    ;

func
    : type IDENTIFIER '(' params ')'    { $$ = sn_alloc(SNT_FUNC, $1, $2, $4, SNNULL); }
    ;

func_def
    : func block    { $$ = sn_alloc(SNT_FUNC_DEF, $1, $2, SNNULL); }
    ;

func_decl
    : func ';'  { $$ = sn_alloc(SNT_FUNC_DECL, $1, SNNULL); }
    ;

params
    : param _params { $$ = sn_alloc(SNT_PARAMS, $1, $2, SNNULL); }
    |               { $$ = EPSILON; } 
    ;

_params
    : ',' param _params { $$ = sn_alloc(SNT_PARAMS, $2, $3, SNNULL); }
    | VARGS             { /* TODO: */ $$ = sn_alloc_wtok(SNT_PARAMS, VARGS);}
    |                   { $$ = EPSILON; }
    ;

param
    : type IDENTIFIER   { $$ = sn_alloc(SNT_PARAM, $1, $2, SNNULL); }
    | type              { $$ = sn_alloc(SNT_PARAM, $1, SNNULL); }
    ;

block
    : '{' _statement '}'       { $$ = sn_alloc(SNT_BLOCK, $2, SNNULL); }
    ;

_statement
    : statement _statement  { $$ = sn_alloc(SNT_STATEMENTS, $1, $2, SNNULL); }
    |                       { $$ = EPSILON; }
    ;

statement
    : func_decl     { $$ = sn_alloc(SNT_STATEMENT, $1, SNNULL); }
    | func_def      { $$ = sn_alloc(SNT_STATEMENT, $1, SNNULL); }
    | func_call     { $$ = sn_alloc(SNT_STATEMENT, $1, SNNULL); }
    | return_stmt   { $$ = sn_alloc(SNT_STATEMENT, $1, SNNULL); }
    | block         { $$ = sn_alloc(SNT_STATEMENT, $1, SNNULL); }
    ;

func_call
    : IDENTIFIER '(' call_params ')' ';'    { $$ = sn_alloc(SNT_FUNC_CALL, $1, $3, SNNULL); }
    ;

call_params
    : expression _call_params   { $$ = sn_alloc(SNT_CALL_PARAMS, $1, $2, SNNULL); }
    |                           { $$ = EPSILON; }
    ;

_call_params
    : ',' expression _call_params   { $$ = sn_alloc(SNT_CALL_PARAMS, $2, $3, SNNULL); }
    |                               { $$ = EPSILON; }
    ;

return_stmt
    : RET ';'               { $$ = sn_alloc(SNT_RETURN_STMT, SNNULL); }
    | RET expression ';'    { $$ = sn_alloc(SNT_RETURN_STMT, $2, SNNULL); }
    ;

expression
    : IDENTIFIER    { $$ = sn_alloc(SNT_EXPRESSION, $1, SNNULL); }
    | QSTRING       { $$ = sn_alloc(SNT_EXPRESSION, $1, SNNULL); }
    | func_call     { $$ = sn_alloc(SNT_EXPRESSION, $1, SNNULL); }
    ;

%%
