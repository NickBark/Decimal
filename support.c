#include "support.h"

int isSetBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    return (num[idxRow] & (1 << idxCol)) != 0;
}

void setBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] |= (1 << idxCol);
}

void resetBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] &= ~(1 << idxCol);
}

void inverseBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] ^= (1 << idxCol);
}

int getRow(int bit) { return (int)floor(bit >> 5); }

int getCol(int bit) { return bit % 32; }

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
    if (val1->pat.exp > val2->pat.exp) {
        mntNorm(val2, val1);
    } else if (val1->pat.exp < val2->pat.exp) {
        mntNorm(val1, val2);
    }
}

void mntNorm(s21_decimal* val1, s21_decimal* val2) {
    int wrongWay = 0;
    s21_decimal ten = {{10, 0, 0, 0}};

    while (val1->pat.exp != val2->pat.exp) {
        if (isSetBit(val1->bits, 95) || isSetBit(val1->bits, 94) ||
            isSetBit(val1->bits, 93) || isSetBit(val1->bits, 92)) {
            wrongWay = 1;
            break;
        }
        multByTen(val1);
        val1->pat.exp++;
    }
    if (wrongWay) {
        while (val1->pat.exp != val2->pat.exp) {
            mntDiv(*val2, ten, val2);
            val2->pat.exp--;
        }
    }
}

void mntShiftLeft(s21_decimal* val, int shift) {
    s21_decimal tmp = {};

    for (int i = 0; i < shift; i++) {
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
}

void mntShiftRight(s21_decimal* val, int shift) {
    s21_decimal tmp = {};

    for (int i = 0; i < shift; i++) {
        //копирование в tmp
        mntCpy(val, &tmp);

        //смещение мантиссы на 1
        for (int i = 94; i != -1; i--) {
            if (isSetBit(tmp.bits, i + 1)) {
                setBit(val->bits, i);
            } else {
                resetBit(val->bits, i);
            }
        }
        resetBit(val->bits, 95);
    }
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
// 1 - Число не помещается в мантиссу
int mntAdd(s21_decimal val1, s21_decimal val2, s21_decimal* res) {
    int ret = 0;
    int addOne = 0;
    // обнуляем мантиссу результата
    mntZero(res);

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

int mntSub(s21_decimal val1, s21_decimal val2, s21_decimal* res) {
    int ret = 0;
    int whoInv = 0;  // число для инверсии: 1 - val1, 2 - val2;

    // выбираем число для инверсии
    whoInv = mnt_comp(val1, val2) == 1 ? 1 : 2;

    //инверсия
    for (int i = 0; i <= 95; i++) {
        inverseBit(whoInv == 1 ? val1.bits : val2.bits, i);
    }

    //сложение
    mntAdd(val1, val2, res);

    //инверсия результата
    for (int i = 0; i <= 95; i++) {
        inverseBit(res->bits, i);
    }

    res->pat.sgn = whoInv == 1 ? 0 : 1;

    return ret;
}

//С учетом знака
int mntMul(s21_decimal val1, s21_decimal val2, s21_decimal* res) {
    int ret = 0;
    mntZero(res);

    for (int i = 95; i != -1; i--) {
        if (isSetBit(val2.bits, i)) {
            mntShiftLeft(&val1, i);
            mntAdd(*res, val1, res);
            mntShiftRight(&val1, i);
        }
    }
    res->pat.sgn = val1.pat.sgn ^ val2.pat.sgn;

    return ret;
}

int mntDiv(s21_decimal dividend, s21_decimal divisor, s21_decimal* res) {
    int ret = 0;
    s21_decimal remainder = {};
    mntZero(res);

    for (int i = 95; i >= 0; i--) {
        mntShiftLeft(&remainder, 1);

        remainder.pat.mnt1 |= isSetBit(dividend.bits, i);
        if (mnt_comp(remainder, divisor) != 2) {
            mntSub(remainder, divisor, &remainder);
            setBit(res->bits, i);
        }
    }

    res->pat.sgn = dividend.pat.sgn ^ divisor.pat.sgn;

    return ret;
}

int mntMod(s21_decimal dividend, s21_decimal divisor, s21_decimal* res) {
    int ret = 0;
    mntZero(res);

    for (int i = 95; i >= 0; i--) {
        mntShiftLeft(res, 1);

        res->pat.mnt1 |= isSetBit(dividend.bits, i);
        if (mnt_comp(*res, divisor) != 2) {
            mntSub(*res, divisor, res);
        }
    }

    return ret;
}

void multByTen(s21_decimal* val) {
    s21_decimal tmp = {};
    mntCpy(val, &tmp);
    mntShiftLeft(val, 3);
    mntShiftLeft(&tmp, 1);
    mntAdd(*val, tmp, val);
}

void mntZero(s21_decimal* res) {
    for (int i = 0; i < 96; i++) resetBit(res->bits, i);
}

void printBit(s21_decimal val) {
    for (int i = 127; i >= 0; i--) {
        if (i == 95 || i == 126 || i == 127) printf(" ");
        printf("%u", isSetBit(val.bits, i));
    }
    printf("\n");
}
