#ifndef filaEstatica
#define filaEstatica
#define TAM 10

typedef struct {
    int inicio;
    int fim;
    int vetor[TAM];
    int quantidade;
} FilaEstatica;

int estaVazia(FilaEstatica *fila);
int estaCheia(FilaEstatica *fila);
int tamanhoFila(FilaEstatica *fila);
void iniciaFila(FilaEstatica *fila);
void inserirFilaEstatica(FilaEstatica *fila, int n);
void imprimirFila(FilaEstatica *fila);
int removerFilaEstatica(FilaEstatica *fila);

#endif