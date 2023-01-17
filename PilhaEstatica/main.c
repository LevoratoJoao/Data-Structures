#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilhaEstatica.h"

typedef struct aluno
{
    int ra;
    char nome[50];
} Aluno;

int main() {
    Pilha *pilha = iniciarPilha();
    Aluno eu = {14, "Levoras"};
    inserir(pilha, eu);

    eu.ra = 2345678;
    strcpy(eu.nome, "Marquin da roça");
    inserir(pilha, eu);

    eu.ra = 2345678;
    strcpy(eu.nome, "Thu do pneu");
    inserir(pilha, eu);

    eu.ra = 2345678;
    strcpy(eu.nome, "Oto");
    inserir(pilha, eu);

    imprimirPilha(pilha);

    int tam = tamanho(pilha);
    printf("Tamanho: %d\n", tam);

    removerPilha(pilha);
    printf("\n\n");
    imprimirPilha(pilha);
    tam = tamanho(pilha);
    printf("Tamanho: %d\n", tam);

    freePilha(pilha);

    return 0;
}