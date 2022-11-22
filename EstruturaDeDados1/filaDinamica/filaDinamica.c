#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila *PtrNoFila;

typedef struct NoFila
{
    int conteudo;
    PtrNoFila proximo;
    //struct NoFila *prox;
} NoFila;

typedef struct
{
    PtrNoFila inicio; //NoFila inicio
    PtrNoFila final; //NoFila final
    int quantidade;
} FilaDinamica;

void iniciaFilaDinamica(FilaDinamica *fila) {
    fila->final = NULL;
    fila->inicio = NULL;
    fila->quantidade = 0;
}

int vaziaFilaDinamica(FilaDinamica *fila) {
    return (fila->inicio == NULL);
}

int tamanhoFilaDinamica(FilaDinamica *fila) {
    return fila->quantidade;
}

// Final

// Inicio

// Funcoes de Modificacao
void inserirFilaDinamica(FilaDinamica *fila, int n) {
    // Criar aux de NoFila, alocar mem, copiar informacao pra ele
    PtrNoFila aux;
    aux = (PtrNoFila) malloc(sizeof(NoFila));
    aux->conteudo = n;
    if (vaziaFilaDinamica(fila)) { // Primeira insercao
        fila->inicio = fila->final = aux; // inicio e final da fila apontam pro novo no
        aux->proximo = NULL;
    } else { // Demais insercoes
        aux->proximo = fila->final->proximo; // Proximo do aux aponta para quem é o prox do fim (NULL)
        fila->final->proximo = aux; // Proximo do fim aponta para o novo elemento
        fila->final = fila->final->proximo; // Fim recebe o proximo do fim
    }
    fila->quantidade++;
}

void imprimirFila(FilaDinamica *fila) {
    printf("fila = {");
    for (PtrNoFila i = fila->inicio; i != NULL; i = i->proximo) {
        printf(" %d ", i->conteudo);
    }
    printf("}\n");
}

void removerFilaDinamica(FilaDinamica *fila) {
    if (!vaziaFilaDinamica(fila)) {
        //ptr auxiliar
        PtrNoFila aux;
        //copiar a info pro user
        aux = fila->inicio;
        //att o inicio do prox dele
        fila->inicio = fila->inicio->proximo;
        free(aux);
        //decrementa qtd
        fila->quantidade--;
    } else {
        printf("Fila esta vazia\n");
    }
}

void destruirFila(FilaDinamica *fila) {
    while (fila->quantidade != 0) {
        removerFilaDinamica(fila);
    }
}

int main() {
    FilaDinamica fila;

    iniciaFilaDinamica(&fila);

    if(vaziaFilaDinamica(&fila)) {
        printf("Esta vazia\n");
    }
    inserirFilaDinamica(&fila, 3);
    inserirFilaDinamica(&fila, 4);
    inserirFilaDinamica(&fila, 9);
    inserirFilaDinamica(&fila, 8);
    inserirFilaDinamica(&fila, 6);
    inserirFilaDinamica(&fila, 7);

    imprimirFila(&fila);

    if(vaziaFilaDinamica(&fila)) {
        printf("Esta vazia\n");
    }
    printf("Tamanho da fila: %d\n", tamanhoFilaDinamica(&fila));

    removerFilaDinamica(&fila);
    imprimirFila(&fila);
    removerFilaDinamica(&fila);
    imprimirFila(&fila);
    removerFilaDinamica(&fila);
    imprimirFila(&fila);
    removerFilaDinamica(&fila);
    imprimirFila(&fila);
    removerFilaDinamica(&fila);
    imprimirFila(&fila);
    removerFilaDinamica(&fila);
    imprimirFila(&fila);
    removerFilaDinamica(&fila);

    inserirFilaDinamica(&fila, 9);
    inserirFilaDinamica(&fila, 8);
    inserirFilaDinamica(&fila, 6);
    imprimirFila(&fila);
    printf("Tamanho da fila: %d\n", tamanhoFilaDinamica(&fila));
    destruirFila(&fila);
    printf("Tamanho da fila: %d\n", tamanhoFilaDinamica(&fila));

    return 0;
}