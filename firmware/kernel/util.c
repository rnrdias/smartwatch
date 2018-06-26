/*
 * File:   Util.c
 * Author: RNR
 *
 * Created on 12 de Mar�o de 2018, 14:23
 */

#include "util.h"

unsigned char Util_parityCalc(unsigned char value, unsigned char Imp_nPar) {
    if (((value >> 0)&0x01)^((value >> 1)&0x01)^((value >> 2)&0x01)^((value >> 3)&0x01)^((value >> 4)&0x01)\
	^((value >> 5)&0x01)^((value >> 6)&0x01)^((value >> 7)&0x01)^((value >> 8)&0x01)) {
        return (unsigned char) !Imp_nPar;
    } else {
        return Imp_nPar;
    }
}

unsigned char Util_stringLenth(char *string) {
    unsigned char i = 0;
    while (*(string++)) {
        i++;
    }
    return i;
}


char mem[Util_malloc_max];

typedef struct {
    char var;
} aloc;

char *indexTop = mem;

void *Util_memPush(unsigned int size) {
    char *p = indexTop;
    if (size + indexTop >= mem + Util_malloc_max)
        return 0;
    indexTop += size;
    return p;
}

void Util_memTop(void *p) {
    if (p >= mem && p <= mem + Util_malloc_max)
        indexTop = p;
}

unsigned int Util_memGetSizeAloc() {
    return mem - indexTop;
}