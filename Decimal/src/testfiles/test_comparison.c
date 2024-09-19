#include "test_main.h"

//-----S21_IS_LESS-----
//---------------------
START_TEST(comparison_1) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  ck_assert_int_eq(s21_is_less(value1, value2), 1);
}
END_TEST

START_TEST(comparison_2) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  ck_assert_int_eq(s21_is_less(value1, value2), 0);
}
END_TEST

START_TEST(comparison_3) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  ck_assert_int_eq(s21_is_less(value1, value2), 0);
}
END_TEST

START_TEST(comparison_4) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  ck_assert_int_eq(s21_is_less(value1, value2), 0);
}
END_TEST

//-----S21_IS_LESS_OR_EQ-----
//---------------------------

START_TEST(comparison_5) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(value1, value2), 1);
}
END_TEST

START_TEST(comparison_6) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(value1, value2), 1);
}
END_TEST

START_TEST(comparison_7) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(value1, value2), 0);
}
END_TEST

START_TEST(comparison_8) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  ck_assert_int_eq(s21_is_less_or_equal(value1, value2), 1);
}
END_TEST

//-----S21_IS_GREATER-----
//------------------------

START_TEST(comparison_9) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  ck_assert_int_eq(s21_is_greater(value1, value2), 0);
}
END_TEST

START_TEST(comparison_10) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  ck_assert_int_eq(s21_is_greater(value1, value2), 0);
}
END_TEST

START_TEST(comparison_11) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value1, value2), 1);
}
END_TEST

START_TEST(comparison_12) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  ck_assert_int_eq(s21_is_greater(value1, value2), 1);
}
END_TEST

//-----S21_IS_GREATER_OR_EQ-----
//------------------------------

START_TEST(comparison_13) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(value1, value2), 0);
}
END_TEST

START_TEST(comparison_14) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(value1, value2), 1);
}
END_TEST

START_TEST(comparison_15) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(value1, value2), 1);
}
END_TEST

START_TEST(comparison_16) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  ck_assert_int_eq(s21_is_greater_or_equal(value1, value2), 1);
}
END_TEST

//-----S21_IS_EQUAL-----
//----------------------

START_TEST(comparison_17) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  ck_assert_int_eq(s21_is_equal(value1, value2), 0);
}
END_TEST

START_TEST(comparison_18) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  ck_assert_int_eq(s21_is_equal(value1, value2), 1);
}
END_TEST

START_TEST(comparison_19) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  ck_assert_int_eq(s21_is_equal(value1, value2), 0);
}
END_TEST

START_TEST(comparison_20) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  ck_assert_int_eq(s21_is_equal(value1, value2), 1);
}
END_TEST

//-----S21_IS_NOT_EQUAL-----
//--------------------------

START_TEST(comparison_21) {
  s21_decimal value1 = {{255, 255, 254, 0}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  ck_assert_int_eq(s21_is_not_equal(value1, value2), 1);
}
END_TEST

START_TEST(comparison_22) {
  s21_decimal value1 = {{0, 0, 255, 0}};
  s21_decimal value2 = {{0, 0, 255, 0}};
  ck_assert_int_eq(s21_is_not_equal(value1, value2), 0);
}
END_TEST

START_TEST(comparison_23) {
  s21_decimal value1 = {{0, 255, 0, 0}};
  s21_decimal value2 = {{0, 254, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(value1, value2), 1);
}
END_TEST

START_TEST(comparison_24) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, MASK_NEGATIVE}};
  ck_assert_int_eq(s21_is_not_equal(value1, value2), 0);
}
END_TEST

START_TEST(comparison_25) {
  s21_decimal value1 = {{255, 255, 255, MASK_NEGATIVE}};
  s21_decimal value2 = {{255, 255, 255, 0}};
  ck_assert_int_eq(s21_comparison(value1, value2), -1);
}
END_TEST

//-----S21_ADDITIONS-----
//-----------------------
START_TEST(comparison_26) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_decimal value_2 = {{123456, 0, 0, 0}};
  s21_set_scale(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(comparison_27) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_decimal value_2 = {{123456, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(comparison_28) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(comparison_29) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(comparison_30) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(comparison_31) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

Suite *test_comparison(void) {
  Suite *s = suite_create("s21_decimal comparison");
  TCase *tc = tcase_create("comparison_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, comparison_1);
  tcase_add_test(tc, comparison_2);
  tcase_add_test(tc, comparison_3);
  tcase_add_test(tc, comparison_4);
  tcase_add_test(tc, comparison_5);
  tcase_add_test(tc, comparison_6);
  tcase_add_test(tc, comparison_7);
  tcase_add_test(tc, comparison_8);
  tcase_add_test(tc, comparison_9);
  tcase_add_test(tc, comparison_10);
  tcase_add_test(tc, comparison_11);
  tcase_add_test(tc, comparison_12);
  tcase_add_test(tc, comparison_13);
  tcase_add_test(tc, comparison_14);
  tcase_add_test(tc, comparison_15);
  tcase_add_test(tc, comparison_16);
  tcase_add_test(tc, comparison_17);
  tcase_add_test(tc, comparison_18);
  tcase_add_test(tc, comparison_19);
  tcase_add_test(tc, comparison_20);
  tcase_add_test(tc, comparison_21);
  tcase_add_test(tc, comparison_22);
  tcase_add_test(tc, comparison_23);
  tcase_add_test(tc, comparison_24);
  tcase_add_test(tc, comparison_25);
  tcase_add_test(tc, comparison_26);
  tcase_add_test(tc, comparison_27);
  tcase_add_test(tc, comparison_28);
  tcase_add_test(tc, comparison_29);
  tcase_add_test(tc, comparison_30);
  tcase_add_test(tc, comparison_31);
  return s;
}
