#ifndef SUPPORT_H
#define SUPPORT_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int isSetBit(int* num, int idx);
void setBit(int* num, int idx);
void resetBit(int* num, int idx);
void inverseBit(int* num, int idx);

int getRow(int bit);
int getCol(int bit);

#endif  // SUPPORT_H