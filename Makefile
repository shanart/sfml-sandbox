CC = g++
FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
FILES=selection-box/main.cpp
BIN=bin/main

build:
	${CC} ${FILES} ${FLAGS} -o ${BIN}

all: build 