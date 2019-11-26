/*
 * smartwatch.c
 *
 * Created: 09/05/2018 21:12:59
 *  Author: RNR
 */

#include "kernel/util.h"
#include "app/app.h"
#include "kernel/kernel.h"
#include "screens/screens.h"
#include "language/language.h"

int main(void) {
    Screen_windowLoad sc_main = {&Sc_main, 0};
    lang = pt_br;
    Start_initialize();
    App_initialize();
    Screen_windowOpen(&sc_main);


    while (1) {
        Start_loop();
        App_loop();
        LCD_sendBuffer(lcdBuffer);
    }
}