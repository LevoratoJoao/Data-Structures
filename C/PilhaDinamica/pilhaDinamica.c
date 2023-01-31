#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

typedef struct no_pilha
{
    int chave;
    struct no_pilha *proximo;
} NoPilha;

typedef struct pilha
{
    NoPilha *topo;
    int quantidade;
} PilhaDinamica;

PilhaDinamica *iniciarPilha()
{
    PilhaDinamica *p = (PilhaDinamica*) malloc(sizeof(PilhaDinamica));
    p->topo = NULL;
    p->quantidade = 0;
    return p;
}

int tamanhoPilha(PilhaDinamica *p)
{
    return p->quantidade;
}

int estaVazia(PilhaDinamica *p)
{
    if (p->quantidade == 0)
    {
        return 1;
    }
    return 0;
}

void inserirPilha(PilhaDinamica *p, int n)
{
    // Criar novo No
    NoPilha *aux = NULL;
    aux = (NoPilha*) malloc(sizeof(NoPilha));
    // Novo no recebe o valor que queremos inserir
    aux->chave = n;
    // Proximo do novo No recebe o topo da pilha
    aux->proximo = p->topo;
    // Topo da pilha passa a apontar para o valor do novo No
    p->topo = aux;
    // Incremento da quantidade
    p->quantidade++;
}

void imprimirPilha(PilhaDinamica *p)
{
    NoPilha *i;
    for (i = p->topo; i != NULL; i = i->proximo)
    {
        printf("Termoda sequencia de Fibonacci: %d\n", i->chave);
    }
}

void removerPilha(PilhaDinamica *p)
{
    NoPilha *aux;
    if (estaVazia(p) == 0)
    {
        // No auiliar recebendo topo da pilha
        aux = p->topo;
        // Topo da pilha aponta para o proximo
        p->topo = p->topo->proximo;
        // Desaloca pilha e diminui a quantidade de elementos
        free(aux);
        p->quantidade--;
    }
    else
    {
        printf("Pilha esta vazia\n");
    }
}

void destruir(PilhaDinamica *p)
{
    while (p->topo != NULL)
    {
        removerPilha(p);
    }
    free(p);
}
