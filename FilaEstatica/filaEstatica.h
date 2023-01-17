#ifndef filaEstatica
#define filaEstatica

typedef struct fila_estatica FilaEstatica;

FilaEstatica *iniciaFila();
int estaVazia(FilaEstatica *fila);
int estaCheia(FilaEstatica *fila);
int tamanhoFila(FilaEstatica *fila);
void inserirFilaEstatica(FilaEstatica *fila, int n);
void imprimirFila(FilaEstatica *fila);
int removerFilaEstatica(FilaEstatica *fila);
void freeFila(FilaEstatica *fila);

#endif