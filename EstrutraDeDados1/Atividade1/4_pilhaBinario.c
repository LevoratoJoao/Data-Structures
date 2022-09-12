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
    printf("Elementos da pilha: { ");
    /** For de ponteiro:
        - var aux recebe o topo da pilha
        - enquanto for diferente de NULL printa valor
        - aponta para proximo valor ate chegar no NULL
    **/
    for (i = p.topo; i != NULL; i = i->proximo) {
        printf("%d, ", i->chave);
    }
    printf(" }\n");
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

void converterBinario(PilhaDinamica *p, int numero) {
    if (numero == 0) {
        printf("Armazenando numero em binario na pilha...\n");
    } else {
        converterBinario(p, numero / 2);
        inserirPilha(p, numero % 2);
    }
}

int main(void) {
    PilhaDinamica stack;
    iniciarPilha(&stack);
    int numero = 0;
    printf("Digite um numero (nao negativo): ");
    while (numero <= 0) { // Verificacao do numero inserido
        scanf("%d", &numero);
    }
    converterBinario(&stack, numero);//Funcao recursiva para converter binario
    imprimirPilha(stack);
    printf("Numero de elementos na pilha %d\n", tamanhoPilha(stack));
    destruir(&stack);
    if(estaVazia(stack) == 0) {
        printf("Pilha esta vazia\n");
    } else {
        printf("Pilha contem elementos\n");
    }
    //removerPilha(&stack);
    return 0;
}