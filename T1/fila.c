#include "includes.h"

typedef struct Node{
    Info info;
    struct Node *proximo;    
}NoFila;

typedef struct {
    struct Node *inicio, *fim;
    int Length;
}FilaStruct;

Fila criaFila(){
    FilaStruct* fila = (FilaStruct*) malloc(sizeof(FilaStruct));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->Length = 0;
    return fila;
}

No getPrimeiroFila(Fila fila){
    FilaStruct* f = (FilaStruct*) fila;
    return f->inicio;
}

void insereNaFila(Info info, Fila fila){
    struct Node* no = (struct Node*) malloc(sizeof(struct Node)), *aux;
    FilaStruct* f = (FilaStruct*) fila;
    
    no->info = info;
    no->proximo = NULL;

    if(filaLength(fila) == 0){
        f->inicio = no;
        f->fim = no;
        f->Length++;
    }else{
        aux = f->fim;
        aux->proximo = no;
        f->fim = no;
        f->Length++;
    }   
    
}

void removeDaFila( Fila fila){
    FilaStruct* f = (FilaStruct*) fila;
    struct Node* aux = f->inicio;
    
    if(filaLength(fila) > 0){
        if(filaLength(filaLength) > 1){
            f->inicio = aux->proximo;
        }
        if(getForma(aux->info) == 'l'){
            free(getPonto2(aux->info));
        }
        free(getPontoFormas(aux->info));
        free(aux->info);
        free(aux);
        f->Length--;
    }
}

Info getInfoFila(No elemento){
    struct Node* no = (struct Node*) elemento;
    return no->info;
}

int filaLength(Fila fila){
    FilaStruct* f = (FilaStruct*) fila;
    return f->Length;
}

void desalocaFila(Fila fila){
    FilaStruct* f = (FilaStruct*) fila;
    struct Node* aux = f->inicio, *aux2;

    while (filaLength(fila) > 0) {
        aux2 = aux;
        aux = aux->proximo;
        if(getForma(aux2->info) == 'l'){
            free(getPonto2(aux2->info));
        }
        free(getPontoFormas(aux2->info));
        free(aux2->info);
        free(aux2);
    }
    free(f);
}