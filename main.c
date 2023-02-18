#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int main() {
    s21_decimal ppp = {{10, 10, 10, 0b10110000100000011000000000000000}};
    s21_decimal ppp2 = {{10, 11, 10, 0b00110000000000011000000000000000}};

    printf("res: %d\n", s21_is_less(ppp, ppp2));
    // printf("%d,%d,%d,%d", ppp.bits[3], ppp.bits[2], ppp.bits[1],
    // ppp.bits[0]);
    return 0;
}