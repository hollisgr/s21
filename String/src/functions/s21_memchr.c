#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *string = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (string[i] == c) {
      return (string + i);
    }
  }
  return S21_NULL;
}
