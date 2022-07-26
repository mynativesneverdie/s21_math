#include "s21_math.h"

long double s21_asin(double x) {
    long double asin = 0;

    if (x == 1.) {
        return S21_PI_2;
    } else if (x == -1.) {
        return -S21_PI_2;
    }

    if (s21_fabs(x) < 1e-9) {
    return 0;
    }

    if (x == 0.7071067811865475244) {
        return S21_PI_4;
    } else if (x == -0.7071067811865475244) {
        return -S21_PI_4;
    }

    if (-1. < x && x < 1.) {
        asin = s21_atan(x / s21_sqrt(1 - x * x));
    } else {
        return S21_NAN;
    }

    return asin;
}
