#ifndef __MAINTYPE__
#define __MAINTYPE__

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef float    f32;
typedef double   f64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef size_t   usize;
typedef ssize_t  isize;

#define PI 3.14159265359f
#define TAU (2.0f * PI)
#define PI_2 (PI / 2.0f)
#define PI_4 (PI / 4.0f)

#define ZNEAR 0.0001f
#define ZFAR  128.0f

typedef struct v2_s { f32 x, y; } v2;
typedef struct v2i_s { i32 x, y; } v2i;

#define v2_to_v2i(_v) ({ __typeof__(_v) __v = (_v); (v2i) { __v.x, __v.y }; })
#define v2i_to_v2(_v) ({ __typeof__(_v) __v = (_v); (v2) { __v.x, __v.y }; })

#ifndef __BYTEBOOL__
#define __BYTEBOOL__

typedef enum {false, true} boolean;

#endif

#endif
