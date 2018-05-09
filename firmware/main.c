/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* 
 * File:   main.c
 * Author: RNR
 *
 * Created on 8 de Maio de 2018, 11:30
 */


#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "main.h"
//#include "kernel/settings/settings.h"

/*void hardwareLoop() {
    if (kbhit()) {
        letra = getch();
        if (letra == 'q')
            exit(0);
    } else {
        letra = 0;
    }
}*/

int main(int argc, char** argv) {

    Start_inicialize();

    Std_printf("%rOla mundo");



    while (1) {
        
        Start_loop();
        
        LCD_SendBuffer(lcdBuffer);
        printf("%d%d%d%d\n\n", Keyboard_keyEnter(), Keyboard_keyEsc(), Keyboard_keyUp(), Keyboard_keyDown());
        //hardwareLoop();
    }
}
