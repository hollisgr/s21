#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmethic_return error = S21_ARITHMETHIC_OK;
  int sing_1 = s21_get_sign(value_1);
  int sing_2 = s21_get_sign(value_2);

  int scale_1 = s21_get_scale(value_1);
  int scale_2 = s21_get_scale(value_2);

  s21_big_decimal big_value_1 = {0};
  s21_big_decimal big_value_2 = {0};
  s21_big_decimal big_result = {0};
  s21_decimal temp_dec = {0};

  s21_convert_to_big_decimal(value_1, &big_value_1);
  s21_convert_to_big_decimal(value_2, &big_value_2);

  if (result == NULL)
    error = 1;
  else {
    if (sing_1 == sing_2) {
      s21_scale_big_force(&big_value_1, &big_value_2, scale_1, scale_2);
      s21_big_add(big_value_1, big_value_2, &big_result);
      error = s21_is_big_infinity(big_result, sing_1);
    } else {
      if (s21_big_is_greater_or_equal(big_value_1, big_value_2)) {
        s21_big_sub(big_value_1, big_value_2, &big_result);
        error = s21_is_big_infinity(big_result, sing_1);
      } else {
        s21_big_sub(big_value_2, big_value_1, &big_result);
        error = s21_is_big_infinity(big_result, sing_2);
      }
    }
    s21_convert_to_decimal(big_result, &temp_dec);
    if (scale_1 >= scale_2)
      s21_set_scale(&temp_dec, scale_1);
    else
      s21_set_scale(&temp_dec, scale_2);

    if (s21_is_zero(temp_dec))
      s21_set_sign(&temp_dec, 0);
    else if (s21_big_is_greater_or_equal(big_value_1, big_value_2))
      s21_set_sign(&temp_dec, sing_1);
    else
      s21_set_sign(&temp_dec, sing_2);

    if (error != 0) s21_zero_decimal(&temp_dec);
    s21_copy_decimal(temp_dec, result);
  }
  return error;
}

void s21_big_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int result_bit = 0;
  int mantissa_size = (sizeof(s21_big_decimal) / sizeof(int)) * 32;
  for (int i = 0; i < mantissa_size; i++) {
    result_bit = s21_big_get_bit(value_1, i) + s21_big_get_bit(value_2, i);
    if (result_bit == 2) {
      for (int j = i + 1; j < mantissa_size; j++) {
        if (s21_big_get_bit(value_1, j) == 1) {
          s21_big_set_bit(&value_1, j, 0);
        } else if (s21_big_get_bit(value_1, j) == 0) {
          s21_big_set_bit(&value_1, j, 1);
          break;
        }
      }
      result_bit = 0;
    }
    s21_big_set_bit(result, i, result_bit);
  }
}

// void s21_big_add(s21_big_decimal value_1, s21_big_decimal value_2,
//                  s21_big_decimal *result) {
//   int result_bit = 0;
//   int mem = 0;
//   int mantissa_size = (sizeof(s21_big_decimal) / sizeof(int)) * 32;
//   for (int i = 0; i < mantissa_size; i++) {
//     result_bit =
//         s21_big_get_bit(value_1, i) + s21_big_get_bit(value_2, i) + mem;
//     mem = result_bit / 2;
//     result_bit %= 2;
//     s21_big_set_bit(result, i, result_bit);
//   }
// }

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmethic_return error = S21_ARITHMETHIC_OK;

  int sing_1 = s21_get_sign(value_1);
  int sing_2 = s21_get_sign(value_2);

  s21_big_decimal big_value_1 = {0};
  s21_big_decimal big_value_2 = {0};
  s21_big_decimal big_result = {0};

  s21_decimal temp_val1 = value_1;
  s21_decimal temp_val2 = value_2;
  s21_set_sign(&temp_val1, 0);
  s21_set_sign(&temp_val2, 0);

  int scale_1 = s21_get_scale(value_1);
  int scale_2 = s21_get_scale(value_2);

  s21_scale_force(&value_1, &value_2, scale_1, scale_2);
  s21_convert_to_big_decimal(value_1, &big_value_1);
  s21_convert_to_big_decimal(value_2, &big_value_2);

  if (result == NULL)
    error = 1;
  else {
    if (sing_1 == sing_2) {
      if (s21_is_greater_or_equal(temp_val1, temp_val2)) {
        s21_set_sign(result, sing_1);
      } else {
        s21_set_sign(result, !sing_1);
      }
      if (s21_big_is_greater_or_equal(big_value_1, big_value_2)) {
        s21_big_sub(big_value_1, big_value_2, &big_result);
      } else {
        s21_big_sub(big_value_2, big_value_1, &big_result);
      }
    } else {
      s21_big_add(big_value_1, big_value_2, &big_result);
      s21_set_sign(result, sing_1);
    }
    error = s21_is_big_infinity(big_result, sing_1);
    s21_convert_to_decimal(big_result, result);
    if (scale_1 >= scale_2)
      s21_set_scale(result, scale_1);
    else
      s21_set_scale(result, scale_2);

    if (error != 0) s21_zero_decimal(result);
  }
  return error;
}

