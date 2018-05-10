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
/*
#include <avr/pgmspace.h>
#define CONST const PROGMEM
#define RCB(VAR) pgm_read_byte(VAR) // Read const byte
*/


#define CONST const
#define RCB(VAR) (VAR)[0] // Read const byte
#define Util_malloc_max 1024 //define o tamanho da memoria das funções memPush e memPop

#endif