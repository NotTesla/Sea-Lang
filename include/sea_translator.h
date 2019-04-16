#ifndef __SEA_TRANSLATOR_H__
#define __SEA_TRANSLATOR_H__

#include "sea_str.h"
#include <stdio.h>

void sea_translate(struct SeaStr program);

void sea_write_translation(FILE* out);

// convert a fixed width integer to the c equivalent
struct SeaStr sea_fint(int type);

#endif // __SEA_TRANSLATOR_H__
