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
        return;
    }
    printf("N: %d | H: %d\n", (*arvore)->chave, (*arvore)->altura);
    preOrdemAVL(&(*arvore)->esquerda);
    preOrdemAVL(&(*arvore)->direita);
}

void posOrdemAVL(NoAVL **arvore) {
    if (estaVaziaAVL((*arvore))) {
        return;
    }
    preOrdemAVL(&(*arvore)->esquerda);
    preOrdemAVL(&(*arvore)->direita);
    printf("N: %d | H: %d\n", (*arvore)->chave, (*arvore)->altura);
}

void emOrdemAVL(NoAVL **arvore) {
    if (estaVaziaAVL((*arvore))) {
        return;
    }
    emOrdemAVL(&(*arvore)->esquerda);
    printf("N: %d | H: %d\n", (*arvore)->chave, (*arvore)->altura);
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

int alturaArvoreAVL(NoAVL *arvoreAvl) {
    if (arvoreAvl == NULL) { return 0; }
    else { return (arvoreAvl->altura); }
}

int atualizarAlturaArvoreAVL(NoAVL *esquerda, NoAVL *direita) {
    int alturaEsquerda = alturaArvoreAVL(esquerda);
    int alturaDireita = alturaArvoreAVL(direita);

    if (alturaEsquerda > alturaDireita) {
        return (alturaEsquerda + 1);
    } else {
        return (alturaDireita + 1);
    }
}

// insercao/remocao -> auxiliares (rotacao, altura)
//rotacao simples para a esquerda (p e u)
// p = ponteiro que temos acesso
// u = p direita
// p direita = u esquerda
// u esquerda = p
void rotacaoSimplesEsquerda(NoAVL **p) {
    NoAVL *u = (*p)->direita;
    (*p)->direita = u->esquerda;
    u->esquerda = (*p);
    (*p)->altura = 0;
    // Atualizar altura do p e do u
    (*p)->altura = atualizarAlturaArvoreAVL((*p)->esquerda, (*p)->direita);
    u->altura = atualizarAlturaArvoreAVL(u->esquerda, u->direita);
    (*p) = u;
}

//rotacao simples para a direita (p e u)
//p = ponteiro que temos acesso
// u = p esquerda
// p esquerda = p direita
// u direita = p
void rotacaoSimplesDireita(NoAVL **p) {
    NoAVL *u = (*p)->esquerda;
    u = (*p)->esquerda;
    (*p)->esquerda = u->direita;
    u->direita = (*p);
    // Atualizar altura do p e do u
    (*p)->altura = atualizarAlturaArvoreAVL((*p)->esquerda, (*p)->direita);
    u->altura = atualizarAlturaArvoreAVL(u->esquerda, u->direita);
    (*p) = u;
}

//rotacao dupla para a esquerda (p, u e v)
// p = temos acesso
// u = p direita
// v = u esquerda
// p direita = v esquerda
// u esquerda = v = direita
// v direita = u
// v esquerda = p
void rotacaoDuplaEsquerda(NoAVL **p) {
    NoAVL *u = (*p)->direita;
    NoAVL *v = u->esquerda;
    (*p)->direita = v->esquerda;
    u->esquerda = v->direita;
    v->direita = u;
    v->esquerda = (*p);
    (*p)->altura = atualizarAlturaArvoreAVL((*p)->esquerda, (*p)->direita);
    u->altura = atualizarAlturaArvoreAVL(u->esquerda, u->direita);
    v->altura = atualizarAlturaArvoreAVL(v->esquerda, v->direita);
    (*p) = v;
}

//rotacao dupla para a direita (p, u e v)
// p = temos acesso
// u = p esquerda
// v = u direita
// p esquerda = v direita
// u direita = v = esquerda
// v esquerda = u
// v direita = p
void rotacaoDuplaDireita(NoAVL **p) {
    NoAVL *u = (*p)->esquerda;
    NoAVL *v = u->direita;
    (*p)->esquerda = v->direita;
    u->direita = v->esquerda;
    v->esquerda = u;
    v->direita = (*p);
    (*p)->altura = atualizarAlturaArvoreAVL((*p)->esquerda, (*p)->direita);
    u->altura = atualizarAlturaArvoreAVL(u->esquerda, u->direita);
    v->altura = atualizarAlturaArvoreAVL(v->esquerda, v->direita);
    (*p) = v;
}

void rotacionarArvoreAVL(NoAVL **arvoreAvl) {
    int alturaEsquerda = alturaArvoreAVL((*arvoreAvl)->esquerda);
    int alturaDireita = alturaArvoreAVL((*arvoreAvl)->direita);

    if (alturaDireita > alturaEsquerda) { // Rotacao para esquerda
        printf("Rotacao para esquerda\n");
        NoAVL *tmp = (*arvoreAvl)->direita; // Filho a direita do no atual
        int tmpArvoreDireita = alturaArvoreAVL((*tmp).direita); // Altura da subarvore direita de tmp
        int tmpArvoreEsquerda = alturaArvoreAVL((*tmp).esquerda); // Altura da subarvore esquerda de tmp
        if (tmpArvoreEsquerda > tmpArvoreDireita) {
            rotacaoDuplaEsquerda(&(*arvoreAvl));
            printf("Rotacao dupla para esquerda\n");
        } else {
            rotacaoSimplesEsquerda(&(*arvoreAvl));
            printf("Rotacao simples para esquerda\n");
        }
    } else { // Rotacao para direita
        printf("Rotacao para direita\n");
        NoAVL *tmp = (*arvoreAvl)->esquerda;
        int tmpArvoreDireita = alturaArvoreAVL((*tmp).direita); // Altura da subarvore direita de tmp
        int tmpArvoreEsquerda = alturaArvoreAVL((*tmp).esquerda); // Altura da subarvore esquerda de tmp
        if (tmpArvoreDireita > tmpArvoreEsquerda) {
            rotacaoDuplaDireita(&(*arvoreAvl));
            printf("Rotacao dupla para direita\n");
        } else {
            rotacaoSimplesDireita(&(*arvoreAvl));
            printf("Rotacao simples para direita\n");
        }
    }
}

int insercaoArvoreAVL(NoAVL **arvoreAvl, int n) {
    if ((*arvoreAvl) == NULL) { // Ponteiro atual = NULL
        (*arvoreAvl) = (NoAVL*) malloc(sizeof(NoAVL));
        (*arvoreAvl)->direita = (*arvoreAvl)->esquerda = NULL;
        (*arvoreAvl)->chave = n;
        (*arvoreAvl)->altura = 1;
        return 1;
    }
    if ((*arvoreAvl)->chave == n) { // Elemento igual
        return 0;
    }
    int inseriu; // Retorno da funcao para necessidade de balanceamento
    if ((*arvoreAvl)->chave < n) { // Direita da arvore
        inseriu = insercaoArvoreAVL(&(*arvoreAvl)->direita, n);
    } else { // Esquerda da arvore
        inseriu = insercaoArvoreAVL(&(*arvoreAvl)->esquerda, n);
    }
    if (inseriu == 0) {
        return 0;
    }
    int alturaEsquerda, alturaDireita; // Altura das subarvores que estamos
    alturaEsquerda = alturaArvoreAVL((*arvoreAvl)->esquerda);
    alturaDireita = alturaArvoreAVL((*arvoreAvl)->direita);
    if ((alturaDireita - alturaEsquerda) == 2 || (alturaDireita - alturaEsquerda) == -2) {
        rotacionarArvoreAVL(&(*arvoreAvl));
    }
    (*arvoreAvl)->altura = atualizarAlturaArvoreAVL((*arvoreAvl)->esquerda, (*arvoreAvl)->direita);
    return 1;
}

int main(int argc, const char *argv[]) {
    NoAVL *arvore;
    arvore = iniciaArvoreAVL();
    if (estaVaziaAVL(arvore)) {
        printf("Esta vazia\n");
    } else {
        printf("Nao esta vazia\n");
    }
    printf("Avrovre\n\n");
    insercaoArvoreAVL(&(arvore), 13);
    insercaoArvoreAVL(&(arvore), 14);
    insercaoArvoreAVL(&(arvore), 15);    
    preOrdemAVL(&(arvore));

    printf("Avrovre\n\n");
    insercaoArvoreAVL(&(arvore), 12);    
    insercaoArvoreAVL(&(arvore), 11);    
    insercaoArvoreAVL(&(arvore), 17);    
    preOrdemAVL(&(arvore));

    printf("Avrovre\n\n");
    insercaoArvoreAVL(&(arvore), 16);    
    insercaoArvoreAVL(&(arvore), 8);    
    insercaoArvoreAVL(&(arvore), 9);    
    preOrdemAVL(&(arvore));

    destruirAVL(&(arvore));
    return EXIT_SUCCESS;
}