#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabelaHash.h"

int main()
{
    TabelaHash *table = inicializarTable();
    if (estaVazia(table) == 1)
    {
        printf("Esta vazia\n");
    }
    inserirElemento(table, 100, "Tamara");
    inserirElemento(table, 100, "Tamara2");
    inserirElemento(table, 40, "Muriel");
    inserirElemento(table, 40, "Muriel2");
    inserirElemento(table, 6, "Mantovani");
    inserirElemento(table, 6, "Mantovani2");
    inserirElemento(table, 0, "Viviane");
    inserirElemento(table, 0, "Maju");
    inserirElemento(table, 17, "Bruno");
    inserirElemento(table, 15, "Maju2");
    inserirElemento(table, 25, "Bruno2");
    inserirElemento(table, 96, "Biel");
    inserirElemento(table, 2, "Viviane2");
    inserirElemento(table, 63, "Biel2");

    int posicao = pesquisarElemento(table, 2);
    if (posicao < 0)
        printf("Elemento nao esta presente\n");
    else
        printf("\nElemento encontrado:\n| [0%-2d] | %-10s |\n", posicao, getElemento(table, posicao));

    removerTabelaHash(table, 2);

    imprimirTabelaHash(table);

    destroiTabelaHash(table);

    return 0;
}