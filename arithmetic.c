#include "s21_decimal.h"
#include "support.h"

// 1 - OK
// 2 - INF
// 3 - MINF
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
    int ret = 0;
    int neg = value_1.pat.sgn && value_2.pat.sgn ? 1 : 0;
    int operation = ADD;

    s21_zero_exp(result);
    mntZero(result);

    normalozation(&value_1, &value_2);
    result->pat.exp = value_1.pat.exp;

    if (!(value_1.pat.sgn ^ value_2.pat.sgn)) {
        if (equalInf(value_1, value_2, operation)) {
            ret = 1;
        } else if (equalMinf(value_1, value_2, operation)) {
            ret = 2;
        } else {
            mntAdd(value_1, value_2, result);
            result->pat.sgn = neg ? 1 : 0;
        }
    } else {
        mntSub(value_1, value_2, result);
        result->pat.sgn =
            mnt_comp(value_1, value_2) == 1 ? value_1.pat.sgn : value_2.pat.sgn;
    }

    return ret;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
    int ret = 0;
    s21_decimal zero = {};

    s21_zero_exp(result);
    mntZero(result);

    normalozation(&value_1, &value_2);
    result->pat.exp = value_1.pat.exp;

    if (value_1.pat.sgn ^ value_2.pat.sgn) {
        mntAdd(value_1, value_2, result);
        result->pat.sgn = value_1.pat.sgn ? 1 : 0;
    } else {
        mntSub(value_1, value_2, result);
        if (value_1.pat.sgn) result->pat.sgn = !result->pat.sgn;
    }

    if (!mnt_comp(*result, zero)) result->pat.sgn = 0;

    return ret;
}

// int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
//     int ret = 0;
//     if (mntMulOverflow()) return ret;
// }

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
    int ret = 0;
    int sgn = value_1.pat.sgn ^ value_2.pat.sgn ? 1 : 0;
    int scale = value_1.pat.exp - value_2.pat.exp;

    s21_decimal remainder = {};
    s21_decimal zero = {};
    s21_decimal tmp = {};

    s21_zero_exp(result);
    mntZero(result);

    mntDiv(value_1, value_2, result, &remainder);

    while ((mnt_comp(remainder, zero) != 0) && (scale < 28)) {
        multByTen(&remainder);
        multByTen(result);
        scale++;
        mntDiv(remainder, value_2, &tmp, &remainder);
        printf("%u\n", tmp.bits[0]);
        mntAdd(*result, tmp, result);
    }
    result->pat.exp = (unsigned int)scale;
    result->pat.sgn = sgn ? 1 : 0;
    return ret;
}

// int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
//     int res = 0;

//     if (!value_1.pat.sgn && !value_2.pat.sgn) {
//         if (UINT32_MAX - value_1.pat.mnt1 < value_1.pat.mnt1) {
//             result->pat.mnt2 = 1;
//             result->pat.mnt1 = value_1.pat.mnt1 + value_1.pat.mnt1;
//         } else {
//             result->pat.mnt1 = value_1.pat.mnt1 + value_1.pat.mnt1;
//         }

//         if (UINT32_MAX - value_1.pat.mnt2 < value_1.pat.mnt2) {
//             result->pat.mnt3 = 1;
//             result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
//         } else {
//             unsigned int tmp = value_1.pat.mnt2 + value_1.pat.mnt2;
//             if (UINT32_MAX - tmp < result->pat.mnt2) {
//                 result->pat.mnt3 = 1;
//                 result->pat.mnt2 += tmp;
//             } else {
//                 result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
//             }
//         }

//         if (UINT32_MAX - value_1.pat.mnt3 < value_1.pat.mnt3) {
//             result->pat.mnt3 = 1;
//             result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
//         } else {
//             unsigned int tmp = value_1.pat.mnt2 + value_1.pat.mnt2;
//             if (UINT32_MAX - tmp < result->pat.mnt2) {
//                 result->pat.mnt3 = 1;
//                 result->pat.mnt2 += tmp;
//             } else {
//                 result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
//             }
//         }
//     }
//     return res;
// }
