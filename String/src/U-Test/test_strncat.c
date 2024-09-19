#include "test_main.h"

START_TEST(strncat_1) {
  char dst1[30] = "Hello";
  char dst2[30] = "Hello";
  char app[] = " ";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_2) {
  char dst1[30] = "Hello";
  char dst2[30] = "Hello";
  char app[] = "!!!";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_3) {
  char dst1[30] = "Hello";
  char dst2[30] = "Hello";
  char app[] = " there";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_4) {
  char dst1[30] = "dARhan";
  char dst2[30] = "dARhan";
  char app[] = " megastar";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_5) {
  char dst1[30] = "20 percent";
  char dst2[30] = "20 percent";
  char app[] = " skill";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_6) {
  char dst1[30] = "10 percent";
  char dst2[30] = "10 percent";
  char app[] = " luck";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_7) {
  char dst1[30] = "VERA";
  char dst2[30] = "VERA";
  char app[] = "<3";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_8) {
  char dst1[30] = "SHAIGU";
  char dst2[30] = "SHAIGU";
  char app[] = " GDE SNARYADII>????";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_9) {
  char dst1[30] = "Hello";
  char dst2[30] = "Hello";
  char app[] = " moto";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

START_TEST(strncat_10) {
  char dst1[30] = "NOKIA";
  char dst2[30] = "NOKIA";
  char app[] = " CONNECTING PEOPLE";
  s21_size_t len = strlen(app);
  ck_assert_pstr_eq(strncat(dst1, app, len), s21_strncat(dst2, app, len));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("S21_strncat");
  TCase *tc = tcase_create("strncat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);
  return s;
}
