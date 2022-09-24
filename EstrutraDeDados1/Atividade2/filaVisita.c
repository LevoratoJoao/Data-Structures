#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 11
//#define NAME "arquivos/visita.txt"
//#define SAIDA "arquivos/saida.txt"

typedef struct ListaVisita
{
    int id;
    char proprietario[51];
    char endereco[25];
    int nCasa;
} Visita;

////////////////////////////////////////////////////////////////////
// FUNCOES FILA ESTATICA
//

typedef struct {
    int inicio;
    int fim;
    Visita vetor[TAM];
    int quantidade;
} FilaEstatica;

void iniciaFilaEstatica(FilaEstatica *fila) {
    fila->quantidade = 0;
    fila->inicio = 0;
    fila->fim = -1;
}

int estaVaziaEstatica(FilaEstatica *fila) {
    return (fila->quantidade == 0);
}

int estaCheiaEstatica(FilaEstatica *fila) {
    return (fila->quantidade == TAM - 1);
}

int tamanhoFilaEstatica(FilaEstatica *fila) {
    return fila->quantidade;
}

int removerFilaEstatica(FilaEstatica *fila) {
    if (estaVaziaEstatica(fila)) {
        printf("Fila esta vazia\n");
        return 0;
    }
    fila->inicio = (fila->inicio + 1) % TAM;
    fila->quantidade--;

    return 1;
}

void inserirFilaEstatica(FilaEstatica *fila, Visita n) {
    if(estaVaziaEstatica(fila)) {
        fila->quantidade++;
        fila->fim = fila->inicio = 0;
        fila->vetor[0] = n;
        return;
    }
    if (estaCheiaEstatica(fila)) {
        printf("Fila esta cheia\n");
        return;
    }
    fila->fim = (fila->fim + 1) % TAM;
    fila->vetor[fila->fim] = n;
    fila->quantidade++;
}

////////////////////////////////////////////////////////////////////
// FUNCOES FILA DINAMICA
//
typedef struct NoFila *PtrNoFila;

typedef struct NoFila
{
    Visita conteudo;
    PtrNoFila proximo;
} NoFila;

typedef struct
{
    PtrNoFila inicio;
    PtrNoFila final;
    int quantidade;
} FilaDinamica;

void iniciaFilaDinamica(FilaDinamica *fila) {
    fila->final = NULL;
    fila->inicio = NULL;
    fila->quantidade = 0;
}

int vaziaFilaDinamica(FilaDinamica *fila) {
    return (fila->inicio == NULL);
}

int tamanhoFilaDinamica(FilaDinamica *fila) {
    return fila->quantidade;
}

void inserirFilaDinamica(FilaDinamica *fila, Visita n) {
    // Criar aux de NoFila, alocar mem, copiar informacao pra ele
    PtrNoFila aux;
    aux = (PtrNoFila) malloc(sizeof(NoFila));
    aux->conteudo = n;
    if (vaziaFilaDinamica(fila)) { // Primeira insercao
        fila->inicio = fila->final = aux; // inicio e final da fila apontam pro novo no
        aux->proximo = NULL;
    } else { // Demais insercoes
        aux->proximo = fila->final->proximo; // Proximo do aux aponta para quem é o prox do fim (NULL)
        fila->final->proximo = aux; // Proximo do fim aponta para o novo elemento
        fila->final = fila->final->proximo; // Fim recebe o proximo do fim
    }
    fila->quantidade++;
}

void removerFilaDinamica(FilaDinamica *fila) {
    if (!vaziaFilaDinamica(fila)) {
        //ptr auxiliar
        PtrNoFila aux;
        //copiar a info pro user
        aux = fila->inicio;
        //att o inicio do prox dele
        fila->inicio = fila->inicio->proximo;
        free(aux);
        //decrementa qtd
        fila->quantidade--;
    } else {
        printf("Fila esta vazia\n");
    }
}

void destruirFila(FilaDinamica *fila) {
    while (fila->quantidade != 0) {
        removerFilaDinamica(fila);
    }
}

////////////////////////////////////////////////////////////////////
// FUNCOES MANIPULACAO DE ARQUIVOS
//
FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        return NULL;
    }
    return file;
}

FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        return NULL;
    }
    return file;
}

FILE sv_file(FILE *file, FilaDinamica fila) {
    for (PtrNoFila i = fila.inicio; i != NULL; i = i->proximo) {
        fprintf(file, "{ %d; %s; %s; %d }\n", i->conteudo.id, i->conteudo.proprietario, i->conteudo.endereco, i->conteudo.nCasa);
    }
}

