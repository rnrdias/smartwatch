/*
 * File:   Util.c
 * Author: RNR
 *
 * Created on 12 de Mar�o de 2018, 14:23
 */

#include "Util.h"

unsigned char Util_parityCalc(unsigned char value, unsigned char Imp_nPar) {
    if (((value >> 0)&0x01)^((value >> 1)&0x01)^((value >> 2)&0x01)^((value >> 3)&0x01)^((value >> 4)&0x01)\
	^((value >> 5)&0x01)^((value >> 6)&0x01)^((value >> 7)&0x01)^((value >> 8)&0x01)) {
        return (unsigned char) !Imp_nPar;
    } else {
        return Imp_nPar;
    }
}

unsigned char Util_stringLenth(char *string){
    unsigned char i = 0;
    while(*(string++)){
        i++;
    }
    return i;
}



char mem[Util_malloc_max];

typedef struct {
    unsigned char size;
    char var;
} aloc;

unsigned char indexTop = 0;

void *Util_memPush(unsigned char size) {
    if (indexTop + size >= Util_malloc_max)
        return 0;
    aloc *ret = (aloc *) & mem[indexTop];
    ret->size = size;
    indexTop += size + 1;
    return &ret->var;
}

void Util_memPop(void *p) {
    aloc *ret = p - sizeof (unsigned char);
    indexTop -= ret->size + 1;
}
