#include "s21_decimal.h"

// void s21_print_binary(int n) {
//   int count = 1;
//   for (int i = 31; i >= 0; i--) {
//     printf("%d", (n >> i) & 1);
//     count++;
//   }
//   printf(" ");
// }

// void s21_print_decimal(s21_decimal n) {
//   for (int i = 3; i >= 0; i--) {
//     s21_print_binary(n.bits[i]);
//   }
//   printf("\n");
// }

// void s21_print_big_decimal(s21_big_decimal n) {
//   for (int i = 7; i >= 0; i--) {
//     s21_print_binary(n.bits[i]);
//   }
//   printf("\n");
// }

// void s21_right_shift(s21_decimal *value) {
//   for (int i = 0; i < 3; i++) {
//     value->bits[i] /= 2;
//   }
// }

void s21_convert_to_big_decimal(s21_decimal value_1, s21_big_decimal *value_2) {
  s21_zero_big_decimal(value_2);
  value_2->bits[0] = value_1.bits[0];
  value_2->bits[1] = value_1.bits[1];
  value_2->bits[2] = value_1.bits[2];
}

void s21_convert_to_decimal(s21_big_decimal value_1, s21_decimal *value_2) {
  value_2->bits[0] = value_1.bits[0];
  value_2->bits[1] = value_1.bits[1];
  value_2->bits[2] = value_1.bits[2];
}

int s21_is_big_infinity(s21_big_decimal value, int sign) {
  int flag = 0;
  for (int i = 7; i >= 3 && !flag; i--) {
    if (value.bits[i] != 0) {
      if (sign)
        flag = 2;
      else
        flag = 1;
    }
  }
  return flag;
}

void s21_zero_decimal(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

void s21_zero_big_decimal(s21_big_decimal *value) {
  for (int i = 0; i < 8; i++) {
    value->bits[i] = 0;
  }
}

void s21_copy_big_decimal(s21_big_decimal value1, s21_big_decimal *value2) {
  for (int i = 0; i < 8; i++) {
    value2->bits[i] = value1.bits[i];
  }
}

void s21_copy_decimal(s21_decimal value1, s21_decimal *value2) {
  for (int i = 0; i < 4; i++) {
    value2->bits[i] = value1.bits[i];
  }
}

void s21_shift_left(s21_big_decimal *value, int shift_value) {
  s21_big_decimal temp = {0};
  int mantissa_size = (sizeof(s21_big_decimal) / sizeof(int)) * 32;
  for (int i = 0; i < mantissa_size - shift_value; i++) {
    s21_big_set_bit(&temp, i + shift_value, s21_big_get_bit(*value, i));
  }
  s21_copy_big_decimal(temp, value);
}

int s21_is_zero(s21_decimal value) {
  int error = 1;
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] != MASK_ZERO) {
      error = 0;
    }
  }
  return error;
}

int s21_is_big_zero(s21_big_decimal value) {
  int error = 1;
  for (int i = 0; i < 8; i++) {
    if (value.bits[i] != MASK_ZERO) {
      error = 0;
    }
  }
  return error;
}

// int s21_is_can_div_ten(s21_decimal value) {
//   int error = 0;
//   s21_big_decimal res = {0};
//   s21_big_decimal big_value = {0};
//   s21_big_decimal not_result = {0};
//   s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};

//   s21_convert_to_big_decimal(value, &big_value);

//   res = s21_big_div(big_value, ten, &not_result);

//   if (s21_is_big_zero(res)) error = 1;

//   return error;
// }

int s21_is_can_big_div_ten(s21_big_decimal value) {
  int error = 0;
  s21_big_decimal res = {0};
  s21_big_decimal not_result = {0};
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};

  res = s21_big_div(value, ten, &not_result);

  if (s21_is_big_zero(res)) error = 1;

  return error;
}

int s21_get_exp_from_float(char *string) {
  int result = 0;
  char *ptr = string;
  while (*ptr) {
    if (*ptr == 'e') {
      ptr++;
      result = strtol(ptr, NULL, 10);
      break;
    }
    ptr++;
  }
  return result;
}

int s21_get_mantissa_from_float(char *string) {
  int result = 0;
  int exp = 10000000;
  int i = 0;
  while (string[i] != 'e') {
    if (string[i] >= '0' && string[i] <= '9') {
      result += ((string[i] - '0') * exp);
      exp /= 10;
    }
    i++;
  }
  return result;
}

void s21_scale_big_force(s21_big_decimal *value_1, s21_big_decimal *value_2,
                         int scale_1, int scale_2) {
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = {0};

  if (scale_1 <= scale_2) {
    for (int i = 0; i < scale_2 - scale_1; i++) {
      s21_zero_big_decimal(&res);
      s21_big_mul(*value_1, ten, &res);
      s21_copy_big_decimal(res, value_1);
    }
  } else {
    for (int i = 0; i < scale_1 - scale_2; i++) {
      s21_zero_big_decimal(&res);
      s21_big_mul(*value_2, ten, &res);
      s21_copy_big_decimal(res, value_2);
    }
  }
}

void s21_scale_force(s21_decimal *value_1, s21_decimal *value_2, int scale_1,
                     int scale_2) {
  if (scale_1 <= scale_2) {
    s21_scale_force_div(value_1, scale_2 - scale_1);
    s21_set_scale(value_1, scale_2);
  } else {
    s21_scale_force_div(value_2, scale_1 - scale_2);
    s21_set_scale(value_2, scale_1);
  }
}

void s21_scale_big_force_div(s21_big_decimal *value_1, int scale) {
  for (int i = 0; i < scale; i++) {
    s21_big_div_norm(value_1);
  }
}

void s21_scale_force_div(s21_decimal *value_1, int scale) {
  s21_big_decimal big_value = {{0}};
  s21_convert_to_big_decimal(*value_1, &big_value);
  s21_scale_big_force_div(&big_value, scale);
  s21_zero_decimal(value_1);
  s21_convert_to_decimal(big_value, value_1);
}

void s21_scale_div_ten(s21_decimal *value) {
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal time_result = {{0, 0, 0, 0}};
  s21_div(*value, ten, &time_result);
  s21_zero_decimal(value);
  s21_copy_decimal(time_result, value);
}

void s21_scale_big_div_ten(s21_big_decimal *value) {
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal time_result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_div(*value, ten, &time_result);
  s21_zero_big_decimal(value);
  s21_copy_big_decimal(time_result, value);
}

void s21_big_div_norm(s21_big_decimal *value_1) {
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_mul(*value_1, ten, value_1);
}