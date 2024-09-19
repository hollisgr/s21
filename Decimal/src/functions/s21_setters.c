#include "s21_decimal.h"

int s21_get_sign(s21_decimal value) {
  int sign;
  if ((value.bits[3] >> 31) & 1)
    sign = 1;
  else
    sign = 0;
  return sign;
}

void s21_set_sign(s21_decimal *value, int sign_value) {
  s21_set_bit(value, 127, sign_value);
}

int s21_get_scale(s21_decimal value) {
  int scale = 0;
  s21_decimal temp = value;
  s21_set_sign(&temp, 0);
  scale = temp.bits[3] >> 16;
  return scale;
}

void s21_set_scale(s21_decimal *value, int scale_value) {
  int sign = s21_get_sign(*value);
  int arg = scale_value << 16;
  value->bits[3] = arg;
  s21_set_sign(value, sign);
}

int s21_get_bit(s21_decimal value, int index) {
  int bit;
  bit = (value.bits[index / 32] >> index % 32) & 1;
  return bit;
}

void s21_set_bit(s21_decimal *value, int index, int bit_value) {
  int arr_index = index / 32;
  int num_index = index % 32;
  if (bit_value == 1) {
    value->bits[arr_index] |= (1 << num_index);
  } else {
    value->bits[arr_index] &= (~(1 << num_index));
  }
}

// int s21_big_get_sign(s21_big_decimal value) {
//   int sign;
//   if ((value.bits[8] >> 31) & 1) sign = 1;
//   else sign = 0;
//   return sign;
// }

// void s21_big_set_sign(s21_big_decimal *value, int sign_value) {
//   s21_big_set_bit(value, 255, sign_value);
// }

// int s21_big_get_scale(s21_big_decimal value) {
//   int scale = 0;
//   for (int i = 0; i < 6; i++)
//     if (value.bits[7] >> (16 + i)) scale++;
//   return scale;
// }

// void s21_big_set_scale(s21_big_decimal *value, int scale_value) {
//   int sign = s21_bit_get_sign(value);
//   value->bits[7] = scale_value;
//   if (sign == 1) s21_bit_set_scale(value, 1);
// }

int s21_big_get_bit(s21_big_decimal value, int index) {
  int bit;
  bit = (value.bits[index / 32] >> index % 32) & 1;
  return bit;
}

void s21_big_set_bit(s21_big_decimal *value, int index, int bit_value) {
  int arr_index = index / 32;
  int num_index = index % 32;
  if (bit_value == 1) {
    value->bits[arr_index] |= (1 << num_index);
  } else {
    value->bits[arr_index] &= (~(1 << num_index));
  }
}
