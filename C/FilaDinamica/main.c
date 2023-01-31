#include <stdlib.h>
#include <stdio.h>
#include "filaDinamica.h"

int main() {
    FilaDinamica *fila = iniciaFilaDinamica();

    if(vaziaFilaDinamica(fila)) {
        printf("Esta vazia\n");
    }
    inserirFilaDinamica(fila, 3);
    inserirFilaDinamica(fila, 4);
    inserirFilaDinamica(fila, 9);
    inserirFilaDinamica(fila, 8);
    inserirFilaDinamica(fila, 6);
    inserirFilaDinamica(fila, 7);

    imprimirFila(fila);

    if(vaziaFilaDinamica(fila)) {
        printf("Esta vazia\n");
    }
    printf("Tamanho da fila: %d\n", tamanhoFilaDinamica(fila));

    removerFilaDinamica(fila);
    imprimirFila(fila);
    removerFilaDinamica(fila);
    imprimirFila(fila);
    removerFilaDinamica(fila);
    imprimirFila(fila);
    removerFilaDinamica(fila);
    imprimirFila(fila);
    removerFilaDinamica(fila);
    imprimirFila(fila);
    removerFilaDinamica(fila);
    imprimirFila(fila);
    removerFilaDinamica(fila);

    inserirFilaDinamica(fila, 9);
    inserirFilaDinamica(fila, 8);
    inserirFilaDinamica(fila, 6);
    imprimirFila(fila);
    printf("Tamanho da fila: %d\n", tamanhoFilaDinamica(fila));
    destruirFila(fila);
    printf("Tamanho da fila: %d\n", tamanhoFilaDinamica(fila));

    return 0;
}