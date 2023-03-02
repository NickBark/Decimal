#include "s21_decimal.h"
#include "support.h"

// 1 - OK
// 2 - INF
// 3 - MINF
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
    int ret = 0;
    int neg = value_1.pat.sgn && value_2.pat.sgn ? 1 : 0;

    s21_zero_exp(result);
    mntZero(result);

    normalozation(&value_1, &value_2);
    result->pat.exp = value_1.pat.exp;

    if (!(value_1.pat.sgn ^ value_2.pat.sgn)) {
        if (equalInf(value_1, value_2)) {
            ret = 1;
        } else if (equalMinf(value_1, value_2)) {
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

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
    int ret = 0;
    int neg = value_1.pat.sgn && value_2.pat.sgn ? 1 : 0;
    s21_decimal remainder = {};
    s21_decimal zero = {};
    s21_decimal tmp = {};

    s21_zero_exp(result);
    mntZero(result);

    mntMod(value_1, value_2, &remainder);
    mntDiv(value_1, value_2, result);

    result->pat.exp = value_1.pat.exp - value_2.pat.exp;

    while (mnt_comp(remainder, zero) != 0) {
        multByTen(&remainder);
        multByTen(result);
        result->pat.exp++;

        mntDiv(remainder, value_2, &tmp);
    }

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