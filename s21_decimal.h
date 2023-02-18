#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
//---
#include <stdio.h>
//---
#include <stdint.h>
#include <stdlib.h>

// typedef struct s21_decimal {
//     int bits;
// } s21_decimal;

typedef struct BitPattern {
    uint32_t mnt1 : 32;
    uint32_t mnt2 : 32;
    uint32_t mnt3 : 32;
    uint16_t null1 : 16;
    uint8_t exp : 8;
    uint16_t null2 : 16;
    uint32_t sgn : 1;
} BitPattern;

typedef union s21_decimal {
    int bits[4];
    BitPattern pat;
} s21_decimal;

void s21_zero_exp(s21_decimal *val);

//Операторы сравнение
int s21_is_less(s21_decimal val1, s21_decimal val2);

#endif  // S21_DECIMAL_H