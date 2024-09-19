#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  int rez = 0;
  va_start(args, format);

  while (*format != '\0') {
    char form_flag = {'0'};
    char form_fat = {'0'};
    char form_long = {'0'};
    int form_count = 0;

    if (*format == '%') {
      for (int i = 1; format[i] != '%' && format[i] != ' ' && format[i] != '\0';
           i++) {
        if (format_flag(format[i])) form_flag = format[i];
        if (is_len(format[i])) form_long = format[i];
        if (format_fat(format[i])) {
          if (format[i] == '*')
            form_fat = format[i];
          else if (is_digit(format[i])) {
            form_fat = 'q';
            form_count = (form_count * 10) + (format[i] - '0');
          }
        }
      }
    }

    switch (form_flag) {
      case 'd':
      case 'i':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        if (form_long == 'h')
          rez += get_short_d_format(str, args, form_fat, form_count);
        else if (form_long == 'l')
          rez += get_long_d_format(str, args, form_fat, form_count);
        else
          rez += get_d_format(str, args, form_fat, form_count);
        while (is_digit(*str)) {
          str++;
          form_count--;
          if (form_fat == 'q' && form_count <= 0) break;
        }
        break;
      case 'u':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        if (form_long == 'h')
          rez += get_short_u_format(str, args, form_fat, form_count);
        else if (form_long == 'l')
          rez += get_long_u_format(str, args, form_fat, form_count);
        else
          rez += get_u_format(str, args, form_fat, form_count);
        while (is_digit(*str)) {
          str++;
          form_count--;
          if (form_fat == 'q' && form_count <= 0) break;
        }
        break;
      case 'x':
      case 'X':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        if (form_long == 'h')
          rez += get_short_u_format(str, args, form_fat, form_count);
        else if (form_long == 'l')
          rez += get_long_u_format(str, args, form_fat, form_count);
        else
          rez += get_hex_u_format(str, args, form_fat, form_count);
        while (is_hex_digit(*str)) {
          str++;
          form_count--;
          if (form_fat == 'q' && form_count <= 0) break;
        }
        break;
      case 'o':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        if (form_long == 'h')
          rez += get_short_u_format(str, args, form_fat, form_count);
        else if (form_long == 'l')
          rez += get_long_u_format(str, args, form_fat, form_count);
        else
          rez += get_octo_u_format(str, args, form_fat, form_count);
        while (is_octal_digit(*str)) {
          str++;
          form_count--;
          if (form_fat == 'q' && form_count <= 0) break;
        }
        break;
      case 'p':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        rez += get_p_format(str, args, form_fat, form_count);
        while (is_hex_digit(*str)) {
          str++;
          form_count--;
          if (form_fat == 'q' && form_count <= 0) break;
        }
        break;
      case 'f':
      case 'e':
      case 'E':
      case 'g':
      case 'G':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        if (form_long == 'l')
          rez += get_double_f_format(str, args, form_fat, form_count);
        else if (form_long == 'L')
          rez += get_long_double_f_format(str, args, form_fat, form_count);
        else
          rez += get_f_format(str, args, form_fat, form_count);
        while (is_digit(*str) || *str == '.') {
          str++;
          form_count--;
          if (form_fat == 'q' && form_count <= 0) break;
        }
        break;
      case 'c':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        rez += get_c_format(str, args, form_fat);
        str++;
        break;
      case 's':
        while (*str == ' ' || *str == '\n' || *str == '\t') str++;
        rez += get_s_format(str, args, form_fat, form_count);
        while (*str != ' ' && *str != '\0') {
          str++;
          form_count--;
          if (form_fat == 'q' && form_count <= 0) break;
        }
        break;
      default:
        break;
    }
    format++;
  }
  va_end(args);
  return rez;
}

