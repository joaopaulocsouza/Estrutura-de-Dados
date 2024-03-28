#include "includes.h"

char *tratamento(char arqNome[]){    
    int i,x,y;
    char *prefixo, caractere;

    for(i=strlen(arqNome);i>=0;i--) {
		caractere = arqNome[i];
        if(caractere=='/') {
 			y = strlen(arqNome)-i;
        	prefixo = (char*) malloc(y*sizeof(char));

        	for(x=0;x<=y;x++){
            	prefixo[x] = arqNome[i+1];
            	i++; 
        	}  
			return strtok(prefixo,".");
        }        
    }
	return strtok(arqNome,".");
}

int main(int argc, char *argv[]){
    char *nomeArq = NULL;
    char *qry = NULL;
    char *saida = NULL;
    char *path = NULL;
    char *arqQry = NULL;
    char *geo = NULL;
    char *pgeo = NULL;
    char *pqry = NULL;
    char *arqSvg = NULL;
    char *parq = NULL;
    char *arqTxt = NULL;
    Lista listas[10];
    Pilha pilhas[10];
    Fila filas[10];

    for(int i = 0; i < 10; i++){
        listas[i] = criaLista();
        filas[i] = criaFila();
        pilhas[i] = criaPilha();
    }

    Lista lista = criaLista();

    for(int i = 1; i<argc;i++){
            if (strcmp("-f",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("-f nao recebeu parametros!!\n");
                    exit(1);
                }
                nomeArq = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
                strcpy(nomeArq,argv[i]);
            }
            if (strcmp("-o",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("-o nao recebeu parametros!!\n");
                    exit(1);
                }
                saida = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
                strcpy(saida,argv[i]);
            }
            if (strcmp("-q",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("-q nao recebeu parametros!!\n");
                    exit(1);
                }
                qry = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
                strcpy(qry,argv[i]);
            }
            if (strcmp("-e",argv[i])==0){
                i++;
                if(argv[i]==NULL){
                    printf("-e nao recebeu parametros!!\n");
                    exit(1);
                }
                path = (char*) malloc((strlen(argv[i])+1)*sizeof(char));
                strcpy(path,argv[i]);
            }
        }

    if(path!=NULL){
        geo = (char *)malloc((strlen(nomeArq)+strlen(path)+2)*sizeof(char));
        sprintf(geo,"%s/%s",path,nomeArq);

        if (qry!=NULL){       
            arqQry = (char *)malloc((strlen(qry)+strlen(path)+2)*sizeof(char));
            sprintf(arqQry,"%s/%s",path,qry);
        }
    }
    else{
        geo = (char *)malloc((strlen(nomeArq)+1)*sizeof(char));
        strcpy(geo,nomeArq);

        if (qry!=NULL){        
            arqQry = (char *)malloc((strlen(qry)+1)*sizeof(char));
            strcpy(arqQry,qry);
        }
    }

    pgeo = tratamento(nomeArq);

    if (qry != NULL){ pqry = tratamento(qry); }

    arqSvg = (char *) malloc((strlen(saida)+strlen(pgeo)+6)*sizeof(char));
    sprintf(arqSvg,"%s/%s.svg",saida,pgeo);

    leituraGeo(geo, arqSvg, lista);

    if (arqQry !=NULL){

        parq = (char *) malloc((strlen(arqSvg)+strlen(pqry)+6)*sizeof(char));
        sprintf(parq,"%s/%s-%s.svg", saida, pgeo, pqry);

        arqTxt = (char *) malloc((strlen(arqSvg)+strlen(pqry)+6)*sizeof(char));
        sprintf(arqTxt,"%s/%s-%s.txt", saida, pgeo, pqry);

        leituraQry(parq, arqTxt, arqQry, lista, listas, pilhas, filas); 
    }

    for(int i = 0; i < 10; i++){
        desalocaLista(listas[i]);
        desalocaFila(filas[i]);
        desalocaPilha(pilhas[i]);
    }
    desalocaLista(lista);
    free(parq);
    free(arqSvg);
    if (qry!=NULL){
        free(pqry); 
        free(arqQry); 
        free(arqTxt);
        free(qry);
    }
    free(geo);
    free(path);
    free(saida);  
    free(nomeArq);
    return 0;
}