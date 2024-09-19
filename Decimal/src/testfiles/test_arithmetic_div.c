#include "test_main.h"

//-----S21_DIV-----
//-----------------
START_TEST(arithmetic_div_1) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 1, 1, 0}};
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_div_2) {
  s21_decimal value1 = {{2, 0, 0, MASK_NEGATIVE}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, MASK_NEGATIVE}};
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_div_3) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_div_4) {
  s21_decimal value1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value2 = {{3, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0x55555555, 0, 0, 0}};
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_div_5) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{1, 0, 0, MASK_NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 1, 1, MASK_NEGATIVE}};
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_div_6) {
  s21_decimal value1 = {{20, 0, 0, 0}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_set_scale(&value2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1000, 0, 0, 0}};
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_div_7) {
  s21_decimal value1 = {{2, 0, 0, 0}};
  s21_decimal value2 = {{20, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, 0}};
  s21_set_scale(&result2, 1);
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_div_8) {
  s21_decimal value1 = {{1000, 0, 0, 0}};
  s21_decimal value2 = {{10, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, 0}};
  s21_set_scale(&value1, 2);
  // s21_set_scale(&result2, 2);
  s21_div(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

Suite *test_arithmetic_div(void) {
  Suite *s = suite_create("s21_decimal arithmetic_div");
  TCase *tc = tcase_create("arithmetic_div_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, arithmetic_div_1);
  tcase_add_test(tc, arithmetic_div_2);
  tcase_add_test(tc, arithmetic_div_3);
  tcase_add_test(tc, arithmetic_div_4);
  tcase_add_test(tc, arithmetic_div_5);
  tcase_add_test(tc, arithmetic_div_6);
  tcase_add_test(tc, arithmetic_div_7);
  tcase_add_test(tc, arithmetic_div_8);
  return s;
}
