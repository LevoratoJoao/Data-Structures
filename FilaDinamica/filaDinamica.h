#ifndef filaDinamica
#define filaDinamica

typedef struct fila_dinamica FilaDinamica;

FilaDinamica *iniciaFilaDinamica();
int vaziaFilaDinamica(FilaDinamica *fila);
int tamanhoFilaDinamica(FilaDinamica *fila);
void inserirFilaDinamica(FilaDinamica *fila, int n);
void imprimirFila(FilaDinamica *fila);
void removerFilaDinamica(FilaDinamica *fila);
void destruirFila(FilaDinamica *fila);

#endif