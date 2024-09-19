#include "test_main.h"

START_TEST(test_sscanf_1) {
  char src[] = "hello, world!";
  char dst[30];
  char format[] = "%s";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_2) {
  char src[] = "hello, world!";
  char dst[30];
  char format[] = "%c";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_3) {
  char src[] = "123hello, world!";
  char dst[30];
  char format[] = "%d";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_4) {
  char src[] = "-123.3 +123132 hello, world!";
  char dst[30];
  char format[] = "%f";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_5) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%lf";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_6) {
  char src[] = "123 123123 hello, world!";
  char dst[30];
  char format[] = "%ld";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_7) {
  char src[] = "12bcde3fa23 hello, world!";
  char dst[30];
  char format[] = "%x";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_8) {
  char src[] = "A0 hello, world!";
  char dst[30];
  char format[] = "%o";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_9) {
  char src[] = "A0 hello, world!";
  char dst[30];
  char format[] = "%X";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_10) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%Lf";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_11) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%*d %s";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_12) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%2d";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_13) {
  char src[] = "-123.3, 123123.3 hello, world!";
  char dst[30];
  char format[] = "%u";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_14) {
  char src[] = "123.3, hello, world!";
  char dst[30];
  char format[] = "%p";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_15) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%i";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_16) {
  char src[] = "123.3, hello, world!";
  char dst[30];
  char format[] = "%G";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_17) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%g";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_18) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%hd";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_19) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%lu";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_20) {
  char src[] = "-123.3, hello, world!";
  char dst[30];
  char format[] = "%hu";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_21) {
  char src[] = "123 743 6347";
  char dst[30];
  char format[] = "%o";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_22) {
  char src[] = "123 743 6347";
  char dst[30];
  char format[] = "%ho";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_23) {
  char src[] = "123 743 6347";
  char dst[30];
  char format[] = "%lo";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_24) {
  char src[] = "123123123.3, 123123.3 hello, world!";
  char dst[30];
  char format[] = "%2u";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_25) {
  char src[] = "12bcde3fa23 hello, world!";
  char dst[30];
  char format[] = "%hx";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_26) {
  char src[] = "12bcde3fa23 hello, world!";
  char dst[30];
  char format[] = "%lx";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_27) {
  char src[] = "-123!";
  char dst[30];
  char format[] = "%d";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_28) {
  char src[] = "+123!";
  char dst[30];
  char format[] = "%d";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

START_TEST(test_sscanf_29) {
  char src[] = "-1af23!";
  char dst[30];
  char format[] = "%p";
  ck_assert_int_eq(sscanf(src, format, dst), s21_sscanf(src, format, dst));
}
END_TEST

Suite *test_sscanf(void) {
  Suite *s = suite_create("s21_sscanf");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, test_sscanf_1);
  tcase_add_test(tc, test_sscanf_2);
  tcase_add_test(tc, test_sscanf_3);
  tcase_add_test(tc, test_sscanf_4);
  tcase_add_test(tc, test_sscanf_5);
  tcase_add_test(tc, test_sscanf_6);
  tcase_add_test(tc, test_sscanf_7);
  tcase_add_test(tc, test_sscanf_8);
  tcase_add_test(tc, test_sscanf_9);
  tcase_add_test(tc, test_sscanf_10);
  tcase_add_test(tc, test_sscanf_11);
  tcase_add_test(tc, test_sscanf_12);
  tcase_add_test(tc, test_sscanf_13);
  tcase_add_test(tc, test_sscanf_14);
  tcase_add_test(tc, test_sscanf_15);
  tcase_add_test(tc, test_sscanf_16);
  tcase_add_test(tc, test_sscanf_17);
  tcase_add_test(tc, test_sscanf_18);
  tcase_add_test(tc, test_sscanf_19);
  tcase_add_test(tc, test_sscanf_20);
  tcase_add_test(tc, test_sscanf_21);
  tcase_add_test(tc, test_sscanf_22);
  tcase_add_test(tc, test_sscanf_23);
  tcase_add_test(tc, test_sscanf_24);
  tcase_add_test(tc, test_sscanf_25);
  tcase_add_test(tc, test_sscanf_26);
  tcase_add_test(tc, test_sscanf_27);
  tcase_add_test(tc, test_sscanf_28);
  tcase_add_test(tc, test_sscanf_29);
  suite_add_tcase(s, tc);
  return s;
}
