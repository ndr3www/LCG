#pragma once

#include <stddef.h>

const long M = 1L << 48L;  // 2^48
const long A = 25214903917;
const long C = 11;

void lcg_gen(__int128* dest, size_t n, long seed) {
  dest[0] = seed;

  for (size_t i = 1; i < n; ++i) {
    dest[i] = (dest[i - 1] * A + C) % M;
  }
}
