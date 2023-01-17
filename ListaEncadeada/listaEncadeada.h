#ifndef listaEncadeada
#define listaEncadeada

typedef struct lista_encadeada Lista;

Lista *inicializarLista();
int estaVazia(Lista *list);
int tamanhoLista(Lista *list);
void inserirElemento(Lista *list, int chave);
void imprimirLista(Lista *list);
int pesquisarLista(Lista *lista, int chave);
int removerLista(Lista *lista, int chave);
void destroiLista(Lista *list);

#endif