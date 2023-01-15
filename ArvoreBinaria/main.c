#include <stdlib.h>
#include <stdio.h>
#include "arvoreBinaria.h"

int main() {
    NoArvore *raiz;
    raiz = iniciarlizarArvore();
    if (estaVazia(raiz)) {
        printf("Arvore esta vazia\n");
    }
    inserirArvore(&raiz, 12);
    inserirArvore(&raiz, 4);
    inserirArvore(&raiz, 2);
    inserirArvore(&raiz, 8);
    inserirArvore(&raiz, 6);
    inserirArvore(&raiz, 16);
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
    if (estaVazia(raiz)) {
        printf("Arvore cortada\n");
    }
    removeArvore(&raiz, 9);
    printf("Em Ordem: { ");
    emOrdem(&raiz);
    printf("}\n");
    removeArvore(&raiz, 2);
    printf("Em Ordem: { ");
    emOrdem(&raiz);
    printf("}\n");
    removeArvore(&raiz, 6);
    printf("Em Ordem: { ");
    emOrdem(&raiz);
    printf("}\n");
    removeArvore(&raiz, 4);
    printf("Em Ordem: { ");
    emOrdem(&raiz);
    printf("}\n");
    removeArvore(&raiz, 7);
    printf("Em Ordem: { ");
    emOrdem(&raiz);
    printf("}\n");
    removeArvore(&raiz, 5);
    printf("Em Ordem: { ");
    emOrdem(&raiz);
    printf("}\n");

    printf("Queimando arvore...\n");
    destroiArvore(&raiz);

    return EXIT_SUCCESS;
}