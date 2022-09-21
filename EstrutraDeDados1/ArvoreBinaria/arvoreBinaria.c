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
    return arvore->chave == NULL;
}

void inserirArvore(NoArvore *arvore, int n) {
    arvore = (NoArvore*) malloc(sizeof(NoArvore));
    if (estaVazia(arvore)) {
        arvore->chave = n;
    } else if(arvore->esquerda == NULL) {
        arvore->esquerda->chave = n;
    } else if (arvore->direita == NULL) {
        arvore->direita->chave = n;
    }     
}


int main() {
    NoArvore *raiz;
    raiz = iniciarlizarArvore();
    inserirArvore(&raiz, 6);
    inserirArvore(&raiz, 4);
    inserirArvore(&raiz, 9);


    return EXIT_SUCCESS;
}