int get_d_format(const char *str, va_list args, char form_fat, int form_count) {
  int positive = 1;
  int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str)) {
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    int *valp = va_arg(args, int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_short_d_format(const char *str, va_list args, char form_fat,
                       int form_count) {
  int positive = 1;
  short int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str)) {
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    short int *valp = va_arg(args, short int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_long_d_format(const char *str, va_list args, char form_fat,
                      int form_count) {
  int positive = 1;
  long int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str)) {
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    long int *valp = va_arg(args, long int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_u_format(const char *str, va_list args, char form_fat, int form_count) {
  int positive = 1;
  unsigned int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str)) {
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    unsigned int *valp = va_arg(args, unsigned int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}
int get_hex_u_format(const char *str, va_list args, char form_fat,
                     int form_count) {
  int positive = 1;
  unsigned int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_hex_digit(*str)) {
    value = (value * 16) - from_hex_to_dec(*str);
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    unsigned int *valp = va_arg(args, unsigned int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}
int get_octo_u_format(const char *str, va_list args, char form_fat,
                      int form_count) {
  int positive = 1;
  unsigned int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_octal_digit(*str)) {
    value = (value * 8) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    unsigned int *valp = va_arg(args, unsigned int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_short_u_format(const char *str, va_list args, char form_fat,
                       int form_count) {
  int positive = 1;
  unsigned short int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str)) {
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    unsigned short int *valp = va_arg(args, unsigned short int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_long_u_format(const char *str, va_list args, char form_fat,
                      int form_count) {
  int positive = 1;
  unsigned long int value = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str)) {
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    unsigned long int *valp = va_arg(args, unsigned long int *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_f_format(const char *str, va_list args, char form_fat, int form_count) {
  int positive = 1;
  float value = 0;
  int dote = 0;
  int count = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str) || *str == '.') {
    if (*str == '.') {
      dote = 1;
      str++;
      form_count--;
    }
    if (dote) count++;
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  for (int i = 0; i < count; i++) value = value / 10;
  if (form_fat != '*') {
    float *valp = va_arg(args, float *);
    *valp = (float)value;
    if (*valp) rez++;
  }
  return rez;
}

int get_double_f_format(const char *str, va_list args, char form_fat,
                        int form_count) {
  int positive = 1;
  double value = 0;
  int dote = 0;
  int count = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str) || *str == '.') {
    if (*str == '.') {
      dote = 1;
      str++;
      form_count--;
    }
    if (dote) count++;
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  for (int i = 0; i < count; i++) value = value / 10;
  if (form_fat != '*') {
    double *valp = va_arg(args, double *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_long_double_f_format(const char *str, va_list args, char form_fat,
                             int form_count) {
  int positive = 1;
  long double value = 0;
  int dote = 0;
  int count = 0;
  int rez = 0;
  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }
  while (is_digit(*str) || *str == '.') {
    if (*str == '.') {
      dote = 1;
      str++;
      form_count--;
    }
    if (dote) count++;
    value = (value * 10) - (*str - '0');
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  for (int i = 0; i < count; i++) value = value / 10;
  if (form_fat != '*') {
    long double *valp = va_arg(args, long double *);
    *valp = value;
    if (*valp) rez++;
  }
  return rez;
}

int get_c_format(const char *str, va_list args, char form_fat) {
  int rez = 0;
  char value[512] = {'0'};
  value[0] = str[0];
  if (value[1]) value[1] = '\0';
  if (form_fat != '*') {
    char *valp = (char *)va_arg(args, char *);
    *valp = *value;
    if (*valp) rez++;
  }
  return rez;
}

int get_s_format(const char *str, va_list args, char form_fat, int form_count) {
  int rez = 0;
  int i = 0;
  if (form_fat != '*') {
    char *valp = va_arg(args, char *);
    do {
      valp[i] = *str;
      str++;
      i++;
      valp[i] = '\0';
      form_count--;
      if (form_fat == 'q' && form_count <= 0) break;
    } while (*str != ' ' && *str != '\0');
    if (*valp) rez++;
  }
  return rez;
}

int get_p_format(const char *str, va_list args, char form_fat, int form_count) {
  int rez = 0;
  void **valp = va_arg(args, void *);
  long value = 0;
  void *p = S21_NULL;
  int positive = 1;

  if (*str == '-') {
    positive = 0;
    str++;
  } else if (*str == '+') {
    positive = 1;
    str++;
  }

  while (is_hex_digit(*str)) {
    value = (value * 16) - from_hex_to_dec(*str);
    str++;
    form_count--;
    if (form_fat == 'q' && form_count <= 0) break;
  }
  if (positive) value = -value;
  if (form_fat != '*') {
    p = (void *)value;
    *valp = p;
    if (*valp) rez++;
  }
  return rez;
}

int from_hex_to_dec(const char str) {
  int rez;
  if (is_digit(str)) {
    rez = str - '0';
  } else {
    switch (str) {
      case 'a':
      case 'A':
        rez = 10;
        break;
      case 'b':
      case 'B':
        rez = 11;
        break;
      case 'c':
      case 'C':
        rez = 12;
        break;
      case 'd':
      case 'D':
        rez = 13;
        break;
      case 'e':
      case 'E':
        rez = 14;
        break;
      case 'f':
      case 'F':
        rez = 15;
        break;
    }
  }
  return rez;
}
