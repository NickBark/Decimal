#include "s21_decimal.h"
#include "support.h"

int s21_is_less(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;
    int comp = 0;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;
    comp = mnt_comp(val1, val2);

    if (val1.pat.sgn && !val2.pat.sgn) {
        res = 1;
    } else if (!val1.pat.sgn && val2.pat.sgn) {
        res = 0;
    } else if (!comp) {
        if (val1.pat.exp > val2.pat.exp)
            res = neg ? 0 : 1;
        else if (val1.pat.exp < val2.pat.exp)
            res = neg ? 1 : 0;
        else
            res = 0;
    } else if (val1.pat.exp == val2.pat.exp) {
        res = (comp == 2) ? 1 : 0;
        if (neg) res = !res;
    } else {
        normalozation(&val1, &val2);
        comp = mnt_comp(val1, val2);
        res = (comp == 2) ? 1 : 0;
        if (neg) res = !res;
    }

    return res;
}