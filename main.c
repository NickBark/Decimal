#include <stdio.h>
#include <stdlib.h>

// #include "s21_decimal.h"
#include "support.h"

int main() {
    s21_decimal ppp1 = {{13, 0x0, 0x0, 0}};
    s21_decimal ppp2 = {{12, 0x2, 0x00ffffff, 0}};
    ppp1.pat.exp = 5;
    ppp2.pat.exp = 4;

    // printf("ppp1:");
    // printBit(ppp1);

    // printf("ppp2:");
    // printBit(ppp2);

    // normalozation(&ppp1, &ppp2);

    // printf("ppp1:");
    // printBit(ppp1);

    // printf("ppp2:");
    // printBit(ppp2);

    int a = 0;
    a = !a;
    printf("%d", a);

    return 0;
}
