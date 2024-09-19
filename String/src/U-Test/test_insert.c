#include "test_main.h"

START_TEST(insert_1) {
  char src[30] = "Hello, world!";
  char str[30] = "123 ";
  size_t index = 7;
  char *sample = "Hello, 123 world!";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_2) {
  char src[30] = "";
  char str[30] = "asd";
  size_t index = 1;
  char *sample = S21_NULL;
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_3) {
  char src[30] = "Hello, world!";
  char str[30] = "";
  size_t index = 7;
  char *sample = "Hello, world!";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_4) {
  char src[30] = "123, world!";
  char str[30] = "123 ";
  size_t index = 5;
  char *sample = "123, 123 world!";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_5) {
  char src[30] = "floriand//hollisgr";
  char str[30] = "thycydil";
  size_t index = 9;
  char *sample = "floriand/thycydil/hollisgr";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_6) {
  char src[30] = "Hello";
  char str[30] = "123 ";
  size_t index = 12;
  char *sample = S21_NULL;
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_7) {
  char src[30] = "Hello, world!";
  char str[30] = "123 ";
  size_t index = 7;
  char *sample = "Hello, 123 world!";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_8) {
  char src[30] = "Hello, world!";
  char str[30] = "123";
  size_t index = 7;
  char *sample = "Hello, 123world!";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_9) {
  char src[30] = "Hello, world!";
  char str[30] = " 123";
  size_t index = 7;
  char *sample = "Hello,  123world!";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

START_TEST(insert_10) {
  char src[30] = "Hello, world!";
  char str[30] = "^^^ ";
  size_t index = 7;
  char *sample = "Hello, ^^^ world!";
  char *pstr = s21_insert(src, str, index);
  ck_assert_pstr_eq(pstr, sample);
  free(pstr);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("S21_insert");
  TCase *tc = tcase_create("insert_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);
  tcase_add_test(tc, insert_7);
  tcase_add_test(tc, insert_8);
  tcase_add_test(tc, insert_9);
  tcase_add_test(tc, insert_10);
  return s;
}
