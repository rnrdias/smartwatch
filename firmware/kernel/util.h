/*
 * Util.h
 *
 * Created: 06/03/2018 23:40:45
 *  Author: RNR
 */


#ifndef UTIL_H_
#define UTIL_H_

#include "compiler_define.h"


/*
 * Pototipo para atraso de milesegundos
 */
extern void Util_delayMs(unsigned int val);
/*
 * Prototipo para atraso de micro segundos
 */
extern void Util_delayUs(unsigned int val);
/*
 * Função para o calculo de paridade de um numero
 */
extern unsigned char Util_parityCalc(unsigned char value, unsigned char Imp_nPar);
/*
 * Prototipo de alternação a cada segundo de 0 para 1 e 1 para 0
 */
extern char Util_toggleSeg();
/*
 * returna o tamanho de uma string
 */
extern unsigned char Util_stringLenth(char *string);
/*
 * Aloca variavel na pilha de memoria
 */
void *Util_memPush(unsigned int size);
/*
 * Retira variavel da pilha de memoria
 */
void Util_memTop(void *p);

#endif /* UTIL_H_ */