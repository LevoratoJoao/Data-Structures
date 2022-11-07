#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    }
    
}

int hash(int k) {
    return k % M;
}

int inserirElemento(TabelaHash *table, int k, char *name) {
    table->elemento[hash(k)].info = k;
    strcpy(table->elemento[hash(k)].nome, name);
    table->quantidade = table->quantidade + 1;
}

int main() {
    TabelaHash table;
    inicializarTable(&table);
    inserirElemento(&table, 100, "Tamara");
    inserirElemento(&table, 40, "Muriel");
    inserirElemento(&table, 6, "Mantovani");
    inserirElemento(&table, 0, "Viviane");

    return 0;
}