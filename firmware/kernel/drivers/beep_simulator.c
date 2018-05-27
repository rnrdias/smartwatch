/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "beep_simulator.h"
#include <pthread.h>
#include <windows.h>

void *Beep_beep(void *param) {
    Beep_paramFormat *p = (Beep_paramFormat *) param;
    while (p->repeat && p->masterRepeat) {
        Beep(p->frequency, p->frequencyDelay);
        Sleep(p->repeatDelay);
        p->repeat--;
        if (!(p->repeat % p->masterRepeat)) {
            Sleep(p->masterRepeatDelay);
        }
    }
    p->repeat = 0;
    pthread_exit(NULL);
}

pthread_t thread;

void Beep_loop(void) {
    /*if (pthread_kill(thread, 0) && Beep_param)
        pthread_create(&thread, NULL, Beep_beep, (void *) Beep_param);*/
}

void Beep_initialize(void) {
    Beep_param = 0;
}