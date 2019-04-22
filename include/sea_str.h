#ifndef __SEA_STR_H__
#define __SEA_STR_H__

#define CHEAP 1

enum SeaStrMem {
    STR_HEAP,
    STR_TOKEN,
    STR_CONST,
};

struct SeaStr {
    enum SeaStrMem alloc;
    char* s;
};

struct SeaStr sea_hstr(char* node, ...);

struct SeaStr sea_tstr(char* str);

struct SeaStr sea_cstr(const char* str);

void sea_str_free(struct SeaStr* str, ...);

#endif // __SEA_STR_H__
