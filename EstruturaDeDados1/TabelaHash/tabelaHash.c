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

int inserirElemento(TabelaHash *table, int k, char *name) {
    if (estaCheia(table) == 1) {
        printf("Tabela cheia\n");
        return 1;
    }
    if (strcmp(table->elemento[hash(k)].nome, "") == 0)
    {
        table->elemento[hash(k)].info = k;
        strcpy(table->elemento[hash(k)].nome, name);
        table->quantidade = table->quantidade + 1;
    } else if (strcmp(table->elemento[hash(k) + 1].nome, "") == 0) {
        table->elemento[hash(k) + 1].info = k;
        strcpy(table->elemento[hash(k) + 1].nome, name);
        table->quantidade = table->quantidade + 1;
    } else {
        table->elemento[hash(k) - 1].info = k;
        strcpy(table->elemento[hash(k) - 1].nome, name);
        table->quantidade = table->quantidade - 1;
    }
}

void imprimirTabelaHash(TabelaHash *table) {
    printf("Tabela:\n");
    for (int i = 0; i < M; i++) {
        if (estaVazia(table) == 1) {
            printf("| [0%-2d] | NULL |\n", i);
        } else {
            printf("| [0%-2d] | %-10s |\n", i, table->elemento[i].nome);
        }
    }
}

int removerTabelaHash(TabelaHash *table, int chave) {
    table->quantidade--;
    return (strcpy(table->elemento[chave].nome, ""));
}

int main() {
    TabelaHash table;
    inicializarTable(&table);
    if(estaVazia(&table) == 1) {
        printf("Esta vazia\n");
    }
    imprimirTabelaHash(&table);
    inserirElemento(&table, 100, "Tamara");
    inserirElemento(&table, 100, "Tamara2");
    inserirElemento(&table, 40, "Muriel");
    inserirElemento(&table, 40, "Muriel2");
    inserirElemento(&table, 6, "Mantovani");
    inserirElemento(&table, 6, "Mantovani2");
    inserirElemento(&table, 0, "Viviane");
    inserirElemento(&table, 0, "Viviane2");
    imprimirTabelaHash(&table);
    removerTabelaHash(&table, 1);
    imprimirTabelaHash(&table);

    return 0;
}