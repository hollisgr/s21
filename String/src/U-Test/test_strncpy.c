#include "test_main.h"

START_TEST(strncpy_1) {
  char str[30] = "Hello, world!";
  char dst[30] = "";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_2) {
  char str[30] = "123";
  char dst[30] = "";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_3) {
  char str[30] = "H3110 W0R1D";
  char dst[30] = "";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_4) {
  char str[30] = "321";
  char dst[30] = "123";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_5) {
  char str[30] = "321, 321";
  char dst[30] = "123";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_6) {
  char str[30] = "!!!";
  char dst[30] = "";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_7) {
  char str[30] = "qwe123qwe321";
  char dst[30] = "ewqewq";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_8) {
  char str[30] = "qwe123123qweasd";
  char dst[30] = "!!!!";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_9) {
  char *str = "\0";
  char dst[] = "Hello";
  // char *null = S21_NULL;
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

START_TEST(strncpy_10) {
  char str[30] = "omegalul";
  char dst[30] = "snoop doggy dogg";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(strncpy(str, dst, len), s21_strncpy(str, dst, len));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("S21_strncpy");
  TCase *tc = tcase_create("strncpy_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);
  tcase_add_test(tc, strncpy_8);
  tcase_add_test(tc, strncpy_9);
  tcase_add_test(tc, strncpy_10);
  return s;
}
