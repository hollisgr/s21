#include "s21_string.h"

void *s21_memcpy(void *dst, const void *src, s21_size_t n) {
  const char *sourceString = src;
  char *destinationString = dst;
  for (s21_size_t i = 0; i < n; i++) {
    destinationString[i] = sourceString[i];
  }
  return destinationString;
}
