CC = gcc
CFLAGS = -fstack-protector-all -g -Wall

arvoreBinaria.o: ArvoreBinaria/main.c ArvoreBinaria/arvoreBinaria.c ArvoreBinaria/arvoreBinaria.h
	$(CC) ArvoreBinaria/*.c $(CFLAGS) -c ArvoreBinaria/*.c

arvoreBinaria_main: arvoreBinaria.o main.o
	$(CC) $(CFLAGS) arvoreBinaria.o main.o -o main

avlTree.o: AVL/main.c AVL/avlTree.c AVL/avlTree.h
	$(CC) $(CFLAGS) AVL/*.c $(CFLAGS) -c AVL/*.c

avlTree_main: avlTree.o main.o
	$(CC) $(CFLAGS) avlTree.o main.o -o main

filaEstatica.o: FilaEstatica/main.c FilaEstatica/filaEstatica.c FilaEstatica/filaEstatica.h
	$(CC) FilaEstatica/*.c $(CFLAGS) -c FilaEstatica/*.c

filaEstatica_main: filaEstatica.o main.o
	$(CC) $(CFLAGS) filaEstatica.o main.o -o main

filaDinamica.o: FilaDinamica/main.c FilaDinamica/filaDinamica.c FilaDinamica/filaDinamica.h
	$(CC) FilaDinamica/*.c $(CFLAGS) -c FilaDinamica/*.c

filaDinamica_main: filaDinamica.o main.o
	$(CC) $(CFLAGS) filaDinamica.o main.o -o main

grafoMatriz.o: Grafos/main.c Grafos/grafoMatriz.c Grafos/grafoMatriz.h
	$(CC) Grafos/*.c $(CFLAGS) -c Grafos/*.c

grafoMatriz_main: grafoMatriz.o main.o
	$(CC) $(CFLAGS) grafoMatriz.o main.o -o main

listaDupla.o: ListaDuplamenteEncadeada/main.c ListaDuplamenteEncadeada/listaDupla.c ListaDuplamenteEncadeada/listaDupla.h
	$(CC) $(CFLAGS) ListaDuplamenteEncadeada/*.c $(CFLAGS) -c ListaDuplamenteEncadeada/*.c

listaDupla_main: listaDupla.o main.o
	$(CC) $(CFLAGS) listaDupla.o main.o -o main

listaEncadeada.o: ListaEncadeada/main.c ListaEncadeada/listaEncadeada.c ListaEncadeada/listaEncadeada.h
	$(CC) $(CFLAGS) ListaEncadeada/*.c $(CFLAGS) -c ListaEncadeada/*.c

listaEncadeada_main: listaEncadeada.o main.o
	$(CC) $(CFLAGS) listaEncadeada.o main.o -o main

pilhaEstatica.o: PilhaEstatica/main.c PilhaEstatica/pilhaEstatica.c PilhaEstatica/pilhaEstatica.h
	$(CC) $(CFLAGS) PilhaEstatica/*.c $(CFLAGS) -c PilhaEstatica/*.c

pilhaEstatica_main: pilhaEstatica.o main.o
	$(CC) $(CFLAGS) pilhaEstatica.o main.o -o main

pilhaDinamica.o: PilhaDinamica/main.c PilhaDinamica/pilhaDinamica.c PilhaDinamica/pilhaDinamica.h
	$(CC) $(CFLAGS) PilhaDinamica/*.c $(CFLAGS) -c PilhaDinamica/*.c

pilhaDinamica_main: pilhaDinamica.o main.o
	$(CC) $(CFLAGS) pilhaDinamica.o main.o -o main

valgrind:
	valgrind --leak-check=full -s ./main

clean:
	rm *.o
	rm main