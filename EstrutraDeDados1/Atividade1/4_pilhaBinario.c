/**
 * @file 4_pilhaBinario.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br) / Arthur Henrique de Oliveira Petroli (arthurpetroli@alunos.utfpr.edu.br)
 * @brief Elabore um programa que realize a convers ̃ao de n ́umeros decimais (nao negativos) para
 * numeros bin ́arios usando Pilhas Dinˆamicas. O programa deve:
 * • O usu ́ario digitar um n ́umero decimal (N ≥ 0);
 * • Efetuar sucessivas divis ̃oes por 2 e armazenar os restos destas divis ̃oes na pilha
 * • Na  ́ultima divis ̃ao, armazenar tamb ́em o quociente que ser ́a o elemento do topo;
 * • Imprimir a pilha, pois ela conter ́a o valor de N em base bin ́aria.
 *
 * @version 0.1
 * @date 2022-09-12
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
    PonteiroNo i;
    printf("Elementos da pilha: { ");
    /** For de ponteiro:
        - var aux recebe o topo da pilha
        - enquanto for diferente de NULL printa valor
        - aponta para proximo valor ate chegar no NULL
    **/
    for (i = p.topo; i != NULL; i = i->proximo) {
        printf("%d ", i->chave);
    }
    printf("}\n");
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
    while (p->topo != NULL) {
        removerPilha(p);
    }
}

/**
 * @brief Funcao que converte numero inserido pelo usuario em binario atraves de recursividade
 *
 * @param p
 * @param numero
 */
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
    if(estaVazia(stack) == 1) {
        printf("Pilha esta vazia\n");
    } else {
        printf("Pilha contem elementos\n");
    }
    //removerPilha(&stack);
    return 0;
}