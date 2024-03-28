#ifndef __LISTA_H__
#define __LISTA_H__

typedef void *Lista;
typedef void *No;
typedef void *Info;

/* Esta funcao cria as listas utilizadas no projeto
ela nao recebe nenhum parametro, ela apenas retorna as listas
inicializadas */
Lista criaLista();

/* Esta funcao insere elementos nas listas
ela recebe como parametro a lista e o elemento que sera adicionado na lista */
No insere(Lista l, Info info);

/* Esta funcao insere um elemento depois de outro elemento
   ela recebe como parametro a lista, o elemento que servirá
   de base para a inserção e o novo elemento */
No insertAfter(Lista l, Info posicao, Info info);

/* Esta funcao insere um elemento antes de outro elemento
   ela recebe como parametro a lista, o elemento que servirá
   de base para a inserção e o novo elemento */
No insertBefore(Lista l, Info posicao, Info info);

/* Esta funcao retorna a quantidade de elementos contidos em uma lista
para realizar esta tarefa ela recebe uma lista por parametro*/
int length(Lista l);

/* Esta funcao remove elementos nas listas
ela recebe como parametro a lista e o elemento que sera removido da lista */
void removeElemento(Lista l, Info info);

/* Esta funcao localiza e retorna o primeiro elemento contido na lista
ele recebe como parametro a lista
e retorna seu primeiro elemeno */  
No getFirst(Lista lista);

/* Esta funcao localiza e retorna o ultimo elemento contido na lista
ele recebe como parametro a lista
e retorna seu ultimo elemeno */  
No getLast(Lista lista);

/* Esta funcao localiza e retorna o promixo elemento contido na lista
ele recebe como parametro um elemento da lista
e retorna o elemeno sucessor ao recebido*/ 
No getNext(No elemento);

/* Esta funcao localiza e retorna o anterior elemento contido na lista
ele recebe como parametro um elemento da lista
e retorna o elemeno antecessor ao recebido*/ 
No getPrevious(No elemento);

/* Esta funcao retorna as informacoes um elemento da lista
ela recebe como parametro um elemento da lista
e retorna as informações deste elemento*/ 
No getInfo(No elemento);

/* Esta funcao retorna desaloca uma lista
ela recebe como a lista
e retorna não tem retorno*/ 
void desalocaLista(Lista l);

/* Esta funcao retorna desaloca uma lista
ela recebe como a lista
e retorna não tem retorno*/ 
void desalocaListaQRY(Lista l);

/* Esta funcao retorna remove um elemento da lista
ela recebe como a lista, e a informação
e retorna não tem retorno*/ 
void removeElemento(Lista l, Info info);

/* Esta funcao retorna remove um elemento da lista
ela recebe como a lista, e a informação
e retorna não tem retorno*/ 
void removeElementoQRY(Lista l, Info info);

/* Esta funcao retorna esvazia uma lista
ela recebe como a lista
e retorna não tem retorno*/ 
void esvaziaLista(Lista l);

#endif