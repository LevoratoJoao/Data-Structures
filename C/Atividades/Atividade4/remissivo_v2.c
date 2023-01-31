#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char termo[25];
    int pagina;
} Objeto;

typedef struct noAvl {
    Objeto obj;
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

void emOrdemAVL(NoAVL **arvore) {
    if (estaVaziaAVL((*arvore))) {
        return;
    }
    emOrdemAVL(&(*arvore)->esquerda);
    printf("%s | %d\n", (*arvore)->obj.termo, (*arvore)->obj.pagina);
    emOrdemAVL(&(*arvore)->direita);
}

int pesquisaAVL(NoAVL **arvore, Objeto termos) {
    if (estaVaziaAVL((*arvore))) {
        printf("Esta vazia\n");
        return 0;
    }
    if (strcmp((*arvore)->obj.termo, termos.termo) == 0) {
        return 1;
    }
    if (strcmp((*arvore)->obj.termo, termos.termo) > 0) {
        return (pesquisaAVL(&(*arvore)->direita, termos));
    } else {
        return (pesquisaAVL(&(*arvore)->direita, termos));
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

int insercaoArvoreAVL(NoAVL **arvoreAvl, Objeto termos) {
    if ((*arvoreAvl) == NULL) { // Ponteiro atual = NULL
        (*arvoreAvl) = (NoAVL*) malloc(sizeof(NoAVL));
        (*arvoreAvl)->direita = (*arvoreAvl)->esquerda = NULL;
        (*arvoreAvl)->obj = termos;
        (*arvoreAvl)->altura = 1;
        return 1;
    }
    if (strcmp((*arvoreAvl)->obj.termo, termos.termo) == 0) { // Elemento igual
        return 0;
    }
    int inseriu; // Retorno da funcao para necessidade de balanceamento
    if (strcmp((*arvoreAvl)->obj.termo, termos.termo) < 0) { // Direita da arvore
        inseriu = insercaoArvoreAVL(&(*arvoreAvl)->direita, termos);
    } else { // Esquerda da arvore
        inseriu = insercaoArvoreAVL(&(*arvoreAvl)->esquerda, termos);
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

///////////////////////////////////////////////////////////////////
// FUNCOES ARQUIVOS

/**
 * @brief Open file - funcao para abrir arquivo com nome passado por parametro em formato de leitura (read)
 *
 * @param name
 * @return FILE*
 */
FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        exit(1);
    }
    return file;
}

/**
 * @brief Create file - funcao para criar arquivos com o nome que foi passado por parametro
 *
 * @param name
 * @return FILE*
 */
FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        exit(1);
    }
    return file;
}

/**
 * @brief Read file - funcao para ler arquivo e armazenar seus dados em uma variavel
 *
 * @param file
 * @param termos
 */
void rd_file(FILE *file, NoAVL **termos) {
    Objeto aux;
    while (1) { // acaba o loop ao final do arquivo
        fscanf(file, "%s \t %d\n", &aux.termo, &aux.pagina);
        insercaoArvoreAVL(termos, aux);
        if (feof(file)) break;
    }
}

int main(int argc, const char *argv[]) {
    FILE *entrada = op_file("remissivo.xlsx");
    FILE *saida = cr_file("remissivo2.xlsx"); //Nao pede pra salvar os novos dados
    NoAVL *arvore;
    arvore = iniciaArvoreAVL();
    rd_file(entrada, &arvore);
    emOrdemAVL(&arvore);

    destruirAVL(&(arvore));
    return EXIT_SUCCESS;
}