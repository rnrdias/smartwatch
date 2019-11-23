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
}

void Hardware_initialize(void) {
    initscr();
    noecho();
    cbreak();         // don't interrupt for user input
    timeout(1);
}