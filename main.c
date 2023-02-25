#include <stdio.h>
#include <stdlib.h>

// #include "s21_decimal.h"
#include "support.h"

int main() {
    s21_decimal ppp1 = {{22, 0x10, 0x0, 0b00110000000000010000000000000000}};
    s21_decimal ppp2 = {{10, 0x4, 0x0, 0b00110000000000010000000000000000}};
    s21_decimal res = {0};

    mntDiv(ppp1, ppp2, &res);

    printBit(ppp1);
    printBit(ppp2);
    printBit(res);

    return 0;
}
