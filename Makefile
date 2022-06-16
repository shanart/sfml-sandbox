CC = g++
FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

# SELECTION BOX
# FILES=selection-box/main.cpp selection-box/SelectionBox.cpp

# CANNONS
FILES=cannons/main.cpp

BIN=bin/main

build:
	${CC} ${FILES} ${FLAGS} -o ${BIN}

all: build 
