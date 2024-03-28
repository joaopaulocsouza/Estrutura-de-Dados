#include "includes.h"

void abrirSvg(char saida[]){
    FILE *arq;
    arq = fopen(saida,"w");
    
    if (arq==NULL){
        printf("Erro ao abrir SVG!\n");
        exit(1);
    }

    fprintf(arq,"<svg xmlns=\"http://www.w3.org/2000/svg\" >"); 
    fclose(arq);   
}

void fecharSvg(char saida[]){
    FILE *arq;
    arq = fopen(saida,"a");
    
    if (arq==NULL){
        printf("Erro ao fechar SVG!\n");
        exit(1);
    }

    fprintf(arq,"\n</svg>");
    fclose(arq);
}