ALL:	main

main:	main.o fila_fifo.o logtree.o escalonador.o caixas.o
	gcc main.o logtree.o fila_fifo.o escalonador.o caixas.o -o main -lm

logtree.o:	logtree.c logtree.h
	gcc -c logtree.c 

fila_fifo.o:	fila_fifo.c fila_fifo.h
	gcc -c fila_fifo.c

escalonador.o:	escalonador.c escalonador.h fila_fifo.h caixas.h
	gcc -c escalonador.c

caixas.o:	caixas.c caixas.h
	gcc -c caixas.c

main.o:	main.c fila_fifo.h logtree.h escalonador.h
	gcc -c main.c

clean:
	rm *.o main
