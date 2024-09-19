#include "test_main.h"

START_TEST(strtok_1) {
  char str[30] = "Hello, world!";
  char sep[10] = ",";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_2) {
  char str[30] = "Hello world!";
  char sep[10] = "/";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_3) {
  char str[30] = "Hello, world!";
  char sep[30] = "Hello, world!";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_4) {
  char str[30] = "floriand/thycidyl";
  char sep[10] = "/";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_5) {
  char str[30] = "floriand/hollisgr";
  char sep[10] = "/";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_6) {
  char str[30] = "floriand/thycidyl";
  char sep[10] = "3";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_7) {
  char str[30] = "Hello, world!";
  char sep[10] = "\0";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_8) {
  char str[30] = "\0";
  char sep[10] = "3";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_9) {
  char str[30] = "qweqwe!ave caesar!";
  char sep[10] = "!";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

START_TEST(strtok_10) {
  char str[30] = "verter <3 my wifu";
  char sep[10] = "<3";
  ck_assert_ptr_eq(strtok(str, sep), s21_strtok(str, sep));
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("S21_strtok");
  TCase *tc = tcase_create("strtok_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  return s;
}
