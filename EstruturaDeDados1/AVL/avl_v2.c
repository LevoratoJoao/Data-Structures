#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noAvl {
    int chave;
    struct noAvl *esquerda;
    struct noAvl *direita;
    int altura;
} NoAVL;

NoAVL *iniciarArvoreAvl(){
    return NULL;
}

int estaVazia(NoAVL** arvoreAvl){
    return ((*arvoreAvl)==NULL) ;
}

int maxAlturaFilho(NoAVL **arvoreAvl){
    if((*arvoreAvl)->esquerda == NULL && (*arvoreAvl)->direita == NULL) return (-1); //Se esquerda for NULL e direita NULL retorna valor da alura -1
    else if((*arvoreAvl)->esquerda == NULL) return ((*arvoreAvl)->direita->altura); //Se so esquerda for NULL retorna altura da direita
    else if((*arvoreAvl)->direita == NULL) return ((*arvoreAvl)->esquerda->altura); //Se so direeita for NULL retorna altura da esquerda
    return ((*arvoreAvl)->direita->altura > (*arvoreAvl)->esquerda->altura ? (*arvoreAvl)->direita->altura : (*arvoreAvl)->esquerda->altura); //Se altura da direeita for maior que altura da esquerda retorna altura da dirita, se nao for rtorna da esquerda
}

void rotacaoEsquerda(NoAVL **arvoreAvl){
    NoAVL *aux = NULL;
    aux = (*arvoreAvl)->direita; //u = p direita
    (*arvoreAvl)->direita = aux->esquerda; //p direita = u esquerda
    aux->esquerda = (*arvoreAvl); //u esquerda = p
    (*arvoreAvl) = aux; //p = u
    (*arvoreAvl)->esquerda->altura = maxAlturaFilho(&(*arvoreAvl)->esquerda) + 1; //Att altura esquerda
    (*arvoreAvl)->altura = maxAlturaFilho(arvoreAvl) + 1; //Att altura
}

void rotacaoDireita(NoAVL **arvoreAvl){
    NoAVL *aux = (*arvoreAvl)->esquerda; //u = p direita
    (*arvoreAvl)->esquerda = aux->direita; //p esquerda = u direita
    aux->direita = (*arvoreAvl); //u direita = p
    (*arvoreAvl) = aux; //p = u
    (*arvoreAvl)->direita->altura = maxAlturaFilho(&(*arvoreAvl)->direita) + 1; //Att altura direita
    (*arvoreAvl)->altura = maxAlturaFilho(arvoreAvl) + 1; //Att altura
}

int alturaArvoreAVL(NoAVL **arvoreAvl){
    if ((*arvoreAvl) == NULL) return -1;
    return ((*arvoreAvl)->altura);
}

void inserirArvoreAVL(NoAVL **arvoreAvl, int chave){
    if ((*arvoreAvl) == NULL) {
        (*arvoreAvl) = (NoAVL*) malloc(sizeof(NoAVL));
        (*arvoreAvl)->chave = chave;
        (*arvoreAvl)->direita = (*arvoreAvl)->esquerda = NULL;
        (*arvoreAvl)->altura = 0;
        return;
    }
    if ((*arvoreAvl)->chave == chave) {
        printf("\nElemento repetido");
        return;
    }
    (*arvoreAvl)->chave > chave ? inserirArvoreAVL(&((*arvoreAvl)->esquerda), chave) : inserirArvoreAVL(&((*arvoreAvl)->direita), chave); //Se chave atual da arvore for maior que a chave insre na esquerda se nao for insere na direita
    //Obs: altura + direita | altura - esquerda | balanceado +1, 0, -1
    (*arvoreAvl)->altura = maxAlturaFilho(arvoreAvl) + 1;
    if(alturaArvoreAVL(&(*arvoreAvl)->direita) - alturaArvoreAVL(&(*arvoreAvl)->esquerda) == 2) { //direita - esquerda == 2 -> rotacao direita -> rotacao esquerda
        if (alturaArvoreAVL(&(*arvoreAvl)->direita->direita) - alturaArvoreAVL(&(*arvoreAvl)->direita->esquerda) < 0) { //Se altura da direita->direita - altura direita->esquerda for menor que 0 -> rotacaoDireita
            rotacaoDireita(&(*arvoreAvl)->direita);
        }
        rotacaoEsquerda(arvoreAvl);
    } else if(alturaArvoreAVL(&(*arvoreAvl)->direita) - alturaArvoreAVL(&(*arvoreAvl)->esquerda) == -2) { //Diferença da direita - esquerda == -2 -> rotacao esquerda -> rotacao esquerda
        if(alturaArvoreAVL(&(*arvoreAvl)->esquerda->direita) - alturaArvoreAVL(&(*arvoreAvl)->esquerda->esquerda) > 0) { //Se altura da direita->direita - altura direita->esquerda for menor que 0 -> rotacaoDireita
            rotacaoEsquerda(&(*arvoreAvl)->esquerda);
        }
        rotacaoDireita(arvoreAvl);
    }
}

