#ifndef listaDupla
#define listaDupla

typedef struct lista_dupla Lista;

Lista *inicializarLista();
int estaVazia(Lista *list);
int tamanhoLista(Lista *list);
void inserirElemento(Lista *list, int chave);
void imprimirLista(Lista *list);
void destroiLista(Lista *list);

#endif