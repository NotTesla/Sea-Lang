%{
#include "sea.h"
%}

%union {
    int i;
    char* s;
};

%token <s> IDENTIFIER STR
%token INT VOID
%token RETURN

%left '+' '-'
%left '*' '/'

%start program

%%

program
    : func_decl_def program
    | func_decl_def
    ;

type
    : IDENTIFIER
    | INT
    ;

func_decl_def
    : type IDENTIFIER '(' params ')' block
    | VOID IDENTIFIER '(' params ')' block
    ;

params
    : param _params
    | VOID
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
    : func_decl_def
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
    : RETURN ';'
    | RETURN expression ';'
    ;

expression
    : IDENTIFIER
    | STR
    | func_call
    ;

%%
