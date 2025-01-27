#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "grafoMatriz.h"

int main()
{
    GrafoMatriz *grafo = inicializarGrafo(5, false);

    inserirGrafo(grafo, 1, 2);
    inserirGrafo(grafo, 1, 3);
    inserirGrafo(grafo, 2, 3);
    inserirGrafo(grafo, 2, 5);
    inserirGrafo(grafo, 3, 4);
    inserirGrafo(grafo, 4, 5);
    imprimirGrafo(grafo);

    if (existeAresta(grafo, 3, 4) > 0)
        printf("Aresta existe\n");
    else
        printf("Aresta nao existe\n");

    bool *visitado = (bool *)calloc(getVertices(grafo), sizeof(bool));
    buscaEmProfundidade(grafo, 1, visitado);
    destruirGrafo(grafo);

    return EXIT_SUCCESS;
}