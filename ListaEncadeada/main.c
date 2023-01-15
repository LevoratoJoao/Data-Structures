#include <stdlib.h>
#include <stdio.h>
#include "listaEncadeada.h"

int main()
{
    Lista lista;

    inicializarLista(&lista);
    inserirElemento(&lista, 1);
    inserirElemento(&lista, 8);
    inserirElemento(&lista, -12);
    inserirElemento(&lista, 54);
    inserirElemento(&lista, 7);
    if (pesquisarLista(&lista, 8) == 1)
    {
        printf("Elemento esta na lista\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }
    if (pesquisarLista(&lista, 0) == 1)
    {
        printf("Elemento esta na lista\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }
    if (pesquisarLista(&lista, 7) == 1)
    {
        printf("Elemento esta na lista\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }

    removerLista(&lista, 8);
    imprimirLista(&lista);
    if (pesquisarLista(&lista, 8) == 1)
    {
        printf("Elemento esta na lista\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }

    removerLista(&lista, 7);
    imprimirLista(&lista);
    if (pesquisarLista(&lista, 7) == 1)
    {
        printf("Elemento esta na lista\n");
    }
    else
    {
        printf("Elemento nao encontrado\n");
    }
    removerLista(&lista, 1000);
    imprimirLista(&lista);

    destroiLista(&lista);

    return EXIT_SUCCESS;
}