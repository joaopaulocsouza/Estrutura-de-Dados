#include "includes.h"

typedef struct Node{
    Info info;
    struct Node *proximo, *anterior;    
}PilhaNo;

typedef struct {
    struct Node *topo;
    int Length;
}PilhaStruct;

Pilha criaPilha(){
    PilhaStruct* pilha = (PilhaStruct*) malloc(sizeof(PilhaStruct));
    pilha->topo = NULL;
    pilha->Length = 0;
    return pilha;
}

void insereNaPilha(Info info, Pilha pilha){
    struct Node* no = (struct Node*) malloc(sizeof(struct Node));
    PilhaStruct* p = (PilhaStruct*) pilha;
    no->info = info;
    if (p->topo == NULL){
        no->proximo = NULL;
        no->anterior = NULL;
        p->topo = no;
        p->Length++;
    }else{
        no->proximo = p->topo;
        no->proximo->anterior = no;
        p->topo = no;
        p->Length++;
    }
    
}

void removeDaPilha(Pilha pilha){
    PilhaStruct* p = (PilhaStruct*) pilha;
    struct Node* aux = p->topo;

    if(pilhaLength(pilha) > 0){
        if(pilhaLength(pilha) > 1){
            p->topo = aux->proximo;
            aux->proximo->anterior = NULL;
        }
        if(getForma(aux->info) == 'l'){
            free(getPonto2(aux->info));
        }
        free(getPontoFormas(aux->info));
        free(aux->info);
        free(aux);
        p->Length--; 
    }  
    
}

No getTopo(Pilha pilha){
    PilhaStruct* p = (PilhaStruct*) pilha;
    return p->topo;
}

Info getInfoPilha(No elemento){
    struct Node* no = (struct Node*) elemento;
    return no->info;
}

int pilhaLength(Pilha pilha){
    PilhaStruct* p = (PilhaStruct*) pilha;
    return p->Length;
}

void desalocaPilha(Pilha pilha){
    PilhaStruct* p = (PilhaStruct*) pilha;
    struct Node* aux = p->topo, *aux2 = aux;

    while (pilhaLength(pilha) > 0){
        aux2 = aux;
        if(pilhaLength(pilha) > 1){
            aux = aux->proximo;
        }
        if(getForma(aux2->info) == 'l'){
            free(getPonto2(aux2->info));
        }
        free(getPontoFormas(aux2->info));
        free(aux2->info);
        free(aux2);
        p->Length--;
    }
    
    free(p);
}