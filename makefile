
############################# Makefile ##########################
CC=gcc 
CFLAGS= -W -Wall -ansi -pedantic -std=c11 -lncurses
CFLAGSLINKER= -std=c11 -lncurses

PATH_BIN=build
PATH_OBJS=$(PATH_BIN)/obj
EXEC=$(PATH_BIN)/smartwatch
EXEC_DEBUG=$(PATH_BIN)/smartwatchdebug

SOURCES = $(wildcard *.c)
SOURCES += $(wildcard ./app/*.c)
SOURCES += $(wildcard ./app/status_bar/*.c)
SOURCES += $(wildcard ./kernel/*.c)
SOURCES += $(wildcard ./kernel/drivers/*.c)
SOURCES += $(wildcard ./kernel/fonts/*.c)
SOURCES += $(wildcard ./kernel/screen/*.c)
SOURCES += $(wildcard ./kernel/settings/*.c)
SOURCES += $(wildcard ./kernel/upp/*.c)
SOURCES += $(wildcard ./language/*.c)
SOURCES += $(wildcard ./screens/*.c)

PATH_OBJS_DIR = $(PATH_OBJS)
PATH_OBJS_DIR += $(PATH_OBJS)/app
PATH_OBJS_DIR += $(PATH_OBJS)/app/status_bar
PATH_OBJS_DIR += $(PATH_OBJS)/kernel
PATH_OBJS_DIR += $(PATH_OBJS)/kernel/drivers
PATH_OBJS_DIR += $(PATH_OBJS)/kernel/fonts
PATH_OBJS_DIR += $(PATH_OBJS)/kernel/screen
PATH_OBJS_DIR += $(PATH_OBJS)/kernel/settings
PATH_OBJS_DIR += $(PATH_OBJS)/kernel/upp
PATH_OBJS_DIR += $(PATH_OBJS)/language
PATH_OBJS_DIR += $(PATH_OBJS)/screens

OBJS = $(patsubst %.c,$(PATH_OBJS)/%.o,$(SOURCES))


all: mkdir $(EXEC)

all_debug: CFLAGS += -g
all_debug: CFLAGSLINKER += -g
all_debug: mkdir $(EXEC_DEBUG)

mkdir:
	mkdir -p $(PATH_BIN)
	mkdir -p $(PATH_OBJS_DIR)

	
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGSLINKER)

$(EXEC_DEBUG): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGSLINKER)

#Processe todos os arquivos .c para .o
$(PATH_OBJS)/%.o: %.c
	$(CC) -o $@ -c $*.c $(CFLAGS)

#Para limpeza
.PHONY: clean mrproper
clean: 
	rm -rf $(PATH_OBJS)
mrproper: clean
	rm -rf $(EXEC)
