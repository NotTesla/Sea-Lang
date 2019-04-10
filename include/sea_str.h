#ifndef __SEA_STR_H__
#define __SEA_STR_H__

enum SeaStrMem {
    HEAP,
    CONST,
    TOKEN,
};

struct SeaStr {
    enum SeaStrMem alloc;
    char* str;
};

struct SeaStr sea_hstr(struct SeaNode* node, ...);

struct SeaStr sea_cstr(char* buff);

struct SeaStr sea_tstr(char* buff);

void sea_str_free(struct SeaStr* str, ...);

#endif // __SEA_STR_H__
