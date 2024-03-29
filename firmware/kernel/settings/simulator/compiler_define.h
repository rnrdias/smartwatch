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

#define _SIMULATOR_
//Load const
#define _LC(x) ((void*)x+((long long int)1<<(sizeof(char *)*8-2)))
//#define _LC(x) (x)

#define CONST const
#define RCB(VAR) (VAR)[0] // Read const byte
#define RCW(VAR) &((*VAR)[0]) // Read const word
#define _CONST  // define variable const
#define MEM_MAX 1024 //define o tamanho da memoria das funções mem

#endif