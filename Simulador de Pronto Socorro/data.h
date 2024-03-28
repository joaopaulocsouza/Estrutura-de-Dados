#ifndef __DATA_H__
#define __DATA_H__

typedef void *DATA;

void header();

int getGravidade(DATA data);

char *getNome(DATA data);

char *getSobrenome(DATA data);

char *getData(DATA data);

char *getSexo(DATA data);

void RegisterPatient(HEAP *heap);

void PrintPatient(DATA data);

void ReadFile(HEAP *heap);

#endif