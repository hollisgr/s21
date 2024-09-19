#include "test_main.h"

START_TEST(strstr_1) {
  char str1[30] = "Hello, world!";
  char str2[30] = "o";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_2) {
  char str1[30] = "Hello, world!";
  char str2[30] = "l";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_3) {
  char str1[30] = "Hello, world!";
  char str2[30] = "world";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_4) {
  char str1[30] = "Hello, world!";
  char str2[30] = "World";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_5) {
  char str1[30] = "Darhan";
  char str2[30] = "KOROL'";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_6) {
  char str1[30] = "123, 123!";
  char str2[30] = "123";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_7) {
  char str1[30] = "Hell0, w0rld!";
  char str2[30] = "\0";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_8) {
  char str1[30] = "Hello! World!";
  char str2[30] = "!";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_9) {
  char str1[30] = "Hello, world!";
  char str2[30] = "hollisgr ftw";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_10) {
  char str1[30] = "qweasdqweasd";
  char str2[30] = "floriand";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("S21_strstr");
  TCase *tc = tcase_create("strstr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  return s;
}
