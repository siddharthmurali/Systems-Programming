CC = gcc
CFLAGS = -Wall -g
OUTPUT = ./mymalloc
EXEOBJ = ./mymalloc.o
HEADERS = ./mymalloc.h

MAINOUTPUT = main
MAINOBJ = ./main.o

default: test1
all: default

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test1: $(EXEOBJ) $(MAINOBJ)
	$(CC) $(CFLAGS) $(MAINOBJ)  $(HEADERS) -o $@
clean:
	rm -f *.o $(MAINOUTPUT) 
