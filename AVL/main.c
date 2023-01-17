#include <stdlib.h>
#include <stdio.h>
#include "avlTree.h"

int main(void) {

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