void s21_big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int result_bit;
  int mantissa_size = (sizeof(s21_big_decimal) / sizeof(int)) * 32;

  for (int i = 0; i < mantissa_size; i++) {
    result_bit = s21_big_get_bit(value_1, i) - s21_big_get_bit(value_2, i);

    if (result_bit == -1) {
      for (int j = i + 1; j < mantissa_size; j++) {
        if (s21_big_get_bit(value_1, j) == 0) {
          s21_big_set_bit(&value_1, j, 1);
        } else if (s21_big_get_bit(value_1, j) == 1) {
          s21_big_set_bit(&value_1, j, 0);
          break;
        }
      }
      result_bit = 1;
    }
    s21_big_set_bit(result, i, result_bit);
  }
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmethic_return error = S21_ARITHMETHIC_OK;
  int sing_1 = s21_get_sign(value_1);
  int sing_2 = s21_get_sign(value_2);
  int sing = sing_1 ^ sing_2;

  int scale_1 = s21_get_scale(value_1);
  int scale_2 = s21_get_scale(value_2);
  int scale = scale_1;

  s21_big_decimal big_value_1 = {0};
  s21_big_decimal big_value_2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal result_temp = {0};
  s21_decimal temp_dec = {0};

  if (s21_is_zero(value_2)) {
    error = S21_ARITHMETHIC_ZERO_DIV;
  } else if (result == NULL)
    error = 1;
  else {
    s21_convert_to_big_decimal(value_1, &big_value_1);
    s21_convert_to_big_decimal(value_2, &big_value_2);

    s21_scale_big_force_div(&big_value_1, scale_2);

    for (; scale < 28; scale++) {
      s21_big_div_norm(&big_value_1);
    }

    s21_big_div(big_value_1, big_value_2, &result_temp);

    while ((s21_is_can_big_div_ten(result_temp) ||
            s21_is_big_infinity(result_temp, sing)) &&
           scale != 0) {
      s21_scale_big_div_ten(&result_temp);
      scale--;
    }
    s21_copy_big_decimal(result_temp, &big_result);

    s21_convert_to_decimal(big_result, &temp_dec);
    s21_set_sign(&temp_dec, sing);
    s21_set_scale(&temp_dec, scale);
    error = s21_is_big_infinity(big_result, sing);
    if (error != 0) s21_zero_decimal(&temp_dec);

    s21_copy_decimal(temp_dec, result);
  }

  return error;
}

s21_big_decimal s21_big_div(s21_big_decimal value_1, s21_big_decimal value_2,
                            s21_big_decimal *result) {
  s21_big_decimal temp = {0};
  s21_big_decimal result_temp = {0};
  int result_bit = 0;
  int mantissa_size = (sizeof(s21_big_decimal) / sizeof(int) - 1) * 32;
  for (int i = 0; i <= mantissa_size; i++) {
    s21_shift_left(&temp, 1);
    s21_shift_left(&result_temp, 1);
    result_bit = s21_big_get_bit(value_1, mantissa_size - i);
    s21_big_set_bit(&temp, 0, result_bit);
    if (s21_big_is_greater_or_equal(temp, value_2)) {
      s21_shift_left(result, 1);
      s21_big_set_bit(&result_temp, 0, 1);
      s21_big_sub(temp, value_2, &temp);
    }
  }
  s21_big_add(result_temp, *result, result);
  return temp;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmethic_return error = S21_ARITHMETHIC_OK;
  int sing_1 = s21_get_sign(value_1);
  int sing_2 = s21_get_sign(value_2);
  int sing = sing_1 ^ sing_2;

  int scale_1 = s21_get_scale(value_1);
  int scale_2 = s21_get_scale(value_2);
  int scale = scale_1 + scale_2;

  if (scale > 28) scale = 28;

  s21_big_decimal big_value_1 = {0};
  s21_big_decimal big_value_2 = {0};
  s21_big_decimal big_result = {0};
  s21_decimal temp_dec = {0};

  s21_convert_to_big_decimal(value_1, &big_value_1);
  s21_convert_to_big_decimal(value_2, &big_value_2);

  if (result == NULL)
    error = 1;
  else {
    s21_big_mul(big_value_1, big_value_2, &big_result);

    while (s21_is_can_big_div_ten(big_result) && scale > 0) {
      s21_scale_big_div_ten(&big_result);
      scale--;
    }

    s21_convert_to_decimal(big_result, &temp_dec);
    s21_set_sign(&temp_dec, sing);
    s21_set_scale(&temp_dec, scale);
    error = s21_is_big_infinity(big_result, sing);

    if (error != 0) s21_zero_decimal(&temp_dec);

    s21_copy_decimal(temp_dec, result);
  }
  return error;
}

void s21_big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int result_bit;

  s21_big_decimal temp1 = {0};
  s21_big_decimal temp2 = {0};
  s21_big_decimal big_result = {0};

  int mantissa_size = (sizeof(s21_big_decimal) / sizeof(int)) * 32;

  for (int i = 0; i < mantissa_size; i++) {
    s21_zero_big_decimal(&temp1);
    for (int j = 0; j < mantissa_size; j++) {
      result_bit = s21_big_get_bit(value_1, j) & s21_big_get_bit(value_2, i);
      s21_big_set_bit(&temp1, j, result_bit);
    }
    s21_copy_big_decimal(big_result, &temp2);
    s21_shift_left(&temp1, i);
    s21_big_add(temp1, temp2, &big_result);
  }

  s21_copy_big_decimal(big_result, result);
}
