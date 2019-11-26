/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../settings.h"

char Keyboard_getKeyEnter() {
    return (!(PINB&(1<<PINB4)));
}

char Keyboard_getKeyEsc() {
    return (!(PINB&(1<<PINB3)));
}

char Keyboard_getKeyUp() {
    return (!(PINB&(1<<PINB2)));//return (!(PINC&(1<<PINC2)));
}

char Keyboard_getKeyDown() {
    return (!(PINB&(1<<PINB5)));//return (!(PINC&(1<<PINC3)));
}