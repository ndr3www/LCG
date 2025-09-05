#pragma once

#include <stddef.h>

#define LCG_CONST_M (1L << 48L)  // 2^48
#define LCG_CONST_A 25214903917
#define LCG_CONST_C 11
#define LCG_RAND_MAX (LCG_CONST_M - 1)

_BitInt(128) lcg_gen(_BitInt(128) number);
void lcg_randi(int* dest, size_t n, long seed, int min, int max);
void lcg_randf(float* dest, size_t n, long seed, float min, float max);
