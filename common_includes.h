// cpp_playground.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define local_persist static
#define internal static
#define global_variable static

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef size_t usize;
typedef intmax_t isize;

#define Bit (1)
#define Byte (Bit)
#define Kilobyte (Byte * 1024)
#define Megabyte (Kilobyte * 1024)
#define Gigabyte (Megabyte * 1024)
// TODO: Reference additional headers your program requires here.
