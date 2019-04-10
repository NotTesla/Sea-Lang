%{
#include "sea.h"
#include "sea_node.h"
#include "sea_internal.h"
#include <stdio.h>

#define S(str) sea_cterm(str)
%}

%union {
    struct SeaNode* node;
}

%token <str> IDENTIFIER QSTRING NUMBER

%token I8 I16 I32 I64 U8 U16 U32 U64 F32 F64

%token WORD CSTR BOOL TRUE FALSE PSIZE VOID
%token CAP MUT RET IF ELSE VARGS

%token IS_EQ NOT_EQ LESS_EQ MORE_EQ
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ
%token SHL_EQ SHR_EQ AND_EQ XOR_EQ OR_EQ


%type <node> global _global type
%type <node> return_stmt expression
%type <node> func_call call_params _call_params
%type <node> params _params param
%type <node> func func_decl func_def
%type <node> block _statement statement

%left '+' '-'
%left '*' '/'
%left ELSE

%start program

%%

program
    : _global   { sea_translate($1); }
    ;

_global
    : global _global    { $$ = sea_nonterm($1, $2, NULL); }
    |                   { $$ = EPSILON; } 
    ;

global
    : func_def  { $$ = $1; }
    | func_decl { $$ = sea_nonterm($1); }
    ;

type
    : IDENTIFIER    { $$ = $1; }
    | I8            { $$ = sea_fint(I8); }
    | I16           { $$ = sea_fint(I16); }
    | I32           { $$ = sea_fint(I32); }
    | I64           { $$ = sea_fint(I64); }
    | U8            { $$ = sea_fint(I8); }
    | U16           { $$ = sea_fint(I16); }
    | U32           { $$ = sea_fint(I32); }
    | U64           { $$ = sea_fint(I64); }
    | F32           { $$ = sea_cstr("float"); }
    | F64           { $$ = sea_cstr("double"); }
    | WORD          { $$ = sea_cstr("int"); }
    | CSTR          { $$ = sea_cstr("const char*"); }
    | BOOL          { $$ = sea_cstr("char"); }
    | PSIZE         { $$ = sea_cstr("size_t"); }
    | VOID          { $$ = sea_cstr("void"); }
    ;

func
    : type IDENTIFIER '(' params ')'    { $$ = sea_hstr($1, $2, S("("), $4, S(")"), NULL); }
    ;

func_def
    : func block    { $$ = sea_nonterm($1, $2); }
    ;

func_decl
    : func ';'  { $$ = sea_hstr($1, S(";"), NULL); }
    ;

params
    : param _params { $$ = sea_hstr($1, $2, NULL); }
    |               { $$ = EPSILON; } 
    ;

_params
    : ',' param _params { $$ = sea_hstr(S(", "), $2, $3, NULL); }
    | VARGS             { $$ = sea_cstr(S("..."));}
    |                   { $$ = EPSILON; }
    ;

param
    : type IDENTIFIER   { $$ = sea_hstr($1, $2, NULL); }
    | type              { $$ = $1; }
    ;

block
    : '{' _statement '}'       { $$ = sea_nonterm(sea_cstr("{"), $2); }
    ;

_statement
    : statement _statement  { $$ = sea_nonterm($1, $2); }
    |                       { $$ = EPSILON; }
    ;

statement
    : func_decl     { $$ = $1; }
    | func_def      { $$ = $1; }
    | func_call     { $$ = $1; }
    | return_stmt   { $$ = $1; }
    | block         { $$ = $1; }
    ;

func_call
    : IDENTIFIER '(' call_params ')' ';'    { $$ = sea_hstr($1, S("("), $3, S(");"), NULL); }
    ;

call_params
    : expression _call_params   { $$ = sea_hstr($1, $2, NULL); }
    |                           { $$ = EPSILON; }
    ;

_call_params
    : ',' expression _call_params   { $$ = sea_hstr(S(", "), $2, $3, NULL); }
    |                               { $$ = EPSILON; }
    ;

return_stmt
    : RET ';'               { $$ = sea_cstr("return;"); }
    | RET expression ';'    { $$ = sea_hstr(S("return "), $2, S(";"), NULL); }
    ;

expression
    : IDENTIFIER    { $$ = $1; }
    | QSTRING       { $$ = $1; }
    | func_call     { $$ = $1; }
    ;

%%
