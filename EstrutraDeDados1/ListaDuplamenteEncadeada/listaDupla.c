#include <stdio.h>
#include <stdlib.h>

typedef struct obj {
    int chave;
    struct obj* proximo;
    struct obj* anterior;
} NoLista;

typedef struct listaEncadeada {
    NoLista *inicio;
    int numElemento;
} Lista;

void inicializarLista(Lista *list) {
    list->inicio = NULL;
    list->numElemento = 0;
}

int estaVazia(Lista *list) {
    if (list->numElemento == 0) {
        return 0;
    } else {
        return 1;
    }
}

int tamanhoLista(Lista *list) {
    return list->numElemento;
}

void inserirElemento(Lista *list, int chave) {
    NoLista *novo;
    novo = (NoLista*) malloc(sizeof(NoLista));
    novo->chave = chave;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if(estaVazia(list) == 0) {
        list->inicio = novo;
    } else if(chave < list->inicio->chave) {
        novo->proximo = list->inicio;
        list->inicio->anterior = novo;
        list->inicio = novo;
    } else {
        NoLista *aux = list->inicio;
        while (aux->proximo != NULL && aux->proximo->chave < chave) {
            //aux->anterior = aux;
            aux = aux->proximo;
        }
        if (aux->proximo != NULL)
        {
            aux->proximo->anterior = novo;
            /* code */
        }

        novo->proximo = aux->proximo;
        novo->anterior = aux;
        //novo->proximo->anterior = novo; //novo(7)->prox(8)->ante(1) passa a ser 7
        aux->proximo = novo;
        //aux->proximo = aux->proximo;
        //aux->proximo->anterior = novo;
        printf("\n");
    }
    list->numElemento++;
}

void imprimirLista(Lista *list) {
    NoLista *aux = list->inicio;
    int pos = 0;
    printf("Inicio da lista:\n");
    while (aux != NULL) {
        printf("\nPos %d --> %d\n", ++pos, aux->chave);
        aux = aux->proximo;
    }
    printf("\nFim da lista\n");
}

void destroiLista(Lista *list) {
    NoLista *aux = list->inicio;
    while (list->inicio != NULL) {
        list->inicio = list->inicio->proximo;
        free(aux);
        aux = list->inicio;
    }
}

int main() {
    Lista lista;

    inicializarLista(&lista);
    inserirElemento(&lista, 1);
    inserirElemento(&lista, 8);
    inserirElemento(&lista, -12);
    inserirElemento(&lista, 54);
    inserirElemento(&lista, 7);

    imprimirLista(&lista);

    destroiLista(&lista);

    imprimirLista(&lista);
    return 0;
}
