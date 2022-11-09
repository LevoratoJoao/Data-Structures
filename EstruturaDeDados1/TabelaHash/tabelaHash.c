#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 13

typedef struct obj {
    int info;
    char nome[100];
    /* data */
} Objeto;

typedef struct t_hash {
    int quantidade;
    Objeto elemento[M];
} TabelaHash;

void inicializarTable(TabelaHash *table) {
    table->quantidade = 0;
    for (int i = 0; i < M; i++) {
        table->elemento[i].info = -1;
        strcpy(table->elemento[i].nome, "");
        //table->elemento[i] = NULL;
    }
}

int estaVazia(TabelaHash *table) {
    return (table->quantidade == 0);
}

int estaCheia(TabelaHash *table) {
    return (table->quantidade == M);
}

int hash(int k) {
    return k % M;
}

void inserirElemento(TabelaHash *table, int k, char *name) {
    int posicao = hash(k);
    if (estaCheia(table) == 1) {
        printf("Tabela cheia\n");
        return;
    }
    while (table->elemento[posicao].info != -1) {
        posicao++;
        if (posicao >= M) posicao = 0;
    }
    table->quantidade++;
    table->elemento[posicao].info = k;
    strcpy(table->elemento[posicao].nome, name);
}

void imprimirTabelaHash(TabelaHash *table) {
    printf("Tabela:\n");
    for (int i = 0; i < M; i++) {
        if (estaVazia(table) == 1) {
            printf("| [0%-2d]\t | NULL |\n", i);
        } else {
            printf("| [0%-2d] | %-10s |\n", i, table->elemento[i].nome);
        }
    }
}

int pesquisarElemento(TabelaHash *table, int chave) {
    int posicao = hash(chave);
    while (table->elemento[posicao].info != chave) {
        posicao++;
        if (posicao >= M) posicao = 0;
        if (posicao == hash(chave)) return (-1);
    }
    return posicao;
}

int removerTabelaHash(TabelaHash *table, int chave) {
    int posicao = pesquisarElemento(table, chave);
    if (posicao < 0) {
        printf("Elemento %d nao esta na tabela\n", chave);
        return 1;
    }
    table->quantidade--;
    table->elemento[posicao].info = -1;
    strcpy(table->elemento[posicao].nome, "");

    return 0;
}

int main() {
    TabelaHash table;
    inicializarTable(&table);
    if(estaVazia(&table) == 1) {
        printf("Esta vazia\n");
    }
    inserirElemento(&table, 100, "Tamara");
    inserirElemento(&table, 100, "Tamara2");
    inserirElemento(&table, 40, "Muriel");
    inserirElemento(&table, 40, "Muriel2");
    inserirElemento(&table, 6, "Mantovani");
    inserirElemento(&table, 6, "Mantovani2");
    inserirElemento(&table, 0, "Viviane");
    inserirElemento(&table, 0, "Viviane3");
    inserirElemento(&table, 17, "Viviane4");
    inserirElemento(&table, 15, "Viviane5");
    inserirElemento(&table, 25, "Viviane6");
    inserirElemento(&table, 96, "Viviane7");
    inserirElemento(&table, 2, "Viviane2");
    inserirElemento(&table, 63, "Viviane8");

    int posicao = pesquisarElemento(&table, 2);
    if (posicao < 0) printf("Elemento nao esta presente\n");
    else printf("\nElemento encontrado:\n| [0%-2d] | %-10s |\n", posicao, table.elemento[posicao].nome);

    removerTabelaHash(&table, 2);

    imprimirTabelaHash(&table);

    return 0;
}