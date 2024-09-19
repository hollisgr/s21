#include "test_main.h"

START_TEST(strncmp_1) {
  char str1[30] = "Hello";
  char str2[30] = "Hello";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_2) {
  char str1[30] = "Hell0";
  char str2[30] = "Hell0";
  s21_size_t len = 0;
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_3) {
  char str1[30] = "Hello";
  char str2[30] = "HellO";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(32, s21_strncmp(str1, str2, len));
  // ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_4) {
  char str1[30] = "123";
  char str2[30] = "123";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_5) {
  char str1[30] = "321";
  char str2[30] = "321";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_6) {
  char str1[30] = "!!!";
  char str2[30] = "!!!";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_7) {
  char str1[30] = "qwe123qwe321";
  char str2[30] = "qwe123qwe321";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_8) {
  char str1[30] = "qwe123123qweasd";
  char str2[30] = "qwe123123qweasd";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_9) {
  char str1[30] = "asdasd123321";
  char str2[30] = "asdasd123321";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

START_TEST(strncmp_10) {
  char str1[30] = "omegalul";
  char str2[30] = "omegalul";
  s21_size_t len = strlen(str1);
  ck_assert_int_eq(strncmp(str1, str2, len), s21_strncmp(str1, str2, len));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("S21_strncmp");
  TCase *tc = tcase_create("strncmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);
  return s;
}
