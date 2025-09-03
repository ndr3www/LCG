#include "lcg.h"

unsigned _BitInt(128) lcg_proc(unsigned _BitInt(128) number) {
  return (number * LCG_CONST_A + LCG_CONST_C) % LCG_CONST_M;
}

void lcg_gen(unsigned _BitInt(128)* dest, size_t n, long seed) {
  dest[0] = lcg_proc(seed);

  for (size_t i = 1; i < n; ++i) {
    dest[i] = lcg_proc(dest[i - 1]);
  }
}
