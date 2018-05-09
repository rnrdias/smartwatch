/*
 * Buffer.h
 *
 * Created: 06/03/2018 23:47:02
 *  Author: RNR
 */


#ifndef STD_H_
#define STD_H_

#include <stdarg.h>


/*
 * Prototipo de saida padrão para o printf
 */
void Std_out(char val);

/*
 Inicializa o Std
 */
void Std_initialize();

/*
 Função padrão para impressões
 * comandos suportados:  %d  %l  %c  %s %%
 * %d imprime numero tipo int
 * %l imprime numero tipo long int
 * %c imprime caracter char
 * %s imprime string char *
 * %% imprime o caracter %
 * sub comandos
 * %nd %nl n é um numero de 0 a 9 : limita o numero de digitos e completa com zeros
 * %+d %+l força a exibição do sinal positivo
 * % nd % nl é um numero de 0 a 9 : limita o numero de digitos e completa com espaços
 * %ud %ul imprime numero do tipo unsigned
 * %*d %*l oculta o sinal do numero
 * 
 * exemplos
 * %5d , 15 : 000015
 * % 5d, 15 :     15
 * %d, 15   :15
 * %u1+d,15 :+5
 * %%d,15   :%
 */
void Std_printf(char *str, ...);

/*
 *  Equivalente oa Std_printf mas com a saida redirecionavel para outra função
 */
void Std_fprintf(void (*functionPtr)(char), char *str, ...);

/*
 * Equivalente oa Std_printf mas com a saida um string
 */
void Std_sprintf(char *source, char *str, ...);

/*
 * Função de extenção das funcionalidades do Std print
 */
void (*Std_extends)(void (*functionPtr)(char), char*, va_list *arg_ptr);

/*
 * Função de impressão rapida sem uso de comandos. ex: '%c, %d ...'.
 */
void Std_put(char *str);
#endif /* STD_H_ */