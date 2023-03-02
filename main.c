#include <stdio.h>
#include <stdlib.h>

// #include "s21_decimal.h"
#include "support.h"

int main() {
    s21_decimal ppp1 = {{35, 0, 0, 0x00000000}};
    s21_decimal ppp2 = {{8, 0, 0, 0x00000000}};
    s21_decimal res = {};
    s21_decimal rem = {};
    ppp1.pat.exp = 4;
    ppp2.pat.exp = 2;

    printf("ppp1:");
    printBit(ppp1);

    printf("ppp2:");
    printBit(ppp2);

    s21_div(ppp1, ppp2, &res);

    // printf("%d\n", equalMinf(ppp1, ppp2));
    // s21_add(ppp1, ppp2, &res);

    printf("rest:");
    printBit(res);

    return 0;
}
