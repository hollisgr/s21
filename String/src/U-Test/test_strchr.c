#include "test_main.h"

START_TEST(strchr_1) {
  char str[] = "Hello, world!";
  int symbol = 72;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_2) {
  char str[] = "Hello, world!";
  int symbol = 69;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_3) {
  char str[] = "Hello, world!";
  int symbol = 33;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_4) {
  char str[] = "123123";
  int symbol = 69;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_5) {
  char str[] = "123 123";
  int symbol = 8;

  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_6) {
  char str[] = "123123";
  int symbol = 72;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_7) {
  char str[] = "123123!";
  int symbol = 49;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_8) {
  char *str = "";
  int symbol = 72;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_9) {
  char str[] = "Hello, world!";
  int symbol = 0;
  ck_assert_ptr_eq(strchr(str, symbol), s21_strchr(str, symbol));
}
END_TEST

START_TEST(strchr_10) {
  char *str = S21_NULL;
  int symbol = 44;
  ck_assert_ptr_eq(S21_NULL, s21_strchr(str, symbol));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("S21_strchr");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);
  return s;
}
