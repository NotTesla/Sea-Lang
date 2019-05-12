%{
#include "sea.h"
#include "sea_translator.h"
#include "sea_scope.h"
#include <string>

#define EPSILON (sea_cstr(""))
%}

%code requires {

#include "sea_str.h"
}

%union {
    struct SeaStr str;
    std::string ing;
}

%token <str> IDENTIFIER QSTRING NUMBER

%token I8 I16 I32 I64 U8 U16 U32 U64 F32 F64

%token UWORD WORD CSTR BOOL TRUE FALSE PSIZE VOID
%token FN CAP DEF VAR RET IF ELSE VARGS
%token NAMESPACE INC_SEA_DEP INC_C_DEP

%token IS_EQ NOT_EQ LESS_EQ MORE_EQ
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ
%token SHL_EQ SHR_EQ AND_EQ XOR_EQ OR_EQ

%type <str> type option_type include
%type <ing> return_stmt
%type <str> expression
%type <ing> func_call call_params _call_params
%type <str> params _params param
%type <str> func
%type <str> block _statement statement

%left '+' '-'
%left '*' '/'
%left ELSE

%start program

%%

program
    : _global
    ;

_global
    : global _global
    |
    ;

global
    : func_def
    | func_decl
    | include
    ;

include
    : INC_C_DEP QSTRING
    {
        sea_c_dep(&$2.s[1]);
        $$ = EPSILON;
    }
    | INC_SEA_DEP IDENTIFIER
    {
        sea_sea_dep(&$2.s[1]);
        $$ = EPSILON;
    }
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
    | UWORD         { $$ = sea_cstr("unsigned int"); }
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
    : DEF IDENTIFIER FN '(' params ')' option_type
    {
        struct SeaStr decl = sea_fndecl($7.s, $2.s, $5.s);
        sea_forward_decl(&decl.s[1]);
        $$ = std::string(decl.s);
    }
    ;

func_def
    : func '=' block    { sea_func_def(&sea_hstr($1.s, $3.s, NULL).s[1]); }
    ;

func_decl
    : func ';'
    ;

params
    : param _params { $$ = $1 + $2.s; }
    |               { $$ = "void"; } 
    ;

_params
    : ',' param _params { $$ = ", " + $2 + $3); }
    |                   { $$ = ""; }
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
    : func_decl     { $$ = EPSILON; }
    | func_def      { $$ = EPSILON; }
    | func_call ';' { $$ = sea_hstr($1.s, ";", NULL); }
    | return_stmt   { $$ = $1; }
    | block         { $$ = $1; }
    ;

func_call
    : IDENTIFIER '(' call_params ')'    { $$ = sea_hstr(sea_getfndecl($1.s).s, "(", $3.s, ")", NULL); }
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
    : RET ';'           { $$ = "return;"; }
    | RET expression ';'{ $$ = "return " + $2.s + ";" }
    ;

expression
    : IDENTIFIER    { $$ = $1; }
    | NUMBER        { $$ = $1; }
    | QSTRING       { $$ = $1; }
    | func_call     { $$ = $1; }
    ;

%%
