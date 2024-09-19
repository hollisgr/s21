#include "test_main.h"

START_TEST(to_lower_1) {
  char str1[30] = "HELLO, WORLD!";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "hello, world!";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_2) {
  char *str1 = S21_NULL;
  char *pstr = s21_to_lower(str1);
  ck_assert_pstr_eq(pstr, S21_NULL);
  free(pstr);
}
END_TEST

START_TEST(to_lower_3) {
  char str1[30] = "ThyCyDiL";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "thycydil";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_4) {
  char str1[30] = "QWE123";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "qwe123";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_5) {
  char str1[30] = "123123";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "123123";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_6) {
  char str1[30] = "123QWE";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "123qwe";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_7) {
  char str1[30] = "HOLLISGR";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "hollisgr";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_8) {
  char str1[30] = "H3110 W0R1D";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "h3110 w0r1d";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_9) {
  char str1[30] = "FLORIAND/THYCYDIL/HOLLISGR";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "floriand/thycydil/hollisgr";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_lower_10) {
  char str1[30] = "123,QWE,123";
  char *pstr = s21_to_lower(str1);
  char str2[30] = "123,qwe,123";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("S21_to_lower");
  TCase *tc = tcase_create("to_lower_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, to_lower_3);
  tcase_add_test(tc, to_lower_4);
  tcase_add_test(tc, to_lower_5);
  tcase_add_test(tc, to_lower_6);
  tcase_add_test(tc, to_lower_7);
  tcase_add_test(tc, to_lower_8);
  tcase_add_test(tc, to_lower_9);
  tcase_add_test(tc, to_lower_10);
  return s;
}
