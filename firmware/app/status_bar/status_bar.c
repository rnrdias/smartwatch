/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "status_bar.h"

Util_list *root;
unsigned char count;

void StatusBar_register(StatusBar_registerFormat *r) {
    Util_listAdd(&root, &r->item);
    count++;
}

void StatusBar_unregister(StatusBar_registerFormat *r) {
    if (Util_listRemove(&root, &r->item)) {
        count--;
    }
}

void StatusBar_initialize() {
    root = 0;
    count = 0;
}

void StatusBar_check(void (*functionPtr)(const StatusBar_paramFormat *s, void *parameter), void *parameter) {
    StatusBar_registerFormat *aux = (StatusBar_registerFormat*) root;
    while (aux) {
        functionPtr(aux->data, parameter);
        aux = (StatusBar_registerFormat*) aux->item.next;
    }
}

unsigned char StatusBar_size() {
    return count;
}