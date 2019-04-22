#include "sea_translator.h"
#include "sea_debug.h"
#include "yyparser.h"

#include <stdio.h>

enum includes {
    inc_stdint,
    inc_stdio,
    inc_num,
};

int includes[] = {
    [inc_stdint] = 0,
    [inc_stdio] = 0,
};

const char* INCLUDE[] = {
    [inc_stdint] = "<stdint.h>",
    [inc_stdio]  = "<stdio.h>",
};

struct SeaStr p;

void sea_translate(struct SeaStr program) {
    p = program;
}

void sea_write_translation(FILE* out) {
    for (int i = 0; i < inc_num; ++i) {
        if (includes[i])
            fprintf(out, "#include %s\n", INCLUDE[i]);
    }

    fprintf(out, "%s", &p.s[1]);
}

struct SeaStr sea_fint(int type) {
    includes[inc_stdint] = 1;
    switch(type) {
    case I8:
        return sea_cstr("int8_t");
    case I16:
        return sea_cstr("int16_t");
    case I32:
        return sea_cstr("int32_t");
    case I64:
        return sea_cstr("int64_t");
    case U8:
        return sea_cstr("uint8_t");
    case U16:
        return sea_cstr("uint16_t");
    case U32:
        return sea_cstr("uint32_t");
    case U64:
        return sea_cstr("uint64_t");
    default:
        fprintf(stderr, SEA_DBG("unrecognized fixed-with type id (%d)"), type);
        return sea_cstr("int");
    }
}
