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

#include "lcg.h"

_BitInt(128) lcg_gen(_BitInt(128) number) {
  return (number * LCG_CONST_A + LCG_CONST_C) % LCG_CONST_M;
}

void lcg_randi(int* dest, size_t n, long seed, int min, int max) {
  _BitInt(128) numbers[n];
  numbers[0] = lcg_gen(seed);
  dest[0] = min + numbers[0] / (LCG_RAND_MAX / (max - min));
  
  for (size_t i = 1; i < n; ++i) {
    numbers[i] = lcg_gen(numbers[i - 1]);
    dest[i] = min + numbers[i] / (LCG_RAND_MAX / (max - min));
  }
}

void lcg_randf(float* dest, size_t n, long seed, float min, float max) {
  _BitInt(128) numbers[n];
  numbers[0] = lcg_gen(seed);
  dest[0] = min + (float)numbers[0] / ((float)LCG_RAND_MAX / (max - min));
  
  for (size_t i = 1; i < n; ++i) {
    numbers[i] = lcg_gen(numbers[i - 1]);
    dest[i] = min + (float)numbers[i] / ((float)LCG_RAND_MAX / (max - min));
  }
}
