h25765
s 00016/00000/00000
d D 1.1 16/03/15 23:40:49 danieldk 1 0
c date and time created 16/03/15 23:40:49 by danieldk
e
u
U
f e 0
t
T
I 1
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
E 1
