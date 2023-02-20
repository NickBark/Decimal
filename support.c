#include "support.h"

int isSetBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    return (num[idxRow] & (1 << idxCol)) != 0;
}

void setBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] |= (1 << idxCol);
}

void resetBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] &= ~(1 << idxCol);
}

void inverseBit(int* num, int idx) {
    int idxRow = getRow(idx);
    int idxCol = getCol(idx);
    num[idxRow] ^= (1 << idxCol);
}

int getRow(int bit) { return (int)floor(bit >> 5); }

int getCol(int bit) { return bit % 32; }