#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str;
  char *modsrc;
  if (!src)
    return S21_NULL;
  else {
    size_t srcLen = s21_strlen(src);
    if (!trim_chars) {
      modsrc = malloc(srcLen + 1 * sizeof(char));
      s21_strncpy(modsrc, src, srcLen);
      modsrc[srcLen] = '\0';
      return (char *)modsrc;
    } else {
      char *start = (char *)src;
      char *end = (char *)src + srcLen - 1;
      while (*start && s21_strchr(trim_chars, *start)) {
        start++;
      }
      while (end > start && s21_strchr(trim_chars, *end)) {
        end--;
      }
      new_str = malloc((end - start + 2) * sizeof(char));
      s21_memcpy(new_str, start, end - start + 1);
      new_str[end - start + 1] = '\0';
    }
  }
  return (char *)new_str;
}
