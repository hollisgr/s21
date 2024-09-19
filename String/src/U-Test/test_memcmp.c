#include "test_main.h"

START_TEST(memcmp_1) {
  char str[30] = "Hello, world!";
  char dst[30] = "Hello, world!";
  s21_size_t len = 13;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_2) {
  char str[30] = "Aello, world!";
  char dst[30] = "Hello, borld!";
  s21_size_t len = 1;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_3) {
  char str[30] = "3ello, world!";
  char dst[30] = "H3llo, world!";
  s21_size_t len = 1;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_4) {
  char str[30] = "Hello, world!";
  char dst[30] = "12345, world!";
  s21_size_t len = 1;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_5) {
  char str[30] = "Wello, world!";
  char dst[30] = "Hello, 123!";
  s21_size_t len = 1;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_6) {
  char str[30] = "Hello, world!";
  char dst[30] = "123, 123!";
  s21_size_t len = 1;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_7) {
  char str[30] = "Hello, world!";
  char dst[30] = "asd, dsa!";
  s21_size_t len = 1;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_8) {
  char str[30] = "asd, asd!";
  char dst[30] = "asd, asd!";
  s21_size_t len = 9;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_9) {
  char str[30] = "asd, 123!";
  char dst[30] = "asd, 123!";
  s21_size_t len = 9;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

START_TEST(memcmp_10) {
  char str[30] = "asd, 123!";
  char dst[30] = "123, 123!";
  s21_size_t len = 1;
  ck_assert_int_eq(memcmp(str, dst, len), s21_memcmp(str, dst, len));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("S21_memcmp");
  TCase *tc = tcase_create("memcmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  return s;
}
