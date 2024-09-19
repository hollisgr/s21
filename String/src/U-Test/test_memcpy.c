#include "test_main.h"

START_TEST(memcpy_1) {
  char str[] = "Hello";
  char dst[] = "world!";
  s21_size_t len = strlen(dst);
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_2) {
  char str[] = "Hello";
  char dst[] = "123!";
  s21_size_t len = strlen(dst);
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_3) {
  char str[] = "123";
  char dst[] = "456";
  s21_size_t len = strlen(dst);
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_4) {
  char str[] = "!";
  char dst[] = " ";
  s21_size_t len = strlen(dst);
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_5) {
  char str[] = "asd";
  char dst[] = "dsa";
  s21_size_t len = strlen(dst);
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_6) {
  char str[] = "qwe";
  char dst[] = "123";
  s21_size_t len = 3;
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_7) {
  char str[] = "Hello, world!";
  char dst[] = "asd, dsa!";
  s21_size_t len = 2;
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_8) {
  char str[] = "asd, asd!";
  char dst[] = "asd, asd!";
  s21_size_t len = 8;
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_9) {
  char str[] = "asd, 123!";
  char dst[] = "asd, 123!";
  s21_size_t len = 2;
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

START_TEST(memcpy_10) {
  char str[] = "123)(&*&*^&*6)";
  char dst[] = ":{}(*^$)";
  s21_size_t len = strlen(dst);
  ck_assert_ptr_eq(memcpy(str, dst, len), s21_memcpy(str, dst, len));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("S21_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  tcase_add_test(tc, memcpy_7);
  tcase_add_test(tc, memcpy_8);
  tcase_add_test(tc, memcpy_9);
  tcase_add_test(tc, memcpy_10);
  return s;
}
