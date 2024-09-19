#include "s21_decimal.h"

void s21_mul_ten(s21_decimal *value) {
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal time_result = {{0, 0, 0, 0}};
  s21_mul(*value, ten, &time_result);
  s21_zero_decimal(value);
  s21_copy_decimal(time_result, value);
}

void s21_normalization(s21_decimal *value_1, s21_decimal *value_2) {
  int scale1, scale2 = 0;
  scale1 = s21_get_scale(*value_1);
  scale2 = s21_get_scale(*value_2);
  if (scale1 == scale2)
    return;
  else {
    s21_decimal temp1 = {{0, 0, 0, 0}};
    s21_decimal temp2 = {{0, 0, 0, 0}};
    s21_copy_decimal(*value_1, &temp1);
    s21_copy_decimal(*value_2, &temp2);
    s21_set_scale(&temp1, 0);
    s21_set_scale(&temp2, 0);
    if (scale1 > scale2) {
      while (scale1 > scale2) {
        s21_mul_ten(&temp2);
        scale2++;
      }
    } else {
      while (scale1 < scale2) {
        s21_mul_ten(&temp1);
        scale1++;
      }
    }
    s21_copy_decimal(temp1, value_1);
    s21_copy_decimal(temp2, value_2);
    s21_set_scale(value_1, scale1);
    s21_set_scale(value_2, scale2);
  }
}

int s21_check_mantissa(s21_decimal value_1, s21_decimal value_2) {
  int code = 1;
  for (int i = 0; i < 3; i++) {
    if (value_1.bits[i] != value_2.bits[i]) code = 0;
  }
  return code;
}

int s21_comparison(s21_decimal value_1, s21_decimal value_2) {
  int eq_mant, code, sign1, sign2, scale1, scale2 = 0;
  sign1 = s21_get_sign(value_1);
  sign2 = s21_get_sign(value_2);
  if (s21_is_zero(value_1) && s21_is_zero(value_2))
    code = 0;
  else if (sign1 > sign2)
    code = -1;
  else if (sign1 < sign2)
    code = 1;
  else {
    scale1 = s21_get_scale(value_1);
    scale2 = s21_get_scale(value_2);
    s21_decimal temp1 = {{0, 0, 0, 0}};
    s21_decimal temp2 = {{0, 0, 0, 0}};
    s21_copy_decimal(value_1, &temp1);
    s21_copy_decimal(value_2, &temp2);
    s21_set_scale(&temp1, scale1);
    s21_set_scale(&temp2, scale2);
    eq_mant = s21_check_mantissa(temp1, temp2);
    if (eq_mant == 1) {
      if (scale1 == scale2) code = 0;
      if (scale1 > scale2) code = -1;
      if (scale1 < scale2) code = 1;
    } else {
      if (scale1 != scale2) s21_normalization(&temp1, &temp2);
      code = 0;
      for (int i = 95; i >= 0; i--) {
        if (s21_get_bit(temp1, i) > s21_get_bit(temp2, i)) code = 1;
        if (s21_get_bit(temp1, i) < s21_get_bit(temp2, i)) code = -1;
        if (code != 0) break;
      }
      if (sign1 && sign2 == 1) code *= -1;
    }
  }
  return code;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;
  if (s21_comparison(value_1, value_2) == -1) code = 1;
  return code;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;
  if (s21_comparison(value_1, value_2) < 1) code = 1;
  return code;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;
  if (s21_comparison(value_1, value_2) == 1) code = 1;
  return code;
}
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;
  if (s21_comparison(value_1, value_2) > -1) code = 1;
  return code;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;
  if (s21_comparison(value_1, value_2) == 0) code = 1;
  return code;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;
  if (s21_comparison(value_1, value_2) != 0) code = 1;
  return code;
}

int s21_big_comparison(s21_big_decimal value_1, s21_big_decimal value_2) {
  int n = 0;
  for (int i = 255; i >= 0; i--) {
    if (s21_big_get_bit(value_1, i) > s21_big_get_bit(value_2, i)) {
      n = 1;
      break;
    } else if (s21_big_get_bit(value_1, i) < s21_big_get_bit(value_2, i)) {
      n = -1;
      break;
    }
  }
  return n;
}

int s21_big_is_less(s21_big_decimal value_1, s21_big_decimal value_2) {
  int code = 0;
  if (s21_big_comparison(value_1, value_2) == -1) code = 1;
  return code;
}

int s21_big_is_less_or_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int code = 0;
  if (s21_big_comparison(value_1, value_2) < 1) code = 1;
  return code;
}

int s21_big_is_greater(s21_big_decimal value_1, s21_big_decimal value_2) {
  int code = 0;
  if (s21_big_comparison(value_1, value_2) == 1) code = 1;
  return code;
}
int s21_big_is_greater_or_equal(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  int code = 0;
  if (s21_big_comparison(value_1, value_2) > -1) code = 1;
  return code;
}

int s21_big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int code = 0;
  if (s21_big_comparison(value_1, value_2) == 0) code = 1;
  return code;
}

int s21_big_is_not_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int code = 0;
  if (s21_big_comparison(value_1, value_2) != 0) code = 1;
  return code;
}