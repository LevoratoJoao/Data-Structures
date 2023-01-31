#ifndef grafoMatriz
#define grafoMatriz

typedef struct grafo_st GrafoMatriz;

GrafoMatriz *inicializarGrafo(int vertices, bool dirigido);
int getVertices(GrafoMatriz *grafo);
void inserirGrafo(GrafoMatriz *grafo, int verticeUm, int verticeDois);
void imprimirGrafo(GrafoMatriz *grafo);
bool existeAresta(GrafoMatriz *grafo, int verticeUm, int verticeDois);
int buscaEmProfundidade(GrafoMatriz *grafo, int vertices, bool *visitado);
void destruirGrafo(GrafoMatriz *grafo);

#endif