void emOrdemAVL(NoAVL **arvoreAvl) {
    if(*arvoreAvl == NULL) return;
    emOrdemAVL(&((*arvoreAvl)->esquerda));
    printf("%d | %d\n", (*arvoreAvl)->chave, (*arvoreAvl)->altura);
    emOrdemAVL(&((*arvoreAvl)->direita));
}

void preOrdem(NoAVL **arvoreAvl){
    if(*arvoreAvl==NULL) return;
    printf("\n--> %d [h=%d]", (*arvoreAvl)->chave, (*arvoreAvl)->altura);
    preOrdem(&((*arvoreAvl)->esquerda));
    preOrdem(&((*arvoreAvl)->direita));
}

void destruirArvoreAVL(NoAVL **arvoreAvl) {
    if((*arvoreAvl) == NULL) return;
    destruirArvoreAVL(&((*arvoreAvl)->esquerda));
    destruirArvoreAVL(&((*arvoreAvl)->direita));
    free(*arvoreAvl);
    (*arvoreAvl) = NULL;
}

void excluirElem(NoAVL **no, int chave){
    if (*no == NULL) {
        printf("\n\n------------\n\n\t Chave nao encontrada \n\n----------------\n");
        return;
    }
    if ((*no)->chave == chave) {
        if ((*no)->esquerda == NULL && (*no)->direita == NULL) {
            free(*no);
            *no = NULL;
        }
        else if ((*no)->esquerda == NULL) {
            NoAVL *aux=*no;
            *no=(*no)->direita;
            free(aux);
        }
        else if ((*no)->direita == NULL) {
            NoAVL *aux=*no;
            *no=(*no)->esquerda;
            free(aux);
        }
        else { //arrumar
            NoAVL *aux = (*no); //aux = no atual
            NoAVL *anterior = (*no); //anterior = no atual
            *no = (*no)->esquerda; //no atual = no->esquerda
            while ((*no)->direita != NULL) { //Percorre ate direita ser null
                anterior = (*no);
                *no = (*no)->direita;
            }
            (*no)->direita = aux->direita; //atual direita = aux direita
            anterior->direita = (*no)->esquerda; //anterior direita = atual esquerda
            if (aux != anterior) (*no)->esquerda = aux->esquerda;
            free(aux);
        }
        return;
    }
    if ((*no)->chave > chave) excluirElem(&(*no)->esquerda, chave); //Se chave atual for maior que chave exclui->esquerda
    else excluirElem(&(*no)->direita, chave); //Senao exclui->direita
    (*no)->altura = maxAlturaFilho(no) + 1;
    if(alturaArvoreAVL(&(*no)->direita) - alturaArvoreAVL(&(*no)->esquerda) == 2) {
        if(alturaArvoreAVL(&(*no)->direita->direita) - alturaArvoreAVL(&(*no)->direita->esquerda) < 0) {
            rotacaoDireita(&(*no)->direita);
        }
        rotacaoEsquerda(no);
    }
    else if(alturaArvoreAVL(&(*no)->direita) - alturaArvoreAVL(&(*no)->esquerda) == -2) {
        if(alturaArvoreAVL(&(*no)->esquerda->direita) - alturaArvoreAVL(&(*no)->esquerda->esquerda) > 0)  rotacaoEsquerda(&(*no)->esquerda);
        rotacaoDireita(no);
    }
}

int main(void){

    NoAVL *raiz = iniciarArvoreAvl();

    inserirArvoreAVL(&raiz, 10);
    inserirArvoreAVL(&raiz, 15);
    inserirArvoreAVL(&raiz, 13);
    inserirArvoreAVL(&raiz, 17);
    inserirArvoreAVL(&raiz, 16);
    inserirArvoreAVL(&raiz, 12);
    inserirArvoreAVL(&raiz, 14);
    inserirArvoreAVL(&raiz, 5);

    printf("\n\n-----------------INICIO------------------\n\n");
    preOrdem(&raiz);
    printf("\n\n-----------------FIM------------------\n\n");

    excluirElem(&raiz, 10);
    excluirElem(&raiz, 16);
    excluirElem(&raiz, 13);

    printf("\n\n-----------------Inicio------------------\n\n");
    preOrdem(&raiz);
    printf("\n\n-----------------Fim------------------\n\n");

    destruirArvoreAVL(&raiz);
    return 0;
}