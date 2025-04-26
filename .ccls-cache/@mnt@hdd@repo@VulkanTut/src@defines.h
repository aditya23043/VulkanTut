#pragma once

#define TRUE 1
#define FALSE 0

// Unsigned int types.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types.

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types

typedef float f32;
typedef double f64;

// Boolean types

typedef int b32;
typedef char b8;

#ifdef KEXPORT
#define KAPI __attribute__((visibility("default")))
#else
#define KAPI
#endif
