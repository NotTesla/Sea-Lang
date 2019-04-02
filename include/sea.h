#ifndef __SEA_H__
#define __SEA_H__

#include "sea_node.h"

void error_bad_token(const char *tok);

int yylex(void);
void yyerror(const char* msg);
int yywrap(void);

#endif // __SEA_H__
