#ifndef __READQRY_H__
#define __READQRY_H__
#include "includes.h"

/* Esta funcao e resposavel pela leitura do arquivo .qry
ela lê o arquivo, e chama as funções para solucionar os comandos lidos,
apos isso gera um arquivo txt com os dados do geo e do qry,
para realizar isto ela recebe como parametro o nome do arquivo
a ser lido, o local de saida do arquivo gerado e as listas */
void leituraQry(char saida[],char arquivotxt[], char qry[], Lista lista, Lista *listas, Pilha *pilhas,Fila *filas);

#endif