/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   keyboard.h
 * Author: RNR
 *
 * Created on 9 de Maio de 2018, 12:25
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#ifdef __cplusplus
extern "C" {
#endif

    char Keyboard_getKeyEnter();
    char Keyboard_getKeyEsc();
    char Keyboard_getKeyUp();
    char Keyboard_getKeyDown();
    
    char Keyboard_keyEnter();
    char Keyboard_keyEsc();
    char Keyboard_keyUp();
    char Keyboard_keyDown();
    
    void Keyboard_inicialize();
    void Keyboard_loop();


#ifdef __cplusplus
}
#endif

#endif /* KEYBOARD_H */

