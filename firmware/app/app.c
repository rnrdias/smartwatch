/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "app.h"

void App_loop(void) {
    App_alarms_loop();
    App_stopwatch_loop();
}

void App_initialize(void) {
    StatusBar_initialize();
    App_alarms_initialize();
    App_stopwatch_initialize();
}
