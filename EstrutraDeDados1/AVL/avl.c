#include <stdio.h>
#include <stdlib.h>

typedef struct noAvl {
    int chave;
    struct noAvl *esquerda;
    struct noAvl *direita;
    int altura;
} NoAVL;

// Funcoes padroes de arvore
NoAVL *iniciaArvoreAVL() {
    return NULL;
}

int estaVaziaAVL(NoAVL *arvore) {
    return (arvore == NULL);
}

void preOrdemAVL(NoAVL **arvore) {
    if (estaVaziaAVL((*arvore))) {
        printf("Esta vazia\n");
        return;
    }
    printf("%d ", (*arvore)->chave);
    preOrdemAVL(&(*arvore)->esquerda);
    preOrdemAVL(&(*arvore)->direita);
}

void posOrdemAVL(NoAVL **arvore) {
    if (estaVaziaAVL((*arvore))) {
        printf("Esta viazia\n");
        return;
    }
    preOrdemAVL(&(*arvore)->esquerda);
    preOrdemAVL(&(*arvore)->direita);
    printf("%d ", (*arvore)->chave);
}

void emOrdemAVL(NoAVL **arvore) {
    if (estaVaziaAVL((*arvore))) {
        printf("Esta viazia\n");
        return;
    }
    emOrdemAVL(&(*arvore)->esquerda);
    printf("%d ", (*arvore)->chave);
    emOrdemAVL(&(*arvore)->direita);

}

int pesquisaAVL(NoAVL **arvore, int n) {
    if (estaVaziaAVL((*arvore))) {
        printf("Esta vazia\n");
        return 0;
    }
    if ((*arvore)->chave == n) {
        return 1;
    }
    if (n > (*arvore)->chave) {
        return (pesquisaAVL(&(*arvore)->direita, n));
    } else {
        return (pesquisaAVL(&(*arvore)->direita, n));
    }
}

void destruirAVL(NoAVL **arvore) {
    if (!estaVaziaAVL((*arvore))) {
        destruirAVL(&(*arvore)->esquerda);
        destruirAVL(&(*arvore)->direita);
        free(*arvore);
        (*arvore) = NULL;
    }
}

// insercao/remocao -> auxiliares (rotacao, altura)
//rotacao simples para a esquerda (p e u)
// p = ponteiro que temos acesso
// u = p direita
// p direita = u esquerda
// u esquerda = p

//rotacao simples para a direita (p e u)
//p = ponteiro que temos acesso
// u = p esquerda
// p esquerda = p direita
// u direita = p

//rotacao dupla para a esquerda (p, u e v)
// p = temos acesso
// u = p direita
// v = u esquerda
// p direita = v esquerda
// u esquerda = v = direita
// v direita = u
// v esquerda = p

//rotacao dupla para a direita (p, u e v)
// p = temos acesso
// u = p esquerda
// v = u direita
// p esquerda = v direita
// u direita = v = esquerda
// v direita = u
// v direita = p

int alturaArvoreAVL(NoAVL *arvoreAvl) {
    if (arvoreAvl == NULL) { return 0; }
    else { return (arvoreAvl->altura); }
}

int atualizaAlturaArvoreAVL(NoAVL *esquerda, NoAVL *direita) {
    int alturaEsquerda = alturaArvoreAVL(&esquerda);
    int alturaDireita = alturaArvoreAVL(&direita);

    if (alturaEsquerda > alturaDireita) {
        return (alturaEsquerda + 1);
    }
    else {
        return(alturaDireita + 1);
    }
}

void aplicarRotacoesAVL(NoAVL **arvoreAvl) {
    int alturaEsquerda = alturaArvoreAVL(&(*arvoreAvl)->esquerda);
    int alturaDireita = alturaArvoreAVL(&(*arvoreAvl)->direita);

    int diferenca = alturaDireita - alturaDireita;

    if (diferenca == 2) { // Rotacao para esquerda
        NoAVL *tmp = (*arvoreAvl)->direita;
        int tmpArvoreDireita = alturaArvoreAVL((*tmp).direita);
        int tmpArvoreEsquerda = alturaArvoreAVL((*tmp).esquerda);
        if (tmpArvoreEsquerda > tmpArvoreDireita) {
            rotacaoDuplaEsquerda(&(*arvoreAvl));
        } else {
            rotacaoSimplesEsquerda(&(*arvoreAvl));
        }
    } else { // Rotacao para direita
        NoAVL *tmp = (*arvoreAvl)->direita;
        int tmpArvoreDireita = alturaArvoreAVL((*tmp).direita);
        int tmpArvoreEsquerda = alturaArvoreAVL((*tmp).esquerda);
        if (tmpArvoreDireita > tmpArvoreEsquerda) {
            rotacaoDuplaDireita(&(*arvoreAvl));
        } else {
            rotacaoSimplesDireita(&(*arvoreAvl));
        }
    }
}

int insercaoArvoreAVL(NoAVL **arvoreAvl, int n) {
    if ((*arvoreAvl) == NULL) {
        (*arvoreAvl) = (NoAVL*) malloc(sizeof(NoAVL));
        (*arvoreAvl)->direita = (*arvoreAvl)->esquerda = NULL;
        (*arvoreAvl)->chave = n;
        (*arvoreAvl)->altura = 1;
        return 1;
    }
    if ((*arvoreAvl)->chave == n) {
        return 0;
    }
    int in;
    if ((*arvoreAvl)->chave < n) {
        in = insercaoArvoreAVL(&(*arvoreAvl)->direita, n);
    } else {
        in = insercaoArvoreAVL(&(*arvoreAvl)->esquerda, n);
    }
    if (in == 0) {
        return 0;
    }
    int alturaEsquerda, alturaDireita;
    alturaEsquerda = alturaArvoreAVL((*arvoreAvl)->esquerda);
    alturaDireita = alturaArvoreAVL((*arvoreAvl)->direita);
    if ((alturaDireita - alturaEsquerda) == 2 || (alturaDireita - alturaEsquerda) == -2) {
        aplicarRotacoesAVL(&(*arvoreAvl));
    }
    (*arvoreAvl)->altura = atualizaAlturaArvoreAVL((*arvoreAvl)->esquerda, (*arvoreAvl)->direita);
}

int main(int argc, const char *argv[]) {
    NoAVL *arvore;
    arvore = iniciaArvoreAVL();
    if (estaVaziaAVL(arvore)) {
        printf("Esta vazia\n");
    } else {
        printf("Nao esta vazia\n");
    }


    return EXIT_SUCCESS;
}