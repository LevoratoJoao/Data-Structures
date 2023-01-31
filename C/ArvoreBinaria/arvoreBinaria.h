#ifndef arvoreBinaria
#define arvoreBinaria

typedef struct noArv NoArvore;

NoArvore *iniciarlizarArvore();
int estaVazia(NoArvore *arvore);
void preOrdem(NoArvore **arvore);
void posOrdem(NoArvore **arvore);
void emOrdem(NoArvore **arvore);
int pesquisaArvore(NoArvore **arvore, int n);
int inserirArvore(NoArvore **arvore, int n);
NoArvore *getMaxAux(NoArvore **arvore);
NoArvore *getMinAux(NoArvore **arvore);
int removeArvore(NoArvore **arvore, int n);
void destroiArvore(NoArvore **arvore);

#endif