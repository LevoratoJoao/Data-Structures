#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

int main()
{
    FilaEstatica fila;

    iniciaFila(&fila);

    if (estaVazia(&fila))
    {
        printf("Esta vazia\n");
    }
    if (estaCheia(&fila))
    {
        printf("Esta cheia\n");
    }

    inserirFilaEstatica(&fila, 9);
    imprimirFila(&fila);
    printf("%d\n", tamanhoFila(&fila));

    inserirFilaEstatica(&fila, 10);
    imprimirFila(&fila);
    removerFilaEstatica(&fila);

    inserirFilaEstatica(&fila, 3);

    inserirFilaEstatica(&fila, 4);
    imprimirFila(&fila);

    printf("%d\n", tamanhoFila(&fila));

    removerFilaEstatica(&fila);

    imprimirFila(&fila);

    printf("%d\n", tamanhoFila(&fila));

    return 0;
}