#ifndef __HEAP_H__
#define __HEAP_H__
#include "includes.h"
typedef void *HEAP;
typedef void *DATA;

HEAP createHeap();

int insertInfo(HEAP *heap, DATA info);

void removeInfo(HEAP heap);

void ListPatients(HEAP heap);

void destroyHeap(HEAP heap);

DATA Find(HEAP heap,char *nome,char *sobrenome);

#endif
