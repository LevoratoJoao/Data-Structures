#ifndef pilhaDinamica
#define pilhaDinamica

typedef struct pilha PilhaDinamica;

PilhaDinamica *iniciarPilha();
int tamanhoPilha(PilhaDinamica *p);
int estaVazia(PilhaDinamica *p);
void inserirPilha(PilhaDinamica *p, int n);
void imprimirPilha(PilhaDinamica *p);
void removerPilha(PilhaDinamica *p);
void destruir(PilhaDinamica *p);

#endif