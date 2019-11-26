/*
 * File:   Util.c
 * Author: RNR
 *
 * Created on 12 de Mar�o de 2018, 14:23
 */

/*
Define configurações para o compilador personalizadas
*/

#ifndef USER_H_
#define USER_H_

//AVR

#include <avr/pgmspace.h>
#define CONSTMAX 0x8000
#define CONST const PROGMEM
#define RCB(VAR) pgm_read_byte(VAR) // Read const byte
#define RCW(VAR) pgm_read_word(VAR) // Read const byte

#define _LC(x) ((const void *)((unsigned int)x+CONSTMAX)) // load const variable

//#define CONST const
//#define RCB(VAR) (VAR)[0] // Read const byte
#define MEM_MAX 512 //define o tamanho da memoria das funções mem
#define stackSize 10 // define o tamanho maximo da pilha de janelas

#endif