#include <stdio.h>
#include <stdlib.h>

typedef struct NoPilha *PonteiroNo; //Ponteiro para estrutura NoPilha

typedef struct NoPilha {
    int chave;
    PonteiroNo proximo;
} NoPilha;

typedef struct {
    PonteiroNo topo;
    int quantidade;
} PilhaDinamica;

void iniciarPilha (PilhaDinamica *p) {
    p->topo = NULL;
    p->quantidade = 0;
}

int tamanhoPilha(PilhaDinamica p) {
    return p.quantidade;
}

int estaVazia (PilhaDinamica p) {
    if (p.quantidade == 0) {
        return 1;
    }
    return 0;
}

void inserirPilha(PilhaDinamica *p, int n) {
    //Criar novo No
    PonteiroNo aux = NULL;
    aux = (PonteiroNo) malloc(sizeof(NoPilha));
    //Novo no recebe o valor que queremos inserir
    aux->chave = n;
    //Proximo do novo No recebe o topo da pilha
    aux->proximo = p->topo;
    //Topo da pilha passa a apontar para o valor do novo No
    p->topo = aux;
    //Incremento da quantidade
    p->quantidade++;
}

void imprimirPilha(PilhaDinamica p) {
    PonteiroNo i;
    for (i = p.topo; i != NULL; i = i->proximo) {
        printf("Termoda sequencia de Fibonacci: %d\n", i->chave);
    }
}

void removerPilha(PilhaDinamica *p) {
    PonteiroNo *aux;
    if (estaVazia(*p) == 0) {
        //No auiliar recebendo topo da pilha
        aux = p->topo;
        //Topo da pilha aponta para o proximo
        p->topo = p->topo->proximo;
        //Desaloca pilha e diminui a quantidade de elementos
        free(aux);
        p->quantidade--;
    } else {
        printf("Pilha esta vazia\n");
    }
}

void destruir(PilhaDinamica *p) {
    while (p->topo != NULL) {
        removerPilha(p);
    }
}

int main(int argc, char *argv[]) {
    PilhaDinamica stack;

    iniciarPilha(&stack);

    inserirPilha(&stack, 5);
    inserirPilha(&stack, 2);

    imprimirPilha(stack);
    printf("A quantidade e %d\n", tamanhoPilha(stack));

    removerPilha(&stack);

    if(estaVazia(stack) == 1) {
        printf("está vazia\n");
    } else {
        printf("não é vazia\n");
    }

    imprimirPilha(stack);
    destruir(&stack);
    if(estaVazia(stack) == 1) {
        printf("está vazia\n");
    } else {
        printf("não é vazia\n");
    }

    return 0;
}