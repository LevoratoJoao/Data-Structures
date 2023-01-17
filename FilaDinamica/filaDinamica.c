#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filaDinamica.h"

typedef struct no_fila
{
    int conteudo;
    struct no_fila *proximo;
    // struct NoFila *prox;
} NoFila;

typedef struct fila_dinamica
{
    NoFila *inicio; // NoFila inicio
    NoFila *final;  // NoFila final
    int quantidade;
} FilaDinamica;

FilaDinamica *iniciaFilaDinamica()
{
    FilaDinamica *fila = (FilaDinamica*) malloc(sizeof(FilaDinamica));
    fila->final = NULL;
    fila->inicio = NULL;
    fila->quantidade = 0;
    return fila;
}

int vaziaFilaDinamica(FilaDinamica *fila)
{
    if (fila == NULL) return printf("Fila vazia\n");
    return (fila->quantidade == 0);
}

int tamanhoFilaDinamica(FilaDinamica *fila)
{
    if (fila == NULL) return printf("Fila vazia\n");
    return fila->quantidade;
}

// Final

// Inicio

// Funcoes de Modificacao
void inserirFilaDinamica(FilaDinamica *fila, int n)
{
    // Criar aux de NoFila, alocar mem, copiar informacao pra ele
    NoFila *aux;
    aux = (NoFila *)malloc(sizeof(NoFila));
    aux->conteudo = n;
    aux->proximo = NULL;
    if (vaziaFilaDinamica(fila))
    {                                     // Primeira insercao
        fila->inicio = fila->final = aux; // inicio e final da fila apontam pro novo no
    }
    else
    {                                        // Demais insercoes
        fila->final->proximo = aux;          // Proximo do fim aponta para o novo elemento
        fila->final = aux;  // Fim recebe o proximo do fim
    }
    fila->quantidade++;
}

void imprimirFila(FilaDinamica *fila)
{
    printf("fila = {");
    for (NoFila *i = fila->inicio; i != NULL; i = i->proximo)
    {
        printf(" %d ", i->conteudo);
    }
    printf("}\n");
}

void removerFilaDinamica(FilaDinamica *fila)
{
    if (!vaziaFilaDinamica(fila))
    {
        // ptr auxiliar
        NoFila *aux;
        // copiar a info pro user
        aux = fila->inicio;
        // att o inicio do prox dele
        fila->inicio = fila->inicio->proximo;
        free(aux);
        // decrementa qtd
        fila->quantidade--;
    }
    else
    {
        printf("Fila esta vazia\n");
    }
}

void destruirFila(FilaDinamica *fila)
{
    while (fila->quantidade != 0)
    {
        removerFilaDinamica(fila);
    }
    free(fila);
}