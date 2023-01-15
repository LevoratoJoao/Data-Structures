#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabelaHash.h"

#define M 13

typedef struct obj
{
    int info;
    char nome[100];
    /* data */
} Objeto;

typedef struct tabela_hash
{
    int quantidade;
    Objeto *elemento;
} TabelaHash;

TabelaHash *inicializarTable()
{
    TabelaHash *table = (TabelaHash*) malloc(sizeof(TabelaHash));
    table->elemento = (Objeto*) malloc(M * sizeof(Objeto));
    table->quantidade = 0;
    for (int i = 0; i < M; i++)
    {
        table->elemento[i].info = -1;
        strcpy(table->elemento[i].nome, "");
        // table->elemento[i] = NULL;
    }
    return table;
}

int estaVazia(TabelaHash *table)
{
    return (table->quantidade == 0);
}

int estaCheia(TabelaHash *table)
{
    return (table->quantidade == M);
}

int hash(int k)
{
    return k % M;
}

void inserirElemento(TabelaHash *table, int k, char *name)
{
    int posicao = hash(k);
    if (estaCheia(table) == 1)
    {
        printf("Tabela cheia\n");
        return;
    }
    while (table->elemento[posicao].info != -1)
    {
        posicao++;
        if (posicao >= M)
            posicao = 0;
    }
    table->quantidade++;
    table->elemento[posicao].info = k;
    strcpy(table->elemento[posicao].nome, name);
}

void imprimirTabelaHash(TabelaHash *table)
{
    printf("Tabela:\n");
    for (int i = 0; i < M; i++)
    {
        if (estaVazia(table) == 1)
        {
            printf("| [0%-2d]\t | NULL |\n", i);
        }
        else
        {
            printf("| [0%-2d] | %-10s |\n", i, table->elemento[i].nome);
        }
    }
}

int pesquisarElemento(TabelaHash *table, int chave)
{
    int posicao = hash(chave);
    while (table->elemento[posicao].info != chave)
    {
        posicao++;
        if (posicao >= M)
            posicao = 0;
        if (posicao == hash(chave))
            return (-1);
    }
    return posicao;
}

String getElemento(TabelaHash *table, int chave)
{
    return table->elemento[chave].nome;
}

int removerTabelaHash(TabelaHash *table, int chave)
{
    int posicao = pesquisarElemento(table, chave);
    if (posicao < 0)
    {
        printf("Elemento %d nao esta na tabela\n", chave);
        return 1;
    }

    table->quantidade--;
    table->elemento[posicao].info = -1;
    strcpy(table->elemento[posicao].nome, "");
    return 0;
}

void destroiTabelaHash(TabelaHash *table)
{
    if (estaVazia(table) == 0)
    {
        free(table->elemento);
    }
    free(table);
}