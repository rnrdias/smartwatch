/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"upp.h"
#define BUFFER_TAM ((UPP_getDisplayWidth()*UPP_getDisplayHeight()))

/*void UPP_setFlag(char flag) {

}*/

unsigned int cursIndex;
#define GET_CURSOR_X() (cursIndex%UPP_getDisplayWidth())
#define GET_CURSOR_Y() (cursIndex/UPP_getDisplayWidth())

unsigned char UPP_getCursorX() {
    return (cursIndex % UPP_getDisplayWidth());
}

unsigned char UPP_getCursorY() {
    return (cursIndex / UPP_getDisplayWidth());
}

//#define SET_CURSOR_X(value) (cursIndex=GET_CURSOR_Y()*UPP_getDisplayWidth()+value)
//#define SET_CURSOR_Y(value) (cursIndex=GET_CURSOR_X()+value*UPP_getDisplayWidth())

#define CURSOR_YP() cursIndex+=UPP_getDisplayWidth()
#define CURSOR_YN() cursIndex-=UPP_getDisplayWidth()

unsigned int cursIndexScroll;
unsigned int cursIndexAntScroll;
char cursIndexScrollHasNext;

/*adiciona dados no buffer*/
char bufferAdd(unsigned char data) {
    if (cursIndex >= BUFFER_TAM + cursIndexScroll) {
        cursIndexScrollHasNext = 1;
        return 1;
    }

    if (UPP_flag.invert)
        data = ~data;
    if (UPP_flag.toggle && Util_toggleSeg())
        data = 0x00;
    if (cursIndex >= cursIndexScroll + cursIndexAntScroll)
        UPP_buffer(data, (cursIndex - cursIndexScroll));
    cursIndex++;
    return 0;
}

void UPP_loadText(char *message) {
    while (*message)
        UPP_loadTextChar(*(message++));
}

char UPP_loadBitmap(const UPP_BitmapFormat *bitmap, unsigned char index) {
    const unsigned char *bitmapDados;
    unsigned char x, y;

    //Validate input
    if (RVCB(&bitmap->start) > index)
        return 1;
    if ((RVCB(&bitmap->size) + RVCB(&bitmap->start)) < index)
        return 1;
    if (UPP_flag.boxBegin >= UPP_getDisplayWidth())
        return 1;
    /*if (cursIndex >= BUFFER_TAM)
        return 1;*/

    //load variables
    index -= RVCB(&bitmap->start);
    bitmapDados = (bitmap->data + (index * RVCB(&bitmap->width) * RVCB(&bitmap->height)));
    y = RVCB(&bitmap->height);

    if (UPP_flag.boxBegin > GET_CURSOR_X() || UPP_flag.boxEnd == GET_CURSOR_X()) {
        UPP_setCursorXY(UPP_flag.boxBegin, GET_CURSOR_Y());
    }

    //process
    while (1) {
        x = RVCB(&bitmap->width);
        while (x) {
            if (bufferAdd(RVCB(bitmapDados++))) {
                cursIndex += x;
                break;
            }
            x--;
            if (UPP_flag.boxEnd <= GET_CURSOR_X()) {
                bitmapDados += x;
                break;
            }
        }
        if (--y) {
            cursIndex -= (RVCB(&bitmap->width) - x);
            CURSOR_YP();
        } else if (UPP_flag.boxEnd == GET_CURSOR_X() && GET_CURSOR_X() != 0) {
            CURSOR_YP();
            break;
        } else {
            break;
        }
    }
    if (UPP_flag.boxEnd != GET_CURSOR_X())
        cursIndex -= UPP_getDisplayWidth() * (RVCB(&bitmap->height) - 1);
    return 0;
}

void UPP_setCursorXY(unsigned char x, unsigned char y) {
    /*if (y >= UPP_getDisplayHeight || x >= UPP_getDisplayWidth()) {
        return 1;
    }*/
    cursIndex = (y * UPP_getDisplayWidth()) + x;
    //return 0;
}

char setTextPosition;

void UPP_loadTextChar(char message) {
    if (message == '\n')
        UPP_setCursorXY(GET_CURSOR_X(), GET_CURSOR_Y() + RVCB(&UPP_fontDefault->height));
    else if (message == '\r')
        UPP_setCursorXY(0, GET_CURSOR_Y());
    else if (UPP_fontDefault != 0)
        UPP_loadBitmap(UPP_fontDefault, message);
}

