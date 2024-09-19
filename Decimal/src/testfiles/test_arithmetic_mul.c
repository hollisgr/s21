#include "test_main.h"

//-----S21_MUL-----
//-----------------
START_TEST(arithmetic_mul_1) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{1, 1, 1, 0}};
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 1, 1, 0}};
  s21_mul(value1, value2, &result1);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(result1.bits[i], result2.bits[i]);
}
END_TEST

// START_TEST(arithmetic_mul_1) {
//   s21_decimal value1 = {{1, 1, 1, MASK_NEGATIVE}};
//   s21_decimal value2 = {{2, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal result2 = {{2, 2, 2, MASK_NEGATIVE}};
//   s21_mul(value1, value2, &result);
//   for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i],
//   result2.bits[i]);
// }
// END_TEST

START_TEST(arithmetic_mul_2) {
  s21_decimal value1 = {{1, 1, 1, MASK_NEGATIVE}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{2, 2, 2, MASK_NEGATIVE}};
  s21_mul(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_mul_3) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, 31);
  s21_set_scale(&value2, 31);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_mul(value1, value2, &result);
  s21_set_scale(&result, 28);
  s21_set_scale(&result2, 28);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_mul_4) {
  s21_decimal value1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0xFFFFFFFE, 0x1, 0, 0}};
  s21_mul(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_mul_5) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{1, 0, 0, MASK_NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 1, 1, MASK_NEGATIVE}};
  s21_mul(value1, value2, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], result2.bits[i]);
}
END_TEST

// -----S21_BIG_MUL-----
// ---------------------
START_TEST(arithmetic_mul_6) {
  s21_decimal value1 = {{1, 0, 0, 0}};
  s21_decimal value2 = {{1, 1, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 1, 1, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_mul(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

// START_TEST(arithmetic_mul_6) {
//   s21_decimal value1 = {{1, 1, 1, 0}};
//   s21_decimal value2 = {{2, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal result2 = {{2, 2, 2, 0}};
//   s21_big_decimal big_value1 = {0};
//   s21_big_decimal big_value2 = {0};
//   s21_big_decimal big_result = {0};
//   s21_big_decimal big_result2 = {0};
//   s21_convert_to_big_decimal(value1, &big_value1);
//   s21_convert_to_big_decimal(value2, &big_value2);
//   s21_convert_to_big_decimal(result, &big_result);
//   s21_convert_to_big_decimal(result2, &big_result2);
//   s21_big_mul(big_value1, big_value2, &big_result);
//   for (int i = 0; i < 8; i++) ck_assert_int_eq(big_result.bits[i],
//   big_result2.bits[i]);
// }
// END_TEST

START_TEST(arithmetic_mul_7) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{2, 2, 2, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_mul(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_mul_8) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
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
  s21_big_mul(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_mul_9) {
  s21_decimal value1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0xFFFFFFFE, 0x1, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_mul(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

START_TEST(arithmetic_mul_10) {
  s21_decimal value1 = {{1, 1, 1, 0}};
  s21_decimal value2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal result2 = {{1, 1, 1, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_big_decimal big_result = {0};
  s21_big_decimal big_result2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  s21_convert_to_big_decimal(result, &big_result);
  s21_convert_to_big_decimal(result2, &big_result2);
  s21_big_mul(big_value1, big_value2, &big_result);
  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(big_result.bits[i], big_result2.bits[i]);
}
END_TEST

Suite *test_arithmetic_mul(void) {
  Suite *s = suite_create("s21_decimal arithmetic_mul");
  TCase *tc = tcase_create("arithmetic_mul_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, arithmetic_mul_1);
  tcase_add_test(tc, arithmetic_mul_2);
  tcase_add_test(tc, arithmetic_mul_3);
  tcase_add_test(tc, arithmetic_mul_4);
  tcase_add_test(tc, arithmetic_mul_5);
  tcase_add_test(tc, arithmetic_mul_6);
  tcase_add_test(tc, arithmetic_mul_7);
  tcase_add_test(tc, arithmetic_mul_8);
  tcase_add_test(tc, arithmetic_mul_9);
  tcase_add_test(tc, arithmetic_mul_10);
  return s;
}
