#include "s21_decimal.h"

void s21_normalozation(s21_decimal* val1, s21_decimal* val2) {
    int offset = 0;
    if (val1->pat.exp > val2->pat.exp) {
        printf("val2 mnt1: %u\n", val2->pat.mnt1);
        printf("val2 mnt2: %u\n", val2->pat.mnt2);
        printf("val2 mnt3: %u\n", val2->pat.mnt3);

        offset = val1->pat.exp - val2->pat.exp;
        printf("offset: %u\n", offset);

        for (size_t i = offset; i > 0; i--) {
            val2->pat.mnt1 *= 10;
            val2->pat.mnt2 *= 10;
            val2->pat.mnt3 *= 10;
        }

        printf("val2 mnt1: %u\n", val2->pat.mnt1);
        printf("val2 mnt2: %u\n", val2->pat.mnt2);
        printf("val2 mnt3: %u\n", val2->pat.mnt3);
    } else if (val1->pat.exp < val2->pat.exp) {
        offset = val2->pat.exp - val1->pat.exp;
        val1->pat.mnt1 *= 10 * offset;
        val1->pat.mnt2 *= 10 * offset;
        val1->pat.mnt3 *= 10 * offset;

        printf("val1 mnt1: %u\n", val1->pat.mnt1);
        printf("val1 mnt2: %u\n", val1->pat.mnt2);
        printf("val1 mnt3: %u\n", val1->pat.mnt3);
    }
}

int s21_is_less(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;

    if (val1.pat.mnt1 == val2.pat.mnt1 && val1.pat.mnt2 == val2.pat.mnt2 &&
        val1.pat.mnt3 == val2.pat.mnt3) {
        if (val1.pat.exp > val2.pat.exp)
            res = neg ? 0 : 1;
        else if (val1.pat.exp < val2.pat.exp)
            res = neg ? 1 : 0;
    } else {
        s21_normalozation(&val1, &val2);

        if (val1.pat.sgn && !val2.pat.sgn)
            res = 1;
        else if (!val1.pat.sgn && val2.pat.sgn)
            res = 0;
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
    }

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
    else if (val1.pat.mnt1 < val2.pat.mnt1)
        res = neg ? 0 : 1;
    else if (val1.pat.mnt1 > val2.pat.mnt1)
        res = neg ? 1 : 0;
    else if (val1.pat.mnt1 == val2.pat.mnt1)
        res = 1;

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

int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2) {
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
    else if (val1.pat.mnt1 == val2.pat.mnt1)
        res = 1;

    return res;
}

int s21_is_equal(s21_decimal val1, s21_decimal val2) {
    int res = 0;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    if (val1.pat.sgn && !val2.pat.sgn)
        ;
    else if (!val1.pat.sgn && val2.pat.sgn)
        ;
    else if (val1.pat.exp < val2.pat.exp)
        ;
    else if (val1.pat.exp > val2.pat.exp)
        ;
    else if (val1.pat.mnt3 < val2.pat.mnt3)
        ;
    else if (val1.pat.mnt3 > val2.pat.mnt3)
        ;
    else if (val1.pat.mnt2 < val2.pat.mnt2)
        ;
    else if (val1.pat.mnt2 > val2.pat.mnt2)
        ;
    else if (val1.pat.mnt1 < val2.pat.mnt1)
        ;
    else if (val1.pat.mnt1 > val2.pat.mnt1)
        ;
    else if (val1.pat.mnt1 == val2.pat.mnt1)
        res = 1;

    return res;
}

int s21_is_not_equal(s21_decimal val1, s21_decimal val2) {
    int res = 1;

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    if (val1.pat.sgn && !val2.pat.sgn)
        ;
    else if (!val1.pat.sgn && val2.pat.sgn)
        ;
    else if (val1.pat.exp < val2.pat.exp)
        ;
    else if (val1.pat.exp > val2.pat.exp)
        ;
    else if (val1.pat.mnt3 < val2.pat.mnt3)
        ;
    else if (val1.pat.mnt3 > val2.pat.mnt3)
        ;
    else if (val1.pat.mnt2 < val2.pat.mnt2)
        ;
    else if (val1.pat.mnt2 > val2.pat.mnt2)
        ;
    else if (val1.pat.mnt1 < val2.pat.mnt1)
        ;
    else if (val1.pat.mnt1 > val2.pat.mnt1)
        ;
    else if (val1.pat.mnt1 == val2.pat.mnt1)
        res = 0;

    return res;
}

void s21_zero_exp(s21_decimal* val) {
    val->pat.null1 = 0;
    val->pat.null2 = 0;
    if (val->pat.exp > 28) val->pat.exp = 28;
}

// Возвращаемое значение
// 0 - равны
// 1 - val1 больше
// 2 - val2 больше
int mnt_comp(s21_decimal val1, s21_decimal val2) {
    int larger = 0;

    for (int idx = 95; idx >= 0; idx--) {
        if (isSetBit(val1.bits, idx) ^ isSetBit(val2.bits, idx)) {
            larger = isSetBit(val1.bits, idx) ? 1 : 2;
            break;
        }
    }

    return larger;
}
