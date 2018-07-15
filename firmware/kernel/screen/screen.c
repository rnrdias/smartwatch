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

void Screen_editNumber(Screen_numberEditFormat *numEdit) {
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

void mastEditNumber(Screen_numberEditFormat *numEdit) {
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

signed char stackPont, antStackPont;
Screen_windowLoad *stack[stackSize];

/*#define stackNext() &stack[++stackPont]
#define stackPush(x) stack[++stackPont]=x
#define stackWindow() (stack[stackPont])
#define stackPop() stack[stackPont--]*/

void Screen_windowOpen(Screen_windowLoad *win) {
    Mem_alloc(stack[++stackPont], sizeof (Screen_windowLoad));
    stack[stackPont]->parameters = win->parameters;
    stack[stackPont]->windows = win->windows;
}

void Screen_windowClose() {
    stackPont--;
}

void Screen_loop() {
    //carregamento de screen
    if (antStackPont < stackPont) {
        void (*start)(Screen_windowLoad * this) = (void (*)(Screen_windowLoad *))RVCW(&stack[stackPont]->windows->start);
        void (*resume)(Screen_windowLoad * this) = (void (*)(Screen_windowLoad *))RVCW(&stack[stackPont]->windows->resume);
        antStackPont = stackPont;

        //pausa tela anterior
        if (stackPont > 0) {
            void (*pause)(Screen_windowLoad * this) = (void (*)(Screen_windowLoad *))RVCW(&stack[stackPont - 1]->windows->pause);
            if (pause != 0)
                pause(stack[stackPont - 1]);
        }

        //inicializa proxima tela
        if (start != 0)
            start(stack[stackPont]);
        if (resume != 0)
            resume(stack[stackPont]);
        mastEditNumRun = 0;
    } else if (antStackPont > stackPont) {
        void (*pause)(Screen_windowLoad * this) = (void (*)(Screen_windowLoad *))RVCW(&stack[stackPont + 1]->windows->pause);
        void (*end)(Screen_windowLoad * this) = (void (*)(Screen_windowLoad *))RVCW(&stack[stackPont + 1]->windows->end);
        void (*resume)(Screen_windowLoad * this) = (void (*)(Screen_windowLoad *))RVCW(&stack[stackPont]->windows->resume);
        antStackPont = stackPont;
        //finaliza tela
        if (pause != 0)
            pause(stack[stackPont + 1]);
        if (end != 0)
            end(stack[stackPont + 1]);
        Mem_free(stack[stackPont + 1]);
        //retorna a tela anterior
        if (resume != 0)
            resume(stack[stackPont]);
    }


    if (stackPont >= 0) {
        void (*loop)(Screen_windowLoad * this) = (void (*)(Screen_windowLoad *))RVCW(&stack[stackPont]->windows->loop);
        if (stack[stackPont]->windows->title != 0) {
            Screen_windowLoadHead(stack[stackPont]->windows->title);
        }
        loop(stack[stackPont]);
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
    antStackPont = -1;
}

void Screen_Std_Extends(void (*functionPtr)(char), const char *vstr, va_list * arg_ptr) {
    char str = RVCB(vstr);

    if (str == 'y') {
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

    if (str == 'x') {
        Screen_numberEditFormat *aux;
        aux = va_arg(*arg_ptr, Screen_numberEditFormat *);

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
                    switch (aux->type) {
                        case 1:
                            *(char *) aux->numVar = aux->numView;
                            break;
                        case 2:
                            *(int *) aux->numVar = aux->numView;
                            break;
                        case 3:
                            *(long *) aux->numVar = aux->numView;
                            break;
                        case 4:
                            *(unsigned char *) aux->numVar = aux->numView;
                            break;
                        case 5:
                            *(unsigned int *) aux->numVar = aux->numView;
                            break;
                        case 6:
                            *(unsigned long *) aux->numVar = aux->numView;
                            break;
                    }
                }
            }
        } else {
            switch (aux->type) {
                case 1:
                    aux->numView = *(char*) aux->numVar;
                    break;
                case 2:
                    aux->numView = *(int*) aux->numVar;
                    break;
                case 3:
                    aux->numView = *(long*) aux->numVar;
                    break;
                case 4:
                    aux->numView = *(unsigned char*) aux->numVar;
                    break;
                case 5:
                    aux->numView = *(unsigned int*) aux->numVar;
                    break;
                case 6:
                    aux->numView = *(unsigned long*) aux->numVar;
                    break;
            }
        }
    }
}


Screen_list *listAux;

void Screen_listSelectLoad(Screen_list * list) {
    listAux = list;
}

void Screen_listSelectPrint() {
    static unsigned char scrollOffset;
    unsigned char listIndex;
    unsigned char i;

    //keys
    if (!Screen_hasEditNumRun()) {
        if (Screen_getKeyDown())
            listAux->index++;
        if (Screen_getKeyUp() && listAux->index != 0)
            listAux->index--;
    }

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
}