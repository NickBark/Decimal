#include <stdio.h>
#include <stdlib.h>

// #include "s21_decimal.h"
#include "support.h"

int main() {
    s21_decimal ppp1 = {{2, 0x0, 0x0, 0x80000000}};
    s21_decimal ppp2 = {{30, 0x0, 0x0, 0x80000000}};
    ppp1.pat.exp = 5;
    ppp2.pat.exp = 6;

    printf("ppp1:");
    printBit(ppp1);

    printf("ppp2:");
    printBit(ppp2);

    printf("ppp1 <= ppp2 ?: %d\n", s21_is_less_or_equal(ppp1, ppp2));
    normalozation(&ppp1, &ppp2);
    printf("ppp1:");
    printBit(ppp1);

    printf("ppp2:");
    printBit(ppp2);

    return 0;
}
