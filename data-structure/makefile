CC = gcc

.SUFFIXES: .c .o

.c.o:
	$(CC) -o $@ -g $^

all: skiplist.o

clean:
	rm *.o
