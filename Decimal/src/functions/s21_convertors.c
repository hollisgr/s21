#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = 0;
  s21_zero_decimal(dst);
  if (src < 0) {
    src = abs(src);
    s21_set_sign(dst, 1);
  }
  dst->bits[0] = src;
  return code;
}

// int s21_mantissa_range(float src) {
//   int range = 0, mant = 0;
//   mant = (int)src;
//   for (int i = 0; i < 9; i++) {
//     if (mant > 0) {
//       mant = mant / 10;
//       range++;
//     }
//   }
//   return range;
// }

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//   int code = 0, mant = 0, scale = 0, fract_scale = 0, range = 0, sign = 0;
//   float fract = 0;
//   if (src < 0) {
//     src = src * -1;
//     sign = 1;
//   }
//   range = s21_mantissa_range(src);
//   if (range > 8) return code = 1;
//   if (range == 7 || range == 8) {
//     mant = (int)src;
//     dst->bits[0] = mant;
//   }
//   else {
//     scale = 7 - range;
//     fract = src - (int)src;
//     fract = fract * 10;
//     for (int i = 0; i < scale; i++) {
//       if ((int)fract != 0) {
//         src = src * 10;
//         fract = src - (int)src;
//         fract = fract * 10;
//         fract_scale++;
//       }
//     }
//     // fract = src - mant;
//     // fract = fract * 10;
//     // scale = 7 - range;
//     // for (int i = 0; i < scale; i++) {
//     //   if (fract != 0) {
//     //     mant = (mant * 10) + fract;
//     //     fract = fract - (int)fract;
//     //     fract = fract * 10;
//     //     fract_scale++;
//     //   }
//     // }
//     mant = (int)src;
//     dst->bits[0] = mant;
//     s21_set_scale(dst, fract_scale);
//   }
//   if (sign) s21_set_sign(dst, 1);
//   return code;
// }

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int code = 0, f_exp = 0, f_mant = 0, abs_f_exp = 0;
  s21_zero_decimal(dst);
  char temp[100] = {0};
  f_mant = src;
  if (src > 0xFFFFFFFF)
    code = 1;
  else if (src - (int)src) {
    sprintf(temp, "%e", fabsf(src));
    f_exp = s21_get_exp_from_float(temp);
    f_mant = s21_get_mantissa_from_float(temp);
    abs_f_exp = abs(f_exp);
    if (f_exp < 0) {
      for (int i = 0; i < abs_f_exp; i++) {
        f_mant = f_mant / 10;
        f_exp++;
      }
    }
    f_exp = 7 - f_exp;
    while (!(f_mant % 10)) {
      f_mant = f_mant / 10;
      f_exp--;
    }
  }
  s21_from_int_to_decimal(f_mant, dst);
  s21_set_scale(dst, f_exp);
  if (src < 0) s21_set_sign(dst, 1);
  return code;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code = 0, temp_num = 0;
  int scale = s21_get_scale(src);
  int sign = s21_get_sign(src);
  s21_decimal temp = {0};
  s21_copy_decimal(src, &temp);
  if (scale) s21_truncate(src, &temp);
  temp_num = temp.bits[0];
  if (sign == 1) temp_num = temp_num * -1;
  *dst = temp_num;
  return code;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int code = 0, num = 0, scale = 0, sign = 0;
  double f_num = 0, temp = 0;
  scale = s21_get_scale(src);
  sign = s21_get_sign(src);
  s21_decimal temp_dec = {0};
  s21_big_decimal temp_big_dec = {0};
  s21_copy_decimal(src, &temp_dec);
  s21_set_scale(&temp_dec, 0);
  s21_set_sign(&temp_dec, 0);
  if (scale > 7) {
    s21_convert_to_big_decimal(temp_dec, &temp_big_dec);
    while (scale > 7) {
      s21_scale_big_div_ten(&temp_big_dec);
      scale--;
    }
    s21_convert_to_decimal(temp_big_dec, &temp_dec);
  }
  int *pnum = &num;
  int scale_div = scale * 10;
  if (scale_div != 0) {
    s21_from_decimal_to_int(temp_dec, pnum);
    temp = num;
    for (int i = 0; i < scale; i++) {
      temp = temp / 10;
    }
    f_num = temp;
  } else
    f_num = src.bits[0];
  if (sign == 1) f_num = f_num * -1;
  *dst = f_num;
  return code;
}
