#include <stdio.h>
#include <stdlib.h>

// #include "s21_decimal.h"
#include "support.h"

int main() {
    s21_decimal ppp1 = {{0xfffffffe, 0xffffffff, 0xffffffff, 0x00000000}};
    s21_decimal ppp2 = {{0xfffffffe, 0xffffffff, 0xffffffff, 0x00000000}};
    s21_decimal res = {};
    s21_decimal rem = {};
    ppp1.pat.exp = 0;
    ppp2.pat.exp = 0;

    printf("ppp1:");
    printBit(ppp1);

    printf("ppp2:");
    printBit(ppp2);

    s21_sub(ppp1, ppp2, &res);

    // printf("%d\n", equalMinf(ppp1, ppp2));
    // s21_add(ppp1, ppp2, &res);

    printf("rest:");
    printBit(res);

    for (int i = 0; i < 3; i++) {
        printf("%u\n", res.bits[i]);
    }

    return 0;
}
