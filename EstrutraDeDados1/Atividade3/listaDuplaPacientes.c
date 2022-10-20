/**
 * @file listaPacientes.c
 * @author João Vitor Levorato de Souza (joaosouza.2021@alunos.utfpr.edu.br)
 * @brief Um casal de m ́edicos decidiu organizar seus pacientes em listas. Atualmente, os dados dos paciente est ̃ao
 * todos juntos em um  ́unico arquivo e sem qualquer organiza ̧c ̃ao alfab ́etica ou de gˆenero. A ginecologista
 * quer listar suas pacientes em ordem alfab ́etica, de A-Z, por nome. J ́a o andrologista precisa que seus
 * pacientes estejam ordenados em ordem alfab ́etica, mas na sequˆencia de Z-A. O(A) ginecologista  ́e o m ́edico
 * respons ́avel por cuidar da sa ́ude da mulher e o(a) andrologista lida com a sa ́ude dos homens. Fa ̧ca um
 * programa que implemente o funcionamento de um sistema para a cl ́ınica, utilizando listas duplamente
 * encadeadas, e organize as informa ̧c ̃oes dos pacientes que est ̃ao dispostas no arquivo pacientes.txt da
 * seguinte forma:
 *
 * < nome, sexo, nascimento, ultima consulta>
 *
 * O programa tamb ́em dever ́a oferecer tres op̧coes:
 *
 * 1.) adicionar um novo paciente que n ̃ao est ́a contido na base de dados antiga,
 *
 * 2.) realizar a pesquisa por nome, devolvendo a idade e, tambem, ha quantos dias foi a  ́ultima consulta
 * deste paciente (considere os anos com 365 dias, ou seja, NAO precisa adicionar um dia nos anos bissextos);
 *
 * 3.) encerrar a sua execucao, gerando os dois arquivos de saıda, sendo um para cada especialista.
 *
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct pacientes_st{
    char nome[50];
    char sexo[1];
    Data nascimento;
    Data ultimaConsulta;
} Pacientes;

int getSexo(Pacientes pacientes);

///////////////////////////////////////////////////////////////////
// FUNCOES LISTA

typedef struct obj {
    Pacientes pacientes;
    struct obj* proximo;
    struct obj* anterior;
} NoLista;

typedef struct listaEncadeada {
    NoLista *inicio;
    NoLista *final;
    int numElemento;
} Lista;

void inicializarLista(Lista *list) {
    list->inicio = NULL;
    list->final = NULL;
    list->numElemento = 0;
}

int estaVazia(Lista *list) {
    if (list->numElemento == 0) {
        return 0;
    } else {
        return 1;
    }
}

int tamanhoLista(Lista *list) {
    return list->numElemento;
}

void inserirLista(Lista *list, Pacientes pacientes) {
    NoLista *novo;
    novo = (NoLista*) malloc(sizeof(NoLista));
    novo->pacientes = pacientes;
    novo->proximo = NULL;
    novo->anterior = NULL;
    if(estaVazia(list) == 0) {
        list->inicio = novo;
        list->final = novo;
    } else if(strcmp(pacientes.nome, list->inicio->pacientes.nome) < 0) { //Se nome paciente atual for menor que do inicio da lista
        novo->proximo = list->inicio; //Proximo do novo recebe o inicio atual
        list->inicio->anterior = novo; //Anterior de inicio atual recebe o novo
        list->inicio = novo;//Inicio é atualizado para o novo
    } else { //Se nome paciente atual é maior que do inicio da lista
        NoLista *aux = list->inicio;
        while (aux->proximo != NULL && strcmp(aux->proximo->pacientes.nome, pacientes.nome) < 0) { //Enquanto aux nao for nulo e nome do prox paciente for menor que o do paciente atual
            aux = aux->proximo; //aux passa areceber seu proximo
        }
        if (aux->proximo != NULL) {
            aux->proximo->anterior = novo; //O anterior do proximo passa a receber o novo pois caso o novo for menor que o proximo assim o prox atualiza o ponteiro de seu anterior que antes apóntava pra o anterior de aux
        }
        novo->proximo = aux->proximo; //Proximo do novo passa a apontar pra o proximo do auxiliar
        novo->anterior = aux; //Anterior do novo recebe o aux
        if (aux->proximo == NULL) {
            list->final = novo; //Atualizacao do final
        }
        aux->proximo = novo; //Proximo do auxiliar recebe novo
    }
    list->numElemento++;
}

void imprimirLista(Lista *list) {
    NoLista *aux = list->inicio;
    printf("Inicio da lista:\n");
    while (aux != NULL) {
        printf("<%s, %c, %d/%d/%d, %d/%d/%d>\n", aux->pacientes.nome, aux->pacientes.sexo[0], aux->pacientes.nascimento.dia, aux->pacientes.nascimento.mes, aux->pacientes.nascimento.ano, aux->pacientes.ultimaConsulta.dia, aux->pacientes.ultimaConsulta.mes, aux->pacientes.ultimaConsulta.ano);
        aux = aux->proximo;
    }
    printf("\nFim da lista\n");
}

void destroiLista(Lista *list) {
    NoLista *aux = list->inicio;
    while (list->inicio != NULL) {
        list->inicio = list->inicio->proximo;
        free(aux);
        aux = list->inicio;
    }
}

///////////////////////////////////////////////////////////////////
// FUNCOES ARQUIVOS
#define NAME "pacientes.txt"

/**
 * @brief Open file - funcao para abrir arquivo com nome passado por parametro em formato de leitura (read)
 *
 * @param name
 * @return FILE*
 */
