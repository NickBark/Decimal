#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"
#include "support.h"

int divideBy127(int a) {
    static int N = 12;
    int b = 10;
    int L = 7;
    int B = ((1 << (N + L)) / b) + 1;
    return (a * B) >> (N + L);
}

int main() {
    s21_decimal ppp1 = {{0X3234, 0x0, 0x0, 0b00110000000000010000000000000000}};
    s21_decimal ppp2 = {
        {0X366543, 0x323, 0x0, 0b00110000000000010000000000000000}};
    s21_decimal res = {0};
    // for (int i = 0; i < 96; i++) {
    //     printf("b:%2d: %d\n", i, isSetBit(ppp2.bits, i));
    // }
    // printf("---------------\n");

    // mntSub(ppp1, ppp2, &res);
    printf("ppp1:\t");
    for (int i = 95; i != -1; i--) {
        printf("%u", isSetBit(ppp1.bits, i));
    }
    mntShiftLeft(&ppp1, 30);
    printf("\n");
    printf("ppp1:\t");
    for (int i = 95; i != -1; i--) {
        printf("%u", isSetBit(ppp1.bits, i));
    }
    printf("\n");
    // printf("\nppp2:\t");
    // for (int i = 95; i != -1; i--) {
    //     printf("%u", isSetBit(ppp2.bits, i));
    // }
    // printf("\nrest:\t");
    // for (int i = 95; i != -1; i--) {
    //     printf("%u", isSetBit(res.bits, i));
    // }
    // printf("\nsgn: %u\n", res.pat.sgn);

    // for (int i = 1; i <= 96; i++) {
    //     if (i == 17 || i == 33 || i == 49 || i == 65 || i == 81)
    //     printf("\n\n"); printf("b%2d: %d\t", i - 1, isSetBit(res.bits, i -
    //     1));
    // }
    // printf("\n");

    // printf("exp1:%u\n", ppp1.pat.exp);
    // printf("exp2:%u\n", ppp2.pat.exp);

    // printf("%u\n", ppp2.bits[0]);
    // printf("%u\n", ppp2.bits[1]);
    // printf("%u\n", ppp2.bits[2]);

    // normalozation(&ppp1, &ppp2);
    // // printf("---------------\n");

    // printf("%u\n", ppp2.bits[0]);
    // printf("%u\n", ppp2.bits[1]);
    // printf("%u\n", ppp2.bits[2]);
    // for (int i = 0; i < 96; i++) {
    //     printf("b:%2d: %d\n", i, isSetBit(ppp2.bits, i));
    // }

    // for (int i = 0; i < 96; i++) {
    //     printf("b:%2d: %d\n", i, isSetBit(ppp2.bits, i));
    // }
    // int a = 114;
    // for (int i = 0; i < 32; i++) {
    //     printf("b:%2d: %d\n", i, isSetBit(&a, i));
    // }
    // printf("------------\n");
    // a = (a << 3) + (a << 1);

    // printf("%d\n", mnt_comp(ppp1, ppp2));

    // printf("\n\n");

    // printf("%u\n", ppp1.bits[0]);
    // printf("%u\n", ppp1.bits[1]);
    // printf("%u\n", ppp1.bits[2]);

    // s21_add(ppp1, ppp2, &res);

    return 0;
}
