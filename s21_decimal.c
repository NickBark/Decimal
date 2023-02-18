#include "s21_decimal.h"

int s21_is_less(s21_decimal val1, s21_decimal val2) {
    int res = 0;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    if (val1.pat.sgn && !val2.pat.sgn)
        res = 1;
    else if (!val1.pat.sgn && val2.pat.sgn)
        res = 0;
    else if (val1.pat.exp < val2.pat.exp)
        res = 1;
    else if (val1.pat.exp > val2.pat.exp)
        res = 0;
    else if (val1.pat.mnt3 < val2.pat.mnt3)
        res = 1;
    else if (val1.pat.mnt3 > val2.pat.mnt3)
        res = 0;
    else if (val1.pat.mnt2 < val2.pat.mnt2)
        res = 1;
    else if (val1.pat.mnt2 > val2.pat.mnt2)
        res = 0;
    else if (val1.pat.mnt1 < val2.pat.mnt1)
        res = 1;
    else if (val1.pat.mnt1 > val2.pat.mnt1)
        res = 0;

    return res;
}

void s21_zero_exp(s21_decimal *val) {
    val->pat.null1 = 0;
    val->pat.null2 = 0;
    if (val->pat.exp > 28) val->pat.exp = 28;
}