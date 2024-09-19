#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_another_return error = S21_ANOTHER_OK;
  int sign;
  sign = s21_get_sign(value);
  if (sign) {
    s21_copy_decimal(value, result);
    s21_set_sign(result, 0);
  } else {
    s21_copy_decimal(value, result);
    s21_set_sign(result, 1);
  }
  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_another_return error = S21_ANOTHER_OK;
  int scale, sign;
  scale = s21_get_scale(value);
  sign = s21_get_sign(value);
  s21_big_decimal temp_value = {0};
  s21_big_decimal temp_result = {0};
  s21_decimal temp_dec = {0};
  s21_big_decimal ost = {0};
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_convert_to_big_decimal(value, &temp_value);
  for (int i = 0; i < scale - 1; i++) {
    s21_scale_big_div_ten(&temp_value);
  }
  if (scale != 0) {
    ost = s21_big_div(temp_value, ten, &temp_result);
    s21_zero_big_decimal(&temp_value);
    s21_copy_big_decimal(temp_result, &temp_value);
  }

  if (scale && ost.bits[0] >= 5) {
    s21_big_add(temp_value, one, &temp_value);
  }
  s21_convert_to_decimal(temp_value, &temp_dec);
  s21_set_scale(&temp_dec, 0);
  s21_set_sign(&temp_dec, sign);
  s21_copy_decimal(temp_dec, result);
  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_another_return error = S21_ANOTHER_OK;
  // int code = 0;
  int scale = 0, sign = 0;
  scale = s21_get_scale(value);
  sign = s21_get_sign(value);
  s21_big_decimal temp_big_dec = {0};
  s21_decimal temp_dec = {0};
  s21_convert_to_big_decimal(value, &temp_big_dec);
  for (int i = 0; i < scale; i++) {
    s21_scale_big_div_ten(&temp_big_dec);
  }
  s21_convert_to_decimal(temp_big_dec, &temp_dec);
  s21_set_scale(&temp_dec, 0);
  s21_set_sign(&temp_dec, sign);
  s21_copy_decimal(temp_dec, result);
  return error;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_another_return error = S21_ANOTHER_OK;
  int scale, sign;
  scale = s21_get_scale(value);
  sign = s21_get_sign(value);
  s21_big_decimal temp_value = {0};
  s21_big_decimal temp_result = {0};
  s21_decimal temp_dec = {0};
  s21_big_decimal ost = {0};
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_convert_to_big_decimal(value, &temp_value);
  for (int i = 0; i < scale - 1; i++) {
    s21_scale_big_div_ten(&temp_value);
  }
  if (scale != 0) {
    ost = s21_big_div(temp_value, ten, &temp_result);
    s21_zero_big_decimal(&temp_value);
    s21_copy_big_decimal(temp_result, &temp_value);
  }

  if (scale && sign && ost.bits[0] != 0) {
    s21_big_add(temp_value, one, &temp_value);
  }
  s21_convert_to_decimal(temp_value, &temp_dec);
  s21_set_scale(&temp_dec, 0);
  s21_set_sign(&temp_dec, sign);
  s21_copy_decimal(temp_dec, result);
  return error;
}