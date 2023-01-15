#ifndef listaDupla
#define listaDupla

typedef struct obj {
    int chave;
    struct obj* proximo;
    struct obj* anterior;
} NoLista;

typedef struct listaEncadeada {
    NoLista *inicio;
    NoLista *final;
    int numElemento;
} Lista;

void inicializarLista(Lista *list);
int estaVazia(Lista *list);
int tamanhoLista(Lista *list);
void inserirElemento(Lista *list, int chave);
void imprimirLista(Lista *list);
void destroiLista(Lista *list);

#endif