#include "test_main.h"

START_TEST(strpbrk_1) {
  char str[30] = "Hello, world!";
  char sym[30] = "o";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_2) {
  char str[30] = "Hello, world!";
  char sym[30] = "!";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_3) {
  char str[30] = "Hello, world!";
  char sym[30] = "123";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_4) {
  char str[30] = "Hello, 123!";
  char sym[30] = "123";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_5) {
  char str[30] = "123, world!";
  char sym[30] = "123";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_6) {
  char str[30] = "Hello, world!";
  char sym[30] = "w";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_7) {
  char str[30] = "Hello, world!";
  char sym[30] = "a";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_8) {
  char str[30] = "Hello, world!";
  char sym[30] = "K";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_9) {
  char str[30] = "123, 789!";
  char sym[30] = "9";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_10) {
  char str[30] = "Hello, world!";
  char sym[30] = ",";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("S21_strpbrk");
  TCase *tc = tcase_create("strpbrk_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strpbrk_9);
  tcase_add_test(tc, strpbrk_10);
  return s;
}
