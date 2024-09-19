#include "test_main.h"

START_TEST(sprintf_1) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "qwe %s asd";
  char *val = "How's there?";
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_2) {
  char dst1[100];
  char dst2[100];
  char *str = "%s and %s and %s";
  char *val = "hollisgr";
  char *val2 = "floriand";
  char *val3 = "thycydil";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_3) {
  char dst1[100];
  char dst2[100];
  char *str = "%s test %s test %s";
  char *val = "";
  char *val2 = "";
  char *val3 = "";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_4) {
  char dst1[100];
  char dst2[100];
  char *str = "%3s %5s %10s";
  char *val = "abcdef";
  char *val2 = "qwe123";
  char *val3 = "zxcasdqwe";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_5) {
  char dst1[100];
  char dst2[100];
  char *str = "%6.5s Test %.23s Test %3.s Test %.s";
  char *val = "abcdef";
  char *val2 = "qwe123";
  char *val3 = "zxcasdqwe";
  char *val4 = "123asd456qwe";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_6) {
  char dst1[100];
  char dst2[100];
  char *str = "%-10.5s Test %-.8s Test %-7s Test %-.s";
  char *val = "abcdef";
  char *val2 = "qwe123";
  char *val3 = "zxcasdqwe";
  char *val4 = "123asd456qwe";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_7) {
  char dst1[100];
  char dst2[100];
  char *str = "%0s Test %0.s Test %0.0s Test %0s Test %.s";
  char *val = "abc";
  char *val2 = "qwe";
  char *val3 = "zxc";
  char *val4 = "123";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_8) {
  char dst1[100];
  char dst2[100];
  char *str = "%+s Test %+3.s Test %5.7s Test %10s";
  char *val = "abcdef";
  char *val2 = "qwe123";
  char *val3 = "zxcasdqwe";
  char *val4 = "123asd456qwe";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_9) {
  char dst1[100];
  char dst2[100];
  char *str = "%s Test %3.s Test %5.7s Test %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(dst1, str, val, val, val, val, val, val, val, val, val),
      s21_sprintf(dst2, str, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_10) {
  char dst1[100];
  char dst2[100];
  char *str = "% s Test % 3.s Test % 5.7s Test % 10s Test %.s";
  char *val = "abcdef";
  char *val2 = "qwe123";
  char *val3 = "zxcasdqwe";
  char *val4 = "123asd456qwe";
  char *val5 = "123123123";
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_11) {
  char dst1[100];
  char dst2[100];
  char *str = "%c Test %c Test %c Test %c Test %c";
  char a = -1;
  int b = 2;
  int c = -3;
  int d = 4;
  int e = -5;
  ck_assert_int_eq(sprintf(dst1, str, a, b, c, d, e),
                   s21_sprintf(dst2, str, a, b, c, d, e));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_12) {
  char dst1[100];
  char dst2[100];
  char *str = "%c Test %c Test %c Test %c Test %c";
  char a = -13;
  int b = 2497;
  int c = -3697;
  int d = 4654;
  int e = -5465;
  ck_assert_int_eq(sprintf(dst1, str, a, b, c, d, e),
                   s21_sprintf(dst2, str, a, b, c, d, e));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_13) {
  char dst1[100];
  char dst2[100];
  char *str = "%-010c Test % -10c Test %-c";
  int a = 123;
  int b = 123;
  ck_assert_int_eq(sprintf(dst1, str, a, a, b),
                   s21_sprintf(dst2, str, a, a, b));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_14) {
  char dst1[100];
  char dst2[100];
  char *str = "%6.4c Test %-6.4c Test %4.10c Test %-4.10c Test %-0c";
  int a = 10;
  int b = -10;
  int c = 10;
  ck_assert_int_eq(sprintf(dst1, str, a, a, b, c, c),
                   s21_sprintf(dst2, str, a, a, b, c, c));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_15) {
  char dst1[100];
  char dst2[100];
  char *str = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(dst1, str, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(dst2, str, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_16) {
  char dst1[400];
  char dst2[400];
  char *str = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(dst1, str, a, a, a, a, a),
                   s21_sprintf(dst2, str, a, a, a, a, a));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_17) {
  char dst1[100];
  char dst2[100];
  char *str = "Test %d Test";
  int val = 12;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_18) {
  char dst1[100];
  char dst2[100];
  char *str = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_19) {
  char dst1[100];
  char dst2[100];
  char *str = "%ld Test %ld Test %hd Test %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_20) {
  char dst1[100];
  char dst2[100];
  char *str = "%3d Test %.23d Test %3.d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_21) {
  char dst1[200];
  char dst2[200];
  char *str = "%-10.5d Test %-.8d Test %-7d TEST %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_22) {
  char dst1[200];
  char dst2[200];
  char *str = "%#.7d Test %0.d Test %0.0d Test %0d Test %.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_23) {
  char dst1[200];
  char dst2[200];
  char *str = "%+d Test %+3.d Test %+5.7d Test %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_24) {
  char dst1[200];
  char dst2[200];
  char *str = "% d Test % 3.d Test % 5.7d Test % 10d Test %.d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_25) {
  char dst1[200];
  char dst2[200];
  char *str = "%*d Test %-*d Test %*.*d TEST %.*d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(dst1, str, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(dst2, str, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_26) {
  char dst1[200];
  char dst2[200];
  char *str = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num, num, num),
                   s21_sprintf(dst2, str, num, num, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_27) {
  char dst1[200];
  char dst2[200];
  char *str = "%f TEST %.f TEST %3f TEST %4.f TEST %-5.10f!";
  double num = -76.756589367;
  double num2 = 75.6589367;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num2, num, num),
                   s21_sprintf(dst2, str, num, num, num2, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_28) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %+15.f\ntest: %+#16.f\ntest: %+#18.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_29) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_30) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %15Lf!test: %100Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(dst1, str, num, num),
                   s21_sprintf(dst2, str, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_31) {
  char dst1[400];
  char dst2[400];
  char *str = "test: % 15.1Lf!\ntest: % -26.15Lf!\ntest: %- 30.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_32) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %+ 50.15Lf!\ntest: % +40.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(dst1, str, num, num),
                   s21_sprintf(dst2, str, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_33) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %+ 50.14Lf!\ntest: % +40.14Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(dst1, str, num, num),
                   s21_sprintf(dst2, str, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_34) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_35) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_36) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %.6Lf!\ntest: %.Lf\ntest: %+ 0Lf!!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_37) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_38) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_39) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_40) {
  char dst1[400];
  char dst2[400];
  char *str = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 823631075973858585858447757573.6495633;
  ck_assert_int_eq(sprintf(dst1, str, num, num, num),
                   s21_sprintf(dst2, str, num, num, num));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_41) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "Test %x Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_42) {
  char dst1[100];
  char dst2[100];
  char *str = "%x Test %x Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_43) {
  char dst1[100];
  char dst2[100];
  char *str = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_44) {
  char dst1[100];
  char dst2[100];
  char *str = "%lx Test %lx Test %hx Test %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_45) {
  char dst1[100];
  char dst2[100];
  char *str = "%3x Test %0x Test %-10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_46) {
  char dst1[200];
  char dst2[200];
  char *str = "%#x Test %#3x Test %#5.7x TEST %#.7x TEST %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_47) {
  char dst1[200];
  char dst2[200];
  char *str = "%0x Test %06x Test %05.7x TEST %0.7x TEST %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_48) {
  char dst1[200];
  char dst2[200];
  char *str = "%*x Test %-*x Test %*.*x TEST %.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(dst1, str, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(dst2, str, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_49) {
  char dst1[200];
  char dst2[200];
  char *str = "fdsdsds %lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_50) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "Test %X Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_51) {
  char dst1[100];
  char dst2[100];
  char *str = "%X Test %X Test %X";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_52) {
  char dst1[100];
  char dst2[100];
  char *str = "%X Test %X Test %X";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_53) {
  char dst1[100];
  char dst2[100];
  char *str = "%lX Test %lX Test %hX Test %hX";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_54) {
  char dst1[100];
  char dst2[100];
  char *str = "%3X Test %0X Test %-10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_55) {
  char dst1[200];
  char dst2[200];
  char *str = "%#X Test %#3X Test %#5.7X TEST %#.7X TEST %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_56) {
  char dst1[200];
  char dst2[200];
  char *str = "%0X Test %06X Test %05.7X TEST %0.7X TEST %0.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_57) {
  char dst1[200];
  char dst2[200];
  char *str = "%*X Test %-*X Test %*.*X TEST %.*X";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(dst1, str, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(dst2, str, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_58) {
  char dst1[200];
  char dst2[200];
  char *str = "fdsdsds %lX";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_59) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_60) {
  char dst1[100];
  char dst2[100];
  char *str = "%o Test %o Test %o";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_61) {
  char dst1[100];
  char dst2[100];
  char *str = "%lo Test %lo Test %ho Test %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_62) {
  char dst1[100];
  char dst2[100];
  char *str = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_63) {
  char dst1[200];
  char dst2[200];
  char *str = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_64) {
  char dst1[200];
  char dst2[200];
  char *str = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_65) {
  char dst1[200];
  char dst2[200];
  char *str = "%0o Test %0.o Test %0.0o Test %0o Test %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_66) {
  char dst1[200];
  char dst2[200];
  char *str = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_67) {
  char dst1[200];
  char dst2[200];
  char *str = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_68) {
  char dst1[200];
  char dst2[200];
  char *str = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(dst1, str, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(dst2, str, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_69) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_70) {
  char dst1[200];
  char dst2[200];
  char *str = "fdsdsds %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_71) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "%%Test Test";
  ck_assert_int_eq(sprintf(dst1, "%s", str), s21_sprintf(dst2, "%s", str));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_72) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "Test Tes%%%%t";
  ck_assert_int_eq(sprintf(dst1, "%s", str), s21_sprintf(dst2, "%s", str));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_73) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "Te%%st %% Test %%";
  ck_assert_int_eq(sprintf(dst1, "%s", str), s21_sprintf(dst2, "%s", str));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_74) {
  char dst1[100] = "";
  char dst2[100] = "";
  char *str = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_75) {
  char dst1[100];
  char dst2[100];
  char *str = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_76) {
  char dst1[100];
  char dst2[100];
  char *str = "%u Test %u Test %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_77) {
  char dst1[100];
  char dst2[100];
  char *str = "%lu Test %lu Test %hu GOD %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_78) {
  char dst1[100];
  char dst2[100];
  char *str = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3),
                   s21_sprintf(dst2, str, val, val2, val3));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_79) {
  char dst1[200];
  char dst2[200];
  char *str = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_80) {
  char dst1[200];
  char dst2[200];
  char *str = "%-10.5u Test %-.8u Test %-7u TEST %-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4),
                   s21_sprintf(dst2, str, val, val2, val3, val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_81) {
  char dst1[200];
  char dst2[200];
  char *str = "%0u Test %0.u Test %0.0u Test %0u Test %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_82) {
  char dst1[200];
  char dst2[200];
  char *str = "%#u Test %#3u Test %#5.7u TEST %#.7u Ouf %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_83) {
  char dst1[200];
  char dst2[200];
  char *str = "%0u Test %06u Test %05.7u TEST %0.7u Ouf %0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(dst1, str, val, val2, val3, val4, val5),
                   s21_sprintf(dst2, str, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_84) {
  char dst1[200];
  char dst2[200];
  char *str = "%*u Test %-*u Test %*.*u TEST %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  ck_assert_int_eq(
      sprintf(dst1, str, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(dst2, str, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

START_TEST(sprintf_85) {
  char dst1[200];
  char dst2[200];
  char *str = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(dst1, str, val), s21_sprintf(dst2, str, val));
  ck_assert_pstr_eq(dst1, dst2);
}
END_TEST

Suite *test_sprintf(void) {
  Suite *s = suite_create("21_sprintf");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1);
  tcase_add_test(tc, sprintf_2);
  tcase_add_test(tc, sprintf_3);
  tcase_add_test(tc, sprintf_4);
  tcase_add_test(tc, sprintf_5);
  tcase_add_test(tc, sprintf_6);
  tcase_add_test(tc, sprintf_7);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_10);
  tcase_add_test(tc, sprintf_11);
  tcase_add_test(tc, sprintf_12);
  tcase_add_test(tc, sprintf_13);
  tcase_add_test(tc, sprintf_14);
  tcase_add_test(tc, sprintf_15);
  tcase_add_test(tc, sprintf_16);
  tcase_add_test(tc, sprintf_17);
  tcase_add_test(tc, sprintf_18);
  tcase_add_test(tc, sprintf_19);
  tcase_add_test(tc, sprintf_20);
  tcase_add_test(tc, sprintf_21);
  tcase_add_test(tc, sprintf_22);
  tcase_add_test(tc, sprintf_23);
  tcase_add_test(tc, sprintf_24);
  tcase_add_test(tc, sprintf_25);
  tcase_add_test(tc, sprintf_26);
  tcase_add_test(tc, sprintf_27);
  tcase_add_test(tc, sprintf_28);
  tcase_add_test(tc, sprintf_29);
  tcase_add_test(tc, sprintf_30);
  tcase_add_test(tc, sprintf_31);
  tcase_add_test(tc, sprintf_32);
  tcase_add_test(tc, sprintf_33);
  tcase_add_test(tc, sprintf_34);
  tcase_add_test(tc, sprintf_35);
  tcase_add_test(tc, sprintf_36);
  tcase_add_test(tc, sprintf_37);
  tcase_add_test(tc, sprintf_38);
  tcase_add_test(tc, sprintf_39);
  tcase_add_test(tc, sprintf_40);
  tcase_add_test(tc, sprintf_41);
  tcase_add_test(tc, sprintf_42);
  tcase_add_test(tc, sprintf_43);
  tcase_add_test(tc, sprintf_44);
  tcase_add_test(tc, sprintf_45);
  tcase_add_test(tc, sprintf_46);
  tcase_add_test(tc, sprintf_47);
  tcase_add_test(tc, sprintf_48);
  tcase_add_test(tc, sprintf_49);
  tcase_add_test(tc, sprintf_50);
  tcase_add_test(tc, sprintf_51);
  tcase_add_test(tc, sprintf_52);
  tcase_add_test(tc, sprintf_53);
  tcase_add_test(tc, sprintf_54);
  tcase_add_test(tc, sprintf_55);
  tcase_add_test(tc, sprintf_56);
  tcase_add_test(tc, sprintf_57);
  tcase_add_test(tc, sprintf_58);
  tcase_add_test(tc, sprintf_59);
  tcase_add_test(tc, sprintf_60);
  tcase_add_test(tc, sprintf_61);
  tcase_add_test(tc, sprintf_62);
  tcase_add_test(tc, sprintf_63);
  tcase_add_test(tc, sprintf_64);
  tcase_add_test(tc, sprintf_65);
  tcase_add_test(tc, sprintf_66);
  tcase_add_test(tc, sprintf_67);
  tcase_add_test(tc, sprintf_68);
  tcase_add_test(tc, sprintf_69);
  tcase_add_test(tc, sprintf_70);
  tcase_add_test(tc, sprintf_71);
  tcase_add_test(tc, sprintf_72);
  tcase_add_test(tc, sprintf_73);
  tcase_add_test(tc, sprintf_74);
  tcase_add_test(tc, sprintf_75);
  tcase_add_test(tc, sprintf_76);
  tcase_add_test(tc, sprintf_77);
  tcase_add_test(tc, sprintf_78);
  tcase_add_test(tc, sprintf_79);
  tcase_add_test(tc, sprintf_80);
  tcase_add_test(tc, sprintf_81);
  tcase_add_test(tc, sprintf_82);
  tcase_add_test(tc, sprintf_83);
  tcase_add_test(tc, sprintf_84);
  tcase_add_test(tc, sprintf_85);
  suite_add_tcase(s, tc);
  return s;
}
