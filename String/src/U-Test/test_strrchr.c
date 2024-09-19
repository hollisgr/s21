#include "test_main.h"

START_TEST(strrchr_1) {
  char str[30] = "Hello, world!";
  int sym = 'o';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_2) {
  char str[30] = "Hello, world!";
  int sym = 'l';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_3) {
  char str[30] = "Hello, world!";
  int sym = '!';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_4) {
  char str[30] = "Hello, world!";
  int sym = '1';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_5) {
  char str[30] = "qwe, 1231!";
  int sym = '1';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_6) {
  char str[30] = "123, 123!";
  int sym = '3';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_7) {
  char str[30] = "Hell0, w0rld!";
  int sym = '0';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_8) {
  char str[30] = "Hello! World!";
  int sym = '!';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_9) {
  char str[30] = "Hello, world!";
  int sym = 'W';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

START_TEST(strrchr_10) {
  char str[30] = "qweasdqweasd";
  int sym = 'q';
  ck_assert_ptr_eq(strrchr(str, sym), s21_strrchr(str, sym));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("S21_strrchr");
  TCase *tc = tcase_create("strrchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);
  return s;
}
