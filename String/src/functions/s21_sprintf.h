#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define is_flag(ch) \
  ((ch) == '-' || (ch) == '+' || (ch) == ' ' || (ch) == '#' || (ch) == '0')
#define is_len(ch) ((ch) == 'h' || (ch) == 'l' || (ch) == 'L')
#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')
#define is_octal_digit(ch) ((ch) >= '0' && (ch) <= '7')
#define is_hex_digit(ch)                                                      \
  (((ch) >= '0' && (ch) <= '9') || (ch) == 'a' || (ch) == 'b' ||              \
   (ch) == 'c' || (ch) == 'd' || (ch) == 'e' || (ch) == 'f' || (ch) == 'A' || \
   (ch) == 'B' || (ch) == 'C' || (ch) == 'D' || (ch) == 'E' || (ch) == 'F')

#define format_flag(ch)                                                       \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'f' || (ch) == 's' || \
   (ch) == 'u' || (ch) == 'g' || (ch) == 'G' || (ch) == 'e' || (ch) == 'E' || \
   (ch) == 'x' || (ch) == 'X' || (ch) == 'o' || (ch) == 'n' || (ch) == 'p')

#define format_long(ch) ((ch) == 'h' || (ch) == 'l' || (ch) == 'L')

#define format_fat(ch) (((ch) >= '0' && (ch) <= '9') || (ch) == '*')

typedef struct {
  int width;
  int precision;
  char len;
  char spec;
  int flag_error;
  int flag_sharp;
  int flag_zero;
  int flag_minus;
  int flag_space;
  int flag_plus;
} FORMAT;

void init_format(FORMAT *fParams) {
  fParams->width = -1;
  fParams->precision = -1;
  fParams->len = '\0';
  fParams->spec = '\0';
  fParams->flag_error = 0;
  fParams->flag_sharp = 0;
  fParams->flag_zero = 0;
  fParams->flag_minus = 0;
  fParams->flag_space = 0;
  fParams->flag_plus = 0;
}

char *d_class_to_str(char *str, long double x, int accuracy);
void s21_flag_parser(const char **format, va_list *argList, FORMAT *fParams);
void s21_flag_set(FORMAT *fParams, const char *format);
char *s21_main_func(char *str, s21_size_t *str_len, FORMAT *fParams,
                    va_list *argList);
char *s21_format_param_to_str(char *str, s21_size_t *str_len, FORMAT *fParams,
                              va_list *p_arg);
void s21_set_flag(FORMAT *fParams, const char *format);
char *s21_str_to_int(const char *format, int *number, va_list *p_arg);
char *s21_to_str_f(char *str, va_list *argList, FORMAT *fParams);
char *s21_to_str_lf(char *str, long double number, FORMAT *fParams);
char *s21_to_str_s(char *str, va_list *argList, FORMAT *fParams);
char *s21_to_str_c(char *str, va_list *argList, FORMAT *fParams);
char *s21_to_str_wc(char *str, wchar_t *wstr, s21_size_t len);
char *wch_to_str(char *str, wchar_t *wstr, s21_size_t len);
char *s21_to_str_u(char *str, va_list *argList, FORMAT *fParams);
char *s21_to_str_d(char *str, va_list *argList, FORMAT *fParams);
char *s21_to_str_o(char *str, va_list *argList, FORMAT *fParams);
char *s21_to_str_xX(char *str, va_list *argList, FORMAT *fParams);
char *s21_string_of_s(char *str, va_list *p_arg, FORMAT *fParams);
char *s21_string_of_f(char *str, va_list *p_arg, FORMAT *fParams);
char *s21_string_of_c(char *str, va_list *p_arg, FORMAT *fParams);
char *s21_string_of_u(char *str, va_list *p_arg, FORMAT *fParams);
char *s21_string_of_d(char *str, va_list *p_arg, FORMAT *fParams);
char *s21_string_of_o(char *str, va_list *p_arg, FORMAT *fParams);
char *s21_string_of_xX(char *str, va_list *p_arg, FORMAT *fParams);
char *s21_ll_accuracy(char *str, FORMAT *fParams);
char *s21_lf_width_flag(char *str, FORMAT *fParams);
char *s21_ll_width_flag(char *str, FORMAT *fParams);
char *s21_blankplus_flag(char *str, FORMAT *fParams);
char *s21_ll_precis_flag(char *str, FORMAT *fParams);
char *s21_ld_to_a(char *str, long double number, FORMAT *fParams);
char *s21_sign_flag(char *str, FORMAT *fParams);
char *s21_lf_to_str(char *str, long double number, FORMAT *fParams);
char *s21_ll_to_str(char *str, long long number);
char *s21_ul_to_str(char *str, unsigned long long number);
char *s21_ol_to_str(char *str, unsigned long long number, int prefix);
char *s21_hl_to_str(char *str, unsigned long long number, FORMAT *fParams);
char *s21_s_to_i(const char *format, int *number, va_list *argList);
char *s21_reverse_str(char *str);
char *s21_ld_to_e(char *str, long double number, FORMAT *fParams);
char *s21_e_exceptions(char *str, long double x, int accuracy);
long double s21_round(long double x, int accuracy);
char *s21_strcat(char *destination, const char *source);
char *s21_strcpy(char *destination, const char *source);

char *s21_strcat(char *destination, const char *source) {
  char *ptr = destination + s21_strlen(destination);
  while (*source != '\0') {
    *ptr++ = *source++;
  }
  *ptr = '\0';
  return destination;
}

char *s21_strcpy(char *destination, const char *source) {
  char *ptr = destination;
  while (*source != '\0') {
    *ptr++ = *source++;
  }
  *ptr = '\0';
  return destination;
}

#endif  // SRC_S21_STRING_H_
