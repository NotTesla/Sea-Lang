#ifndef __SEA_H__
#define __SEA_H__

#include <stdio.h>

// This is needed for lex
FILE *yyin;

void error_bad_token(const char *tok);

int yylex(void);
void yyerror(const char* msg);
int yywrap(void);

char* bin_to_hex(const char* bin_str);

#endif // __SEA_H__
