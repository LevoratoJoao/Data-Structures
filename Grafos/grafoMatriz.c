#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafoMatriz.h"

typedef struct grafo_st {
    int **matriz;
    int vertices;
    int arestas;
    bool dirigido;
} Grafo;

GrafoMatriz *inicializarGrafo(int vertices, bool dirigido)
{
    Grafo *grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->arestas = 0;
    grafo->vertices = vertices;
    grafo->dirigido = dirigido;
    grafo->matriz = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        // Calloc ja inicia com 0
        grafo->matriz[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            grafo->matriz[i][j] = 0;
    }
    return grafo;
}

int getVertices(GrafoMatriz *grafo)
{
    return grafo->vertices;
}

void inserirGrafo(GrafoMatriz *grafo, int verticeUm, int verticeDois)
{
    grafo->arestas++;
    grafo->matriz[verticeUm - 1][verticeDois - 1] = 1;
    if (grafo->dirigido == false)
    {
        grafo->matriz[verticeDois - 1][verticeUm - 1] = 1;
    }
}

void imprimirGrafo(GrafoMatriz *grafo)
{
    printf("Grafo:\n");
    for (int i = 0; i < grafo->vertices; i++)
    {
        for (int j = 0; j < grafo->vertices; j++)
        {
            if (grafo->matriz[i][j])
            {
                if (grafo->dirigido == true)
                    printf("< %d, %d >\n", i + 1, j + 1);
                else
                    printf("( %d, %d )\n", i + 1, j + 1);
            }
        }
    }
}

bool existeAresta(GrafoMatriz *grafo, int verticeUm, int verticeDois)
{
    return (grafo->matriz[verticeUm - 1][verticeDois - 1] > 0);
}

int buscaEmProfundidade(GrafoMatriz *grafo, int vertices, bool *visitado)
{
    visitado[vertices - 1] = true;
    printf("%d\n", vertices);
    for (int i = 0; i < grafo->vertices; i++)
    {
        if (visitado[i] == false && grafo->matriz[vertices - 1][i] == 1)
        {
            buscaEmProfundidade(grafo, i + 1, visitado);
        }
    }
    return 0;
}

void destruirGrafo(GrafoMatriz *grafo)
{
    for (int i = 0; i < grafo->vertices; i++)
        free(grafo->matriz[i]);
    free(grafo->matriz);
}