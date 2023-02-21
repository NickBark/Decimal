#include "s21_decimal.h"

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
        // s21_normalozation(&val1, &val2);

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

void normalozation(s21_decimal* val1, s21_decimal* val2) {
    int offset = abs(val1->pat.exp - val2->pat.exp);
    int wrongWay = 0;
    s21_decimal tmp = {};

    if (val1->pat.exp > val2->pat.exp) {
        mntCpy(val2, &tmp);
        for (int i = 0; i < offset; i++) {
            //умножение на 10;
            if (isSetBit(val2->bits, 95)) {
                wrongWay = 1;
                break;
            }
            mntCpy(val2, &tmp);
            mntShift(val2);
            mntShift(val2);
            mntShift(val2);
            mntShift(&tmp);
            mntAdd(*val2, tmp, val2);
        }
    } else if (val1->pat.exp < val2->pat.exp) {
        mntShift(val1);
    }
}

void mntShift(s21_decimal* val) {
    s21_decimal tmp = {};

    //копирование в tmp
    mntCpy(val, &tmp);

    //смещение мантиссы на 1
    for (int i = 1; i < 96; i++) {
        if (isSetBit(tmp.bits, i - 1)) {
            setBit(val->bits, i);
        } else {
            resetBit(val->bits, i);
        }
    }
    resetBit(val->bits, 0);
}

//копируе val1 в val2
void mntCpy(s21_decimal* val1, s21_decimal* val2) {
    for (int i = 0; i < 96; i++) {
        if (isSetBit(val1->bits, i))
            setBit(val2->bits, i);
        else
            resetBit(val2->bits, i);
    }
}

//Возвращаемое значение:
// 0 - ОК
// 1 - Число слишком велико или равно бесконечности
int mntAdd(s21_decimal val1, s21_decimal val2, s21_decimal* res) {
    int ret = 0;
    int addOne = 0;
    // обнуляем мантиссу результата
    for (int i = 0; i < 96; i++) resetBit(res->bits, i);

    int v1 = 0;
    int v2 = 0;

    for (int i = 0; i < 96; i++) {
        v1 = isSetBit(val1.bits, i);
        v2 = isSetBit(val2.bits, i);

        if (v1 == 0 && v2 == 0 && addOne == 0) {
            resetBit(res->bits, i);
            addOne = 0;
        } else if (v1 == 1 && v2 == 1 && addOne == 1) {
            if (i == 95) ret = 1;
            setBit(res->bits, i);
            addOne = 1;
        } else if ((v1 ^ v2 ^ addOne) == 0) {
            if (i == 95) ret = 1;
            resetBit(res->bits, i);
            addOne = 1;
        } else if ((v1 ^ v2 ^ addOne) == 1) {
            setBit(res->bits, i);
            addOne = 0;
        }
    }

    return ret;
}

// // нулевой бит
// if (isSetBit(val1.bits, 0) && isSetBit(val2.bits, 0))
//     resetBit(res->bits, 0);
// else if (isSetBit(val1.bits, 0) || isSetBit(val2.bits, 0))
//     setBit(res->bits, 0);
// else
//     resetBit(res->bits, 0);

// // все остальные биты
// for (int i = 0; i < 96; i++) {
//     if (isSetBit(val1.bits, i - 1) && isSetBit(val2.bits, i - 1))
//         addOne = 1;

//     if (isSetBit(val1.bits, i) && isSetBit(val2.bits, i) && addOne) {
//         setBit(res->bits, i);
//         addOne = 1;
//     } else if (isSetBit(val1.bits, i) && isSetBit(val2.bits, i)) {
//         resetBit(res->bits, i);
//         addOne = 1;
//     }

//     if (isSetBit(val1.bits, i) || isSetBit(val2.bits, i) && addOne) {
//         resetBit(res->bits, i);
//         addOne = 1;
//     }
// }