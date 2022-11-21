#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void destruirGrafo(GrafoMatriz *grafo) {
    for (int i = 0; i < grafo->vertices; i++) free(grafo->matriz[i]);
    free(grafo->matriz);
}

int main() {
    GrafoMatriz grafo;

    inicializarGrafo(&grafo, 5, true);    
    destruirGrafo(&grafo);

    return EXIT_SUCCESS;
}