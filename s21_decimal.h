#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

//--- удалить позже
#include <stdio.h>
//---

#include <stdint.h>  // для максимальных, минимальных значений и для типов (uint)
#include <stdlib.h>

#include "support.h"

// typedef struct s21_decimal { // промежуточный этап, нуежен по тз или нет ?
//     int bits[4];
// } s21_decimal;

typedef struct BitPattern {
    uint32_t mnt1 : 32;
    uint32_t mnt2 : 32;
    uint32_t mnt3 : 32;
    uint16_t null1 : 16;
    uint8_t exp : 8;
    uint16_t null2 : 7;
    uint32_t sgn : 1;
} BitPattern;

typedef union s21_decimal {
    unsigned int bits[4];
    BitPattern pat;
} s21_decimal;

//Вспомогательные функции
void s21_zero_exp(s21_decimal* val);
void s21_normalozation(s21_decimal* val1, s21_decimal* val2);
int mnt_comp(s21_decimal val1, s21_decimal val2);

//Операторы сравнение
int s21_is_less(s21_decimal val1, s21_decimal val2);
int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_greater(s21_decimal val1, s21_decimal val2);
int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_equal(s21_decimal val1, s21_decimal val2);
int s21_is_not_equal(s21_decimal val1, s21_decimal val2);

//Арифметические операторы
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

#endif  // S21_DECIMAL_H