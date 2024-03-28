#ifndef _FILA_H_
#define _FILA_H_
#include "includes.h"

typedef void* Fila;

/*Esta funcão aloca e retorna uma fila */
Fila criaFila();

/*Esta funcão insere um elemento na fila,
como parametro ela recebe o dado e a fila */
void insereNaFila(Info info, Fila fila);

/*Esta funcão remove um elemento na fila,
como parametro ela recebe a fila */
void removeDaFila(Fila fila);

/*Esta funcão retorna o primeiro elemento da fila,
como parametro ela recebe a fila */
No getPrimeiroFila(Fila fila);

/*Esta funcão retorna o tamanho da fila,
como parametro ela recebe a fila */
int filaLength(Fila fila);

/*Esta funcão retorna o dado de um nó,
como parametro ela recebe o nó*/
Info getInfoFila(No elemento);

/*Esta funcão desaloca a fila,
como parametro ela recebe a fila*/
void desalocaFila(Fila fila);

#endif