int rd_file(FILE *file, FilaEstatica *fila) {
    Visita n;
    char aux[100];

    if (fgets(aux, 100, file) == NULL) { // acaba o loop ao final do arquivo
        return 1;
    } else {
        sscanf(aux, "{ %d; %[^;]; %[^;]; %d }\n", &n.id, &n.proprietario, &n.endereco, &n.nCasa);
    }

    inserirFilaEstatica(fila, n);
    return 0;
}

// int menu(FilaEstatica *filaVisita, FilaDinamica *filaConcretizadas, FilaDinamica *filaNConcretizadas, FILE *entrada) {
//     char aux[100];
//     Visita auxVisita;

//     while (1) {
//         if (fgets(aux, 100, entrada) != NULL) {
//             int n = 0;
//             sscanf(aux, "{ %d; %[^;]; %[^;]; %d }\n", &auxVisita.id, &auxVisita.proprietario, &auxVisita.endereco, &auxVisita.nCasa);
//             inserirFilaEstatica(filaVisita, auxVisita);
//             for (int i = 0; i < tamanhoFilaEstatica(filaVisita); i++) {
//                 printf("Casa atual = { %d; %s; %s; %d }\n", filaVisita->vetor[(filaVisita->inicio + i) % TAM].id, filaVisita->vetor[(filaVisita->inicio + i) % TAM].proprietario, filaVisita->vetor[(filaVisita->inicio + i) % TAM].endereco, filaVisita->vetor[(filaVisita->inicio + i) % TAM].nCasa);
//                 printf("[1] Visita concretizaa\n[2] Visita nao concretizada\n");
//                 while(n != 2 && n != 1) {
//                     setbuf(stdin, NULL);
//                     scanf("%d", &n);
//                 }
//                 if (n == 1) {
//                     inserirFilaDinamica(filaConcretizadas, filaVisita->vetor[i]);
//                     if (tamanhoFilaDinamica(filaConcretizadas) == 10) {
//                         return 0;
//                     }
//                 } else {
//                     inserirFilaDinamica(filaNConcretizadas, filaVisita->vetor[i]);
//                     removerFilaEstatica(filaVisita);
//                     i = tamanhoFilaEstatica(filaVisita);
//                 }
//             }
//         } else {
//             return 1;
//         }
//     }
// }

int main(int argc, char *argv[]) {
    //Arquivos
    FILE *entrada = op_file(argv[1]);
    FILE *saida = cr_file(argv[2]);
    char aux[100];
    //Var filas
    FilaEstatica filaVisita;
    FilaDinamica filaConcretizadas;
    FilaDinamica filaNConcretizadas;

    iniciaFilaEstatica(&filaVisita);
    iniciaFilaDinamica(&filaConcretizadas);
    iniciaFilaDinamica(&filaNConcretizadas);

    //Carregando os dados do arquivo
    for (int i = 0; i < TAM; i++)
    {
        rd_file(entrada, &filaVisita);
    }

    int i = 0;
    while(1) {
        int n = 0;
        printf("\nCasa atual = { %d; %s; %s; %d }\n", filaVisita.vetor[(i + filaVisita.inicio) % TAM].id, filaVisita.vetor[(i + filaVisita.inicio) % TAM].proprietario, filaVisita.vetor[(i + filaVisita.inicio) % TAM].endereco, filaVisita.vetor[(i + filaVisita.inicio) % TAM].nCasa);
        printf("[1] Visita concretizaa\n[2] Visita nao concretizada\n");
        while(n != 2 && n != 1) {
            setbuf(stdin, NULL);
            scanf("%d", &n);
        }
        if (n == 1) {
            inserirFilaDinamica(&filaConcretizadas, filaVisita.vetor[i]);
            printf("\n\nFila concretizada:\n");
            if (tamanhoFilaDinamica(&filaConcretizadas) == 10) {
                printf("Atencao: 10 visitas foram concretizadas!\n");
                sv_file(saida, filaConcretizadas);
                fprintf(saida, "Meta 10 visitas efetuada\n");

                destruirFila(&filaConcretizadas);
                destruirFila(&filaNConcretizadas);

                fclose(entrada);
                fclose(saida);

                return 0;
            }
        } else {
            inserirFilaDinamica(&filaNConcretizadas, filaVisita.vetor[(filaVisita.inicio + i) % TAM]);
            removerFilaEstatica(&filaVisita);
            rd_file(entrada, &filaVisita);
            if (estaVaziaEstatica(&filaVisita))
            {
                printf("Atencao: todas as casas foram visitadas!\n");
                sv_file(saida, filaNConcretizadas);
                fprintf(saida, "Meta de 10 visitas nao foi efetuada\n");

                return 0;
            }

        }
    }
    return 0;
}