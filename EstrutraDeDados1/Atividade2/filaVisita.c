#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define NAME "arquivos/visita.txt"
#define SAIDA "arquivos/saida.txt"

typedef struct ListaVisita
{
    int id;
    char proprietario[51];
    char endereco[25];
    int nCasa;
} Visita;

typedef struct {
    int inicio;
    int fim;
    Visita vetor[TAM];
    int quantidade;
} FilaEstatica;

void iniciaFila(FilaEstatica *fila) {
    fila->quantidade = 0;
    fila->inicio = 0;
    fila->fim = -1;
}

int estaVazia(FilaEstatica *fila) {
    return (fila->quantidade == 0);
}

int estaCheia(FilaEstatica *fila) {
    return (fila->quantidade == TAM - 1);
}

int tamanhoFila(FilaEstatica *fila) {
    return fila->quantidade;
}

int removerFilaEstatica(FilaEstatica *fila) {
    Visita aux;
    if (estaVazia(fila)) {
        printf("Fila esta vazia\n");
        return 0;
    }
    aux = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM;
    fila->quantidade--;

    return 1;
}

void inserirFilaEstatica(FilaEstatica *fila, Visita n) {
    if (estaCheia(fila)) {
        printf("Fila esta cheia\n");
        return;
    }
    fila->fim = (fila->fim + 1) % TAM;
    fila->vetor[fila->fim] = n;
    fila->quantidade++;
}

FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        return NULL;
    }
    return file;
}

FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        return NULL;
    }
    return file;
}

FILE sv_file(FILE *file, FilaEstatica fila) {
    for (int i = 0; i < tamanhoFila(&fila); i++) {
        fprintf(file, "%d; %s; %s; %d\n", fila.vetor[i].id, fila.vetor[i].proprietario, fila.vetor[i].endereco, fila.vetor[i].nCasa);
    }
}

int rd_file(FILE *file, FilaEstatica *fila) {
    int x = 0;
    Visita n;
    //(c = fgetc(file)) != EOF
    if (feof(file)) { // acaba o loop ao final do arquivo
        return 1;
    }
    fscanf(file, "%[^;]; %[^;]; %[^;]; %d\n", &n.id, &n.proprietario, &n.endereco, &n.nCasa);
    printf("%d\n", ftell(file));
    inserirFilaEstatica(fila, n);
}

int main(int argc, char *argv[]) {
    FILE *entrada = op_file(NAME);
    FILE *saida = cr_file(SAIDA);
    Visita auxVisita[TAM];
    FilaEstatica filaVisita;

    iniciaFila(&filaVisita);

    printf("%d\n", ftell(entrada));
    for (int i = 0; i < TAM; i++)
    {
        rd_file(entrada, &filaVisita);
    }
    for (int i = 0; i < tamanhoFila(&filaVisita); i++)
    {
        printf("%d; %s; %s; %d\n", filaVisita.vetor[i].id, filaVisita.vetor[i].proprietario, filaVisita.vetor[i].endereco, filaVisita.vetor[i].nCasa);
    }
    printf("%d\n", ftell(entrada));
    removerFilaEstatica(&filaVisita);

    printf("\n\n");
    printf("antes de ler %d\n", ftell(entrada));
    for (int i = 0; i < tamanhoFila(&filaVisita); i++)
    {
        printf("%d; %s; %s; %d\n", filaVisita.vetor[i].id, filaVisita.vetor[i].proprietario, filaVisita.vetor[i].endereco, filaVisita.vetor[i].nCasa);
    }
    rd_file(entrada, &filaVisita);
    printf("\n\n");
    printf("Depois de ler %d\n", ftell(entrada));
    for (int i = 0; i < tamanhoFila(&filaVisita); i++)
    {
        printf("%d; %s; %s; %d\n", filaVisita.vetor[i].id, filaVisita.vetor[i].proprietario, filaVisita.vetor[i].endereco, filaVisita.vetor[i].nCasa);
    }

    printf("\n\n");
    removerFilaEstatica(&filaVisita);
    removerFilaEstatica(&filaVisita);
    for (int i = 0; i < tamanhoFila(&filaVisita); i++)
    {
        printf("%d; %s; %s; %d\n", filaVisita.vetor[i].id, filaVisita.vetor[i].proprietario, filaVisita.vetor[i].endereco, filaVisita.vetor[i].nCasa);
    }


    return 0;
}