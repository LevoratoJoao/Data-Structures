#include <stdio.h>
#include <stdlib.h>
#define TAM 10
/**
 *  FUNCOES ESTATICAS
 *  Modificacao:
 *  - inserir
 *  - remover
 *  - primeiro
 *  - ultimo
 *  Consulta
 *  - tamanho
**/

typedef struct {
    int inicio;
    int fim;
    int vetor[TAM];
    int quantidade;
} FilaEstatica;

// FUNCOES DE CONSULTA
/**
 * @brief estaVazia
 *
 * @param fila
 * @return int
 */
int estaVazia(FilaEstatica *fila) {
    return (fila->quantidade == 0);
}

/**
 * @brief estaCheia
 *
 * @param fila
 * @return int
 */
int estaCheia(FilaEstatica *fila) {
    return (fila->quantidade == TAM - 1);
}

int tamanhoFila(FilaEstatica *fila) {
    return fila->quantidade;
}

/**
 * @brief iniciar
 *
 * @param fila
 */
void iniciaFila(FilaEstatica *fila) {
    fila->quantidade = 0;
    fila->inicio = 0;
    fila->fim = -1;
}

//Atribui elemento indicado pelo fim
// incrementa o fim
void inserirFilaEstaticaEstatica(FilaEstatica *fila, int n) {
    if (estaCheia(fila)) {
        printf("Fila esta cheia\n");
        return;
    }
    fila->fim = (fila->fim + 1) % TAM;
    fila->vetor[fila->fim] = n;
    fila->quantidade++;
}

void imprimirFila(FilaEstatica *fila) {
    printf("Fila = {");
    for (int i = 0; i < tamanhoFila(fila); i++) {
        printf(" %d ", fila->vetor[(fila->inicio + i) % TAM]);
    }
    printf("}\n");
}

int removerFilaEstatica(FilaEstatica *fila) {
    int aux;
    if (estaVazia(fila)) {
        printf("Fila esta vazia\n");
        return 0;
    }
    aux = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM;
    fila->quantidade--;

    return aux;
}

int main() {
    FilaEstatica fila;

    iniciaFila(&fila);

    if (estaVazia(&fila)) {
        printf("Esta vazia\n");
    }
    if (estaCheia(&fila)) {
        printf("Esta cheia\n");
    }

    inserirFilaEstatica(&fila, 9);
    imprimirFila(&fila);
    printf("%d\n", tamanhoFila(&fila));

    inserirFilaEstatica(&fila, 10);
    imprimirFila(&fila);
    removerFilaEstatica(&fila);

    inserirFilaEstatica(&fila, 3);

    inserirFilaEstatica(&fila, 4);
    imprimirFila(&fila);

    printf("%d\n", tamanhoFila(&fila));

    removerFilaEstatica(&fila);

    imprimirFila(&fila);

    printf("%d\n", tamanhoFila(&fila));

    return 0;
}