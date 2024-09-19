#include "test_main.h"

START_TEST(memset_1) {
  char str[] = "Hello";
  char dst = 'c';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_2) {
  char str[] = "Hello";
  char dst = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_3) {
  char str[] = "123";
  char dst = '!';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_4) {
  char str[] = "123123123";
  char dst = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_5) {
  char str[] = "asd";
  char dst = '2';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_6) {
  char str[] = "qwerty";
  char dst = '1';
  s21_size_t len = 3;
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_7) {
  char str[] = "Hello, world!";
  char dst = ']';
  s21_size_t len = 2;
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_8) {
  char str[] = "asd, asd!";
  char dst = ' ';
  s21_size_t len = 8;
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_9) {
  char str[] = "asd, 123!";
  char dst = ' ';
  s21_size_t len = 2;
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

START_TEST(memset_10) {
  char str[] = "123)(&*&*^&*6)";
  char dst = '^';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memset(str, dst, len), s21_memset(str, dst, len));
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("S21_memset");
  TCase *tc = tcase_create("memset_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);
  tcase_add_test(tc, memset_7);
  tcase_add_test(tc, memset_8);
  tcase_add_test(tc, memset_9);
  tcase_add_test(tc, memset_10);
  return s;
}
