CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g3

all: EX1 EX2

EX1: exercise1.c
	${CC} -o $@ ${CFLAGS} $^

EX2: exercise2.c
	${CC} -o $@ ${CFLAGS} $^