void UPP_clear() {
    char data = 0x00;
    cursIndexScroll = 0;
    cursIndexAntScroll = 0;
    cursIndex = 0;
    setTextPosition = 0;
    UPP_flag.value = 0;
    UPP_flag.boxEnd = UPP_getDisplayWidth();
    cursIndexScrollHasNext = 0;

    if (UPP_flag.invert) {
        data = 0xff;
    }
    for (int i = 0; i < BUFFER_TAM; i++)
        UPP_buffer(data, i);
    UPP_setCursorXY(0, 0);
}

void UPP_initialize() {
    //cursIndex = 0;
    //textPosition = 0;
    //UPP_fontDefault = 0;
    //cursIndexScroll = 0;
    //UPP_flag.value = 0;
    UPP_clear();
}

void UPP_fillInLine(UPP_BitmapFormat *bitmap, unsigned char index) {
    char y = GET_CURSOR_Y();
    UPP_setCursorXY(0, y);
    while (GET_CURSOR_Y() == y) {
        if (UPP_loadBitmap(bitmap, index))
            return;
    }
    UPP_setCursorXY(0, y);
}

char UPP_scrollHasNext() {
    return cursIndexScrollHasNext;
}

void UPP_setScroll(unsigned char num) {
    if (num > 100)
        num = 0;
    cursIndexScroll = UPP_getDisplayWidth() * num;
    cursIndexAntScroll = cursIndex;

}

void UPP_positionBitmap(const UPP_BitmapFormat *bitmap, unsigned char quantElem, char position) {
    if (position == 1) {
        UPP_setCursorXY(1, GET_CURSOR_Y());
    } else {
        //char x = (UPP_getDisplayWidth() - (size * RVCB(&bitmap->width)));
        char x = (UPP_flag.boxEnd - (quantElem * RVCB(&bitmap->width)));
        if (position == 2) {
            UPP_setCursorXY(x / 2, GET_CURSOR_Y());
        } else if (position == 3) {

            UPP_setCursorXY(x, GET_CURSOR_Y());
        }
    }
}

void UPP_positionText(char *message, char position) {

    UPP_positionBitmap(UPP_fontDefault, UPP_fontDefault->width * Util_stringLenth(message), position);
    UPP_loadText(message);
}

/*char textPosition;
char textBuffer[50];
char *posTextBuffer*/
void UPP_Std_Extends(void (*functionPtr)(char), const char *vstr, va_list *arg_ptr) {
    char str = RVCB(vstr);

    if (str == 'w') {
        UPP_fontDefault = va_arg(*arg_ptr, UPP_BitmapFormat *);
    } else if (str == 'b') {
        UPP_flag.boxBegin = va_arg(*arg_ptr, unsigned int);
    } else if (str == 'e') {
        UPP_flag.boxEnd = va_arg(*arg_ptr, unsigned int);
    } else if (str == 'r') {
        UPP_clear();
    } else if (str == 'm') {
        UPP_flag.invert = va_arg(*arg_ptr, unsigned int);
    } else if (str == 't') {
        UPP_flag.toggle = va_arg(*arg_ptr, unsigned int);
    } else if (str == '<') {
        setTextPosition = UPP_POSITION_LEFT;
    } else if (str == '>') {
        setTextPosition = UPP_POSITION_RIGHT;
    } else if (str == '|') {
        setTextPosition = UPP_POSITION_CENTER;
    } else if (str == 'g') {
        UPP_setCursorXY(0, 0);
    } else if (str == '#') {
        UPP_BitmapFormat *bf = va_arg(*arg_ptr, UPP_BitmapFormat *);
        char index = va_arg(*arg_ptr, unsigned int);
        UPP_fillInLine(bf, index);
    } else if (str == 'o') {
        UPP_setScroll(va_arg(*arg_ptr, unsigned int));
    }

    if (setTextPosition != 0) {
        unsigned int quant = 0;
        while (str) {
            if (str == '\r' || str == '\n')
                break;
            quant++;
            str = RVCB(++vstr);
        }
        UPP_positionBitmap(UPP_fontDefault, quant, setTextPosition);
        setTextPosition = 0;
    }

}