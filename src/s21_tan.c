#include "s21_math.h"
#include <stdio.h>

long double s21_tan(double x) {
    long double res = 0;
    int sign = 1;

    while (x >= S21_PI && !is_inf(x) && !is_nan(x)) {
        x -= S21_PI;
        sign *= -1;
    }

    if (is_nan(x)) {
        res = S21_NAN;
    } else if (x == S21_PI / 2) {
        res = 16331239353195370L;
    } else if (x == -S21_PI / 2) {
        res = -16331239353195370L;
    } else {
        res = s21_sin(x);
        res = s21_sqrt(1 / (1 - res * res) - 1);
    }

    return res * sign;
}
