#include "lcg.h"

_BitInt(128) lcg_gen(_BitInt(128) number) {
  return (number * LCG_CONST_A + LCG_CONST_C) % LCG_CONST_M;
}

void lcg_randi(int* dest, size_t n, long seed, int min, int max) {
  _BitInt(128) numbers[n];
  numbers[0] = lcg_gen(seed);

  for (size_t i = 1; i < n; ++i) {
    numbers[i] = lcg_gen(numbers[i - 1]);
  }

  for (size_t i = 0; i < n; ++i) {
    dest[i] = min + numbers[i] / (LCG_RAND_MAX / (max - min));
  }
}

void lcg_randf(float* dest, size_t n, long seed, float min, float max) {
  _BitInt(128) numbers[n];
  numbers[0] = lcg_gen(seed);

  for (size_t i = 1; i < n; ++i) {
    numbers[i] = lcg_gen(numbers[i - 1]);
  }

  for (size_t i = 0; i < n; ++i) {
    dest[i] = min + (float)numbers[i] / ((float)LCG_RAND_MAX / (max - min));
  }
}
