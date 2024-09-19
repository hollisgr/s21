#include "test_main.h"

//-----S21_SUB-----
//-----------------
START_TEST(arithmetic_sub_1) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_decimal value2 = {{255, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_2) {
  s21_decimal value1 = {{256, 0, 0, 0}};
  s21_decimal value2 = {{255, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, 0}};
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_3) {
  s21_decimal value1 = {{256, 256, 1, 0}};
  s21_decimal value2 = {{255, 255, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 1, 0, 0}};
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_4) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{1, 1, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 1, 0}};
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

//-----S21_BIG_SUB-----
//---------------------
START_TEST(arithmetic_sub_5) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_decimal value2 = {{255, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_sub(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_6) {
  s21_decimal value1 = {{256, 0, 0, 0}};
  s21_decimal value2 = {{255, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_sub(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_7) {
  s21_decimal value1 = {{256, 0, 0, 0}};
  s21_decimal value2 = {{256, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_sub(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_8) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_sub(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_9) {
  s21_decimal value1 = {{3, 0, 0, 0}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_sub(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

//-----S21_SUB_ADDITIONS-----
//---------------------------

START_TEST(arithmetic_sub_10) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_decimal value2 = {{256, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, MASK_NEGATIVE}};
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_11) {
  s21_decimal value1 = {{2, 0, 0, MASK_NEGATIVE}};
  s21_decimal value2 = {{1, 0, 0, MASK_NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 0, 0, MASK_NEGATIVE}};
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_12) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{2, 0, 0, MASK_NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{3, 0, 0, 0}};
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_13) {
  s21_decimal value1 = {{300, 0, 0, 0}};
  s21_decimal value2 = {{1, 0, 0, 0}};
  s21_set_scale(&value1, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{200, 0, 0, 0}};
  s21_set_scale(&result2, 2);
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_sub_14) {
  s21_decimal value1 = {{3, 0, 0, 0}};
  s21_decimal value2 = {{100, 0, 0, 0}};
  s21_set_scale(&value2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{200, 0, 0, 0}};
  s21_set_scale(&result2, 2);
  s21_sub(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

Suite *test_arithmetic_sub(void) {
  Suite *s = suite_create("s21_decimal arithmetic_sub");
  TCase *tc = tcase_create("arithmetic_sub_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, arithmetic_sub_1);
  tcase_add_test(tc, arithmetic_sub_2);
  tcase_add_test(tc, arithmetic_sub_3);
  tcase_add_test(tc, arithmetic_sub_4);
  tcase_add_test(tc, arithmetic_sub_5);
  tcase_add_test(tc, arithmetic_sub_6);
  tcase_add_test(tc, arithmetic_sub_7);
  tcase_add_test(tc, arithmetic_sub_8);
  tcase_add_test(tc, arithmetic_sub_9);
  tcase_add_test(tc, arithmetic_sub_10);
  tcase_add_test(tc, arithmetic_sub_11);
  tcase_add_test(tc, arithmetic_sub_12);
  tcase_add_test(tc, arithmetic_sub_13);
  tcase_add_test(tc, arithmetic_sub_14);
  return s;
}
