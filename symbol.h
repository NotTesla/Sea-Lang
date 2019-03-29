#ifndef __SYMBOL_H__
#define __SYMBOL_H__

// parsing
#define EOF     0x0000
#define ERROR   0x0001

// integer
#define I64     0x0010 // i64
#define I32     0x0011 // i32
#define I16     0x0012 // i16
#define I8      0x0013 // i8
#define U64     0x0014 // u64
#define U32     0x0015 // u32
#define U16     0x0016 // u16
#define U8      0x0017 // u8
#define UPTR    0x0018 // uptr, guaranteed to hold the size of a pointer
#define WCHR    0x0019 // wchr, wide character

// real
#define F64     0x0020 // f64
#define F32     0x0021 // f32

// preprocessor
#define INC     0x0030 // inc, import header
#define CDEF    0x0031 // cdef, compiletime constant
#define RDEF    0x0032 // rdef, runtime constant

// keywords
#define FUN     0x0040 // fun
#define STRUCT  0x0041 // struct
#define MUT     0x0042 // mut
#define LET     0x0043 // let
#define RET     0x0044 // ret
#define IF      0x0045 // if
#define ELSE    0x0046 // else
#define FOR     0x0047 // for
#define DO      0x0048 // do
#define WHILE   0x0049 // while

// blocks
#define OB      0x0050 // {
#define CB      0x0051 // }
#define OP      0x0052 // (
#define CP      0x0053 // )

// vars
#define ID      0x0060 // [a-zA-Z_][a-zA-Z0-9_]*
#define NUM     0x0061 // 0x[0-9A-Fa-f]+ | 0b[01]+ | [0-9]*(\.[0-9]+)?
#define STR     0x0062 // \"[^\"]*\"

// operators
#define SEMICOLON   0x0070 // ;
#define COMMA       0x0071 // ,
#define ADD         0x0072 // +
#define MIN         0x0073 // -
#define MULT        0x0074 // *
#define DIV         0x0075 // /
#define ASSIGN      0x0076 // =
#define COLON       0x0077 // &
#define DOT         0x0078 // .
#define QMARK       0x0079 // ?
#define NOT         0x007A // !
#define COMPLEMENT  0x007B // ~
#define SHL         0x007C // <<
#define SHR         0x007D // >>
#define EQUALITY    0x007E // ==
#define NEQUALITY   0x007F // !=

// assignment operators
#define ADD_EQ      0x0090 // +=
#define MIN_EQ      0x0091 // -=
#define MUL_EQ      0x0092 // *=
#define DIV_EQ      0x0093 // /=
#define SHL_EQ      0x0094 // <<=
#define SHR_EQ      0x0095 // >>=

#endif // __SYMBOL_H__
