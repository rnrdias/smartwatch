/*
 * Buffer.c
 *
 * Created: 06/03/2018 23:47:14
 *  Author: RNR
 */


//Para o PIC impressao de String adicionar conversao para int EX: Std_printf("S:%s",(int)msg);
/* 
 * 03/05 Correção bug do sinal positivo

 */
#include "std.h"


//#define Std_buffer(val) Std_out(val)

typedef union intToStringFragType {

    struct {
        unsigned : 7;
        unsigned ZerosNum : 4;
        unsigned ShortLong : 1;
        unsigned Prefix : 1;
        unsigned VisiblePositive : 1;
        unsigned HidePrintSigned : 1;
        unsigned Signed : 1;
    };

    struct {
        unsigned int Value;
    };
} Std_intToStringFrag_t;

void Std_intToString(void (*functionPtr)(char), unsigned long int num, Std_intToStringFrag_t flags) {
    unsigned long int base = 1;
    //unsigned char i = 0;
    unsigned char zerosNum = flags.ZerosNum;
    char carBase = '0';
    char sinal = 0;

    //prefix
    if (flags.Prefix)
        carBase = ' ';


    //load signal
    if (flags.Signed && !flags.HidePrintSigned) {
        if (!flags.ShortLong) {
            if ((long int) num < 0) {
                sinal = '-';
                num = ~num;
                num++;
            }
        } else {
            if ((int) num < 0) {
                sinal = '-';
                num = ~((unsigned int) num);
                num++;
            }

        }
        if (sinal == 0 && flags.VisiblePositive) {
            sinal = '+';
        }
    }

    /*
    //load signal
    if (flags.Signed && !flags.HidePrintSigned) {
        //if (flags.Signed) {
        if ((long int) num < 0) {
            sinal = '-';
            if (!flags.ShortLong)
                num = ~num;
            else
                num = ~((unsigned int) num);
            num++;
        } else if (flags.VisiblePositive) {
            sinal = '+';
        }
        //}
    }
     */

    if (zerosNum != 0) {
        while (--zerosNum)
            base *= 10;
        num %= base * 10;
    } else if (num < 1000000000)
        while ((base * 10) <= num)
            base *= 10;
    else
        base = 1000000000;


    if (sinal && !num)
        sinal = ' ';

    //process number
    do {
        if (sinal) {
            (*functionPtr)(sinal);
            sinal = 0;
        }

        if (num / base) {
            carBase = '0';
        }

        (*functionPtr)((num / base) + carBase);
        num %= base;
    } while (base /= 10);
}

void Std_vaprintf(void (*functionPtr)(char), const char *vstr, va_list arg_ptr) {
    unsigned char isComand = 0;
    Std_intToStringFrag_t flags;
    char str = RVCB(vstr);

    while (str) {
        if (str == '%') {
            isComand = 1;
            flags.Value = 0;
            flags.Signed = 1;
        } else if (isComand) {
            if (str <= '9' && str >= '0') {
                flags.ZerosNum = str - '0' + 1;
            } else if (str == '+') {
                flags.VisiblePositive = 1;
            } else if (str == 'u') {
                flags.Signed = 0;
            } else if (str == ' ') {
                flags.Prefix = 1;
            } else if (str == '*') {
                flags.HidePrintSigned = 1;
            } else if (str == 'd') {
                flags.ShortLong = 1;
                Std_intToString(functionPtr, va_arg(arg_ptr, unsigned int), flags);
                isComand = 0;
            } else if (str == 'l') {
                Std_intToString(functionPtr, va_arg(arg_ptr, unsigned long int), flags);
                isComand = 0;
            } else if (str == 'c') {
                (*functionPtr)(va_arg(arg_ptr, unsigned int));
                isComand = 0;
            } else if (str == '%') {
                (*functionPtr)('%');
                isComand = 0;
            } else if (str == 's') {
                char *s;
                s = va_arg(arg_ptr, char *);
                while (RVCB(s))
                    (*functionPtr)(RVCB(s++));
                isComand = 0;
            } else {
                isComand = 0;
                if (Std_extends != 0)
                    (*Std_extends)(functionPtr, vstr, arg_ptr);
            }
        } else {
            (*functionPtr)(str);
        }

        str = RVCB(++vstr);
    }
}

void Std_printf(const char *str, ...) {
    va_list arg_ptr; //variavel tipo pilha
    va_start(arg_ptr, str); //seta para posicao inicial da pilha
    Std_vaprintf(Std_out, str, arg_ptr);
    va_end(arg_ptr); //finaliza pilha*/
}

void Std_fprintf(void (*functionPtr)(char), const char *str, ...) {
    va_list arg_ptr; //variavel tipo pilha
    va_start(arg_ptr, str); //seta para posicao inicial da pilha
    Std_vaprintf((*functionPtr), str, arg_ptr);
    va_end(arg_ptr); //finaliza pilha*/
}

char *Std_strAddSource;

void Std_strAdd(char dado) {
    *(Std_strAddSource++) = dado;
}

void Std_sprintf(char *source, const char *str, ...) {
    va_list arg_ptr; //variavel tipo pilha
    Std_strAddSource = source;
    va_start(arg_ptr, str); //seta para posicao inicial da pilha
    Std_vaprintf(Std_strAdd, str, arg_ptr);
    va_end(arg_ptr); //finaliza pilha*/
    Std_strAdd('\0');
}

void Std_put(const char *str) {
    char s;
    while ((s = RVCB(str++)))
        Std_out(s);
}

void Std_initialize() {
    Std_extends = 0;
}