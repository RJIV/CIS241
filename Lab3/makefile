program: main.o Hamilton.o
	gcc -o program main.o Hamilton.o

main.o: main.c lab3.h
	gcc -c main.c

Hamilton.o: Hamilton.c lab3.h
	gcc -c Hamilton.c

clean:
	rm -f *.o program

