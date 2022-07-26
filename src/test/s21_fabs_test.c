#include "s21_tests_suite.h"

START_TEST(test_01_s21_fabs) {
    double x = 1e+16;
    long double s21_res = s21_fabs(x), res = fabs(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_02_s21_fabs) {
    double x = -1e+16;
    long double s21_res = s21_fabs(x), res = fabs(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

START_TEST(test_03_s21_fabs) {
    double x = 0;
    long double s21_res = s21_fabs(x), res = fabs(x);

    ck_assert_ldouble_eq(s21_res, res);
} END_TEST

Suite * s21_fabs_suite(void) {
    Suite * suite = suite_create("group of fabs tests");

    TCase * tc_insert = tcase_create("fabs_tests");

    tcase_add_test(tc_insert, test_01_s21_fabs);
    tcase_add_test(tc_insert, test_02_s21_fabs);
    tcase_add_test(tc_insert, test_03_s21_fabs);
    suite_add_tcase(suite, tc_insert);

    return suite;
}
