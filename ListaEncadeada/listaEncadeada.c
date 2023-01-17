#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// typedef struct NoLista *ponteiroLista;
typedef struct obj
{
    int chave;
    struct obj *proximo;
} NoLista;

typedef struct lista_encadeada
{
    NoLista *inicio;
    int numElemento;
} Lista;

Lista *inicializarLista()
{
    Lista *list = (Lista*) malloc(sizeof(Lista));
    list->inicio = NULL;
    list->numElemento = 0;
    return list;
}

int estaVazia(Lista *list)
{
    if (list->numElemento == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int tamanhoLista(Lista *list)
{
    return list->numElemento;
}

void inserirElemento(Lista *list, int chave)
{
    NoLista *novo;
    novo = (NoLista *)malloc(sizeof(NoLista));
    novo->chave = chave;
    novo->proximo = NULL;
    if (estaVazia(list) == 0)
    {
        list->inicio = novo;
    }
    else if (chave < list->inicio->chave)
    {
        novo->proximo = list->inicio;
        list->inicio = novo;
    }
    else
    {
        NoLista *aux = list->inicio;
        while (aux->proximo != NULL && aux->proximo->chave < chave)
        {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    list->numElemento++;
}

void imprimirLista(Lista *list)
{
    NoLista *aux = list->inicio;
    int pos = 0;
    printf("Inicio da lista:\n");
    while (aux != NULL)
    {
        printf("\nPos %d --> %d\n", ++pos, aux->chave);
        aux = aux->proximo;
    }
    printf("\nFim da lista\n");
}

int pesquisarLista(Lista *lista, int chave)
{
    if (estaVazia(lista) == 0)
    {
        return 0;
    }
    NoLista *aux = lista->inicio;
    while (aux != NULL && chave > aux->chave)
    {
        aux = aux->proximo;
    }
    if (aux == NULL || aux->chave > chave)
    {
        return 0;
    }
    return 1;
}

int removerLista(Lista *lista, int chave)
{
    if (estaVazia(lista) == 0 || chave < lista->inicio->chave)
    { // Lista Vazia ou elemento é menor que o primeiro elemento (nao existe)
        return 1;
    }
    if (chave == lista->inicio->chave)
    { // Elemento a ser removido é o primeiro
        NoLista *aux = lista->inicio;
        lista->inicio = lista->inicio->proximo; // Proximo do inicio passa a ser o inicio
        free(aux);                              // Desaloca mem
        lista->numElemento--;
        return 0;
    }
    // Percorrer lista
    NoLista *auxPercorre = lista->inicio;
    while (auxPercorre->proximo != NULL && (chave > auxPercorre->proximo->chave))
    { // Percorre enquanto aux for differente de NULL e chave maior que proximo
        auxPercorre = auxPercorre->proximo;
    }
    if (auxPercorre->proximo == NULL || chave < auxPercorre->proximo->chave)
    { // Chave menor que o proximo elemento entao elemento que queremos nao esta na lista
        printf("Nao encontrado\n");
        return 1;
    }
    else
    {
        printf("Elemento removido\n");
        NoLista *remover = auxPercorre->proximo;
        auxPercorre->proximo = auxPercorre->proximo->proximo; // Proximo do aux recebe proximo do proximo para manter a ordem da lista
        free(remover);
        lista->numElemento--;
        return 0;
    }
    return 0;
}

void destroiLista(Lista *list)
{
    NoLista *aux = list->inicio;
    while (list->inicio != NULL)
    {
        list->inicio = list->inicio->proximo;
        free(aux);
        aux = list->inicio;
    }
    free(list);
}