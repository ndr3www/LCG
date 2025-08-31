#pragma once

#include <stddef.h>

void lcg_gen(_BitInt(128)* dest, size_t n, long seed);
