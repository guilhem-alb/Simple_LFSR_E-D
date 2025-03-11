CC = gcc
CCFLAGS = -Wall -g

all: main

listes.o: Dependencies/listes.c Dependencies/listes.h
	${CC} ${CCFLAGS} -c Dependencies/listes.c

queue.o: Dependencies/queue.c Dependencies/queue.h
	${CC} ${CCFLAGS} -c Dependencies/queue.c

LFSR.o: LFSR.c LFSR.h
	${CC} ${CCFLAGS} -c LFSR.c	

main.o: main.c
	${CC} ${CCFLAGS} -c main.c

main: LFSR.o queue.o listes.o
	${CC} ${CCFLAGS} -o main main.c LFSR.o queue.o listes.o

clean:
	rm *.o ; rm main