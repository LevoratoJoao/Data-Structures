#ifndef tabelaHash
#define tabelaHash

typedef struct tabela_hash TabelaHash;
typedef char* String;

TabelaHash *inicializarTable();
int estaVazia(TabelaHash *table);
int estaCheia(TabelaHash *table);
int hash(int k);
void inserirElemento(TabelaHash *table, int k, char *name);
void imprimirTabelaHash(TabelaHash *table);
int pesquisarElemento(TabelaHash *table, int chave);
String getElemento(TabelaHash *table, int chave);
int removerTabelaHash(TabelaHash *table, int chave);
void destroiTabelaHash(TabelaHash *table);

#endif