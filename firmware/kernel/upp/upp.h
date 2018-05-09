/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   core.h
 * Author: RNR
 *
 * Created on 2 de Maio de 2018, 20:33
 */

#ifndef UPP_H
#define UPP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include "../util.h"

#define UPP_POSITION_LEFT 1
#define UPP_POSITION_CENTER 2
#define UPP_POSITION_RIGHT 3

    typedef struct {
        unsigned char width;
        unsigned char height;
        unsigned char start;
        unsigned char size;

        unsigned char data[];
    } UPP_BitmapFormat;
    
    /*
     * Prototipo para colheta do tamanho do display sua largura
     */
    int UPP_getDisplayWidth();
    
    /*
     * Prototipo para colheta do tamanho do display sua altura
     */
    int UPP_getDisplayHeight();
    
    /*
     * Prototipo para saida padrão dos dados processados para serem enviados
     * para o display
     */
    void UPP_buffer(char valor, int index);
    
    /*
     * Estrutura que contem alguns flags de controle
     * invert : se 1 o proximo conteudo impresso será invertido os bit
     * toggle : se 1 o proximo conteudo impresso será aplicado o efeito toggle 
     * (pisca pisca)
     * boxBegin : define valor de offset para a posição inicial. Será aplicado 
     * ao proximo conteudo impresso
     * boxEnd : define valor de offset para a posição final. Será aplicado ao 
     * proximo conteudo impresso
     */
    union UPP_flag {

        struct {
            unsigned invert : 1;
            unsigned toggle : 1;
            unsigned char boxBegin;
            unsigned char boxEnd;
        };

        struct {
            unsigned long int value;
        };
    } UPP_flag;

    UPP_BitmapFormat *UPP_fontDefault;
    
    /*
     * Função de inicialização da UPP
     */
    void UPP_initialize();
    /*
     * Carrega mensagem de texto para a posição atual utilizando a fonte padrão
     */
    void UPP_loadText(char *message);
    /*
     * Carrega um caracter para a posição atual utilizando a fonte padrão
     */
    void UPP_loadTextChar(char message);
    /*
     * Carrega uma imagem bitmap
     */
    char UPP_loadBitmap(UPP_BitmapFormat *font, unsigned char index);
    /*
     * Limpa display e seta para a posição inicial
     */
    void UPP_clear();
    /*
     * Set a posição do cursor
     */
    void UPP_setCursorXY(unsigned char x, unsigned char y);
    /*
     * Preenche uma linha inteira com um determinado imagem bitmap
     */
    void UPP_fillInLine(UPP_BitmapFormat *bitmap, unsigned char index);
    /*
     * Set posição do cursor:
     * UPP_POSITION_LEFT : para esquerda
     * UPP_POSITION_CENTER : para o centro
     * UPP_POSITION_RIGHT : para a direita
     */
    void UPP_positionBitmap(UPP_BitmapFormat *bitmap, unsigned char size, char position);
    /*
     * Carrega uma mensagem para uma determinada posição.
     * UPP_POSITION_LEFT : para esquerda
     * UPP_POSITION_CENTER : para o centro
     * UPP_POSITION_RIGHT : para a direita
     */
    void UPP_positionText(char *message, char position);
    /*
     * Seta o deslocamento do scroll
     */
    void UPP_setScroll(unsigned char num);
    /*
     * Verifica se o scroll estar no fim
     */
    char UPP_scrollHasNext();
    
    /*
     * Função de extenção da biblioteca padrão Std_printf
     * Comando acresentados
     * %w : Altera a fonte padrão ("%w",&fonte)
     * %b : Seta offset de posição inicial ("%b",10)
     * %e : Seta offset de posição final ("%e", 90)
     * %r : Limpa display e seta para a posição inicial ("%r")
     * %m : Altera a inversão dos bits impressos ("%m menagem %m",1,0)
     * %t : Define o conteudo que ficará piscado na tela (%t mensagem %t,1,0)
     * %< : Seta cursor para esquerda ("%<mensagem")
     * %| : Seta cursor para centro ("%|mensagem")
     * %> : Seta cursor para direita ("%>mensagem")
     * %# : Preenche a linha com um bitmap ("%#",&bitmap,index)
     */
    void UPP_Std_Extends(void (*functionPtr)(char), char *str, va_list *arg_ptr);

#ifdef __cplusplus
}
#endif

#endif /* CORE_H */

