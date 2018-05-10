/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_mainBody(Screen_window *this) {
    Std_printf("%r\n");
    Std_printf("%w%1d:%1d%w\n %1d\r\n", &Font_numeric_16, 0, 0, &Font_alfanum_8, 0);
    Std_printf("%s %1d-%1d-%3d", "Seg", 1, 1, 2000);
    Std_printf("%s", "info");
    
    if (Keyboard_keyEnter()) {
        Screen_windowOpen(&Sc_menu);
    }
}
Screen_window Sc_main = {0, Sc_mainBody, 0, 0};