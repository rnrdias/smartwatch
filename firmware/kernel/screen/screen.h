/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   displayControl.h
 * Author: RNR
 *
 * Created on 5 de Maio de 2018, 12:32
 */

#ifndef SCREEN_H
#define SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdarg.h>
#include "../util.h"

#define stackSize 10 // define o tamanho maximo da pilha de janelas

    /*
     * Pototipo para colheta da tecla seta para cima
     */
    char Screen_getKeyUp();
    /*
     * Pototipo para colheta da tecla seta para baixo
     */
    char Screen_getKeyDown();
    /*
     * Pototipo para colheta da tecla entre
     */
    char Screen_getKeyEntre();
    /*
     * Pototipo para colheta da tecla sair
     */
    char Screen_getKeyEsc();

#define Screen_numberEditChar 1
#define Screen_numberEditInt 2
#define Screen_numberEditLong 3
#define Screen_numberEditUnsignedChar 4
#define Screen_numberEditUnsignedInt 5
#define Screen_numberEditUnsignedLong 6

    /*
     * Estrutura para configuração para a edição do numero 
     * *numVar : ponteiro para a variavel a ser editada
     * numInc : numero do inclemento, se 0 a edição é desativada
     * numMin : range minimo
     * numMax : range maximo
     * editRun : a edição estar em andamento
     */
    typedef struct {
        long int *numVar;
        unsigned char numInc;
        long int numMin;
        long int numMax;
        long int numView;
        unsigned type : 3;
        unsigned sucess : 1;
        unsigned editRun : 1;
    } Screen_numberEditFormat;

    /*
     * Função para aplicar a edição a um numero com DC_numberEdit
     * de paramentro
     */
    void Screen_editNumber(Screen_numberEditFormat *num);

    /*
     * Estrutura de definição de um item para a lista: item basico:
     * *description : ponteiro para a descrição informativa do item
     * (*click)(DC_listItem *this) : ponteiro para a função do click do item
     * 
     * Parametros acresentados para o itens personalizados:
     * (*itemPrint)(DC_listItem *this) : função padrão para a impressão
     * itemPrintSize : tamanho do item a ser impresso
     * 
     * isSelect : se o item estar selecionado
     */
    typedef struct Screen_listItem_t {
        char *description;
        void (*click)(struct Screen_listItem_t * this);
        void (*itemPrint)(struct Screen_listItem_t * this);
        unsigned char itemPrintSize;
        char isSelect;
        void *parameter;
    } Screen_listItem;

    /*
     * Estrutura a definição de uma lista de itens
     * *itens : ponteiro contendo um lista de itens
     * sizeList : define o tamanho da lista
     * quantPrint : quantidade de item visiveis na impressão
     * scrollIndex : define o deslocamento do scroll
     * index : item atual selecionado
     */
    typedef struct {
        Screen_listItem *itens;
        unsigned char sizeList;
        unsigned char quantPrint;
        unsigned char scrollIndex;
        unsigned char index;
    } Screen_list;

    /*
     * carreaga uma lista de seleção
     */
    void Screen_listSelectLoad(Screen_list *list);
    /*
     * realiza a impressão da lista
     */
    void Screen_listSelectPrint();
    /*
     * prototipo para impressão padrão do item
     */
    void Screen_listSelectOutPrint(Screen_listItem *iten);

    /*
     * 
     */
    void Screen_StartScroll(unsigned char *scroll);
    /*
     * 
     */
    char Screen_getScrollStop();


    struct Screen_windowLoad_t;

    /*
     * Estrutura de definição de janelas
     * *title(DC_window *this) : um ponteiro para o titulo da janela
     * *body(DC_window *this) : função loop de execução da janela
     * *start(DC_window *this) : função de inicilização da janela
     * *end(DC_window *this) : função de finalização da janela
     * *parameters : ponteiro para parametros
     */
    typedef struct Screen_window_t {
        const char *title;
        void (*loop)(struct Screen_windowLoad_t * this);
        void (*start)(struct Screen_windowLoad_t * this);
        void (*end)(struct Screen_windowLoad_t * this);
        void (*resume)(struct Screen_windowLoad_t * this);
        void (*pause)(struct Screen_windowLoad_t * this);
    } Screen_window;

    /*
     * Estrutura de definição de janelas
     * windows : contem definições das janelas
     * *parameters : ponteiro para parametros
     */
    typedef struct Screen_windowLoad_t {
        struct Screen_window_t * windows;
        void *parameters;
    } Screen_windowLoad;


    /*
     * prototipo para a impressão do titulo da janela
     */
    void Screen_windowLoadHead(const char *title);
    /*
     * função para abertura da janela
     */
    void Screen_windowOpen(Screen_windowLoad *win);
    /*
     * função para o fechamento da janela
     */
    void Screen_windowClose();

    /*
     * inicializa o modulo DC
     */
    void Screen_initialize();
    /*
     * Processar o modulo DC
     */
    void Screen_loop();

    /*
     * Função de extenção da biblioteca padrão Std_printf
     * Comando acresentados
     * %y : incializa mudulo de edição de numeros
     * %x : defina numero para edição
     * 
     * ex: "%y %e %e",&num1,&num2 : num1 e num2 são estruturas DC_numberEdit 
     */
    void Screen_Std_Extends(void (*functionPtr)(char), const char *str, va_list *arg_ptr);
    /*
     * Retorna se existe alguma edição em andamento
     */
    char Screen_hasEditNumRun();
#ifdef __cplusplus
}
#endif

#endif /* DISPLAYCONTROL_H */

