Hamilton: main.o product.o	
	gcc -o Hamilton main.o product.o

main.o: main.c product.h
	gcc -c main.c

product.o: product.c product.h	
	gcc -c product.c

clean:	
	rm -f *.o Hamilton


