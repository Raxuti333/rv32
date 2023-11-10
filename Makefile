CC=cc
CFLAGS=-O2 -march=native -mtune=native -Iinc -Wno-incompatible-pointer-types -Wno-int-to-pointer-cast -Wno-unused-result
LFLAGS=
CSRC=src/*
TARGET=rv32

build:
	${CC} ${CFLAGS} -o ${TARGET} ${CSRC} ${LFLAGS}