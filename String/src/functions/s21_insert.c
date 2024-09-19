#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *insert;
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;
  size_t i = 0, j = 0;
  size_t srcLen = s21_strlen(src);
  size_t strLen = s21_strlen(str);
  insert = malloc((strLen + srcLen + 1) * sizeof(char));
  if (start_index > srcLen || insert == S21_NULL) {
    free(insert);
    return S21_NULL;
  } else {
    while (i < start_index) {
      insert[i] = src[i];
      i++;
    }
    while (j < strLen) {
      insert[i] = str[j];
      j++;
      i++;
    }
    j = start_index;
    while (j < srcLen) {
      insert[i] = src[j];
      j++;
      i++;
    }
    insert[i] = '\0';
  }
  return (char *)insert;
}
