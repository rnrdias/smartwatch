/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../hardware.h"

#include <stdio.h>
#include <stdlib.h>
/*#include <unistd.h>
#include <termios.h>
*/

#include <ncurses.h>

#include <unistd.h>
#include "../interruption.h"
#include "../keyboard.h"
void MAIN_INT_Process();


void keyboardLoop(void) {
    /*if (kbhit()) {
        letra = getch();
        if (letra == 'q')
            exit(0);
    } else {
        letra = 0;
    }*/
    
    letra = getch();//kbhit();
    refresh();
    //fflush(stdin);
    if (letra != EOF) {
        if (letra == 'q')
            exit(0);
    } else {
        letra = 0;
    }

}

void Hardware_loop(void) {
    keyboardLoop();
    MAIN_INT_Process();
}

void Hardware_initialize(void) {
    initscr();
    noecho();
    cbreak();         // don't interrupt for user input
    timeout(1);
}

//Interrupt simulator
void MAIN_INT_Process() {
    //execution delay
    for (unsigned int i = 0; i < 10; i++){
        Int_coreTimerMS();
        usleep(5 * 1000);
    }

    if (Keyboard_getKeyUp()) {
        Int_coreButtonUp();
    }

    if (Keyboard_getKeyDown()) {
        Int_coreButtonDown();
    }
}