%{
#include "sea.h"
#include "sea_translator.h"
#include "sea_scope.h"

#define EPSILON (sea_cstr(""))
%}

%code requires {

#include "sea_str.h"
}

%union {
    struct SeaStr str;
}

%token <str> IDENTIFIER QSTRING NUMBER CINCLUDE

%token I8 I16 I32 I64 U8 U16 U32 U64 F32 F64

%token WORD CSTR BOOL TRUE FALSE PSIZE VOID
%token FN CAP DEF VAR RET IF ELSE VARGS
%token NAMESPACE

%token IS_EQ NOT_EQ LESS_EQ MORE_EQ
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ
%token SHL_EQ SHR_EQ AND_EQ XOR_EQ OR_EQ

%type <str> global _global type option_type include
%type <str> return_stmt expression
%type <str> func_call call_params _call_params
%type <str> params _params param
%type <str> func func_decl func_def
%type <str> block _statement statement

%left '+' '-'
%left '*' '/'
%left ELSE

%start program

%%

program
    : _global   { sea_translate($1); }
    ;

_global
    : global _global    { $$ = sea_hstr($1.s, $2.s, NULL); }
    |                   { $$ = EPSILON; }
    ;

global
    : func_def  { $$ = $1; }
    | func_decl { $$ = $1; }
    | include   { $$ = $1; }
    ;

include
    : CINCLUDE QSTRING { $$ = sea_hstr("#include ", $2.s, "\n", NULL); }
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

option_type
    : type  { $$ = $1; }
    |       { $$ = sea_cstr("void"); }
    ;

func
    : DEF IDENTIFIER '=' FN '(' params ')' option_type    { $$ = sea_fndecl($8.s, $2.s, $6.s); }
    ;

func_def
    : func block    { $$ = sea_hstr($1.s, $2.s, NULL); }
    ;

func_decl
    : func ';'  { $$ = sea_hstr($1.s, ";", NULL); }
    ;

params
    : param _params { $$ = sea_hstr($1.s, $2.s, NULL); }
    |               { $$ = sea_cstr("void"); } 
    ;

_params
    : ',' param _params { $$ = sea_hstr(", ", $2.s, $3.s, NULL); }
    |                   { $$ = EPSILON; }
    ;

param
    : IDENTIFIER type VARGS { $$ = sea_hstr($2.s, " ", $1.s, "...", NULL); }
    | IDENTIFIER type       { $$ = sea_hstr($2.s, " ", $1.s, NULL); }
    | type                  { $$ = $1; }
    ;

block
    : '{' _statement '}'       { $$ = sea_hstr("{\n", $2.s, "}\n", NULL); }
    ;

_statement
    : statement _statement  { $$ = sea_hstr($1.s, "\n", $2.s, NULL); }
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
    : IDENTIFIER '(' call_params ')' ';'    { $$ = sea_hstr(sea_getfndecl($1.s).s, "(", $3.s, ");", NULL); }
    ;

call_params
    : expression _call_params   { $$ = sea_hstr($1.s, $2.s, NULL); }
    |                           { $$ = EPSILON; }
    ;

_call_params
    : ',' expression _call_params   { $$ = sea_hstr(", ", $2.s, $3.s, NULL); }
    |                               { $$ = EPSILON; }
    ;

return_stmt
    : RET ';'               { $$ = sea_cstr("return;"); }
    | RET expression ';'    { $$ = sea_hstr("return ", $2.s, ";", NULL); }
    ;

expression
    : IDENTIFIER    { $$ = $1; }
    | NUMBER        { $$ = $1; }
    | QSTRING       { $$ = $1; }
    | func_call     { $$ = $1; }
    ;

%%
