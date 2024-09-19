#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define EPS 1E-6
#define S21_NULL (void *)0
typedef long unsigned s21_size_t;

// Part 1
s21_size_t s21_strcspn(const char *str, const char *delim);
void *s21_strchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *restrict str, const char *restrict sep);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strcat(char *destination, const char *source);
char *s21_strcpy(char *destination, const char *source);
void *s21_memset(void *ptr, int value, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strerror(int errnum);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
// Part 2 + BONUS 3
int s21_sprintf(char *str, const char *format, ...);
// BONUS 4
int s21_sscanf(const char *str, const char *format, ...);
// BONUS 5
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
#endif  // SRC_S21_STRING_H_
