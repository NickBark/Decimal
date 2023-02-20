#include "s21_decimal.h"

// printf("result_mnt1: %u\n", result->pat.mnt1);
// printf("max_int: %u\n", UINT32_MAX);
// printf("result_mnt2: %u\n", result->pat.mnt2);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int res = 0;

    if (!value_1.pat.sgn && !value_2.pat.sgn) {
        if (UINT32_MAX - value_1.pat.mnt1 < value_1.pat.mnt1) {
            result->pat.mnt2 = 1;
            result->pat.mnt1 = value_1.pat.mnt1 + value_1.pat.mnt1;
        } else {
            result->pat.mnt1 = value_1.pat.mnt1 + value_1.pat.mnt1;
        }

        if (UINT32_MAX - value_1.pat.mnt2 < value_1.pat.mnt2) {
            result->pat.mnt3 = 1;
            result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
        } else {
            unsigned int tmp = value_1.pat.mnt2 + value_1.pat.mnt2;
            if (UINT32_MAX - tmp < result->pat.mnt2) {
                result->pat.mnt3 = 1;
                result->pat.mnt2 += tmp;
            } else {
                result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
            }
        }

        if (UINT32_MAX - value_1.pat.mnt3 < value_1.pat.mnt3) {
            result->pat.mnt3 = 1;
            result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
        } else {
            unsigned int tmp = value_1.pat.mnt2 + value_1.pat.mnt2;
            if (UINT32_MAX - tmp < result->pat.mnt2) {
                result->pat.mnt3 = 1;
                result->pat.mnt2 += tmp;
            } else {
                result->pat.mnt2 += value_1.pat.mnt2 + value_1.pat.mnt2;
            }
        }
    }
    return res;
}