FILE *op_file(char *name) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("error: fail to open file\n");
        return EXIT_FAILURE;
    }
    return file;
}

/**
 * @brief Create file - funcao para criar arquivos com o nome que foi passado por parametro
 *
 * @param name
 * @return FILE*
 */
FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        return EXIT_FAILURE;
    }
    return file;
}

/**
 * @brief Read file - funcao para ler arquivo e armazenar seus dados em uma variavel
 *
 * @param file
 * @param pacientesMasculino
 * @param pacientesFeminino
 */
void rd_file(FILE *file, Lista *pacientes) {
    Pacientes n; //Objeto auxiliar
    char aux[100]; //Variavel de leitura auxiliar
    while (fgets(aux, 100, file) != NULL) { // acaba o loop ao final do arquivo
        sscanf(aux, "<%[^,], %[^,], %d/%d/%d, %d/%d/%d>\n", &n.nome, &n.sexo, &n.nascimento.dia, &n.nascimento.mes, &n.nascimento.ano, &n.ultimaConsulta.dia, &n.ultimaConsulta.mes, &n.ultimaConsulta.ano); //Formatacao dos dados armazenados na variavel auxiliar, eles sao armazenados em uma variavel auxiliar do tipo do objeto que é usada para inserir na fila
        inserirLista(pacientes, n);
    }
}

/**
 * @brief Save file - funcao para salvar as informacoes da variavel no arquivo
 *
 * @param file
 * @param lista
 * @return FILE
 */
FILE sv_file(FILE *fileM, FILE *fileF, Lista *lista) {
    for (NoLista *i = lista->inicio; i != NULL; i = i->proximo) {
        if (i->pacientes.sexo[0] == 'F') {
            fprintf(fileF, "<%s, %c, %d/%d/%d, %d/%d/%d>\n", i->pacientes.nome , i->pacientes.sexo[0], i->pacientes.nascimento.dia, i->pacientes.nascimento.mes, i->pacientes.nascimento.ano, i->pacientes.ultimaConsulta.dia, i->pacientes.ultimaConsulta.mes, i->pacientes.ultimaConsulta.ano);
        }
    }
    for (NoLista *i = lista->final; i != NULL; i = i->anterior) {
        if (i->pacientes.sexo[0] == 'M') {
            fprintf(fileM, "<%s, %c, %d/%d/%d, %d/%d/%d>\n", i->pacientes.nome , i->pacientes.sexo[0], i->pacientes.nascimento.dia, i->pacientes.nascimento.mes, i->pacientes.nascimento.ano, i->pacientes.ultimaConsulta.dia, i->pacientes.ultimaConsulta.mes, i->pacientes.ultimaConsulta.ano);
        }
    }
}

