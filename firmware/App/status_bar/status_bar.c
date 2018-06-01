/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "status_bar.h"
#include "../../kernel/std.h"


StatusBar_registerFormat *root;

void StatusBar_register(StatusBar_registerFormat *r) {
    StatusBar_registerFormat *aux;
    if (root == 0) {
        root = r;
    } else {
        aux = root;
        while (aux->p)aux = aux->p;
        aux->p = r;
    }
    r->p = 0;
}

void StatusBar_initialize() {
    //root = 0;
}

void StatusBar_print() {
    StatusBar_registerFormat *aux = root;
    Std_printf("\r");
    while (aux) {
        StatusBar_paramFormat *b = aux->functionRegister();
        if (b)
            Std_printf("%w%c", b->icon, 0);
        aux = aux->p;
    }
    Std_printf("\r\n");
}
