/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"
#include "../App/stopwatch.h"

typedef struct {
    unsigned char hour;
    unsigned char data;
} Sc_stopwatchParam;

void Sc_stopwatchStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->stopwatch);
}

void Sc_stopwatchLoop(Screen_windowLoad *this) {
    Std_printf("%w%2ul:%1ud%w\n%1ud\r", &Font_numeric_16, App_stopwatchTime.timeCurrent.second / 60, (unsigned char) App_stopwatchTime.timeCurrent.second % 60, &Font_alfanum_8, App_stopwatchTime.timeCurrent.millesimal);
    for (unsigned char i = 0; i < 3; i++) {
        App_stopwatchTimeBaseFormat *t = App_stopwatch_getHistory(i);
        Std_printf("%ul:%1ud:%1ud\r\n", t->second / 60, (unsigned char) t->second % 60, t->millesimal);
    }

    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_stopwatchEnd(Screen_windowLoad *this) {

}

void Sc_stopwatchResume(Screen_windowLoad *this) {
    App_stopwatchTime.enableControl = 1;
}

void Sc_stopwatchPause(Screen_windowLoad *this) {
    App_stopwatchTime.enableControl = 0;
}
Screen_window Sc_stopwatch = {0, Sc_stopwatchLoop, Sc_stopwatchStart, Sc_stopwatchEnd, Sc_stopwatchResume, Sc_stopwatchPause};