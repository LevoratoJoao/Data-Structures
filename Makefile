CC = gcc
CFLAGS = -fstack-protector-all -g -Wall

arvoreBinaria.o: ArvoreBinaria/main.c ArvoreBinaria/arvoreBinaria.c ArvoreBinaria/arvoreBinaria.h
	$(CC) ArvoreBinaria/*.c $(CFLAGS) -c ArvoreBinaria/*.c

arvoreBinaria_main: arvoreBinaria.o main.o
	$(CC) $(CFLAGS) arvoreBinaria.o main.o -o main

filaEstatica.o: FilaEstatica/main.c FilaEstatica/filaEstatica.c FilaEstatica/filaEstatica.h
	$(CC) FilaEstatica/*.c $(CFLAGS) -c FilaEstatica/*.c

filaEstatica_main: filaEstatica.o main.o
	$(CC) $(CFLAGS) filaEstatica.o main.o -o main

grafoMatriz.o: Grafos/main.c Grafos/grafoMatriz.c Grafos/grafoMatriz.h
	$(CC) Grafos/*.c $(CFLAGS) -c Grafos/*.c

grafoMatriz_main: grafoMatriz.o main.o
	$(CC) $(CFLAGS) grafoMatriz.o main.o -o main

listaDupla.o: ListaDuplamenteEncadeada/main.c ListaDuplamenteEncadeada/listaDupla.c FilaEstatica/listaDupla.h
	$(CC) $(CFLAGS) ListaDuplamenteEncadeada/*.c $(CFLAGS) -c ListaDuplamenteEncadeada/*.c

listaDupla_main: listaDupla.o main.o
	$(CC) $(CFLAGS) listaDupla.o main.o -o main

listaEncadeada.o: ListaEncadeada/main.c ListaEncadeada/listaEncadeada.c ListaEncadeada/listaEncadeada.h
	$(CC) $(CFLAGS) ListaEncadeada/*.c $(CFLAGS) -c ListaEncadeada/*.c

listaEncadeada_main: listaEncadeada.o main.o
	$(CC) $(CFLAGS) listaEncadeada.o main.o -o main

clean:
	rm *.o
	rm main