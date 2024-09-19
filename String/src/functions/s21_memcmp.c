#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *string1 = str1;
  const char *string2 = str2;
  if (n != 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (string1[i] != string2[i]) return (string1[i] - string2[i]);
    }
  }
  return 0;
}
