#include <stdlib.h>
#include <stdio.h>
#include "pilhaDinamica.h"

int main(int argc, char *argv[]) {
    PilhaDinamica *stack = iniciarPilha();

    inserirPilha(stack, 5);
    inserirPilha(stack, 2);

    imprimirPilha(stack);
    printf("A quantidade e %d\n", tamanhoPilha(stack));

    removerPilha(stack);

    if(estaVazia(stack) == 1) {
        printf("está vazia\n");
    } else {
        printf("não é vazia\n");
    }

    imprimirPilha(stack);
    destruir(stack);
    
    return 0;
}