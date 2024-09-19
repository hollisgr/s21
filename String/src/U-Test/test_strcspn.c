#include "test_main.h"

START_TEST(strcspn_1) {
  char str[] = "Hello, world!";
  char symbol[] = "world";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_2) {
  char str[] = "Hello, world!";
  char symbol[] = "llo";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_3) {
  char str[] = "Hello, world!";
  char symbol[] = "123";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_4) {
  char str[] = "Hello, world!";
  char symbol[] = "!";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_5) {
  char str[] = "Hello, world!";
  char symbol[] = " ";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_6) {
  char str[] = "123, 123!";
  char symbol[] = "123";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_7) {
  char str[] = "qwe, 123!";
  char symbol[] = "!";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_8) {
  char str[] = "1237890!";
  char symbol[] = "0";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_9) {
  char str[] = "123456789!";
  char symbol[] = "89!";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

START_TEST(strcspn_10) {
  char str[] = "qwe123";
  char symbol[] = "";
  ck_assert_int_eq(strcspn(str, symbol), s21_strcspn(str, symbol));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s = suite_create("S21_strcspn");
  TCase *tc = tcase_create("strcspn_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  return s;
}
