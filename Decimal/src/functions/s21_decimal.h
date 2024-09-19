#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MASK_NEGATIVE 0x80000000
#define MASK_EXP 0x10000

#define MASK_ZERO 0x0

#define one_dec_bit 4294967295
#define half_one_dec 2147483648
#define MAX_DEC 79228162514264337593543950336
#define MIN_DEC -79228162514264337593543950336

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef enum s21_arithmethic_return {
  S21_ARITHMETHIC_OK = 0,
  S21_ARITHMETHIC_BIG_INFINITY = 1,
  S21_ARITHMETHIC_SMALL_INFINITY = 2,
  S21_ARITHMETHIC_ZERO_DIV = 3,
} s21_arithmethic_return;

typedef enum s21_comparsion_return {
  S21_COMPARSION_FALSE = 0,
  S21_COMPARSION_TRUE = 1,
} s21_comparsion_return;

typedef enum s21_conversation_return {
  S21_CONVERSATION_OK = 0,
  S21_CONVERSATION_ERROR = 1,
} s21_conversation_return;

typedef enum s21_another_return {
  S21_ANOTHER_OK = 0,
  S21_ANOTHER_ERROR = 1,
} s21_another_return;

//-----FUNC FOR S21_DECIMAL------
int s21_check_mantissa(s21_decimal value_1, s21_decimal value_2);
int s21_comparison(s21_decimal value_1,
                   s21_decimal value_2); /*return 0 if value_1 and value_2 is
                                      equal, return 1 if value_1 is greater than
                                      value_2, return -1 if value_1 is less */
// void s21_right_shift(s21_decimal *value);
void s21_print_binary(int n);
void s21_print_decimal(s21_decimal n);
int s21_get_exp_from_float(char *string);
int s21_get_mantissa_from_float(char *string);
void s21_scale_div_ten(s21_decimal *value);
void s21_normalization(s21_decimal *value_1, s21_decimal *value_2);
void s21_mul_ten(s21_decimal *value);
// ------------
// setters/getters
int s21_get_sign(s21_decimal value);
void s21_set_sign(s21_decimal *value, int sign_value);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, int scale_value);
int s21_get_bit(s21_decimal value, int index);
void s21_set_bit(s21_decimal *value, int index, int bit_value);
// ------------
// arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// ------------
// comparison
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
// ------------
// convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
// ------------
// another
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
// ------------
//-----FUNC FOR S21_BIG_DECIMAL------

// big decimal
void s21_convert_to_big_decimal(s21_decimal value_1, s21_big_decimal *value_2);
void s21_convert_to_decimal(s21_big_decimal value_1, s21_decimal *value_2);
int s21_is_big_infinity(s21_big_decimal number, int sign);
void s21_print_big_decimal(s21_big_decimal n);
void s21_zero_decimal(s21_decimal *value);
void s21_zero_big_decimal(s21_big_decimal *value);
void s21_copy_big_decimal(s21_big_decimal value1, s21_big_decimal *value2);
void s21_shift_left(s21_big_decimal *value, int shift_value);
int s21_is_zero(s21_decimal value);
void s21_scale_big_force(s21_big_decimal *value_1, s21_big_decimal *value_2,
                         int scale_1, int scale_2);
void s21_scale_force(s21_decimal *value_1, s21_decimal *value_2, int scale_1,
                     int scale_2);
void s21_copy_decimal(s21_decimal value1, s21_decimal *value2);
void s21_scale_big_force_div(s21_big_decimal *value_1, int scale_2);
void s21_scale_force_div(s21_decimal *value_1, int scale_2);
void s21_big_div_norm(s21_big_decimal *value_1);
int s21_is_big_zero(s21_big_decimal value);
int s21_is_can_div_ten(s21_decimal value);
int s21_is_can_big_div_ten(s21_big_decimal value);
void s21_scale_big_div_ten(s21_big_decimal *value);

// setters/getters
int s21_big_get_sign(s21_big_decimal value);
void s21_big_set_sign(s21_big_decimal *value, int sign_value);
int s21_big_get_scale(s21_big_decimal value);
void s21_big_set_scale(s21_big_decimal *value, int scale_value);
int s21_big_get_bit(s21_big_decimal value, int index);
void s21_big_set_bit(s21_big_decimal *value, int index, int bit_value);
// ------------
// arithmetic
void s21_big_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
void s21_big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
void s21_big_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
// void s21_big_div(s21_big_decimal value_1, s21_big_decimal value_2,
// s21_big_decimal *result);
s21_big_decimal s21_big_div(s21_big_decimal value_1, s21_big_decimal value_2,
                            s21_big_decimal *result);
void s21_scale_div_ten(s21_decimal *value);

// ------------
// big comparison
int s21_big_comparison(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_is_less(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_is_less_or_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_is_greater_or_equal(s21_big_decimal value_1,
                                s21_big_decimal value_2);
int s21_big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_is_not_equal(s21_big_decimal value_1, s21_big_decimal value_2);

#endif
