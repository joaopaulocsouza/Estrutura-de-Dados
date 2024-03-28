#include "includes.h"

typedef struct f{
    int id;
    Ponto ponto, ponto2;
    double raio, w, h, x, y, x2, y2, scale;
    char corb[20], corp[20], texto[100],forma;
}formasStruct;

void imprimeCirculo(double raio, double x, double y, double scale, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um circulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" transform=\"scale(%lf)\"/>", x, y, raio, corp, corb, scale);

    fclose(arqsvg);    
}

void imprimeRetangulo(double width, double heigth, double x, double y, double scale, char corb[], char corp[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Retangulo!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" transform=\"scale(%lf)\"/>", x, y, width, heigth, corp, corb, scale);

    fclose(arqsvg);
}

void imprimeTexto(double x, double y, double scale, char corb[],char corp[], char texto[],char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Texto!");
        exit(1);
    }

    fprintf(arqsvg, "\n\t<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" transform=\"scale(%lf)\">%s</text>", x, y,corp, corb,scale, texto);

    fclose(arqsvg);
}

Formas circuloLista(int id, double raio, double x, double y, double scale,  char corb[], char corp[]){
    formasStruct* circ = (formasStruct*) malloc(sizeof(formasStruct));

    circ->id = id;
    circ->raio = raio;
    circ->ponto = criaPonto(x,y);
    circ->scale = scale;
    strcpy(circ->corb,corb);
    strcpy(circ->corp,corp);
    circ->forma = 'c';

    return circ;
}

Formas linhaLista(int id, double x1, double y1, double x2, double y2, double scale,char cor[]){
    formasStruct* lin = (formasStruct*) malloc(sizeof(formasStruct));

    lin->id = id;
    lin->ponto = criaPonto(x1,y1);
    lin->ponto2 = criaPonto(x2,y2);
    lin->scale = scale;
    strcpy(lin->corb,cor);
    lin->forma = 'l';

    return lin;
}

Formas retanguloLista(int id, double w, double h, double x, double y, double scale,char corb[], char corp[]){
    formasStruct* ret = (formasStruct*) malloc(sizeof(formasStruct));

    ret->id = id;
    ret->ponto = criaPonto(x,y);
    ret->w = w;
    ret->h = h;
    ret->scale = scale;
    strcpy(ret->corb,corb);
    strcpy(ret->corp,corp);
    ret->forma = 'r';

    return ret;
}

Formas textoLista(int id, double x, double y, double scale,char corb[], char corp[], char text[]){
    formasStruct* txt = (formasStruct*) malloc(sizeof(formasStruct));
    
    txt->id = id;
    txt->x = x;
    txt->y = y;
    txt->scale = scale;
    txt->ponto = criaPonto(x, y);
    strcpy(txt->corb, corb);
    strcpy(txt->corp, corp);
    strcpy(txt->texto, text);
    txt->forma = 't';

    return txt;
}

Formas getPontoFormas(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->ponto;
}

int getIdF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->id;
}

char getForma(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->forma;
}

double getXF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return getXPonto(info->ponto);;
}

double getYF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return getYPonto(info->ponto);
}

double getX2F(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return getXPonto(info->ponto2);
}

double getY2F(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return getYPonto(info->ponto2);
}

Formas getPonto2(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->ponto2;
}

double getWF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->w;
}

double getHF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->h;
}

double getRaioF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->raio;
}

double getScale(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->scale;
}

char *getFillF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->corp;
}

char *getStrokeF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->corb;
}

char *getTextoF(Info elemento){
    formasStruct* info = (formasStruct*) elemento;
    return info->texto;
}

void setStrokeF(Info elemento, char stroke[]){
    formasStruct* info = (formasStruct*) elemento;
    strcpy(info->corb,stroke);
}
            
void setFillF(Info elemento,char fill[]){
    formasStruct* info = (formasStruct*) elemento;
    strcpy(info->corp,fill);
}


void imprimeListaFormas(Lista l,char saida[]){
    No node = getFirst(l), aux = getLast(l);
    Info elemento;
    char forma;
    formasStruct def;

    do{
        elemento = getInfo(node);
        forma = getForma(elemento);

        if (forma=='c'){
            def.x = getXF(elemento);
            def.y = getYF(elemento);
            def.raio = getRaioF(elemento);
            def.scale = getScale(elemento);
            strcpy(def.corb,getStrokeF(elemento));
            strcpy(def.corp,getFillF(elemento));

            imprimeCirculo(def.raio, def.x, def.y, def.scale, def.corb, def.corp, saida);
        }
        if (forma=='r'){
            def.x = getXF(elemento);
            def.y = getYF(elemento);
            def.w = getWF(elemento);
            def.h = getHF(elemento);
            def.scale = getScale(elemento);
            strcpy(def.corb,getStrokeF(elemento));
            strcpy(def.corp,getFillF(elemento));

            imprimeRetangulo(def.w, def.h, def.x, def.y, def.scale,def.corb, def.corp, saida);
        }
        if (forma=='t'){
            def.x = getXF(elemento);
            def.y = getYF(elemento);
            def.scale = getScale(elemento);
            strcpy(def.corb,getStrokeF(elemento));
            strcpy(def.corp,getFillF(elemento));
            strcpy(def.texto,getTextoF(elemento));

            imprimeTexto(def.x, def.y, def.scale,def.corb, def.corp, def.texto, saida);
        }
        if(forma == 'l'){
            def.x = getXF(elemento);
            def.y = getYF(elemento);
            def.x2 = getX2F(elemento);
            def.y2 = getY2F(elemento);
            def.scale = getScale(elemento);
            strcpy(def.corb,getStrokeF(elemento));

            imprimeLinha(def.x, def.y, def.x2, def.y2, def.scale,def.corb, saida);
        }

        node = getNext(node);
    } while (node!=getNext(aux));
    
}