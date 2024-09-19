#include "test_main.h"

//-----S21_IS_LESS-----
//---------------------
START_TEST(big_comparison_1) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_2) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_3) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_4) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less(big_value1, big_value2), 1);
}
END_TEST

//-----S21_IS_LESS_OR_EQ-----
//---------------------------

START_TEST(big_comparison_5) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less_or_equal(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_6) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less_or_equal(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_7) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less_or_equal(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_8) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_less_or_equal(big_value1, big_value2), 1);
}
END_TEST

//-----S21_IS_GREATER-----
//------------------------

START_TEST(big_comparison_9) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_10) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_11) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_12) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater(big_value1, big_value2), 0);
}
END_TEST

//-----S21_IS_GREATER_OR_EQ-----
//------------------------------

START_TEST(big_comparison_13) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater_or_equal(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_14) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater_or_equal(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_15) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater_or_equal(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_16) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_greater_or_equal(big_value1, big_value2), 1);
}
END_TEST

//-----S21_IS_EQUAL-----
//----------------------

START_TEST(big_comparison_17) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_equal(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_18) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_equal(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_19) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_equal(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_20) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_equal(big_value1, big_value2), 1);
}
END_TEST

//-----S21_IS_NOT_EQUAL-----
//--------------------------

START_TEST(big_comparison_21) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_not_equal(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_22) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_not_equal(big_value1, big_value2), 0);
}
END_TEST

START_TEST(big_comparison_23) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_not_equal(big_value1, big_value2), 1);
}
END_TEST

START_TEST(big_comparison_24) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_big_decimal big_value1 = {0};
  s21_big_decimal big_value2 = {0};
  s21_convert_to_big_decimal(value1, &big_value1);
  s21_convert_to_big_decimal(value2, &big_value2);
  ck_assert_int_eq(s21_big_is_not_equal(big_value1, big_value2), 0);
}
END_TEST

Suite *test_big_comparison(void) {
  Suite *s = suite_create("s21_decimal big_comparison");
  TCase *tc = tcase_create("big_comparison_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, big_comparison_1);
  tcase_add_test(tc, big_comparison_2);
  tcase_add_test(tc, big_comparison_3);
  tcase_add_test(tc, big_comparison_4);
  tcase_add_test(tc, big_comparison_5);
  tcase_add_test(tc, big_comparison_6);
  tcase_add_test(tc, big_comparison_7);
  tcase_add_test(tc, big_comparison_8);
  tcase_add_test(tc, big_comparison_9);
  tcase_add_test(tc, big_comparison_10);
  tcase_add_test(tc, big_comparison_11);
  tcase_add_test(tc, big_comparison_12);
  tcase_add_test(tc, big_comparison_13);
  tcase_add_test(tc, big_comparison_14);
  tcase_add_test(tc, big_comparison_15);
  tcase_add_test(tc, big_comparison_16);
  tcase_add_test(tc, big_comparison_17);
  tcase_add_test(tc, big_comparison_18);
  tcase_add_test(tc, big_comparison_19);
  tcase_add_test(tc, big_comparison_20);
  tcase_add_test(tc, big_comparison_21);
  tcase_add_test(tc, big_comparison_22);
  tcase_add_test(tc, big_comparison_23);
  tcase_add_test(tc, big_comparison_24);
  return s;
}
