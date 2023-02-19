#include "s21_decimal.h"

int s21_is_less(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;

    if (val1.pat.sgn && !val2.pat.sgn)
        res = 1;
    else if (!val1.pat.sgn && val2.pat.sgn)
        res = 0;
    else if (val1.pat.exp < val2.pat.exp)
        res = neg ? 0 : 1;
    else if (val1.pat.exp > val2.pat.exp)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt3 < val2.pat.mnt3)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt3 > val2.pat.mnt3)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt2 < val2.pat.mnt2)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt2 > val2.pat.mnt2)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt1 < val2.pat.mnt1)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt1 > val2.pat.mnt1)
        res = neg ? 1 : 0;

    return res;
}

int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;

    if (val1.pat.sgn && !val2.pat.sgn)
        res = 1;
    else if (!val1.pat.sgn && val2.pat.sgn)
        res = 0;
    else if (val1.pat.exp < val2.pat.exp)
        res = neg ? 0 : 1;
    else if (val1.pat.exp > val2.pat.exp)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt3 < val2.pat.mnt3)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt3 > val2.pat.mnt3)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt2 < val2.pat.mnt2)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt2 > val2.pat.mnt2)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt1 <= val2.pat.mnt1)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt1 > val2.pat.mnt1)
        res = neg ? 1 : 0;

    return res;
}

int s21_is_greater(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;

    if (val1.pat.sgn && !val2.pat.sgn)
        res = 0;
    else if (!val1.pat.sgn && val2.pat.sgn)
        res = 1;
    else if (val1.pat.exp < val2.pat.exp)
        res = neg ? 1 : 0;
    else if (val1.pat.exp > val2.pat.exp)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt3 < val2.pat.mnt3)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt3 > val2.pat.mnt3)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt2 < val2.pat.mnt2)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt2 > val2.pat.mnt2)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt1 < val2.pat.mnt1)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt1 > val2.pat.mnt1)
        res = neg ? 0 : 1;

    return res;
}

void s21_zero_exp(s21_decimal *val) {
    val->pat.null1 = 0;
    val->pat.null2 = 0;
    if (val->pat.exp > 28) val->pat.exp = 28;
}