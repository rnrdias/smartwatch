/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "keyboard.h"
char keyEnter, keyEsc, keyUp, keyDown;

char Keyboard_keyEnter(void) {
    return keyEnter;
}

char Keyboard_keyEsc(void) {
    return keyEsc;
}

char Keyboard_keyUp(void) {
    return keyUp;
}

char Keyboard_keyDown(void) {
    return keyDown;
}

void Keyboard_inicialize(void) {
    keyEnter = 0;
    keyEsc = 0;
    keyDown = 0;
    keyUp = 0;
}
char antKeyEnter, antKeyEsc, antKeyUp, antKeyDown;

void Keyboard_loop(void) {
    keyEnter = 0;
    keyEsc = 0;
    keyDown = 0;
    keyUp = 0;

    if (Keyboard_getKeyEnter() != antKeyEnter) {
        antKeyEnter = Keyboard_getKeyEnter();
        keyEnter = antKeyEnter;
    }

    if (Keyboard_getKeyEsc() != antKeyEsc) {
        antKeyEsc = Keyboard_getKeyEsc();
        keyEsc = antKeyEsc;
    }

    if (Keyboard_getKeyUp() != antKeyUp) {
        antKeyUp = Keyboard_getKeyUp();
        keyUp = antKeyUp;
    }

    if (Keyboard_getKeyDown() != antKeyDown) {
        antKeyDown = Keyboard_getKeyDown();
        keyDown = antKeyDown;
    }
}