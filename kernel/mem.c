/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "mem.h"

#define Mem_allocType(type) (type*)(Mem + Mem_index);Mem_index += sizeof(type)
#define Mem_allocSize(size) (Mem + Mem_index);Mem_index += size

typedef struct {
    Util_list item;
    unsigned int size;
    void **var;
} Mem_allocFormat;


unsigned char Mem[MEM_MAX];
unsigned int Mem_index = 0;
Util_list *Mem_root = 0;

void _Mem_alloc(void **var, unsigned int size) {
    if (Mem_index + size >= MEM_MAX) {
        *var = 0;
        return;
    } else {
        Mem_allocFormat *m = Mem_allocType(Mem_allocFormat);
        m->var = var;
        m->size = size + sizeof (Mem_allocFormat);
        *var = Mem_allocSize(size);
        Util_listAdd(&Mem_root, &m->item);
    }
}

void _Mem_free(void **var) {
    Util_listRemove(&Mem_root, *var - sizeof (Mem_allocFormat));
    *var = 0;
    Mem_restructure();
}

void Mem_moveData(void *start, void *data, unsigned char size) {
    char *s = start;
    char *d = data;
    for (unsigned int i = 0; i < size; i++) {
        s[i] = d[i];
    }
}

void Mem_restructure(void) {
    Mem_allocFormat *blockCurrent = (Mem_allocFormat*) Mem;

    if (Mem_root == 0) {
        Mem_index = 0;
        return;
    }

    if (blockCurrent != (void *) Mem_root) {
        blockCurrent->size = 0;
        blockCurrent->item.next = Mem_root;
    }

    while (1) {
        void *blockCurrentEnd = blockCurrent->size + (void *) blockCurrent;

        if (!blockCurrent->item.next) {
            Mem_index = blockCurrentEnd - (void*) Mem_root;
            break;
        }

        void *blockCurrentNext = (void *) blockCurrent->item.next;
        if (blockCurrentNext - blockCurrentEnd != 0) {
            Mem_moveData(blockCurrentEnd, blockCurrentNext, ((Mem_allocFormat*) blockCurrentNext)->size);
            if (blockCurrent != blockCurrentEnd)
                blockCurrent->item.next = blockCurrentEnd;
            else {
                Mem_root = (Util_list*) blockCurrent;
                *blockCurrent->var = &blockCurrent->var + 1;
                continue;
            }
        }
        blockCurrent = (Mem_allocFormat*) blockCurrent->item.next;
        *blockCurrent->var = &blockCurrent->var + 1;
    }
}

unsigned int Mem_getSizeAlloc(void) {
    return Mem_index;
}

void Mem_loop(void) {

}

void Mem_initialize(void) {
    Mem_index = 0;
    Mem_root = 0;
}