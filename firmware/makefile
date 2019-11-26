
############################# Makefile ##########################
#create empty variables
SOURCES = 
PATH_OBJS_DIR =

#set default bin dir
PATH_BIN_DIR = build

#Simulator Load
ifeq "$(MAKECMDGOALS)" "all_simulator"
	CC=gcc 
	CFLAGS= -D SIMULATOR -g -W -Wall -ansi -pedantic -std=c11 -lncurses
	CFLAGSLINKER= -g -std=c11 -lncurses

	PATH_BIN=$(PATH_BIN_DIR)/simulator

	SOURCES += $(wildcard ./kernel/drivers/simulator/*.c)
	SOURCES += $(wildcard ./kernel/settings/simulator/*.c)

	PATH_OBJS_DIR += $(PATH_OBJS)/kernel/drivers/simulator
	PATH_OBJS_DIR += $(PATH_OBJS)/kernel/settings/simulator

#avr Load
else 
	ifeq "$(MAKECMDGOALS)" "all_m328p"
		F_CPU=8000000L
		MMCU=atmega328p
		CC=avr-gcc 
		CFLAGS= -D ATMEGA328P -ansi -pedantic -W -Wall -Os -std=c11 -mmcu=$(MMCU) -D F_CPU=$(F_CPU)
		CFLAGSLINKER=-Wall -Os -std=c11 -mmcu=$(MMCU) -D F_CPU=$(F_CPU)

		PATH_BIN=$(PATH_BIN_DIR)/atmega328p

		SOURCES += $(wildcard ./kernel/drivers/atmega328p/*.c)
		SOURCES += $(wildcard ./kernel/settings/atmega328p/*.c)

		PATH_OBJS_DIR += $(PATH_OBJS)/kernel/drivers/atmega328p
		PATH_OBJS_DIR += $(PATH_OBJS)/kernel/settings/atmega328p

	#others
	else
		#PATH_BIN_M328P=build/atmega328p
		#PATH_BIN=$(PATH_BIN_M328P) build/simulator
	endif

endif



#Generic
PATH_OBJS=$(PATH_BIN)/obj
EXEC=$(PATH_BIN)/smartwatch

SOURCES += $(wildcard *.c)
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

PATH_OBJS_DIR += $(PATH_OBJS)
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


all_simulator: mkdir $(EXEC)
all_m328p: mkdir $(EXEC)

mkdir:
	mkdir -p $(PATH_BIN)
	mkdir -p $(PATH_OBJS_DIR)

	
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGSLINKER)

#Processe todos os arquivos .c para .o
$(PATH_OBJS)/%.o: %.c
	$(CC) -o $@ -c $*.c $(CFLAGS)

#Para limpeza
.PHONY: clean
clean: 
	rm -rf $(PATH_BIN_DIR)
