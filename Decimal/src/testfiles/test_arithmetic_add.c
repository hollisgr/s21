#include "test_main.h"

//-----S21_ADD-----
//-----------------
START_TEST(arithmetic_add_1) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_decimal value2 = {{255, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{510, 0, 0, 0}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_2) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_decimal value2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{256, 0, 0, 0}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_3) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 255, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 510, 0, 0}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_4) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 1, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 256, 0, 0}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_5) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 510, 0}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_6) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 256, 0}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

//-----S21_ADD_ADDITIONS-----
//---------------------------
START_TEST(arithmetic_add_7) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_decimal value2 = {{10, 0, 0, MASK_NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{245, 0, 0, 0}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_8) {
  s21_decimal value1 = {{255, 0, 0, MASK_NEGATIVE}};
  s21_decimal value2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{254, 0, 0, MASK_NEGATIVE}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_9) {
  s21_decimal value1 = {{0, 255, 0, MASK_NEGATIVE}};
  s21_decimal value2 = {{0, 255, 0, MASK_NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 510, 0, MASK_NEGATIVE}};
  s21_add(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_10) {
  s21_decimal value1 = {{10, 0, 0, 0}};
  s21_decimal value2 = {{10, 0, 0, 0}};
  s21_set_scale(&value1, 2);
  s21_set_scale(&value2, 2);
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{20, 0, 0, 0}};
  s21_set_scale(&result1, 2);
  s21_set_scale(&result2, 2);
  s21_add(value1, value2, &result1);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(result1.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_add_11) {
  s21_decimal value1 = {{10, 0, 0, 0}};
  s21_decimal value2 = {{10, 0, 0, 0}};
  s21_set_scale(&value1, 1);
  s21_set_scale(&value2, 2);
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{110, 0, 0, 0}};
  s21_set_scale(&result1, 1);
  s21_set_scale(&result2, 2);
  s21_add(value1, value2, &result1);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(result1.bits[i], result2.bits[i]);
}
END_TEST

Suite *test_arithmetic_add(void) {
  Suite *s = suite_create("s21_decimal arithmetic_add");
  TCase *tc = tcase_create("arithmetic_add_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, arithmetic_add_1);
  tcase_add_test(tc, arithmetic_add_2);
  tcase_add_test(tc, arithmetic_add_3);
  tcase_add_test(tc, arithmetic_add_4);
  tcase_add_test(tc, arithmetic_add_5);
  tcase_add_test(tc, arithmetic_add_6);
  tcase_add_test(tc, arithmetic_add_7);
  tcase_add_test(tc, arithmetic_add_8);
  tcase_add_test(tc, arithmetic_add_9);
  tcase_add_test(tc, arithmetic_add_10);
  tcase_add_test(tc, arithmetic_add_11);
  return s;
}
