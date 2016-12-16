CC=cc
CFLAGS=-c -strict

all: proj1

proj1: proj1.o functions.o
	$(CC) proj1.o functions.o -o proj1

proj1.o: proj1.c
	$(CC) $(CFLAGS) proj1.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

clean:
	rm -rf *.o proj1
