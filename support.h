#ifndef SUPPORT_H
#define SUPPORT_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

typedef union bigDecimal {
    unsigned int bits[7];
} bigDecimal;

enum Operations { ADD, MUL, SUB, DIV, ALL };

int isSetBit(int* num, int idx);
void setBit(int* num, int idx);
void resetBit(int* num, int idx);
void inverseBit(int* num, int idx);

int getRow(int bit);
int getCol(int bit);

void s21_zero_exp(s21_decimal* val);
void normalozation(s21_decimal* val1, s21_decimal* val2);
int mnt_comp(s21_decimal val1, s21_decimal val2);
void mntShiftLeft(s21_decimal* val, int shift);
void mntShiftRight(s21_decimal* val, int shift);

// Copy func
void mntCpy(s21_decimal* val1, s21_decimal* val2);
void mntCpyBig2Std(bigDecimal* val1, s21_decimal* val2);
void mntCpyStd2Big(s21_decimal* val1, bigDecimal* val2);

int mntAdd(s21_decimal val1, s21_decimal val2, s21_decimal* res);
int mntSub(s21_decimal val1, s21_decimal val2, s21_decimal* res);
int mntMul(s21_decimal val1, s21_decimal val2, s21_decimal* res);
int mntDiv(s21_decimal dividend, s21_decimal divisor, s21_decimal* res,
           s21_decimal* remainder);
int mntMod(s21_decimal dividend, s21_decimal divisor, s21_decimal* res);

void multByTen(s21_decimal* val);
int mntBigDivByTen(bigDecimal dividend, bigDecimal* res,
                   s21_decimal* remainder);

// Zero mnt func
void mntZero(s21_decimal* res);
void mntBigZero(bigDecimal* res);

// Printf func
void printBit(s21_decimal val);
void printBigBit(bigDecimal val);

void mntNorm(s21_decimal* val1, s21_decimal* val2);
int mntAddOverflow(s21_decimal val1, s21_decimal val2);
int mntMulOverflow(s21_decimal val1, s21_decimal val2);
int equalMinf(s21_decimal val1, s21_decimal val2, int operation);
int equalInf(s21_decimal val1, s21_decimal val2, int operation);

int mntDiv2(s21_decimal dividend, s21_decimal divisor, s21_decimal* res,
            s21_decimal* rem);

#endif  // SUPPORT_H
