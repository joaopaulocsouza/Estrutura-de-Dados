#include "includes.h"

typedef struct Point{
    double x, y;
}PontoStruct;

Ponto criaPonto(double x, double y){
    PontoStruct* ponto = (PontoStruct*) malloc(sizeof(PontoStruct));
    ponto->x = x;
    ponto->y = y;

    return ponto;
}

double getXPonto(Ponto ponto){
    PontoStruct* p = (PontoStruct*) ponto;
    return p->x;
}

double getYPonto(Ponto ponto){
    PontoStruct* p = (PontoStruct*) ponto;
    return p->y;
}

Ponto getPonto(Ponto ponto){
    PontoStruct* p = (PontoStruct*) ponto;
    return p;
}
