#include <stdio.h>
#include <stdlib.h>

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

void destroiArvore(NoArvore **arvore) {
    if (!estaVazia((*arvore))) {
        destroiArvore(&(*arvore)->esquerda);
        destroiArvore(&(*arvore)->direita);
        free(*arvore);
        *arvore = NULL;
    }
}

int main() {
    NoArvore *raiz;
    raiz = iniciarlizarArvore();
    if (estaVazia(raiz)) {
        printf("Arvore esta vazia\n");
    }
    inserirArvore(&raiz, 6);
    inserirArvore(&raiz, 4);
    inserirArvore(&raiz, 9);
    inserirArvore(&raiz, 5);
    inserirArvore(&raiz, 7);
    inserirArvore(&raiz, 8);
    inserirArvore(&raiz, 2);
    inserirArvore(&raiz, 3);
    if (!estaVazia(raiz)) {
        printf("Arvore nao esta vazia\n");
    }
    printf("Pre Ordem: { ");
    preOrdem(&raiz);
    printf("}\n");
    printf("Pos Ordem: { ");
    posOrdem(&raiz);
    printf("}\n");
    printf("Em Ordem: { ");
    emOrdem(&raiz);
    printf("}\n");
    printf("Pesquisa:\n");
    int vetor[5] = {3, 2, 8, 7, 1};
    for (int i = 0; i < 5; i++) {
        if (pesquisaArvore(&raiz, vetor[i])) {
            printf("Numero %d presente na arvore\n", vetor[i]);
        } else {
            printf("Nao achou\n");
        }
    }
    printf("Queimando arvore...\n");
    destroiArvore(&raiz);
    if (estaVazia(raiz)) {
        printf("Arvore cortada\n");
    }

    return EXIT_SUCCESS;
}