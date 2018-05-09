/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screen.h"

unsigned char *scrollValue;

/*unsigned char DC_getScroll() {
    return *scrollValue;
}*/

void Screen_StartScroll(unsigned char *scroll) {
    scrollValue = scroll;
}

void Screen_editNumber(Screen_numberEdit *numEdit) {
    if (numEdit->editRun) {
        if (Screen_getKeyEsc()) {
            numEdit->sucess = 0;
            numEdit->editRun = 0;
        } else if (Screen_getKeyEntre()) {
            numEdit->sucess = 1;
            numEdit->editRun = 0;
            *numEdit->numVar = numEdit->numView;
        } else if (Screen_getKeyUp()) {
            numEdit->numView += numEdit->numInc;
        } else if (Screen_getKeyDown()) {
            numEdit->numView -= numEdit->numInc;
        }
    } else {
        numEdit->numView = *numEdit->numVar;
    }
    if (numEdit->numView > numEdit->numMax)
        numEdit->numView = numEdit->numMin;
    if (numEdit->numView < numEdit->numMin)
        numEdit->numView = numEdit->numMax;
}

char mastEditNumRun;
unsigned char mastEditNumRunIndex;
char mastEditNumApl;

void mastEditNumber(Screen_numberEdit *numEdit) {
    if (numEdit->editRun) {
        if (Screen_getKeyUp()) {
            numEdit->numView += numEdit->numInc;
        } else if (Screen_getKeyDown()) {
            numEdit->numView -= numEdit->numInc;
        }
    }
    if (numEdit->numView > numEdit->numMax)
        numEdit->numView = numEdit->numMin;
    if (numEdit->numView < numEdit->numMin)
        numEdit->numView = numEdit->numMax;
}

char Screen_hasEditNumRun() {
    return mastEditNumRun != 0;
}

char stackPont;
DC_window *stack[stackSize];

#define stackPush(x) stack[++stackPont]=x
#define stackPop() stack[stackPont--]

void Screen_windowOpen(DC_window *win) {
    stackPush(win);
    scrollValue = 0;
    if (win->start != 0)
        win->start(win);
}

void Screen_windowClose() {
    DC_window *aux = stackPop();
    if (aux->end != 0)
        aux->end(aux);
}

void Screen_loop() {
    if (stackPont >= 0) {
        if (stack[stackPont]->title != 0) {
            Screen_windowLoadHead(stack[stackPont]->title);
        }
        stack[stackPont]->body(stack[stackPont]);
    }
    //scroll process
    if (!Screen_hasEditNumRun() && scrollValue) {
        if (Screen_getKeyDown() && Screen_getScrollStop()) {
            (*scrollValue)++;
        } else if (Screen_getKeyUp() && *scrollValue != 0) {
            (*scrollValue)--;
        }
    }
}

void Screen_initialize() {
    mastEditNumApl = 0;
    mastEditNumRun = 0;
    mastEditNumRunIndex = 0;
    scrollValue = 0;
    stackPont = -1;
}

void Screen_Std_Extends(void (*functionPtr)(char), char *str, va_list *arg_ptr) {
    if (*str == 'y') {
        if (mastEditNumRunIndex < mastEditNumRun) {
            mastEditNumRun = 0;
            mastEditNumApl = 0;
        }

        if (Screen_getKeyEntre())
            mastEditNumRun++;

        if (Screen_getKeyEsc())
            mastEditNumRun = 0;

        if (mastEditNumRunIndex < mastEditNumRun) {
            mastEditNumApl = 1;
        }

        mastEditNumRunIndex = 0;
    }

    if (*str == 'x') {
        Screen_numberEdit *aux;
        aux = va_arg(*arg_ptr, Screen_numberEdit *);

        aux->editRun = (mastEditNumRun == ++mastEditNumRunIndex);

        if (mastEditNumRun != 0) {
            if (aux->numInc == 0) {
                if (aux->editRun) {
                    mastEditNumRun++;
                    aux->editRun = 0;
                }
            } else {
                mastEditNumber(aux);
                if (mastEditNumApl) {
                    *aux->numVar = aux->numView;
                }
            }
        } else {
            aux->numView = *aux->numVar;
        }
    }
}


Screen_list *listAux;

void Screen_listSelectLoad(Screen_list *list) {
    listAux = list;
}

void Screen_listSelectPrint() {
    static unsigned char scrollOffset;
    unsigned char listIndex;
    unsigned char i;

    //limite moviment list
    if (listAux->index >= listAux->sizeList) {
        listAux->index = listAux->sizeList - 1;
    }

    if (listAux->index - (listAux->scrollIndex - scrollOffset) >= listAux->quantPrint) {
        listAux->scrollIndex++;
    } else if (listAux->index < listAux->scrollIndex) {
        listAux->scrollIndex--;
    }


    scrollOffset = 0;
    listIndex = listAux->scrollIndex;
    i = listAux->quantPrint;
    while (i--) {
        if (listAux->index == listIndex) {
            listAux->itens[listIndex].isSelect = 1;
            if (Screen_getKeyEntre()) {
                if (listAux->itens[listIndex].click != 0)
                    listAux->itens[listIndex].click(&listAux->itens[listIndex]);
            }
        } else {
            listAux->itens[listIndex].isSelect = 0;
        }
        if (listAux->itens[listIndex].description != 0) {
            Screen_listSelectOutPrint(&listAux->itens[listIndex]);
        } else if (listAux->itens[listIndex].itemPrint != 0) {
            scrollOffset += listAux->itens[listIndex].itemPrintSize - 1;
            listAux->itens[listIndex].itemPrint(&listAux->itens[listIndex]);
        }

        if (++listIndex >= listAux->sizeList)
            break;

    }

    //keys
    if (!Screen_hasEditNumRun()) {
        if (Screen_getKeyDown())
            listAux->index++;
        if (Screen_getKeyUp() && listAux->index != 0)
            listAux->index--;
    }


}