///////////////////////////////////////////////////////////////////
// FUNCOES DO PROGRAMA

int getSexo(Pacientes pacientes) {
    if (strcmp(pacientes.sexo, "M")) {
        return 0;
    } else {
        return 1;
    }
}

// int getData(Pacientes paciente) {
//     struct tm *data;
//     time_t tm;
//     time(&tm);
//     data = localtime(&tm);
//     int ultimaConsulta = 0;
//
//     printf("Dia do ano: %d\n", data->tm_yday);
//     printf("Data: %d/%d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);
// }

void pesquisarPaciente(Lista pacientes, char *nome) {
    NoLista *aux =  pacientes.inicio;
    while (aux != NULL)
    {
        if (strcmp(aux->pacientes.nome, nome) == 0) {
            //getData(aux->pacientes);
            printf("Paciente encontrado:\n");
            printf("<%s, %c, %d/%d/%d, %d/%d/%d>\n", aux->pacientes.nome, aux->pacientes.sexo[0], aux->pacientes.nascimento.dia, aux->pacientes.nascimento.mes, aux->pacientes.nascimento.ano, aux->pacientes.ultimaConsulta.dia, aux->pacientes.ultimaConsulta.mes, aux->pacientes.ultimaConsulta.ano);
            return;
        }
        aux = aux->proximo;
    }
    printf("Paciente nao encontrado\n");
}

Lista inserirPaciente(Lista *pacientes) {
    Pacientes aux;
    printf("Nome: ");
    setbuf(stdin, NULL);
    fgets(aux.nome, 50, stdin);
    aux.nome[strcspn(aux.nome, "\n")] = '\0';
    printf("Sexo: ");
    scanf("%c", &aux.sexo[0]);
    aux.sexo[0] = toupper(aux.sexo[0]);
    printf("Nascimento\nDia: ");
    scanf("%d", &aux.nascimento.dia);
    printf("Mes: ");
    scanf("%d", &aux.nascimento.mes);
    printf("Ano: ");
    scanf("%d", &aux.nascimento.ano);
    printf("Ultima consulta\nDia: ");
    scanf("%d", &aux.ultimaConsulta.dia);
    printf("Mes: ");
    scanf("%d", &aux.ultimaConsulta.mes);
    printf("Ano: ");
    scanf("%d", &aux.ultimaConsulta.ano);
    inserirLista(pacientes, aux);
}

void menuSistema(Lista pacientes, FILE *saidaF, FILE *saidaM) {
    while(1) {
        int op; //opcao
        printf("Digite sua opcao:\n (1) - Inserir paciente\n (2) - Pesquisar paciente\n (3) - Mostrar pacientes\n (4) - Sair do sistema\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inserirPaciente(&pacientes);
            break;
        case 2:
            char nome[50];
            printf("Digite o nome do paciente que deseja buscar: ");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            pesquisarPaciente(pacientes, nome);
            break;
        case 3:
            printf("\n\nLISTAS\n");
            imprimirLista(&pacientes);
            break;
        case 4:
            sv_file(saidaM, saidaF, &pacientes);
            return;
            break;

        default:
            printf("Opcao invalida! Digite novamente\n");
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    //Variaveis de arquivos
    FILE *entrada = op_file("pacientes.txt");
    FILE *saidaF = cr_file("ginecologita.txt");
    FILE *saidaM = cr_file("andrologista.txt");
    //Variaveis de lista
    Lista pacientes;
    //Inicializando listas
    inicializarLista(&pacientes);
    //Lendo arquivo
    rd_file(entrada, &pacientes);
    //menu
    menuSistema(pacientes, saidaF, saidaM);
    //Destruindo listas
    destroiLista(&pacientes);
    //Fechando arquivos
    fclose(entrada);
    fclose(saidaF);
    fclose(saidaM);
    return EXIT_SUCCESS;
}