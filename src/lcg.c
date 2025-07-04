#include "lcg.h"

enum { VAR_SIZE = sizeof(int) };
const long M = 1L << 32L;

int read_urandom(char* dest, size_t n) {
  int urandom_fd = open("/dev/urandom", O_RDONLY);
  if (urandom_fd < 0) {
    return -1;
  }

  size_t total = 0;
  
  while (total < n) {
    ssize_t bytes_read = read(urandom_fd, dest + total, n - total);

    if (bytes_read < 0) {
      close(urandom_fd);
      return -2;
    }
    else if (bytes_read == 0) {
      close(urandom_fd);
      return -3;
    }

    total += bytes_read;
  }

  close(urandom_fd);

  return 0;
}

// TODO: implement Hull-Dobell conditions for M, A and C
int lcg_gen(long long* dest, size_t n, long seed) {
  union A_union {
    char bytes[VAR_SIZE];
    int value;
  } A;

  if (read_urandom(&A.bytes[0], VAR_SIZE) < 0) {
    return -1;
  }

  union C_union {
    char bytes[VAR_SIZE];
    int value;
  } C;

  if (read_urandom(&C.bytes[0], VAR_SIZE) < 0) {
    return -2;
  }

  dest[0] = seed;

  for (size_t i = 1; i < n; ++i) {
    dest[i] = (dest[i - 1] * A.value + C.value) % M;
  }

  return 0;
}
