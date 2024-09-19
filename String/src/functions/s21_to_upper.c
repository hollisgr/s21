#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper;
  if (str == S21_NULL)
    return (char *)str;
  else {
    s21_size_t len = s21_strlen(str);
    upper = malloc((len + 1) * sizeof(char));
    for (s21_size_t i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 97 && str[i] <= 122) {
        upper[i] = str[i] - 32;
      } else
        upper[i] = str[i];
    }
    upper[len] = '\0';
  }
  return (char *)upper;
}
