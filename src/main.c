#include <stdio.h>
#include <stdlib.h>

const long m = 1L << 32L;
const int a = 1664525;
const int c = 1013904223;

const int AMOUNT = 100;

int main() {
  printf("Enter seed: ");
  char input[100];
  fgets(input, sizeof(input), stdin);

  int numbers[AMOUNT];
  numbers[0] = strtol(input, NULL, 10);

  for (int i = 1; i < AMOUNT; ++i) {
    numbers[i] = (numbers[i - 1] * a + c) % m;
    printf("%d ", numbers[i]);
  }

  puts("");

  return 0;
}
