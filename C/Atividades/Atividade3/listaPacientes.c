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
    char nome[100];
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
} NoLista;

typedef struct listaEncadeada {
    NoLista *inicio;
    int numElemento;
} Lista;

/**
 * @brief Inicializa lista
 *
 * @param list
 */
void inicializarLista(Lista *list) {
    list->inicio = NULL;
    list->numElemento = 0;
}

/**
 * @brief Verifica se a lista esta vazia
 *
 * @param list
 * @return int
 */
int estaVazia(Lista *list) {
    if (list->numElemento == 0) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * @brief Funcao para inserco na lista de forma duplamente encadeada
 *
 * @param list
 * @param pacientes
 */
void inserirLista(Lista *list, Pacientes pacientes) {
    if (getSexo(pacientes)) {
        NoLista *novo;
        novo = (NoLista*) malloc(sizeof(NoLista));
        novo->pacientes = pacientes;
        novo->proximo = NULL;
        if(estaVazia(list) == 0) {
            list->inicio = novo;
        } else if(strcmp(pacientes.nome, list->inicio->pacientes.nome) > 0) {
            novo->proximo = list->inicio;
            list->inicio = novo;
        } else {
            NoLista *aux = list->inicio;
            while (aux->proximo != NULL && strcmp(aux->proximo->pacientes.nome, pacientes.nome) > 0) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        list->numElemento++;
    } else {
        NoLista *novo;
        novo = (NoLista*) malloc(sizeof(NoLista));
        novo->pacientes = pacientes;
        novo->proximo = NULL;
        if(estaVazia(list) == 0) {
            list->inicio = novo;
        } else if(strcmp(pacientes.nome, list->inicio->pacientes.nome) < 0) {
            novo->proximo = list->inicio;
            list->inicio = novo;
        } else {
            NoLista *aux = list->inicio;
            while (aux->proximo != NULL && strcmp(aux->proximo->pacientes.nome, pacientes.nome) < 0) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        list->numElemento++;
    }
}

/**
 * @brief Funcao para destruir a lista liberando memoria
 *
 * @param list
 */
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
void rd_file(FILE *file, Lista *pacientesMasculino, Lista *pacientesFeminino) {
    Pacientes n; //Objeto auxiliar
    char aux[100]; //Variavel de leitura auxiliar
    while (fgets(aux, 100, file) != NULL) { // acaba o loop ao final do arquivo
        sscanf(aux, "<%[^,], %[^,], %d/%d/%d, %d/%d/%d>\n", &n.nome, &n.sexo, &n.nascimento.dia, &n.nascimento.mes, &n.nascimento.ano, &n.ultimaConsulta.dia, &n.ultimaConsulta.mes, &n.ultimaConsulta.ano); //Formatacao dos dados armazenados na variavel auxiliar, eles sao armazenados em uma variavel auxiliar do tipo do objeto que é usada para inserir na fila
        if (getSexo(n)) {
            inserirLista(pacientesMasculino, n);
        } else {
            inserirLista(pacientesFeminino, n);
        }
    }
}

/**
 * @brief Save file - funcao para salvar as informacoes da variavel no arquivo
 *
 * @param fileF
 * @param fileM
 * @param listaF
 * @param listaM
 * @return FILE
 */
FILE sv_file(FILE *fileF, FILE *fileM, Lista *listaF, Lista *listaM) {
    for (NoLista *i = listaF->inicio; i != NULL; i = i->proximo) { //Percorre lista F
        fprintf(fileF, "<%s, %c, %d/%d/%d, %d/%d/%d>\n", i->pacientes.nome , i->pacientes.sexo[0], i->pacientes.nascimento.dia, i->pacientes.nascimento.mes, i->pacientes.nascimento.ano, i->pacientes.ultimaConsulta.dia, i->pacientes.ultimaConsulta.mes, i->pacientes.ultimaConsulta.ano);
    }
    for (NoLista *i = listaM->inicio; i != NULL; i = i->proximo) { //Percorre lista M
        fprintf(fileM, "<%s, %c, %d/%d/%d, %d/%d/%d>\n", i->pacientes.nome , i->pacientes.sexo[0], i->pacientes.nascimento.dia, i->pacientes.nascimento.mes, i->pacientes.nascimento.ano, i->pacientes.ultimaConsulta.dia, i->pacientes.ultimaConsulta.mes, i->pacientes.ultimaConsulta.ano);
    }
}

///////////////////////////////////////////////////////////////////
// FUNCOES DO PROGRAMA

/**
 * @brief Funcao para saber qual sexo do paciente (retorna 1 de masculo e 0 se feminino)
 *
 * @param pacientes
 * @return int
 */
int getSexo(Pacientes pacientes) {
    if (strcmp(pacientes.sexo, "M")) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * @brief Esta funcao realiza os calculos necessarios para se saber qual a quantidade de dias que se passaram desde a ultima consulta de um determinado paciente (desconsidera anos bissextos)
 *
 * @param paciente
 * @return int
 */
int getData(Pacientes paciente) {
    struct tm *data; //var tipo da struct tm (time.h)
    time_t tm; //var tipo time_t para funcoes da time.h
    time(&tm); //retorna time atual e armazena no timer (tm)
    data = localtime(&tm); //var do tipo da struct recebe todos os dados de tm formatados para o localtime
          //meses =  01  02  03  04  05  06  07  08  09  10  11  12
    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Vetor dos meses com seus respectivos dias
    int ultimaConsulta = 0;
    int ano = ((data->tm_year + 1900) - paciente.ultimaConsulta.ano) * 365; //calc da diferenca dos anos (atual - ultima consulta)
    int dia = data->tm_mday - paciente.ultimaConsulta.dia; //calc da diferenca dos dias (dia atual - ultima consulta)
    int mes = 0;
    int subMes = (data->tm_mon + 1) - paciente.ultimaConsulta.mes; //calc da diferenca do mes (mes atual - ultima consulta)
    if (subMes > 0) { //Mes atual > mes da ultima consulta
        //Como mes da ultima consulta é menor que o atual é ele que usaremos para percorrer os meses ate o atual
        int mesAux = paciente.ultimaConsulta.mes;
        while (mesAux != (data->tm_mon + 1)) {
            mes = mes + meses[mesAux]; //Somatorio dos meses
            mesAux++;
        }
    } else { //Mes atual < mes da ultima consulta
        //Como mes atual é menor que o da ultima consulta é ele que usaremos para percorrer os meses ate o da ultima consulta
        int mesAux = data->tm_mon + 1;
        while (mesAux != paciente.ultimaConsulta.mes) {
            mes = mes - meses[mesAux]; //Como mes atual < da ultima consulta seu somatorio sera de forma negativa
            mesAux++;
        }
    }
    ultimaConsulta = ano + dia + mes; //Soma total
    return ultimaConsulta;
}

/**
 * @brief Esta funcao realiza o calculo da idade de um determinado paciente
 *
 * @param paciente
 * @return int
 */
int getAge(Pacientes paciente) {
    struct tm *data; //var tipo da struct tm (time.h)
    time_t tm; //var tipo time_t para funcoes da time.h
    time(&tm); //retorna time atual e armazena no timer (tm)
    data = localtime(&tm); //var do tipo da struct recebe todos os dados de tm formatados para o localtime
    int idade = ((data->tm_year + 1900) - paciente.nascimento.ano);
    if (data->tm_mon < paciente.nascimento.mes) { //Se mes atual é menor que mes de nascimento entao paciente nao fez aniversario ainda
        return (idade - 1);
    } else if (data->tm_mon == paciente.nascimento.mes) { //Se mes atual é igual a mes de nascimento entao paciente pode ou nao ter feito aniversario
        if (data->tm_mday < paciente.nascimento.dia) { //Se dia atual é menor que dia do nascimento entao paciente nao fez aniversario ainda
            return (idade - 1);
        } else {
            return idade;
        }
    } else {
        return idade;
    }
}

/**
 * @brief Funcao para pesquisar um paciente e ver se esta dentro da lista, se estiver é mostrado também quandos dias desde a ultima consulta
 *
 * @param pacientesMasculino
 * @param pacientesFeminino
 * @param nome
 */
void pesquisarPaciente(Lista pacientesMasculino, Lista pacientesFeminino, char *nome) {
    NoLista *auxM =  pacientesMasculino.inicio;
    NoLista *auxF =  pacientesFeminino.inicio;
    //getData(auxM->pacientes);
    while (auxM != NULL)
    {
        if (strcmp(auxM->pacientes.nome, nome) == 0) {
            printf("Paciente %s encontrado(a): idade %d - Ultima consulta realizada foi a %d dias\n", auxM->pacientes.nome, getAge(auxM->pacientes), getData(auxM->pacientes));
            return;
        }
        auxM = auxM->proximo;
    }
    while (auxF != NULL)
    {
        if (strcmp(auxF->pacientes.nome, nome) == 0) {
            printf("Paciente %s encontrado(a): idade %d - Ultima consulta realizada foi a %d dias\n", auxF->pacientes.nome, getAge(auxF->pacientes), getData(auxF->pacientes));
            return;
        }
        auxF = auxF->proximo;
    }
    printf("Paciente nao encontrado\n");
}

/**
 * @brief Funcao para insercao de novo paciente no sistema e na lista.
 *
 * @param pacientesMasculino
 * @param pacientesFeminino
 */
void inserirPaciente(Lista *pacientesMasculino, Lista *pacientesFeminino) {
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
    if(getSexo(aux)) {
        inserirLista(pacientesMasculino, aux);
    } else {
        inserirLista(pacientesFeminino, aux);
    }
}

/**
 * @brief Menu do sistema, contem todas as chamadas das funcoes principais
 *
 * @param pacientesMasculino
 * @param pacientesFeminino
 * @param saidaF
 * @param saidaM
 */
void menuSistema(Lista pacientesMasculino, Lista pacientesFeminino, FILE *saidaF, FILE *saidaM) {
    while(1) {
        int op; //opcao
        printf("Digite sua opcao:\n (1) - Inserir paciente\n (2) - Pesquisar paciente\n (3) - Sair do sistema\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            inserirPaciente(&pacientesMasculino, &pacientesFeminino);
            break;
        case 2:
            char nome[50];
            printf("Digite o nome do paciente que deseja buscar: ");
            setbuf(stdin, NULL);
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            pesquisarPaciente(pacientesMasculino, pacientesFeminino, nome);
            break;
        case 3:
            sv_file(saidaM, saidaF, &pacientesFeminino, &pacientesMasculino);
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
    FILE *entrada = op_file(argv[1]);
    FILE *saidaF = cr_file(argv[2]);
    FILE *saidaM = cr_file(argv[3]);
    //Variaveis de lista
    Lista pacientesMasculino;
    Lista pacientesFeminino;
    //Inicializando listas
    inicializarLista(&pacientesFeminino);
    inicializarLista(&pacientesMasculino);
    //Lendo arquivo
    rd_file(entrada, &pacientesMasculino, &pacientesFeminino);
    //menu
    menuSistema(pacientesMasculino, pacientesFeminino, saidaF, saidaM);
    //Destruindo listas
    destroiLista(&pacientesFeminino);
    destroiLista(&pacientesMasculino);
    //Fechando arquivos
    fclose(entrada);
    fclose(saidaF);
    fclose(saidaM);
    return EXIT_SUCCESS;
}