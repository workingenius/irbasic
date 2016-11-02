exectest1: test_linkedlist.o linkedlist.o
	gcc test_linkedlist.o linkedlist.o -o exectest1

exectest2: linkedlist.o postinglist.o test_postinglist.o
	gcc linkedlist.o postinglist.o test_postinglist.o -o exectest2

test_linkedlist.o:
	gcc -c test_linkedlist.c -o test_linkedlist.o

linkedlist.o:
	gcc -c linkedlist.c -o linkedlist.o

test_postinglist.o:
	gcc -c test_linkedlist.c -o test_postinglist.o

postinglist.o:
	gcc -c postinglist.c -o postinglist.o

clean:
	rm *.o
	rm exectest*
