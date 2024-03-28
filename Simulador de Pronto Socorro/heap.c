#include "includes.h"
#define MAX_SIZE 50


typedef struct HeapStruct{
    DATA data[MAX_SIZE];
    int qtd;
}Heap;


HEAP createHeap(){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->qtd = 0;
    return heap;
}

void upInfo(HEAP heap, int son){
    Heap *h = (Heap*) heap;
    DATA *aux;

    int father = (son - 1) / 2;
    while ((son > 0) && getGravidade(h->data[father]) > getGravidade(h->data[son])){
        aux = h->data[son];
        h->data[son] = h->data[father];
        h->data[father] = aux;
        son = father;
        father = (father - 1) / 2;
    }
    
}

int insertInfo(HEAP *heap, DATA info){
    Heap *h = (Heap*) heap;
    if(h == NULL || h->qtd == MAX_SIZE){
        return 0;
    }
    h->data[h->qtd] = info;
    upInfo(heap, h->qtd);
    h->qtd++;
    return 1;
}

void downInfo(HEAP heap, int father){
    Heap *h = (Heap*) heap;
    DATA *aux;

    int son = 2 * father + 1;
    while (son < h->qtd){
        if(son < h->qtd-1 && getGravidade(h->data[son]) > getGravidade(h->data[son+1])){
            son++;
        }
        if(getGravidade(h->data[father]) <= getGravidade(h->data[son])){
            break;
        }

        aux = h->data[father];
        h->data[father] = h->data[son];
        h->data[son] = aux;

        father = son;
        son = 2 * father + 1;
    }
    

}

void removeInfo(HEAP heap){
    Heap *h = (Heap*) heap;
    DATA *aux;
    if(h == NULL || h->qtd == 0){
        printf("Não existem pacientes para serem atendidos\n");
        return;
    }
    h->qtd--;
    aux = h->data[0];
    h->data[0] = h->data[h->qtd];
    free(aux);
    downInfo(heap, 0);
}

void ListPatients(HEAP heap){
    Heap *h = (Heap *) heap;
    if(h->qtd == 0){
        printf("Não existem pacientes cadastrados\n");
    }
    printf("Prioridade -  Nome - Data de Nascimento - Sexo\n");
    for(int i = 0; i < h->qtd; i++){
        printf("%d - %s - %s - %s - %s\n",getGravidade(h->data[i]) ,getNome(h->data[i]), getSobrenome(h->data[i]), getData(h->data[i]), getSexo(h->data[i]));
    }
    
}

DATA getFirst(HEAP heap){
    Heap *h = (Heap*) heap;
    if(h == NULL || h->qtd == 0){
        return NULL;
    }else{
        return h->data[0];
    }
}

DATA Find(HEAP heap,char *nome,char *sobrenome){
    Heap * h = (Heap *) heap;

    if(h == NULL || h->qtd == 0){
        return NULL;
    }

    for(int i = 0; i < h->qtd; i++){
        if(strcmp(getNome(h->data[i]), nome) == 0
         && strcmp(getSobrenome(h->data[i]), sobrenome) == 0){
             PrintPatient(h->data[i]);
             return h->data[i];
         }
    }

    return NULL;
}

void destroyHeap(HEAP heap){
    Heap *h = (Heap*) heap;
    DATA *aux;

    if(h->qtd == 0){
        printf("Não existem pacientes cadastrados\n");
    }
    for(int i = h->qtd; i > 0; i--){
        aux = h->data[0];
        h->qtd = i;
        PrintPatient(h->data[0]);
        h->data[0] = h->data[i-1];
        free(aux);
        downInfo(heap, 0);
    }
    free(h);
}