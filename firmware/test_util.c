/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "main.h"

void prt() {
    printf("ola\n");
}

void prt2() {
    printf("ola2\n");
}

void prt3() {
    printf("ola2\n");
}

void prt4() {
    printf("ola2\n");
}

void testEventHandler() {
    Util_eventHandle *e = 0;

    Util_eventHandle p = {&prt};
    Util_eventHandle q = {&prt2};
    Util_eventHandle r = {&prt3};
    Util_eventHandle s = {&prt4};

    Util_registerEventHandler(&e, &p);
    Util_registerEventHandler(&e, &q);
    Util_registerEventHandler(&e, &r);
    Util_registerEventHandler(&e, &s);

    Util_unregisterEventHandler(&e, &r);
    Util_unregisterEventHandler(&e, &p);
    Util_unregisterEventHandler(&e, &r);
    while (1);
}

//__________________INT event handle______________________

void fun(void) {
    RTC_date.minute++;
}
INT_eventData f = {&fun};
Util_eventHandle e = {&f};

//INT_register(&e, INT_BUTTON_UP); //main add line
