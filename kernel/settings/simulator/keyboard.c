/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../settings.h"

char Keyboard_getKeyEnter() {
    return letra == 'a';
}

char Keyboard_getKeyEsc() {
    return letra == 'd';
}

char Keyboard_getKeyUp() {
    return letra == 'w';
}

char Keyboard_getKeyDown() {
    return letra == 's';
}