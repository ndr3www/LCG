#pragma once

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int read_urandom(char* dest, size_t n);

int lcg_gen(long long* dest, size_t n, long seed);
