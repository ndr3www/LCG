/*
MIT License

Copyright (c) 2025 ndr3www

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
