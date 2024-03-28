#include "includes.h"

struct corDef{
    char sw[10], cfill[20], cstrk[20];
};


struct formas{
    int id;
    double raio, x, y, w, h, x2, y2;
    char corb[20], corp[20], text[100];
};

void leituraGeo(char geo[],char saida[], Lista lista){
    char comando[3];
    int nx = 5000000, cont = 0;
    struct formas forma;
    Formas crf;

    abrirSvg(saida);

    FILE *arq;
    arq = fopen(geo, "r");

     if (arq == NULL){
        printf("Erro ao abrir GEO!!\n");
        exit(0);
    }

    fscanf(arq,"%s",comando);
    if (strcmp(comando,"nx")==0){
        fscanf(arq,"%d",&nx);
    }
    else{
        fseek(arq, 0, SEEK_SET);
    }

    while (fscanf(arq,"%s",comando) != EOF){
               
        /* ADICONANDO FORMAS */
        if(strcmp("c",comando)==0){
            fscanf(arq,"%d %lf %lf %lf %s %s",&forma.id, &forma.raio, &forma.x, &forma.y, forma.corb, forma.corp); 
            if(cont<nx){
                crf = circuloLista(forma.id, forma.raio, forma.x, forma.y, 1,forma.corb, forma.corp);
                insere(lista, crf);
                cont++;
            }
        }
        if(strcmp("r",comando)==0){
            fscanf(arq,"%d %lf %lf %lf %lf %s %s",&forma.id, &forma.w, &forma.h, &forma.x, &forma.y, forma.corb, forma.corp);
            if(cont < nx){
                crf = retanguloLista(forma.id, forma.w, forma.h, forma.x, forma.y, 1,forma.corb, forma.corp);
                insere(lista, crf);
                cont++;
            }
        }
        if(strcmp("l",comando)==0){
            fscanf(arq,"%d %lf %lf %lf %lf %s",&forma.id, &forma.x, &forma.y, &forma.x2, &forma.y2, forma.corb);
            if(cont < nx){
                crf = linhaLista(forma.id, forma.x, forma.y, forma.x2, forma.y2, 1,forma.corb);
                insere(lista, crf);
                cont++;
            }
        }
        if(strcmp("t",comando)==0){
            fscanf(arq,"%d %lf %lf %s %s",&forma.id, &forma.x, &forma.y, forma.corb, forma.corp);
            fgets(forma.text,100,arq);
            if(cont < nx){
                crf = textoLista(forma.id, forma.x, forma.y, 1, forma.corb, forma.corp, forma.text);
                insere(lista, crf);
                cont++;
            }
        }
            
    }

    imprimeListaFormas(lista, saida);
    fclose(arq);
    fecharSvg(saida);
}