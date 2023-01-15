#include <stdlib.h>
#include <stdio.h>
#include "listaDupla.h"

int main() {
    Lista lista;

    inicializarLista(&lista);
    inserirElemento(&lista, 1);
    inserirElemento(&lista, 8);
    inserirElemento(&lista, -12);
    inserirElemento(&lista, 54);
    inserirElemento(&lista, 7);
    inserirElemento(&lista, 12);
    inserirElemento(&lista, 9);
    inserirElemento(&lista, 100);

    imprimirLista(&lista);

    destroiLista(&lista);

    imprimirLista(&lista);
    return 0;
}