#include <stdio.h>

#include "lcg.h"

int main() {
  printf("Seed: ");
  char seed[100];
  fgets(seed, sizeof(seed), stdin);

  const long SEED = strtol(seed, NULL, 10);

  printf("How many numbers: ");
  char n[100];
  fgets(n, sizeof(n), stdin);

  const size_t N = strtol(n, NULL, 10);

  long long numbers[N];
  lcg_gen(numbers, N, SEED);

  for (size_t i = 0; i < N; ++i) {
    printf("%llu ", numbers[i]);
  }

  puts("");

  return 0;
}
