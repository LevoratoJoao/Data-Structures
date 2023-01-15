#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

////////////////////////////////////////
// FILA DINAMICA

typedef struct obj{
    int chave;
    /*infomações*/
    struct obj *prox;
}Objeto;

typedef struct filaDinamica{
    Objeto* inicio;
    Objeto* fim;
    int tamanho;
} FilaDinamica;

void inicializaFila(FilaDinamica *f){
    f->inicio=NULL;
    f->fim=NULL;
    f->tamanho=0;
}

bool estaVazio(FilaDinamica *f){
    return(f->tamanho==0);
}

int tamanhoFila(FilaDinamica *f){
    return(f->tamanho);
}

void insereFila(FilaDinamica *f, int chave){
    Objeto *novo;
    novo=(Objeto*) malloc(sizeof(Objeto));
    novo->chave=chave;
    novo->prox=NULL;

    if(estaVazio(f)==true) {
        f->inicio= novo;
        f->fim=novo;
    } else {
        f->fim->prox=novo;
        f->fim=novo;
    }
    f->tamanho++;
}

void imprimeFila(FilaDinamica *f){
    int pos=0;
    for(Objeto* aux=f->inicio; aux!=NULL; aux=aux->prox){
        printf("\n-->>Pos %d ==>> Chave=%d  \n\n", ++pos, aux->chave);
    }
}

void remover(FilaDinamica *f){
    Objeto *aux;
    aux=f->inicio;
    f->inicio=f->inicio->prox;
    free(aux);
    f->tamanho--;
}

void destruirFila(FilaDinamica *f){
    while(f->tamanho!=0) remover(f);
}

///////////////////////
// grafo


typedef struct {
    int **matriz;
    int vertices;
    int arestas;
    bool dirigido;
} GrafoMatriz;

void inicializarGrafo(GrafoMatriz *grafo, int vertices, bool dirigido) {
    grafo->arestas = 0;
    grafo->vertices = vertices;
    grafo->dirigido = dirigido;
    grafo->matriz = (int**) malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        //Calloc ja inicia com 0
        grafo->matriz[i] = (int*) malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) grafo->matriz[i][j] = 0;
    }
}

void inserirGrafo(GrafoMatriz *grafo, int verticeUm, int verticeDois) {
    grafo->arestas++;
    grafo->matriz[verticeUm - 1][verticeDois - 1] = 1;
    if (grafo->dirigido == false) {
        grafo->matriz[verticeDois - 1][verticeUm - 1] = 1;
    }
}

void imprimirGrafo(GrafoMatriz *grafo) {
    printf("Grafo:\n");
    for (int i = 0; i < grafo->vertices; i++) {
        for (int j = 0; j < grafo->vertices; j++) {
            if (grafo->matriz[i][j]) {
                if (grafo->dirigido == true)
                    printf("< %d, %d >\n", i + 1, j + 1);
                else
                    printf("( %d, %d )\n", i + 1, j + 1);
            }
        }
    }
}
/*
int existeAresta(GrafoMatriz *grafo, int verticeUm, int verticeDois) {
    if (grafo->matriz[verticeUm - 1][verticeDois - 1] > 0) return grafo->matriz[verticeUm - 1][verticeDois - 1];
    else return 0;
}
*/
bool existeAresta(GrafoMatriz *grafo, int verticeUm, int verticeDois) {
    return (grafo->matriz[verticeUm - 1][verticeDois - 1] > 0);
}

void visitarDFS(GrafoMatriz *grafo, int *visitado, int i, int status) {
    visitado[i] = status;
    printf(" %d \t", i + 1);
    for (int j = 0; j < grafo->vertices; j++) {
        if (grafo->matriz[i][j] == 1) {
            if (visitado[j] == 0) {
                visitarDFS(grafo, visitado, j, 1);
            }
        }
    }
    visitado[i] = 2;
}

int buscaEmProfundidade(GrafoMatriz *grafo, int verticeInicial) {
    int visitado[grafo->vertices]; // 0 = Não visitado | 1 = Visitado | 2 = NoFinal
    verticeInicial--;
    for (int i = 0; i < grafo->vertices; i++) {
        visitado[i] = 0;
    }
    visitado[verticeInicial] = 1;
    printf("\n %d \t", verticeInicial + 1);
    for (int i = 0; i < grafo->vertices; i++) {
        if (grafo->matriz[verticeInicial][i] == 1) {
            if (visitado[i] == 0) {
                visitarDFS(grafo, visitado, i, 1);
            }
        }
    }
    for (int i = 0; i < grafo->vertices; i++) {
        if (visitado[i] == 0) {
            if (visitado[i] == 0) {
                visitarDFS(grafo, visitado, i, 1);
            }
            visitado[i] = 2;
        }
    }
}

void buscaEmLargura(GrafoMatriz *grafo, int verticeInicial) {
    verticeInicial--;
    FilaDinamica filaDinamica;
    bool visitado[grafo->vertices];
    inicializaFila(&filaDinamica);
    for (int i = 0; i < grafo->vertices; i++) {
        visitado[i] = false;
    }
    visitado[verticeInicial] = true;
    insereFila(&filaDinamica, verticeInicial);
    printf("\n\t %d", verticeInicial + 1);
    do {
        while (estaVazio(&filaDinamica) != true) {
            for (int i = 0; i < grafo->vertices; i++) {
                if (grafo->matriz[filaDinamica.inicio->chave][i] == 1) {
                    if (visitado[i] == false) {
                        visitado[i] = true;
                        insereFila(&filaDinamica, i);
                        printf("\t %d", i + 1);
                    }
                }
            }
            remover(&filaDinamica);
        }
        for (int i = 0; i < grafo->vertices; i++) {
            if (visitado[i] == false) {
                visitado[i] = true;
                insereFila(&filaDinamica, i);
                printf("\t %d", i + 1);
                break;
            }
        }

    } while (estaVazio(&filaDinamica) != true);
    destruirFila(&filaDinamica);
}

void destruirGrafo(GrafoMatriz *grafo) {
    for (int i = 0; i < grafo->vertices; i++) free(grafo->matriz[i]);
    free(grafo->matriz);
}

int main() {
    GrafoMatriz grafo;

    inicializarGrafo(&grafo, 5, true);
    inserirGrafo(&grafo, 1, 2);
    inserirGrafo(&grafo, 2, 5);
    inserirGrafo(&grafo, 3, 1);
    inserirGrafo(&grafo, 3, 2);
    inserirGrafo(&grafo, 3, 4);
    inserirGrafo(&grafo, 4, 5);
    imprimirGrafo(&grafo);

    if (existeAresta(&grafo, 3, 4) > 0)
        printf("Aresta existe\n");
    else printf("Aresta nao existe\n");

    //buscaEmProfundidade(&grafo, 1);
    buscaEmLargura(&grafo, 1);
    destruirGrafo(&grafo);
