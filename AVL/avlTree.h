#ifndef avlTree
#define avlTree

typedef struct noAvl NoAVL;

NoAVL *iniciarArvoreAvl();
int estaVazia(NoAVL **arvoreAvl);
int maxAlturaFilho(NoAVL **arvoreAvl);
void rotacaoEsquerda(NoAVL **arvoreAvl);
void rotacaoDireita(NoAVL **arvoreAvl);
int alturaArvoreAVL(NoAVL **arvoreAvl);
int fatorDebalanceamento(NoAVL **arvoreAvl);
void rotacionarArvoreAvl(NoAVL **arvoreAvl);
void inserirArvoreAVL(NoAVL **arvoreAvl, int chave);
void emOrdemAVL(NoAVL **arvoreAvl);
void preOrdem(NoAVL **arvoreAvl);
void destruirArvoreAVL(NoAVL **arvoreAvl);
void excluirElem(NoAVL **no, int chave);

#endif