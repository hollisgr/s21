#include "test_main.h"

START_TEST(test_trim_1) {
  char src[] = "(hello, world)!";
  char trim_chars[] = "!()";
  char sample[] = "hello, world";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_2) {
  char src[] = "hello, world";
  char *trim_chars = S21_NULL;
  char sample[] = "hello, world";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_3) {
  char *src = S21_NULL;
  char trim_chars[] = "!()";
  char *sample = S21_NULL;
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_4) {
  char src[] = "Aehello, worldAB";
  char trim_chars[] = "ABe";
  char sample[] = "hello, world";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_5) {
  char src[] = "/floriand/hollisgr/thycydil/";
  char trim_chars[] = "/";
  char sample[] = "floriand/hollisgr/thycydil";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_6) {
  char *src = S21_NULL;
  char trim_chars[] = "d";
  char *sample = S21_NULL;
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_7) {
  char src[] = "(((hello, world)))!";
  char trim_chars[] = "!()";
  char sample[] = "hello, world";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_8) {
  char src[] = "";
  char trim_chars[] = "";
  char sample[] = "";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_9) {
  char src[] = "987123, 123987";
  char trim_chars[] = "789";
  char sample[] = "123, 123";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

START_TEST(test_trim_10) {
  char src[] = "(123, 123)!";
  char trim_chars[] = "!()";
  char sample[] = "123, 123";
  char *modsrc = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(modsrc, sample);
  free(modsrc);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, test_trim_1);
  tcase_add_test(tc, test_trim_2);
  tcase_add_test(tc, test_trim_3);
  tcase_add_test(tc, test_trim_4);
  tcase_add_test(tc, test_trim_5);
  tcase_add_test(tc, test_trim_6);
  tcase_add_test(tc, test_trim_7);
  tcase_add_test(tc, test_trim_8);
  tcase_add_test(tc, test_trim_9);
  tcase_add_test(tc, test_trim_10);

  suite_add_tcase(s, tc);
  return s;
}
