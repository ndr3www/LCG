#include "lcg.h"

void lcg_gen(unsigned _BitInt(128)* dest, size_t n, long seed) {
  dest[0] = seed;

  for (size_t i = 1; i < n; ++i) {
    dest[i] = (dest[i - 1] * LCG_CONST_A + LCG_CONST_C) % LCG_CONST_M;
  }
}
