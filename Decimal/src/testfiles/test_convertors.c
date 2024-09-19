#include "test_main.h"

//-----S21_FROM_INT_TO_DECIMAL-----
//---------------------------------

START_TEST(convertors_1) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  int value2 = 1;
  s21_from_int_to_decimal(value2, &value1);
  s21_decimal result = {{1, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
}
END_TEST

START_TEST(convertors_2) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  int value2 = 255;
  s21_from_int_to_decimal(value2, &value1);
  s21_decimal result = {{255, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
}
END_TEST

START_TEST(convertors_3) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  int value2 = -255;
  s21_from_int_to_decimal(value2, &value1);
  s21_decimal result = {{255, 0, 0, MASK_NEGATIVE}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
}
END_TEST

// START_TEST(convertors_4) {
//   s21_decimal value1 = {{0, 0, 0, 0}};
//   int value2;
//   int x = s21_from_int_to_decimal(value2, &value1);
//   ck_assert_int_eq(x, 1);
// }
// END_TEST

//-----S21_FROM_FLOAT_TO_DECIMAL-----
//---------------------------------

START_TEST(convertors_5) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  float value2 = 1.25;
  s21_from_float_to_decimal(value2, &value1);
  s21_decimal result = {{125, 0, 0, 0}};
  s21_set_scale(&result, 2);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
}
END_TEST

START_TEST(convertors_6) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  float value2 = -1.25;
  s21_from_float_to_decimal(value2, &value1);
  s21_decimal result = {{125, 0, 0, MASK_NEGATIVE}};
  s21_set_scale(&result, 2);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
}
END_TEST

START_TEST(convertors_7) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  float value2 = -255.255;
  s21_from_float_to_decimal(value2, &value1);
  s21_decimal result = {{255255, 0, 0, MASK_NEGATIVE}};
  s21_set_scale(&result, 3);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
}
END_TEST

// START_TEST(convertors_8) {
//   s21_decimal value1 = {{0, 0, 0, 0}};
//   float value2;
//   int x = s21_from_float_to_decimal(value2, &value1);
//   ck_assert_int_eq(x, 1);
// }
// END_TEST

//-----S21_FROM_DECIMAL_TO_INT-----
//---------------------------------

START_TEST(convertors_9) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  int num = 0;
  int *pnum = &num;
  s21_set_scale(&value1, 1);
  s21_from_decimal_to_int(value1, pnum);
  ck_assert_int_eq(num, 10);
}
END_TEST

START_TEST(convertors_10) {
  s21_decimal value1 = {{250, 0, 0, 0}};
  int num = 0;
  int *pnum = &num;
  s21_set_scale(&value1, 2);
  s21_from_decimal_to_int(value1, pnum);
  ck_assert_int_eq(num, 2);
}
END_TEST

START_TEST(convertors_11) {
  s21_decimal value1 = {{255255, 0, 0, 0}};
  int num = 0;
  int *pnum = &num;
  s21_set_scale(&value1, 3);
  s21_from_decimal_to_int(value1, pnum);
  ck_assert_int_eq(num, 255);
}
END_TEST

START_TEST(convertors_12) {
  s21_decimal value1 = {{0xFFFFFFFF, 1, 0, 0}};
  int num = 0;
  int *pnum = &num;
  s21_set_scale(&value1, 9);
  s21_from_decimal_to_int(value1, pnum);
  ck_assert_int_eq(num, 8);
}
END_TEST

START_TEST(convertors_13) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_set_sign(&value1, 1);
  int num = 0;
  int *pnum = &num;
  s21_from_decimal_to_int(value1, pnum);
  ck_assert_int_eq(num, -255);
}
END_TEST

//-----S21_FROM_DECIMAL_TO_FLOAT-----
//-----------------------------------

START_TEST(convertors_14) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  float num = 0;
  float *pnum = &num;
  s21_set_scale(&value1, 0);
  s21_from_decimal_to_float(value1, pnum);
  ck_assert_float_eq(num, 100);
}
END_TEST

START_TEST(convertors_15) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_set_scale(&value1, 1);
  float num = 0;
  float *pnum = &num;
  s21_from_decimal_to_float(value1, pnum);
  ck_assert_float_eq(num, 10);
}
END_TEST

START_TEST(convertors_16) {
  s21_decimal value1 = {{100, 0, 0, 0}};
  s21_set_scale(&value1, 1);
  s21_set_sign(&value1, 1);
  float num = 0;
  float *pnum = &num;
  s21_from_decimal_to_float(value1, pnum);
  ck_assert_float_eq(num, -10);
}
END_TEST

START_TEST(convertors_17) {
  s21_decimal value1 = {{255, 0, 0, 0}};
  s21_set_scale(&value1, 2);
  float num = 0;
  float *pnum = &num;
  s21_from_decimal_to_float(value1, pnum);
  ck_assert_float_eq(num, 2.55);
}
END_TEST

START_TEST(convertors_18) {
  s21_decimal value1 = {{2, 0, 0, 0}};
  s21_decimal value2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  float num;
  float *pnum = &num;
  s21_div(value1, value2, &result);
  s21_from_decimal_to_float(result, pnum);
  ck_assert_int_eq(fabs((num - 0.66666)) < 1e-4, 1);
}
END_TEST

START_TEST(convertors_19) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  float value2 = 0.000125;
  s21_from_float_to_decimal(value2, &value1);
  s21_decimal result = {{125, 0, 0, 0}};
  s21_set_scale(&result, 6);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
}
END_TEST

START_TEST(convertors_20) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  float value2 = 7777777777777;
  int x = s21_from_float_to_decimal(value2, &value1);
  ck_assert_int_eq(x, 1);
}
END_TEST

START_TEST(convertors_21) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  float value2 = -777;
  int x = s21_from_float_to_decimal(value2, &value1);
  s21_decimal result = {{777, 0, 0, MASK_NEGATIVE}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], value1.bits[i]);
  ck_assert_int_eq(x, 0);
}
END_TEST

Suite *test_convertors(void) {
  Suite *s = suite_create("s21_decimal convertors");
  TCase *tc = tcase_create("convertors_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, convertors_1);
  tcase_add_test(tc, convertors_2);
  tcase_add_test(tc, convertors_3);
  // tcase_add_test(tc, convertors_4);
  tcase_add_test(tc, convertors_5);
  tcase_add_test(tc, convertors_6);
  tcase_add_test(tc, convertors_7);
  // tcase_add_test(tc, convertors_8);
  tcase_add_test(tc, convertors_9);
  tcase_add_test(tc, convertors_10);
  tcase_add_test(tc, convertors_11);
  tcase_add_test(tc, convertors_12);
  tcase_add_test(tc, convertors_13);
  tcase_add_test(tc, convertors_14);
  tcase_add_test(tc, convertors_15);
  tcase_add_test(tc, convertors_16);
  tcase_add_test(tc, convertors_17);
  tcase_add_test(tc, convertors_18);
  tcase_add_test(tc, convertors_19);
  tcase_add_test(tc, convertors_20);
  tcase_add_test(tc, convertors_21);
  return s;
}
