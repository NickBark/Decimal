#include <stdio.h>
#include <stdlib.h>

// #include "s21_decimal.h"
#include "support.h"

int main() {
    s21_decimal ppp1 = {{13, 0, 0, 0x00000000}};
    s21_decimal ppp2 = {{7, 0, 0, 0x00000000}};
    s21_decimal res = {};
    s21_decimal rem = {};
    ppp1.pat.exp = 0;
    ppp2.pat.exp = 0;

    printf("ppp1:");
    printBit(ppp1);

    printf("ppp2:");
    printBit(ppp2);

    mntDiv2(ppp1, ppp2, &res, &rem);

    // printf("%d\n", equalMinf(ppp1, ppp2));
    // s21_add(ppp1, ppp2, &res);

    printf("\nres2:");
    printBit(res);
    printf("rem2:");
    printBit(rem);

    mntZero(&res);
    mntZero(&rem);

    mntDiv(ppp1, ppp2, &res);
    mntMod(ppp1, ppp2, &rem);

    printf("\nres1:");
    printBit(res);
    printf("rem1:");
    printBit(rem);

    return 0;
}
