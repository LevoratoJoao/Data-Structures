#include <stdbool.h>
#ifndef pilhaEstatica
#define pilhaEstatica

typedef struct pilha Pilha;
typedef struct aluno Aluno;

Pilha *iniciarPilha();
bool estaCheia(Pilha *pilha);
void inserir(Pilha *pilha, Aluno eu);
int removerPilha(Pilha *pilha);
void imprimirPilha(Pilha *pilha);
int tamanho(Pilha *pilha);
void freePilha(Pilha *pilha);

#endif