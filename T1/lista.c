#include "includes.h"

typedef struct node{
    Info info;
    struct node *anterior;
    struct node *proximo;
} NoStruct;

typedef struct lista{
    NoStruct *primeiro;
    NoStruct *ultimo;
} ListaStruct;


Lista criaLista(){
    ListaStruct* lista = (ListaStruct*) malloc(sizeof(ListaStruct));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
};

No insere(Lista l, Info info){

    ListaStruct* lista = (ListaStruct*) l;

    NoStruct* no = (NoStruct*) malloc(sizeof(NoStruct));
    no->info = info;

    if(lista->primeiro == NULL){
        no->anterior = NULL;
        lista->primeiro = no;
    }
    else{
        lista->ultimo->proximo = no;
        no->anterior = lista->ultimo;
    }

    no->proximo = NULL;
    lista->ultimo = no;

    return no;
    
}

No insertAfter(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (getInfo(aux)==posicao){
            if(lista->ultimo == aux){
                lista->ultimo = no;
            }else{
                aux->proximo->anterior = no;
            }
            no->proximo = aux->proximo;
            no->anterior = aux;
            aux->proximo = no;
        }
        aux = getNext(aux);
    }

    return no;
    
}


No insertBefore(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (getInfo(aux)==posicao){
            no->proximo = aux;
            no->anterior = aux->anterior;
            aux->anterior = no;
            if (no->anterior == NULL){
                lista->primeiro = no;
            }else{
                no->anterior->proximo = no;
            }
                 
        }
        aux = aux->proximo;
    }

    return no;
}

int length(Lista l){
    No node = getFirst(l);
    int i = 0; 

    while (node!=NULL){
        i++;
        node = getNext(node);
    }
    
    return i;
}


No getFirst(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->primeiro;
}

No getLast(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->ultimo;
}

No getNext(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->proximo;
}

No getPrevious(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->anterior;
}

Info getInfo(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->info;
}

void desalocaLista(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;

    aux = lista->primeiro;

    while (aux!=NULL){
        aux2 = aux->proximo;
        if('l' == getForma(aux->info)){
            free(getPonto2(aux->info));
        }
        free(getPontoFormas(aux->info));
        free(aux->info);
        free(aux);
        aux = aux2;
    }
    free(lista);
}

void desalocaListaQRY(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;

    aux = lista->primeiro;

    while (aux!=NULL){
        aux2 = aux->proximo;
        free(aux->info);
        free(aux);
        aux = aux2;
    }
    free(lista);
}

void removeElemento(Lista l, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;
    aux = lista->primeiro;
    
    while (aux!=NULL){
        if(aux->info == info){
            if (aux==lista->primeiro){
                lista->primeiro = aux->proximo;
                aux->proximo->anterior = NULL;
            }else if(aux==lista->ultimo){
                lista->ultimo = aux->anterior;
                aux->anterior->proximo = NULL;
                
            }else{
                aux2 = aux->proximo;
                aux2->anterior = aux->anterior;
                if(aux2->proximo != NULL){
                    aux2->proximo->anterior = aux2;
                }

                if(aux->anterior!=NULL){
                    aux->anterior->proximo = aux2;
                }
            }
            if('l' == getForma(aux->info)){
                free(getPonto2(aux->info));
            }
            free(getPontoFormas(aux->info));
            free(aux->info);
            free(aux);
            break;
         }
        aux = aux->proximo;
    }  
}

void removeElementoQRY(Lista l, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;
    aux = lista->primeiro;
    
    while (aux!=NULL){
        if(aux->info == info){
            if (aux==lista->primeiro){
                lista->primeiro = aux->proximo;
                aux->proximo->anterior = NULL;
            }else if(aux==lista->ultimo){
                lista->ultimo = aux->anterior;
                aux->anterior->proximo = NULL;
            }else{
                aux2 = aux->proximo;
                aux2->anterior = aux->anterior;
                aux2->proximo->anterior = aux2;

                if(aux->anterior!=NULL){
                    aux->anterior->proximo = aux2;
                }
            }
            free(aux->info);
            free(aux);
            break;
         }
        aux = aux->proximo;
    }  
}

void esvaziaLista(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    No aux, aux2;

    aux = getFirst(l);

    while (aux != NULL){
        aux2 = aux;
        aux = getNext(aux);
        if('l' == getForma(getInfo(aux2))){
            free(getPonto2(getInfo(aux2)));
        }
        free(getPontoFormas(getInfo(aux2)));
        free(getInfo(aux2));
        free(aux2);
    }

    lista->ultimo = NULL;
    lista->primeiro = NULL;
    
}