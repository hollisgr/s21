#ifndef SRC_TESTS_MAIN_H
#define SRC_TESTS_MAIN_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../functions/s21_decimal.h"

Suite *test_arithmetic(void);
Suite *test_arithmetic_add(void);
Suite *test_arithmetic_sub(void);
Suite *test_arithmetic_mul(void);
Suite *test_arithmetic_div(void);
Suite *test_setters(void);
Suite *test_comparison(void);
Suite *test_big_comparison(void);
Suite *test_support_functions(void);
Suite *test_convertors(void);
Suite *test_other_functions(void);
#endif  // SRC_TESTS_MAIN_H
