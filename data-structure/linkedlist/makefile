exectest1.out: test_linkedlist.o linkedlist.o
	gcc $^ -o $@

exectest2.out: linkedlist.o postinglist.o test_postinglist.o
	gcc $^ -o $@

.SUFFIXES: .c .o

.c.o:
	gcc -c $^ -o $@

clean:
	rm *.o
	rm *.out
