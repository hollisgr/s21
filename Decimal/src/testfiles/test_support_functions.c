#include "test_main.h"

//-----S21_IS_BIG_INFINITY-----
//-----------------------------

START_TEST(support_functions_1) {
  s21_big_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                            0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int x = s21_is_big_infinity(value, 1);
  ck_assert_int_eq(x, 2);
}
END_TEST

START_TEST(support_functions_2) {
  s21_big_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                            0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int x = s21_is_big_infinity(value, 0);
  ck_assert_int_eq(x, 1);
}
END_TEST

//-----S21_ZERO_DECIMAL-----
//--------------------------

START_TEST(support_functions_3) {
  s21_decimal value1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value2 = {0};
  s21_zero_decimal(&value1);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(value1.bits[i], value2.bits[i]);
}
END_TEST

//-----S21_COPY_DECIMAL-----
//--------------------------

START_TEST(support_functions_4) {
  s21_decimal value1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value2 = {0};
  s21_copy_decimal(value1, &value2);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(value1.bits[i], value2.bits[i]);
}
END_TEST

//-----S21_IS_ZERO-----
//--------------------------

START_TEST(support_functions_5) {
  s21_decimal value1 = {{0xFFFFFFFF, 0, 0, 0}};
  int x = s21_is_zero(value1);
  ck_assert_int_eq(x, 0);
}
END_TEST

START_TEST(support_functions_6) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  int x = s21_is_zero(value1);
  ck_assert_int_eq(x, 1);
}
END_TEST

//-----S21_SCALE_BIG_FORCE-----
//--------------------------

START_TEST(support_functions_7) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_scale_big_force(&big_value1, &big_value2, 2, 1);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_value1.bits[i], big_value2.bits[i]);
}
END_TEST

START_TEST(support_functions_8) {
  s21_decimal value1 = {{10, 0, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {{100, 0, 0, 0, 0, 0, 0, 0}};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_scale_big_force(&big_value1, &big_value2, 1, 2);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_value1.bits[i], big_value2.bits[i]);
}
END_TEST

//-----S21_SCALE_FORCE-----
//--------------------------

START_TEST(support_functions_9) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_decimal value2 = {{10, 0, 0, 0}};
  s21_set_scale(&value1, 1);
  s21_scale_force(&value1, &value2, 1, 0);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(value1.bits[i], value2.bits[i]);
}
END_TEST

START_TEST(support_functions_10) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{100, 0, 0, 0}};
  s21_set_scale(&value2, 2);
  s21_scale_force(&value1, &value2, 0, 2);
  for (int i = 0; i < 3; i++) ck_assert_int_eq(value1.bits[i], value2.bits[i]);
}
END_TEST

//-----S21_IS_BIG_ZERO-----
//-------------------------

START_TEST(support_functions_11) {
  s21_big_decimal value1;
  s21_zero_big_decimal(&value1);
  int x = s21_is_big_zero(value1);
  ck_assert_int_eq(x, 1);
}
END_TEST

START_TEST(support_functions_12) {
  s21_big_decimal value1 = {{1, 1, 1, 1, 1, 1, 1, 1}};
  // s21_zero_big_decimal(&value1);
  int x = s21_is_big_zero(value1);
  ck_assert_int_eq(x, 0);
}
END_TEST

//-----S21_NORMALIZATION-----
//---------------------------

START_TEST(support_functions_13) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_decimal value2 = {{100, 0, 0, 0}};
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{10100, 0, 0, 0}};
  s21_set_scale(&value1, 2);
  s21_normalization(&value1, &value2);
  s21_add(value1, value2, &result1);
  s21_set_scale(&result2, 2);
  for (int i = 0; i < 3; i++)
    ck_assert_int_eq(result1.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(support_functions_14) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_decimal value2 = {{100, 0, 0, 0}};
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{10100, 0, 0, 0}};
  s21_set_scale(&value2, 2);
  s21_normalization(&value1, &value2);
  s21_add(value1, value2, &result1);
  s21_set_scale(&result2, 2);
  for (int i = 0; i < 3; i++)
    ck_assert_int_eq(result1.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(support_functions_15) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_decimal value2 = {{100, 0, 0, 0}};
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{200, 0, 0, 0}};
  s21_normalization(&value1, &value2);
  s21_add(value1, value2, &result1);
  for (int i = 0; i < 3; i++)
    ck_assert_int_eq(result1.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(support_functions_16) {
  s21_decimal value1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value2 = {0};
  s21_set_sign(&value1, 1);
  s21_copy_decimal(value1, &value2);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(value1.bits[i], value2.bits[i]);
}
END_TEST

START_TEST(support_functions_17) {
  s21_decimal value1 = {{255, 255, 255, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  int res = s21_check_mantissa(value1, value2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(support_functions_18) {
  s21_decimal value1 = {{255, 255, 255, 0}};
  s21_decimal value2 = {{255, 255, 254, 0}};
  int res = s21_check_mantissa(value1, value2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(support_functions_19) {
  s21_decimal value1 = {{250, 0, 0, 0}};
  s21_decimal value2 = {{25, 0, 0, 0}};
  s21_scale_div_ten(&value1);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(value1.bits[i], value2.bits[i]);
}
END_TEST

START_TEST(support_functions_20) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_decimal value2 = {{1000, 0, 0, 0}};
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{2000, 0, 0, 0}};
  s21_set_scale(&value2, 1);
  s21_normalization(&value1, &value2);
  s21_add(value1, value2, &result1);
  for (int i = 0; i < 3; i++)
    ck_assert_int_eq(result1.bits[i], result2.bits[i]);
}
END_TEST

Suite *test_support_functions(void) {
  Suite *s = suite_create("s21_decimal support_functions");
  TCase *tc = tcase_create("support_functions_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, support_functions_1);
  tcase_add_test(tc, support_functions_2);
  tcase_add_test(tc, support_functions_3);
  tcase_add_test(tc, support_functions_4);
  tcase_add_test(tc, support_functions_5);
  tcase_add_test(tc, support_functions_6);
  tcase_add_test(tc, support_functions_7);
  tcase_add_test(tc, support_functions_8);
  tcase_add_test(tc, support_functions_9);
  tcase_add_test(tc, support_functions_10);
  tcase_add_test(tc, support_functions_11);
  tcase_add_test(tc, support_functions_12);
  tcase_add_test(tc, support_functions_13);
  tcase_add_test(tc, support_functions_14);
  tcase_add_test(tc, support_functions_15);
  tcase_add_test(tc, support_functions_16);
  tcase_add_test(tc, support_functions_17);
  tcase_add_test(tc, support_functions_18);
  tcase_add_test(tc, support_functions_19);
  tcase_add_test(tc, support_functions_20);
  return s;
}
