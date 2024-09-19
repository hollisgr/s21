#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include "s21_string.h"

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
#define format_fat(ch) (((ch) >= '0' && (ch) <= '9') || (ch) == '*')

int get_d_format(const char *str, va_list args, char form_fat, int form_count);
int get_u_format(const char *str, va_list args, char form_fat, int form_count);
int get_short_d_format(const char *str, va_list args, char form_fat,
                       int form_count);
int get_short_u_format(const char *str, va_list args, char form_fat,
                       int form_count);
int get_long_d_format(const char *str, va_list args, char form_fat,
                      int form_count);
int get_long_u_format(const char *str, va_list args, char form_fat,
                      int form_count);
int get_f_format(const char *str, va_list args, char form_fat, int form_count);
int get_double_f_format(const char *str, va_list args, char form_fat,
                        int form_count);
int get_long_double_f_format(const char *str, va_list args, char form_fat,
                             int form_count);
int get_c_format(const char *str, va_list args, char form_fat);
int get_s_format(const char *str, va_list args, char form_fat, int form_count);
int get_p_format(const char *str, va_list args, char form_fat, int form_count);
int get_hex_u_format(const char *str, va_list args, char form_fat,
                     int form_count);
int get_octo_u_format(const char *str, va_list args, char form_fat,
                      int form_count);

int from_hex_to_dec(const char str);

#endif  // SRC_S21_STRING_H_
