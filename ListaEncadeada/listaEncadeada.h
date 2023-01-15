#ifndef listaEncadeada
#define listaEncadeada

typedef struct obj
{
    int chave;
    struct obj *proximo;
} NoLista;

typedef struct listaEncadeada
{
    NoLista *inicio;
    int numElemento;
} Lista;

void inicializarLista(Lista *list);
int estaVazia(Lista *list);
int tamanhoLista(Lista *list);
void inserirElemento(Lista *list, int chave);
void imprimirLista(Lista *list);
int pesquisarLista(Lista *lista, int chave);
int removerLista(Lista *lista, int chave);
void destroiLista(Lista *list);

#endif