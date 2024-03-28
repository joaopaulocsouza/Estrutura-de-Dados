#ifndef __PILHA_H__
#define __PILHA_H__
#include "includes.h"

typedef void* Pilha;

/* está funcao cria e retorna uma pilha */
Pilha criaPilha();

/* está funcao insere um elemento na pilha,
ela recebe como parametro a informacao e a pilha */
void insereNaPilha(Info info, Pilha pilha);

/* está funcao remove um elemento na pilha,
ela recebe como parametro a pilha */
void removeDaPilha(Pilha pilha);

/* está funcao retorna o tamanho de uma pilha,
ela recebe como parametro a pilha */
int pilhaLength(Pilha pilha);

/* está funcao retorna o topo de uma pilha,
ela recebe como parametro a pilha */
No getTopo(Pilha pilha);

/* está funcao retorna o dado de um nó.
ela recebe como parametro um nó */
Info getInfoPilha(No elemento);

/* está funcao desaloca uma pilha.
ela recebe como parametro a pilha */
void desalocaPilha(Pilha pilha);

#endif