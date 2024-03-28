#include "includes.h"

struct Default{
    double x, y, w, h, r, prop, incprop;
    char corb[20], corp[20];
    int id, j, k, p, i, d, ro, rd;
};


void leituraQry(char saida[],char arquivotxt[], char qry[], Lista lista,  Lista *listas, Pilha *pilhas, Fila *filas){
    char comando[5];
    struct Default def;
    Lista listaQRY = criaLista();
    No *registrador[10];

    /* Abertura arquivo qry */

    FILE *arq;
    arq = fopen(qry,"r");
    if(arq==NULL){
        printf("Erro ao abrir qry!!");
        exit(1);
    }


    while (!feof(arq)){

        fscanf(arq,"%s",comando);
        /* QRY FORMAS */

        if(strcmp("o?",comando)==0){
            fscanf(arq,"%d %d %d %s %s", &def.j, &def.k, &def.id,def.corp, def.corb);
            oFormas(def.j, def.k,def.id,def.corp, def.corb, lista, listaQRY, arquivotxt);
        }

        if(strcmp("i?",comando)==0){
            fscanf(arq,"%d %lf %lf", &def.j, &def.x, &def.y);
            iFormas(def.j, def.x, def.y, lista,listaQRY, arquivotxt);
        }

        if(strcmp("pnt",comando)==0){
            fscanf(arq,"%d %s %s", &def.j, def.corb, def.corp);
            pnt(def.j, def.corb, def.corp, lista, arquivotxt);
        }

        if(strcmp("delf",comando)==0){
            fscanf(arq,"%d", &def.j);
            delf(def.j, lista, arquivotxt);
        }

        if(strcmp("psh",comando)==0){
            fscanf(arq,"%d %d", &def.p, &def.i);
            psh(def.i, lista, pilhas[def.p]);
        }

        if(strcmp("pop",comando)==0){
            fscanf(arq,"%d %d %lf %lf %lf", &def.p, &def.i, &def.x, &def.y, &def.prop);
            pop(def.i, def.x, def.y, def.prop, pilhas[def.p], lista);
        }

        if(strcmp("inf",comando)==0){
            fscanf(arq,"%d %d", &def.p, &def.i);
            inf(def.i, lista, filas[def.p]);
        }

        if(strcmp("rmf",comando)==0){
            fscanf(arq,"%d %d %lf %lf %lf", &def.p, &def.i, &def.x, &def.y, &def.prop);
            rmf(def.i, def.x, def.y, def.prop, filas[def.p], lista);
        }

        if(strcmp("ii",comando)==0){
            fscanf(arq,"%d %d %d", &def.p, &def.i, &def.d);
            registrador[def.d] = ii(def.i, registrador[def.d], listas[def.p],lista);
        }

        if(strcmp("if",comando)==0){
            fscanf(arq,"%d %d %d", &def.p, &def.i, &def.d);
            registrador[def.d] = ifc(def.i, registrador[def.d], listas[def.p],lista);
        }

        if(strcmp("ia",comando)==0){
            fscanf(arq,"%d %d %d %d", &def.p, &def.i, &def.ro, &def.rd);
            registrador[def.rd] = ia(def.i, registrador[def.ro], registrador[def.rd], listas[def.p], lista);
        }

        if(strcmp("id",comando)==0){
            fscanf(arq,"%d %d %d %d", &def.p, &def.i, &def.ro, &def.rd);
            registrador[def.rd] = id(def.i, registrador[def.ro], registrador[def.rd], listas[def.p], lista);
        }

        if(strcmp("da",comando)==0){
            fscanf(arq,"%d %d", &def.p, &def.d);
            da(registrador[def.d], listas[def.p]);
        }

        if(strcmp("dd",comando)==0){
            fscanf(arq,"%d %d", &def.p, &def.d);
            dd(registrador[def.d], listas[def.p]);
        }        

        if(strcmp("dpl",comando)==0){
            fscanf(arq,"%d %d %lf %lf %lf %lf", &def.p, &def.i, &def.x, &def.y, &def.prop, &def.incprop);
            dpl(def.i,def.x,def.y,def.prop,def.incprop, listas[def.p], lista);
        }

        strcpy(comando,"NULL");
    }

    abrirSvg(saida);
    imprimeListaFormas(lista, saida);
    imprimeListaQRY(listaQRY, saida);
    fecharSvg(saida);

    desalocaListaQRY(listaQRY);
}