#include "arvoreBinaria.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct noArv {
    int chave;
    struct noArv *esquerda;
    struct noArv *direita;
} NoArvore;

NoArvore *iniciarlizarArvore() {
    return NULL;
}

int estaVazia(NoArvore *arvore) {
    return (arvore == NULL);
}

void preOrdem(NoArvore **arvore) {
    if (estaVazia((*arvore))) {
        return;
    }
    //Imprime
    printf("%d ", (*arvore)->chave);
    //Esquerda
    preOrdem(&(*arvore)->esquerda);
    //Direita
    preOrdem(&(*arvore)->direita);
}

void posOrdem(NoArvore **arvore) {
    if (estaVazia((*arvore))) {
        return;
    }
    //Esquerda
    posOrdem(&(*arvore)->esquerda);
    //Direita
    posOrdem(&(*arvore)->direita);
    //Imprime
    printf("%d ", (*arvore)->chave);
}

void emOrdem(NoArvore **arvore) {
    if (estaVazia((*arvore))) {
        return;
    }
    //Esquerda
    emOrdem(&(*arvore)->esquerda);
    //Imprime
    printf("%d ", (*arvore)->chave);
    //Direita
    emOrdem(&(*arvore)->direita);
}

int pesquisaArvore(NoArvore **arvore, int n) {
    if (estaVazia((*arvore))) {
        return 0;
    }
    if ((*arvore)->chave == n) {
        return 1;
    }
    if (n > (*arvore)->chave) {
        return (pesquisaArvore(&(*arvore)->direita, n));
    } else {
        return (pesquisaArvore(&(*arvore)->esquerda, n));
    }
}

int inserirArvore(NoArvore **arvore, int n) {
    if (estaVazia((*arvore))) {
        //Nova arvore
        (*arvore) = (NoArvore*) malloc(sizeof(NoArvore));
        (*arvore)->chave = n;
        (*arvore)->direita = (*arvore)->esquerda = NULL;
        return 1;
    }
    if ((*arvore)->chave == n) {
        printf("Chave duplicada!\n");
        return 0;
    }
    if ((*arvore)->chave < n) {
        return (inserirArvore(&(*arvore)->direita, n));
    } else {
        return (inserirArvore(&(*arvore)->esquerda, n));
    }
}

NoArvore *getMaxAux(NoArvore **arvore) {
    NoArvore *ret;
    if ((*arvore)->direita == NULL) {
        ret = (*arvore);
        (*arvore) = (*arvore)->esquerda;
        return(ret);
    }
    return getMaxAux(&(*arvore)->direita);
}

NoArvore *getMinAux(NoArvore **arvore) {
    NoArvore *ret;
    if ((*arvore)->esquerda == NULL) {
        ret = (*arvore);
        (*arvore) = (*arvore)->direita;
        return(ret);
    }
    return getMinAux(&(*arvore)->esquerda);
}

int removeArvore(NoArvore **arvore, int n) {
    if (estaVazia((*arvore))) {
        return 0;
    }
    if ((*arvore)->chave == n) {
        NoArvore *tmp = (*arvore);
        if ((*arvore)->esquerda == NULL && (*arvore)->direita != NULL) { //Caso 1 - tem subarvore na direita
            (*arvore) = (*arvore)->direita;
        } else if ((*arvore)->esquerda == NULL && (*arvore)->direita == NULL) { //Caso 2 - nao tem subarvore na direita e esquerda
            (*arvore) = NULL;
        } else if ((*arvore)->direita == NULL && (*arvore)->esquerda != NULL) { //Caso 3 - tem subarvore esquerda
            (*arvore) = (*arvore)->esquerda;
        } else {
            //recebe no que vai ser apagado
            tmp = getMinAux(&(*arvore)->esquerda); //Pega valor maximo da subArvore da esquerda
            (*arvore)->chave = tmp->chave;
        }
        printf("Elemento removido\n");
        free(tmp);
        return 1;
    }
    if (n > (*arvore)->chave) {
        return (removeArvore(&(*arvore)->direita, n));
    } else {
        return (removeArvore(&(*arvore)->esquerda, n));
    }
    return 1;
}

void destroiArvore(NoArvore **arvore) {
    if (!estaVazia((*arvore))) {
        destroiArvore(&(*arvore)->esquerda);
        destroiArvore(&(*arvore)->direita);
        free(*arvore);
        *arvore = NULL;
    }
}