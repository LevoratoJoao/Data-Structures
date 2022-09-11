#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3

/** Informações:
    S - Estrutura de dados
    k - chave 
    x - objeto que queremos inserir na estrutura
**/

typedef struct aluno {
    int ra;
    char nome[50];
} Aluno;

typedef struct pilha {
    int topo; // Chave
    Aluno alunos[N]; // Estrutura
} Pilha;

//////////////////////////////////////////////////
// OPERACOES DE MODIFICAÇÃO //

void iniciarPilha(Pilha *pilha) {
    pilha->topo = 0;
}

void inserir(Pilha *pilha, Aluno eu) {
    if (estaCheia(pilha) == true)
    {
        printf("\nPilha esta cheia\n");
        return;
    }
    pilha->alunos[pilha->topo] = eu; // Insercao do elemento na posicao do topo
    pilha->topo++; // Incremento do topo para ir para proxima posicao
}

int removerPilha(Pilha *pilha) {
    return pilha->topo--;
}

//Pesquisar...

//////////////////////////////////////////////////
// OPERACOES DE CONSULTA //

bool estaCheia(Pilha *pilha) {
    if (pilha->topo == N) {
        return true;
    } else {
        return false;
    }
}

//Esta vazia...

//Topo...

void imprimirPilha(Pilha pilha) {
    for (int i = 0; i < pilha.topo; i++)
    {
        printf("Nome: %s\nRA: %d\n", pilha.alunos[i].nome, pilha.alunos[i].ra);
    }
}


int tamanho(Pilha *pilha) {
    return pilha->topo;
}
//////////////////////////////////////////////////

int main() {
    Pilha pilha;
    Aluno eu = {14, "Levoras"};
    iniciarPilha(&pilha);
    inserir(&pilha, eu);

    eu.ra = 2345678;
    strcpy(eu.nome, "Marquin da roça");
    inserir(&pilha, eu);

    eu.ra = 2345678;
    strcpy(eu.nome, "Thu do pneu");
    inserir(&pilha, eu);

    eu.ra = 2345678;
    strcpy(eu.nome, "Oto otario");
    inserir(&pilha, eu);

    imprimirPilha(pilha);

    int tam = tamanho(&pilha);
    printf("Tamanho: %d\n", tam);

    removerPilha(&pilha);
    printf("\n\n");
    imprimirPilha(pilha);
    tam = tamanho(&pilha);
    printf("Tamanho: %d\n", tam);

    return 0;
}