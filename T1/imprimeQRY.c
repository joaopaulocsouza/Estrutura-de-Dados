#include "includes.h"

typedef struct novas{
    char tipo, cor[20];
    double x, y, x2, y2,w, h, area, raio;
    int n;
} structQry;

void imprimeListaQRY(Lista l, char saida[]){
    No node = getFirst(l);
    Info elemento;
    structQry def;

    while (node != NULL)
    {
        elemento = getInfo(node);
        def.tipo = getTipoQRY(elemento);

        if (def.tipo == 'l'){
            imprimeLinha(getXQRY(elemento), getYQRY(elemento), getX2QRY(elemento), getY2QRY(elemento), getScaleQRY(elemento) ,getCorQRY(elemento), saida);
        }
        if (def.tipo == 'c'){
            imprimeCirculoQry(getXQRY(elemento), getYQRY(elemento),getRaioQRY(elemento), getCorQRY(elemento), saida);
        }
        if (def.tipo == 't'){
            imprimeIdQRY(getXQRY(elemento), getYQRY(elemento), getIdQRY(elemento),getCorQRY(elemento), saida);
        }
        node = getNext(node);
    }
}


void imprimeLinha(double x, double y, double x2, double y2, double scale, char cor[], char saida[]){
    FILE *arq;
    arq = fopen(saida, "a");

    fprintf(arq, "\n\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1px\" transform=\"scale(%lf)\"/>", x, y, x2, y2, cor, scale);

    fclose(arq);
}

void imprimeCirculoQry(double x, double y, double raio, char cor[], char saida[]){
    FILE *arq;
    arq = fopen(saida, "a");

    fprintf(arq, "\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lfpx\" fill=\"%s\" />", x, y, raio, cor);

    fclose(arq);
}

void imprimeIdQRY(double x, double y, int id, char cor[], char saida[]){
    FILE *arqsvg;
    arqsvg = fopen(saida,"a");
    if (arqsvg == NULL){
        printf("Erro ao abrir arquivo SVG, durante uma tentativa de adicionar um Texto!");
        exit(1);
    }
    
    fprintf(arqsvg, "\n\t<text x=\"%lf\" y=\"%lf\" fill=\"%s\" font-size=\"5.0px\">%d</text>", x, y,cor, id);

    fclose(arqsvg);
}