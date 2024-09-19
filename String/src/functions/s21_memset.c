#include "s21_string.h"

void *s21_memset(void *dst, int c, s21_size_t n) {
  char *destinationString = dst;
  for (s21_size_t i = 0; i < n; i++) destinationString[i] = c;
  return destinationString;
}