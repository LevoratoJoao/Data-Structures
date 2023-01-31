/**
 * @file 1_pilhasNumeros.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br) / Arthur Henrique de Oliveira Petroli (arthurpetroli@alunos.utfpr.edu.br)
 * @brief Elabore um programa em C implementando uma Pilha Dinamica que armazene N numeros
 * da sequencia de Fibonacci, onde N sera um valor recebido pelo usu ́ario e dever ́a estar contido entre
 * 5 < N < 20.
 * • Usu ́ario fornece um valor (entre 5 < N < 20), por exemplo, N = 10
 * • Elementos da Pilha (nesta ordem) { 34, 21, 13, 8, 5, 3, 2, 1, 1, 0 }
 *
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NoPilha *PonteiroNo; //Ponteiro para estrutura NoPilha

typedef struct NoPilha {
    int chave; //Informacao
    PonteiroNo proximo; //Ponteiro prox elemento
} NoPilha;

typedef struct {
    PonteiroNo topo;
    int quantidade;
} PilhaDinamica;

/**
 * @brief Funcao que inicia a pilha zerando seu topo e suas demais variaveis
 *
 * @param pPar
 * @param pImpar
 */
void iniciarPilha (PilhaDinamica *p) {
    p->topo = NULL;
    p->quantidade = 0;
}

/**
 * @brief Funcao que retorna numero de elementos contidos na pilha (quantidade)
 *
 * @param p
 * @return int
 */
int tamanhoPilha(PilhaDinamica p) {
    return p.quantidade;
}

/**
 * @brief funcao que retorna se a pilha esta vazia (1 = true // 0 = false)
 *
 * @param p
 * @return int
 */
int estaVazia (PilhaDinamica p) {
    if (p.quantidade == 0) {
        return 1;
    }
    return 0;
}

/**
 * @brief Funcao para insercao de elemento na pilha
 *
 * @param p
 * @param n
 */
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

/**
 * @brief Funcao para impressao da pilha
 *
 * @param p
 */
void imprimirPilha(PilhaDinamica p) {
    PonteiroNo i; //Variavel aux PonteiroNo
    printf("Elementos da pilha: { ");
    /** For de ponteiro:
        - var aux recebe o topo da pilha
        - enquanto for diferente de NULL printa valor
        - aponta para proximo valor ate chegar no NULL
    **/
    for (i = p.topo; i != NULL; i = i->proximo) {
        if (i->chave == 0) { // Verificacao para impressao da virgula
            printf("%d ", i->chave);

        } else {
            printf("%d, ", i->chave);
        }
    }
    printf(" }\n");
}

/**
 * @brief Funcao para remocao de elemento na pilha
 *
 * @param p
 */
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

/**
 * @brief Funcao para destruir pilha, e feito a chamada da funcao remover ate que o valor do topo seja NULL
 *
 * @param p
 */
void destruir(PilhaDinamica *p) {
    while (p->topo != NULL) { //Enquanto topo for diferente de NULL entra na funcao remover
        removerPilha(p);
    }
}

/**
 * @brief Funcao que calcula o fibonacci do numero inserido atravez de recurividade
 *
 * @param numero
 * @return int
 */
int calcularFibonacci(int numero) {
    if (numero == 1) {
        return 0;
    } else if (numero == 2) {
        return 1;
    } else {
        return calcularFibonacci(numero - 1) + calcularFibonacci(numero - 2);
    }
}

int main(void) {
    PilhaDinamica stack;
    iniciarPilha(&stack);
    int numero = 0;

    printf("Digite um numero entre 5 e 20: ");
    while (numero < 5 || numero > 20) { //Verificacao do numero
        scanf("%d", &numero);
    }
    for (int i = 1; i <= numero; i++) {
        inserirPilha(&stack, calcularFibonacci(i));
    }
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