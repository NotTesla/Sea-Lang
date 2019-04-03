#ifndef __SEA_COMPILER_H__
#define __SEA_COMPILER_H__

#include <stdio.h>

struct SeaNode;

void sea_translate(struct SeaNode* program);

void sea_write_translation(FILE* out);

#endif // __SEA_COMPILER_H__