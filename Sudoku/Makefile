CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: sudoku

sudoku: main.o sudoku.o
	$(CC) $(CFLAGS) -o sudoku main.o sudoku.o

main.o: main.c sudoku.h
	$(CC) $(CFLAGS) -c main.c

sudoku.o: sudoku.c sudoku.h
	$(CC) $(CFLAGS) -c sudoku.c

clean:
	rm -f *.o sudoku

