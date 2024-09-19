#include "test_main.h"

//-----S21_GET_BIT-----
//---------------------
START_TEST(setters_1) {
  s21_decimal value1 = {{256, 0, 0, 0}};
  s21_decimal value2 = {{256, 0, 0, 0}};
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, i), s21_get_bit(value2, i));
}
END_TEST

START_TEST(setters_2) {
  s21_decimal value1 = {{0, 256, 0, 0}};
  s21_decimal value2 = {{0, 256, 0, 0}};
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, i), s21_get_bit(value2, i));
}
END_TEST

START_TEST(setters_3) {
  s21_decimal value1 = {{0, 0, 256, 0}};
  s21_decimal value2 = {{0, 0, 256, 0}};
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, i), s21_get_bit(value2, i));
}
END_TEST

START_TEST(setters_4) {
  s21_decimal value1 = {{0, 0, 0, 256}};
  s21_decimal value2 = {{0, 0, 0, 256}};
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, i), s21_get_bit(value2, i));
}
END_TEST

START_TEST(setters_5) {
  s21_decimal value1 = {{0, 0, 256, 0}};
  s21_decimal value2 = {{0, 0, 256, 0}};
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, i), s21_get_bit(value2, i));
}
END_TEST

START_TEST(setters_6) {
  s21_decimal value1 = {{1, 1, 1, 1}};
  s21_decimal value2 = {{1, 1, 1, 1}};
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, i), s21_get_bit(value2, i));
}
END_TEST

START_TEST(setters_7) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, i), s21_get_bit(value2, i));
}
END_TEST

//-----S21_SET_BIT-----
//---------------------

START_TEST(setters_8) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{1, 0, 0, 0}};
  s21_set_bit(&value1, 0, 1);
  for (int i = 0; i < 127; i++)
    ck_assert_int_eq(s21_get_bit(value1, 1), s21_get_bit(value2, 1));
}
END_TEST

START_TEST(setters_9) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 1, 0, 0}};
  s21_set_bit(&value1, 32, 1);
  ck_assert_int_eq(s21_get_bit(value1, 32), s21_get_bit(value2, 32));
}
END_TEST

START_TEST(setters_10) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 1, 0}};
  s21_set_bit(&value1, 64, 1);
  ck_assert_int_eq(s21_get_bit(value1, 64), s21_get_bit(value2, 64));
}
END_TEST

START_TEST(setters_11) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 1}};
  s21_set_bit(&value1, 96, 1);
  ck_assert_int_eq(s21_get_bit(value1, 96), s21_get_bit(value2, 96));
}
END_TEST

//-----S21_GET_SIGN-----
//----------------------

START_TEST(setters_12) {
  s21_decimal value1 = {{0, 0, 0, MASK_NEGATIVE}};
  s21_decimal value2 = {{0, 0, 0, MASK_NEGATIVE}};
  ck_assert_int_eq(s21_get_sign(value1), s21_get_sign(value2));
}
END_TEST

START_TEST(setters_13) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_get_sign(value1), s21_get_sign(value2));
}
END_TEST

//-----S21_SET_SIGN-----
//----------------------

START_TEST(setters_14) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, MASK_NEGATIVE}};
  s21_set_sign(&value1, 1);
  ck_assert_int_eq(s21_get_bit(value1, 127), s21_get_bit(value2, 127));
}
END_TEST

START_TEST(setters_15) {
  s21_decimal value1 = {{0, 0, 0, MASK_NEGATIVE}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  s21_set_sign(&value1, 0);
  ck_assert_int_eq(s21_get_bit(value1, 127), s21_get_bit(value2, 127));
}
END_TEST

//-----S21_GET_SCALE-----
//-----------------------

START_TEST(setters_16) {
  int a;
  a = 31;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, a);
  ck_assert_int_eq(s21_get_scale(value1), 31);
}
END_TEST

START_TEST(setters_17) {
  int a;
  a = 0;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, a);
  ck_assert_int_eq(s21_get_scale(value1), 0);
}
END_TEST

START_TEST(setters_18) {
  int a;
  a = 5;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, a);
  ck_assert_int_eq(s21_get_scale(value1), 5);
}
END_TEST

START_TEST(setters_19) {
  int a;
  a = 13;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, a);
  ck_assert_int_eq(s21_get_scale(value1), 13);
}
END_TEST

START_TEST(setters_20) {
  int a;
  a = 28;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, a);
  ck_assert_int_eq(s21_get_scale(value1), 28);
}
END_TEST

START_TEST(setters_21) {
  int a;
  a = 1;
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, a);
  ck_assert_int_eq(s21_get_scale(value1), 1);
}
END_TEST

//-----S21_SET_SCALE-----
//-----------------------

START_TEST(setters_22) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, 31);
  ck_assert_int_eq(s21_get_scale(value1), 31);
}
END_TEST

START_TEST(setters_23) {
  s21_decimal value1 = {{0, 256, 0, 0x1F00}};
  s21_set_scale(&value1, 0);
  ck_assert_int_eq(s21_get_scale(value1), 0);
}
END_TEST

START_TEST(setters_24) {
  s21_decimal value1 = {{0, 0, 256, 0}};
  s21_set_scale(&value1, 15);
  ck_assert_int_eq(s21_get_scale(value1), 15);
}
END_TEST

START_TEST(setters_25) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_set_scale(&value1, 7);
  ck_assert_int_eq(s21_get_scale(value1), 7);
}
END_TEST

START_TEST(setters_26) {
  s21_decimal value1 = {{0, 256, 256, 0}};
  s21_set_scale(&value1, 3);
  ck_assert_int_eq(s21_get_scale(value1), 3);
  ck_assert_int_eq(s21_get_sign(value1), 0);
}
END_TEST

START_TEST(setters_27) {
  s21_decimal value1 = {{0, 255, 255, MASK_NEGATIVE}};
  s21_set_scale(&value1, 1);
  ck_assert_int_eq(s21_get_scale(value1), 1);
  ck_assert_int_eq(s21_get_sign(value1), 1);
}
END_TEST

Suite *test_setters(void) {
  Suite *s = suite_create("s21_decimal setters");
  TCase *tc = tcase_create("setters_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, setters_1);
  tcase_add_test(tc, setters_2);
  tcase_add_test(tc, setters_3);
  tcase_add_test(tc, setters_4);
  tcase_add_test(tc, setters_5);
  tcase_add_test(tc, setters_6);
  tcase_add_test(tc, setters_7);
  tcase_add_test(tc, setters_8);
  tcase_add_test(tc, setters_9);
  tcase_add_test(tc, setters_10);
  tcase_add_test(tc, setters_11);
  tcase_add_test(tc, setters_12);
  tcase_add_test(tc, setters_13);
  tcase_add_test(tc, setters_14);
  tcase_add_test(tc, setters_15);
  tcase_add_test(tc, setters_16);
  tcase_add_test(tc, setters_17);
  tcase_add_test(tc, setters_18);
  tcase_add_test(tc, setters_19);
  tcase_add_test(tc, setters_20);
  tcase_add_test(tc, setters_21);
  tcase_add_test(tc, setters_22);
  tcase_add_test(tc, setters_23);
  tcase_add_test(tc, setters_24);
  tcase_add_test(tc, setters_25);
  tcase_add_test(tc, setters_26);
  tcase_add_test(tc, setters_27);
  return s;
}
