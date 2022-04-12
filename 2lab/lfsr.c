#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t pos0 = *reg & 1;
    uint16_t pos2 = (*reg & (1<<2)) >> 2;
    uint16_t pos3 = (*reg & (1<<3)) >> 3;
    uint16_t pos5 = (*reg & (1<<5)) >> 5;
    uint16_t bit_to_set = pos0 ^ pos2 ^ pos3 ^ pos5;
    *reg >>= 1;
    *reg += (bit_to_set << 15);
}