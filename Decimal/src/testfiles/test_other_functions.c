#include "test_main.h"

//-----S21_NEGATE-----
//--------------------
START_TEST(other_functions_1) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 0);
  s21_set_sign(&value2, 1);
  s21_negate(value1, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value2.bits[i]);
}
END_TEST

START_TEST(other_functions_2) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_sign(&value2, 0);
  s21_negate(value1, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value2.bits[i]);
}
END_TEST

//-----S21_ROUND-----
//-------------------

START_TEST(other_functions_3) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{250, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_scale(&value1, 1);
  s21_round(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(25, num);
}
END_TEST

START_TEST(other_functions_4) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{2555, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_scale(&value1, 1);
  s21_round(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-256, num);
}
END_TEST

START_TEST(other_functions_5) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{1000, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_scale(&value1, 2);
  s21_round(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-10, num);
}
END_TEST

START_TEST(other_functions_6) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{1000, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_scale(&value1, 0);
  s21_round(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-1000, num);
}
END_TEST

//-----S21_TRUNCATE-----
//----------------------

START_TEST(other_functions_7) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_scale(&value1, 2);
  s21_truncate(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(2, num);
}
END_TEST

START_TEST(other_functions_8) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{2555, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_scale(&value1, 1);
  s21_truncate(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-255, num);
}
END_TEST

START_TEST(other_functions_9) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{1000, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_scale(&value1, 0);
  s21_truncate(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-1000, num);
}
END_TEST

//-----S21_FLOOR-----
//-------------------

START_TEST(other_functions_10) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{257, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_scale(&value1, 1);
  s21_floor(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(25, num);
}
END_TEST

START_TEST(other_functions_11) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{2555, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_scale(&value1, 1);
  s21_floor(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-256, num);
}
END_TEST

START_TEST(other_functions_12) {
  float num;
  float *pnum = &num;
  s21_decimal value1 = {{1000, 0, 0, 0}};
  s21_decimal result = {0};
  s21_set_sign(&value1, 1);
  s21_set_scale(&value1, 2);
  s21_floor(value1, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-10, num);
}
END_TEST

Suite *test_other_functions(void) {
  Suite *s = suite_create("s21_decimal other_functions");
  TCase *tc = tcase_create("other_functions_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, other_functions_1);
  tcase_add_test(tc, other_functions_2);
  tcase_add_test(tc, other_functions_3);
  tcase_add_test(tc, other_functions_4);
  tcase_add_test(tc, other_functions_5);
  tcase_add_test(tc, other_functions_6);
  tcase_add_test(tc, other_functions_7);
  tcase_add_test(tc, other_functions_8);
  tcase_add_test(tc, other_functions_9);
  tcase_add_test(tc, other_functions_10);
  tcase_add_test(tc, other_functions_11);
  tcase_add_test(tc, other_functions_12);

  return s;
}
