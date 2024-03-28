#ifndef __QRY1FASE_H__
#define __QRY1FASE_H__
#include "includes.h"

char getTipoQRY(Info elemento);

double getYQRY(Info elemento);

double getXQRY(Info elemento);

double getY2QRY(Info elemento);

double getX2QRY(Info elemento);

int getIdQRY(Info elemento);

double getRaioQRY(Info elemento);

double getScaleQRY(Info elemento);

char *getCorQRY(Info elemento);

void criaCirculo(Lista l, double raio, double x, double y, char cor[]);

void criaLinha(double x, double y, double x2, double y2, char cor[], Lista lista);

void criaTexto(double x, double y, int id, Lista lista);

/* esta funcao retorna o maior valor, recebido
ele rebece dois valores double por paremetro*/
double max(double x1, double x2);

/* esta funcao retorna o menor valor, recebido
ele rebece dois valores double por paremetro*/
double min(double x1, double x2);

/* esta funcao retorna a distancia entre dois pontos,
ele rebece os dados dos pontos por paremetro*/
double dist(double x1, double y1, double x2, double y2);

bool PontoInternoCirc(double x1, double y1, double x2, double y2, double raio);

bool PontoInternoRet(double px, double py, double x, double y, double h, double w);

bool sobreposicaoCirc(double x1, double y1, double r1, double x2, double y2, double r2);

bool sobreposicaoCircRet(double cx, double cy, double rx, double ry, double raio, double w, double h);

bool sobreposicaoRet(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2);

/* esta funcao resolve o comando o?
ela recebe como parametro a lista, os dados lidos do comando o?
e o nome arquivo do txt junto ao seu diretório*/
void oFormas(int j, int k, int id,char cor1[], char cor2[],Lista lista, Lista listaQRY,char txt[]);

/* esta funcao resolve o comando i?
ela recebe como parametro a lista, os dados lidos do comando i?
e o nome arquivo do txt junto ao seu diretório*/
void iFormas(int j, double x, double y, Lista lista, Lista listaQRY, char txt[]);


/* esta funcao resolve o comando pnt
ela recebe como parametro a lista, os dados lidos do comando pnt
e o nome arquivo do txt junto ao seu diretório*/
void pnt(int j, char stroke[], char fill[], Lista lista, char txt[]);

/* esta funcao resolve o comando delf
ela recebe como parametro a lista, os dados lidos do comando delf
e o nome arquivo do txt junto ao seu diretório*/
void delf(int j, Lista lista, char txt[]);

void psh(int i, Lista lista,Pilha pilha);

void pop(int i, double dx, double dy, double prop, Pilha pilha, Lista lista);

void inf(int i, Lista lista,Fila fila);

void rmf(int i, double dx, double dy, double prop, Fila fila, Lista lista);

No ii(int i, No registrador, Lista l, Lista lista);

No ifc(int i, No registrador, Lista l, Lista lista);

No ia(int i, No ro, No rd, Lista l, Lista lista);

No id(int i, No ro, No rd, Lista l, Lista lista);

void da(No registrador,Lista l);

void dd(No registrador,Lista l);

void dpl(int i, double dx,double dy,double prop,double incprop, Lista l, Lista lista);

#endif