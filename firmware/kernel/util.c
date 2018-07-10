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

void Util_registerEventHandler(Util_eventHandle **root, Util_eventHandle *add) {
    Util_eventHandle *aux;
    if (*root == 0) {
        *root = add;
    } else {
        aux = *root;
        while (aux->next)aux = aux->next;
        aux->next = add;
    }
    add->next = 0;
}

unsigned char Util_unregisterEventHandler(Util_eventHandle **root, Util_eventHandle *add) {
    if (*root) {
        void *id = add->data;
        Util_eventHandle *aux = *root;

        if ((*root)->data == id) {
            *root = (*root)->next;
            return 1;
        } else {
            while (aux->next) {
                if (aux->next->data == id) {
                    aux->next = aux->next->next;
                    return 1;
                }
                aux = aux->next;
            }
        }
    }
    return 0;
}