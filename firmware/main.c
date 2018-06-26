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
//#include <conio.h>
//#include <windows.h>

#include "main.h"
#include "App/app.h"
#include <unistd.h> 

int main(int argc, char** argv) {
    Screen_windowLoad sc_main = {&Sc_main, 0};
    lang = pt_br;
    Start_initialize();
    App_initialize();

    Screen_windowOpen(&sc_main);

    while (1) {
        App_loop();
        Start_loop();
        LCD_sendBuffer(lcdBuffer);
        usleep(100 * 1000);
    }
}
