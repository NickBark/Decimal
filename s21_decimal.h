#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdlib.h>

typedef struct s21_decimal {
    int bits[4];
} s21_decimal;

typedef union dec_bits {
    s21_decimal d;

} dec_bits;

#endif  // S21_DECIMAL_H