#include "test_main.h"

START_TEST(to_upper_1) {
  char str1[30] = "Hello, world!";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "HELLO, WORLD!";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_2) {
  char *str1 = S21_NULL;
  char *pstr = s21_to_upper(str1);
  ck_assert_pstr_eq(pstr, S21_NULL);
  free(pstr);
}
END_TEST

START_TEST(to_upper_3) {
  char str1[30] = "thycydil";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "THYCYDIL";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_4) {
  char str1[30] = "qwe123";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "QWE123";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_5) {
  char str1[30] = "123123";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "123123";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_6) {
  char str1[30] = "123qwe";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "123QWE";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_7) {
  char str1[30] = "hoLLiSgR";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "HOLLISGR";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_8) {
  char str1[30] = "h3110 w0r1d";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "H3110 W0R1D";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_9) {
  char str1[30] = "floriand/thycydil/hollisgr";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "FLORIAND/THYCYDIL/HOLLISGR";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

START_TEST(to_upper_10) {
  char str1[30] = "123,qwe,123";
  char *pstr = s21_to_upper(str1);
  char str2[30] = "123,QWE,123";
  ck_assert_pstr_eq(pstr, str2);
  free(pstr);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("S21_to_upper");
  TCase *tc = tcase_create("to_upper_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_3);
  tcase_add_test(tc, to_upper_4);
  tcase_add_test(tc, to_upper_5);
  tcase_add_test(tc, to_upper_6);
  tcase_add_test(tc, to_upper_7);
  tcase_add_test(tc, to_upper_8);
  tcase_add_test(tc, to_upper_9);
  tcase_add_test(tc, to_upper_10);
  return s;
}
