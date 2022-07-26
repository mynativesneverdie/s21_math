#include "s21_math.h"

long double s21_cos(double x) {
    long double ret = 1;

    for (; (x < -2*S21_PI || 2*S21_PI < x) && !is_inf(x);) {
        if (x > 2*S21_PI) {
            x -= 2*S21_PI;
        } else {
            x += 2*S21_PI;
        }
    }

    if (x == S21_NAN || x == S21_INF || x == -S21_INF) {
        return S21_NAN;
    } else if (x == 0 || x == 2*S21_PI) {
        return ret;
    } else if (x == -S21_PI) {
        ret = -ret;
        return ret;
    } else {
        int k = 1;
        long double val = 1;

        while (S21_EPS < val) {
            val = s21_powi((-1), k) * s21_powi(x, 2 * k) / s21_factorial(2 * k);
            ret += val;

            if (val < 0) val = -val;

            k++;
        }
    }

    return ret;
}
