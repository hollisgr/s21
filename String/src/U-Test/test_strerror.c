#include "test_main.h"

START_TEST(strerror_1) {
  int number = 1;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_2) {
  int number = 12;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_3) {
  int number = 55;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_4) {
  int number = 16;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_5) {
  int number = 23;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_6) {
  int number = 9;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_7) {
  int number = 22;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_8) {
  int number = 75;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_9) {
  int number = 61;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

START_TEST(strerror_10) {
  int number = 0;
  ck_assert_str_eq(strerror(number), s21_strerror(number));
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("S21_strerror");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  tcase_add_test(tc, strerror_6);
  tcase_add_test(tc, strerror_7);
  tcase_add_test(tc, strerror_8);
  tcase_add_test(tc, strerror_9);
  tcase_add_test(tc, strerror_10);
  return s;
}
