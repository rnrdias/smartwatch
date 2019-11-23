/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include "../beep.h"
#include "../interruption.h"

//#include <pthread.h>
//#include <windows.h>

/*void *Beep_beep(void *param) {
    Beep_paramFormat *p = (Beep_paramFormat *) param;
    /*while (p->repeat && p->masterRepeat) {
        Beep(p->frequency, p->frequencyDelay);
        Sleep(p->repeatDelay);
        p->repeat--;
        if (!(p->repeat % p->masterRepeat)) {
            Sleep(p->masterRepeatDelay);
        }
    }*
    p->repeat = 0;
    pthread_exit(NULL);
}*/

//pthread_t thread;

Beep_paramFormat Beep_core;

char beep_onNoff = 0;

void Beep_on() {
    if (!beep_onNoff) {
        beep_onNoff = 1;
        char command[100];
        snprintf(command, 100, "pactl load-module module-sine frequency=%d>>/dev/null", Beep_core.frequency);
        system(command);
    }
}

void Beep_off() {
    if (beep_onNoff) {
        beep_onNoff = 0;
        system("pactl unload-module module-sine");
    }
}

void Beep_intTimerMS() {
    if (Beep_param) {
        if (Beep_core.masterRepeat == 255) {
            Beep_core = *Beep_param;
        }

        if (Beep_core.masterRepeat) {
            if (Beep_core.repeat) {
                if (Beep_core.frequencyDelay) {
                    Beep_core.frequencyDelay--;
                    Beep_on();
                } else if (Beep_core.repeatDelay) {
                    Beep_core.repeatDelay--;
                    Beep_off();
                } else {
                    Beep_core.repeat--;
                    Beep_core.frequencyDelay = Beep_param->frequencyDelay;
                    Beep_core.repeatDelay = Beep_param->repeatDelay;
                }
            } else if (Beep_core.masterRepeatDelay) {
                Beep_core.masterRepeatDelay--;
                Beep_off();
            } else {
                Beep_core.masterRepeat--;
                Beep_core.repeat = Beep_param->repeat;
                Beep_core.masterRepeatDelay = Beep_param->masterRepeatDelay;
            }
        } else {
            Beep_param = 0;
        }
    } else {
        Beep_core.masterRepeat = 255;
        Beep_off();
    }
}

Int_event Beep_IntEventTimerMS = {0, Beep_intTimerMS};

void Beep_loop(void) {
    /*if (Beep_param) {
        Beep_core = *Beep_param;
        Beep_param = 0;
    }*/
}

void Beep_initialize(void) {
    Beep_param = 0;
    Int_register(&Beep_IntEventTimerMS, INT_TIMER_MS);
    Beep_off();
}