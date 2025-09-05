#pragma once

#include <stddef.h>

#define LCG_CONST_M (1L << 48L)  // 2^48
#define LCG_CONST_A 25214903917
#define LCG_CONST_C 11
#define LCG_RAND_MAX (LCG_CONST_M - 1)

// Core formula of the linear congruential generator
_BitInt(128) lcg_gen(_BitInt(128) number);

// Generates a pseudorandom series of integers of size n in the range [min, max)
// and stores the results in the dest array
void lcg_randi(int* dest, size_t n, long seed, int min, int max);

// Generates a pseudorandom series of floating-point numbers of size n in the range (min, max)
// and stores the results in the dest array
void lcg_randf(float* dest, size_t n, long seed, float min, float max);
