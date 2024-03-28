#include "includes.h"

typedef struct novas{
    char tipo, cor[20];
    double x, y, x2, y2, w, h, id, area, raio, scale;
    int n;
} structQry;

char getTipoQRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->tipo;
}

double getYQRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->y;
}

double getXQRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->x;
}

double getY2QRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->y2;
}

double getX2QRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->x2;
}

int getIdQRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->id;
}

double getRaioQRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->raio;
}

double getScaleQRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->scale;
}

char *getCorQRY(Info elemento){
    structQry *info = (structQry *)elemento;
    return info->cor;
}

void criaCirculo(Lista l, double raio, double x, double y, char cor[])
{
    structQry *circulo = (structQry *)malloc(sizeof(structQry));

    circulo->x = x;
    circulo->raio = raio;
    circulo->y = y;
    strcpy(circulo->cor, cor);
    circulo->tipo = 'c';

    insere(l, circulo);
}


void criaLinha(double x, double y, double x2, double y2, char cor[], Lista lista)
{
    structQry *linha = (structQry *)malloc(sizeof(structQry));

    linha->x = x;
    linha->y = y;
    linha->x2 = x2;
    linha->y2 = y2;
    linha->scale = 1;
    strcpy(linha->cor, cor);
    linha->tipo = 'l';

    insere(lista, linha);
}


void criaTexto(double x, double y, int id, Lista lista){
    structQry *txt = (structQry *)malloc(sizeof(structQry));
    
    txt->id = id;
    txt->x = x;
    txt->y = y;
    strcpy(txt->cor, "black");
    txt->tipo = 't';

    insere(lista, txt);
}

double max(double x1, double x2){
    if (x1 > x2){ return x1; }
    else{ return x2; }
}

double min(double x1, double x2){
    if (x1 < x2){return x1;  }
    else{ return x2; }
}

double dist(double x1, double y1, double x2, double y2){
    double deltax, deltay, res;
    deltay = y2 - y1;
    deltax = x2 - x1;
    res = sqrt((deltax * deltax) + (deltay * deltay));
    return res;
}


bool PontoInternoCirc(double x1, double y1, double x2, double y2, double raio)
{
    double DX, DY, res;

    DX = x2 - x1;
    DY = y2 - y1;

    res = sqrt((DX * DX) + (DY * DY));

    if (raio >= res){
        return true;
    }
    else{
        return false;
    }
}

bool PontoInternoRet(double px, double py, double x, double y, double h, double w){
    if (px > x && py >y && px < (x+w) && py < (y+h)){
        return true;
    }
    else{
        return false;
    }
}

bool sobreposicaoCirc(double x1, double y1, double r1, double x2, double y2, double r2){

    if (dist(x1, y1, x2, y2) <= r1 + r2){
        return true;
    }
    else{
        return false;
    }
}

bool sobreposicaoCircRet(double cx, double cy, double rx, double ry, double raio, double w, double h){
 
    if (dist(cx, max(rx, min(cx, rx + w)), cy, max(cy, min(cy, ry + h))) < raio)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool sobreposicaoRet(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2){

    if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2){
        return true;
    }
    else {
        return false;
    }
}

void oFormas(int j, int k, int id,char cor1[], char cor2[],Lista lista, Lista listaQRY,char txt[]){
    No *aux = getFirst(lista), *aux2 = getFirst(lista);
    Info elemento1, elemento2;
    Formas linha;
    double x1, x2, y1, y2, r1, r2, w1, w2, h1, h2, xTexto, yTexto;

    FILE *fp;
    fp = fopen(txt, "a");

    fprintf(fp, "o?\n");

    while (aux != NULL){
        elemento1 = getInfo(aux);

        if (getIdF(elemento1) == j){
            while (aux2 != NULL){
                elemento2 = getInfo(aux2);
                if (k == getIdF(elemento2)){
                    if (getForma(elemento1) == 'c' && getForma(elemento2) == 'c'){
                        x1 = getXF(elemento1);
                        x2 = getXF(elemento2);
                        y1 = getYF(elemento1);
                        y2 = getYF(elemento2);
                        r1 = getRaioF(elemento1);
                        r2 = getRaioF(elemento2);

                        if (sobreposicaoCirc(x1, y1, r1, x2, y2, r2) == true){
                            fprintf(fp, "\tcirculo circulo j:%d k:%d Sobrepõe\n\n",j,k);
                            setFillF(elemento1, cor1);
                            setFillF(elemento2, cor1);
                            linha = linhaLista(id, x1,y1,x2,y2, 1,"black");
                        }
                        else{
                            fprintf(fp, "\tcirculo circulo j:%d k:%d Não Sobrepõe\n\n",j,k);
                            setFillF(elemento1, cor2);
                            setFillF(elemento2, cor2); 
                            linha = linhaLista(id, x1,y1,x2,y2,1, "black");  
                        }
                    }
                    if (getForma(elemento1) == 'r' && getForma(elemento2) == 'c')
                    {
                        x1 = getXF(elemento1);
                        x2 = getXF(elemento2);
                        y1 = getYF(elemento1);
                        y2 = getYF(elemento2);
                        w1 = getWF(elemento1);
                        r2 = getRaioF(elemento2);
                        h1 = getHF(elemento1);

                        if (sobreposicaoCircRet(x2, y2, x1, y1, r2, w1, h1) == true)
                        {
                            fprintf(fp, "\tretangulo circulo j:%d k:%d  Sobrepõe\n\n" ,j,k);
                            setFillF(elemento1, cor1);
                            setFillF(elemento2, cor1);
                            linha = linhaLista(id, x1,y1,x2,y2,1, "black");
                        }
                        else
                        {
                            fprintf(fp, "\tretangulo circulo j:%d k:%d  Não Sobrepõe\n\n" ,j,k);
                            setFillF(elemento1, cor2);
                            setFillF(elemento2, cor2);
                            linha = linhaLista(id, x1,y1,x2,y2,1, "black");   
                        }

                    }
                    if (getForma(elemento1) == 'c' && getForma(elemento2) == 'r')
                    {
                        x1 = getXF(elemento1);
                        x2 = getXF(elemento2);
                        y1 = getYF(elemento1);
                        y2 = getYF(elemento2);
                        w2 = getWF(elemento2);
                        r1 = getRaioF(elemento1);
                        h2 = getHF(elemento2);

                        if (sobreposicaoCircRet(x1, y1, x2, y2, r1, w2, h2) == true)
                        {
                            fprintf(fp, "\tcirculo  retangulo j:%d k:%d Sobrepõe\n\n",j,k);
                            setFillF(elemento1, cor1);
                            setFillF(elemento2, cor1);
                            linha = linhaLista(id, x1,y1,x2,y2,1, "black");
                        }
                        else
                        {
                            fprintf(fp, "\tcirculo retangulo j:%d k:%d Não Sobrepõe\n\n",j,k);
                            setFillF(elemento1, cor2);
                            setFillF(elemento2, cor2); 
                            linha = linhaLista(id, x1,y1,x2,y2,1, "black");  
                        }
                    }
                    if (getForma(elemento1) == 'r' && getForma(elemento2) == 'r'){
                        x1 = getXF(elemento1);
                        x2 = getXF(elemento2);
                        y1 = getYF(elemento1);
                        y2 = getYF(elemento2);
                        w1 = getWF(elemento1);  w2 = getWF(elemento2);
                        h1 = getHF(elemento1);  h2 = getHF(elemento2);

                        if (sobreposicaoRet(x1, y1, w1, h1, x2, y2, w2, h2)==true){
                            fprintf(fp, "\tretangulo retangulo j:%d k:%d Sobrepõe\n\n",j,k);
                            setFillF(elemento1, cor1);
                            setFillF(elemento2, cor1);
                            linha = linhaLista(id, x1,y1,x2,y2,1, "black");
                        }
                        else{
                            fprintf(fp, "\tretangulo retangulo j:%d k:%d Não Sobrepõe\n\n",j,k); 
                            setFillF(elemento1, cor2);
                            setFillF(elemento2, cor2); 
                            linha = linhaLista(id, x1,y1,x2,y2,1, "black");   
                        }
                        
                    }

                    if(x1 > x2){
                        xTexto = x2 + ((x1 - x2) / 2);
                        if(y1 > y2){
                            yTexto = y2 + ((y1 - y2) / 2);
                        }else if(y1 < y2){
                            yTexto = y1 + ((y2 - y1) / 2);
                        }else{
                            yTexto = y2;
                        }
                    }else if(x1 < x2){
                        xTexto = x1 + ((x2 - x1) / 2);
                        if(y1 > y2){
                            yTexto = y2 + ((y1 - y2) / 2);
                        }else if(y1 < y2){
                            yTexto = y1 + ((y2 - y1) / 2);
                        }else{
                            yTexto = y2;
                        }
                    }else{
                        xTexto = x1;
                        if(y1 > y2){
                            yTexto = y2 + ((y1 - y2) / 2);
                        }else if(y1 < y2){
                            yTexto = y1 + ((y2 - y1) / 2);
                        }else{
                            yTexto = y2;
                        }
                    }

                    insere(lista, linha);
                    criaTexto(xTexto, yTexto, id, listaQRY);
                }
                aux2 = getNext(aux2);
            }
        }

        aux = getNext(aux);
    }
    fclose(fp);
    elemento1 = NULL;
    elemento2 = NULL;
}


void iFormas(int j, double x, double y, Lista lista, Lista listaQRY, char txt[]){
    No node = getFirst(lista);
    Info elemento;
    bool verificacao;
    double x2, y2;

    FILE *fp;
    fp = fopen(txt,"a");

    fprintf(fp,"i? %d %lf %lf\n",j,x,y);

    while (node != NULL){
        elemento = getInfo(node);

        if (j == getIdF(elemento)){
            x2 = getXF(elemento);
            y2 = getYF(elemento);


            if ('c' == getForma(elemento)){
                verificacao = (PontoInternoCirc(x,y,x2, y2, getRaioF(elemento)));
                if (verificacao == true){
                    fprintf(fp,"Circulo INTERNO\n\n");
                    criaCirculo(listaQRY, 2, x, y, "blue");
                    criaLinha(x, y, x2, y2, "blue", listaQRY);
                }
                else{
                    fprintf(fp,"Circulo NAO INTERNO\n\n");
                    criaCirculo(listaQRY, 2, x, y, "magenta");
                    criaLinha(x, y, x2, y2, "magenta", listaQRY);
                }
            }
            if ('r' == getForma(elemento)){
                verificacao = (PontoInternoRet(x,y,x2, y2, getHF(elemento),getWF(elemento)));
                if (verificacao==true){
                    fprintf(fp,"Retangulo INTERNO\n\n");
                    criaCirculo(listaQRY, 2, x, y, "blue");
                    criaLinha(x, y, x2 + getWF(elemento)/2 , y2 + getHF(elemento)/2, "blue", listaQRY);
                }
                else{
                    fprintf(fp,"Retangulo NAO INTERNO\n\n");
                    criaCirculo(listaQRY, 2, x, y, "magenta");
                    criaLinha(x, y, x2 + getWF(elemento)/2 , y2 + getHF(elemento)/2, "magenta", listaQRY);
                }
            }
            
        }        

        node = getNext(node);
    }
    fclose(fp);
    
}

void pnt(int j, char stroke[], char fill[], Lista lista, char txt[]){
    No node = getFirst(lista);
    Info elemento;
    
    FILE *fp;
    fp = fopen(txt,"a");

    fprintf(fp,"pnt %d %s %s\n",j, stroke, fill);

    while (node != NULL){
        elemento = getInfo(node);
        
        if (j == getIdF(elemento)){
            setStrokeF(elemento, stroke);
            setFillF(elemento, fill);
            fprintf(fp,"x: %lf y: %lf\n\n", getXF(elemento), getYF(elemento));
            break;
        }
        

        node = getNext(node);
    }
    fclose(fp);
}

void delf(int j, Lista lista, char txt[]){
    No node = getFirst(lista);
    Info elemento;

    FILE *fp;
    fp = fopen(txt,"a");

    fprintf(fp,"delf %d\n", j);

    while (node != NULL){
        elemento = getInfo(node);
        if (j == getIdF(elemento)){
            if ('c' == getForma(elemento)){
                fprintf(fp,"id : %d forma : circulo raio : %lf x : %lf y : %lf corb : %s corp : %s\n\n", getIdF(elemento), getRaioF(elemento),getXF(elemento), getYF(elemento), getStrokeF(elemento), getFillF(elemento));
                removeElemento(lista, elemento);
                break;
            }else if ('r' == getForma(elemento)){
                fprintf(fp,"id : %d forma : retangulo w : %lf h : %lf x : %lf y : %lf corb : %s corp : %s\n\n", getIdF(elemento), getWF(elemento), getHF(elemento), getXF(elemento), getYF(elemento),  getStrokeF(elemento), getFillF(elemento));
                removeElemento(lista, elemento);
                break;
            }else if ('t' == getForma(elemento)){
                fprintf(fp,"id : %d forma : texto  x : %lf y : %lf texto : %s corb : %s corp : %s\n\n", getIdF(elemento),  getXF(elemento), getYF(elemento), getTextoF(elemento), getStrokeF(elemento), getFillF(elemento));
                removeElemento(lista, elemento);
                break;
            }else if ('l' == getForma(elemento)){
                fprintf(fp,"id : %d forma : linha x1 : %lf y1 : %lf x2 : %lf y2 : %lf corp : %s\n\n", getIdF(elemento), getXF(elemento), getYF(elemento), getX2F(elemento), getY2F(elemento), getFillF(elemento));
                removeElemento(lista, elemento);
                break;
            }
            break;
        }

        node = getNext(node);
    }
    fclose(fp);
}

void psh(int i,Lista lista,Pilha pilha){
    No node = getFirst(lista);
    Info elemento;
    Ponto ponto;

    while (node != NULL){
        elemento = getInfo(node);
        
        if(getIdF(elemento) == i){
            ponto = getPontoFormas(elemento);

            if(getForma(elemento) == 'c'){
                Info info = circuloLista(i, getRaioF(elemento), getXPonto(ponto), getYPonto(ponto),1, getStrokeF(elemento), getFillF(elemento));
                insereNaPilha(info, pilha);
            }
            if(getForma(elemento) == 'r'){
                Info info = retanguloLista(i, getWF(elemento), getHF(elemento),getXPonto(ponto), getYPonto(ponto), 1, getStrokeF(elemento), getFillF(elemento));
                insereNaPilha(info, pilha);
            }
            if(getForma(elemento) == 't'){
                Info info = textoLista(i, getXPonto(ponto), getYPonto(ponto),1, getFillF(elemento), getStrokeF(elemento), getTextoF(elemento));
                insereNaPilha(info, pilha);
            }
            if(getForma(elemento) == 'l'){
                Info info = linhaLista(i, getXF(elemento), getYF(elemento), getX2F(elemento), getY2F(elemento),1, getStrokeF(elemento));
                insereNaPilha(info, pilha);
            }
        }

        node = getNext(node);
    }
    
}

void pop(int i, double dx, double dy, double prop, Pilha pilha, Lista lista){
    Info elemento, novoElemento;
    Ponto ponto;

    elemento = getInfoPilha(getTopo(pilha));
    ponto = getPontoFormas(elemento);

    if(getForma(elemento) == 'c'){
        novoElemento = circuloLista(i, getRaioF(elemento), (getXPonto(ponto) + dx), (getYPonto(ponto) + dy), prop, getFillF(elemento), getStrokeF(elemento));
        removeDaPilha(pilha);
        insere(lista, novoElemento);
        return;
    }
    if(getForma(elemento) == 'r'){
        novoElemento = retanguloLista(i,getWF(elemento), getHF(elemento) ,getXPonto(ponto) + dx, getYPonto(ponto) + dy, prop, getFillF(elemento), getStrokeF(elemento));
        removeDaPilha(pilha);
        insere(lista, novoElemento);
        return;
    }
    if(getForma(elemento) == 't'){
        novoElemento = textoLista(i,getXPonto(ponto) + dx, getYPonto(ponto) + dy, prop, getFillF(elemento),getStrokeF(elemento),getTextoF(elemento));
        removeDaPilha(pilha);
        insere(lista, novoElemento);
        return;
    }
    if(getForma(elemento) == 'l'){
        novoElemento = linhaLista(i,getXF(elemento) + dx, getYF(elemento) + dy, getX2F(elemento) + dx, getY2F(elemento) + dy, prop, getStrokeF(elemento));
        removeDaPilha(pilha);
        insere(lista, novoElemento);
        return;
    }
}

void inf(int i,Lista lista, Fila fila){
    No node = getFirst(lista);
    Info elemento;
    Ponto ponto;

    while (node != NULL){
        elemento = getInfo(node);
        
        if(getIdF(elemento) == i){
            ponto = getPontoFormas(elemento);

            if(getForma(elemento) == 'c'){
                Info info = circuloLista(i, getRaioF(elemento), getXPonto(ponto), getYPonto(ponto),1, getStrokeF(elemento), getFillF(elemento));
                insereNaFila(info, fila);
            }
            if(getForma(elemento) == 'r'){
                Info info = retanguloLista(i, getWF(elemento), getHF(elemento),getXPonto(ponto), getYPonto(ponto), 1, getStrokeF(elemento), getFillF(elemento));
                insereNaFila(info, fila);
            }
            if(getForma(elemento) == 't'){if(getForma(elemento) == 't'){
                Info info = textoLista(i, getXPonto(ponto), getYPonto(ponto),1, getStrokeF(elemento), getFillF(elemento), getTextoF(elemento));
                insereNaFila(info, fila);
            }
                Info info = textoLista(i, getXPonto(ponto), getYPonto(ponto), 1,getStrokeF(elemento), getFillF(elemento), getTextoF(elemento));
                insereNaFila(info, fila);
            }
            if(getForma(elemento) == 'l'){
                Info info = linhaLista(i, getXF(elemento), getYF(elemento), getX2F(elemento), getY2F(elemento), 1, getStrokeF(elemento));
                insereNaFila(info, fila);
            }

        }

        node = getNext(node);
    }
    
}

void rmf(int i, double dx, double dy, double prop, Fila fila, Lista lista){
    Info elemento, novoElemento;
    Ponto ponto;

    elemento = getInfoFila(getPrimeiroFila(fila));
    ponto = getPontoFormas(elemento);

    if(getForma(elemento) == 'c'){
        novoElemento = circuloLista(i, getRaioF(elemento), (getXPonto(ponto) + dx), (getYPonto(ponto) + dy), prop, getFillF(elemento), getStrokeF(elemento));
        removeDaFila(fila);
        insere(lista, novoElemento);
        return;
    }
    if(getForma(elemento) == 'r'){
        novoElemento = retanguloLista(i,getWF(elemento), getHF(elemento) ,getXPonto(ponto) + dx, getYPonto(ponto) + dy, prop, getFillF(elemento), getStrokeF(elemento));
        removeDaFila(fila);
        insere(lista, novoElemento);
        return;
    }
    if(getForma(elemento) == 't'){
        novoElemento = textoLista(i,getXPonto(ponto) + dx, getYPonto(ponto) + dy, prop, getFillF(elemento),getStrokeF(elemento),getTextoF(elemento));
        removeDaFila(fila);
        insere(lista, novoElemento);
        return;
    }
    if(getForma(elemento) == 'l'){
        novoElemento = linhaLista(i,getXF(elemento) + dx, getYF(elemento) + dy, getX2F(elemento) + dx, getY2F(elemento) + dy, prop, getStrokeF(elemento));
        removeDaFila(fila);
        insere(lista, novoElemento);
        return;
    }
}

No ii(int i, No registrador,Lista l, Lista lista){
    No node = getFirst(lista);
    Info elemento, novoElemento;

    while (node != NULL){
        elemento = getInfo(node);

        if(getIdF(elemento) == i){

            if(getForma(elemento) == 'c'){
                novoElemento = circuloLista(i, getRaioF(elemento), getXF(elemento) , getYF(elemento), getScale(elemento), getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 'r'){
                novoElemento = retanguloLista(i,getWF(elemento), getHF(elemento) ,getXF(elemento) , getYF(elemento), getScale(elemento),getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 't'){
                novoElemento = textoLista(i,getXF(elemento) , getYF(elemento) , getScale(elemento), getFillF(elemento),getStrokeF(elemento),getTextoF(elemento));
            }
            if(getForma(elemento) == 'l'){
                novoElemento = linhaLista(i,getXF(elemento) , getYF(elemento) , getX2F(elemento) , getY2F(elemento), getScale(elemento), getStrokeF(elemento));
            }

            if(length(l) == 0){
                registrador = insere(l, novoElemento);
            }else{
                registrador = insertBefore(l, getInfo(getFirst(l)), novoElemento);
            }
            break;
        }

        node = getNext(node);
    }

    return registrador;

}

No ifc(int i, No registrador,Lista l, Lista lista){
    No node = getFirst(lista);
    Info elemento, novoElemento;

    while (node != NULL){
        elemento = getInfo(node);

        if(getIdF(elemento) == i){

            if(getForma(elemento) == 'c'){
                novoElemento = circuloLista(i, getRaioF(elemento), getXF(elemento) , getYF(elemento), getScale(elemento), getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 'r'){
                novoElemento = retanguloLista(i,getWF(elemento), getHF(elemento) ,getXF(elemento) , getYF(elemento), getScale(elemento),getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 't'){
                novoElemento = textoLista(i,getXF(elemento) , getYF(elemento) , getScale(elemento), getFillF(elemento),getStrokeF(elemento),getTextoF(elemento));
            }
            if(getForma(elemento) == 'l'){
                novoElemento = linhaLista(i,getXF(elemento) , getYF(elemento) , getX2F(elemento) , getY2F(elemento), getScale(elemento), getStrokeF(elemento));
            }

            registrador = insere(l, novoElemento);
            break;
        }

        node = getNext(node);
    }

    return registrador;
}

No ia(int i, No ro, No rd, Lista l, Lista lista){
    No node = getFirst(lista);
    Info elemento, novoElemento;

    while (node != NULL){
        elemento = getInfo(node);

        if(getIdF(elemento) == i){

            if(getForma(elemento) == 'c'){
                novoElemento = circuloLista(i, getRaioF(elemento), getXF(elemento) , getYF(elemento), getScale(elemento), getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 'r'){
                novoElemento = retanguloLista(i,getWF(elemento), getHF(elemento) ,getXF(elemento) , getYF(elemento), getScale(elemento),getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 't'){
                novoElemento = textoLista(i,getXF(elemento) , getYF(elemento) , getScale(elemento), getFillF(elemento),getStrokeF(elemento),getTextoF(elemento));
            }
            if(getForma(elemento) == 'l'){
                novoElemento = linhaLista(i,getXF(elemento) , getYF(elemento) , getX2F(elemento) , getY2F(elemento), getScale(elemento), getStrokeF(elemento));
            }

            rd = insertBefore(l, getInfo(ro), novoElemento);
            break;
        }

        node = getNext(node);
    }


    return rd;
}

No id(int i, No ro, No rd, Lista l, Lista lista){
    No node = getFirst(lista);
    Info elemento, novoElemento;

    while (node != NULL){
        elemento = getInfo(node);

        if(getIdF(elemento) == i){

            if(getForma(elemento) == 'c'){
                novoElemento = circuloLista(i, getRaioF(elemento), getXF(elemento) , getYF(elemento), getScale(elemento), getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 'r'){
                novoElemento = retanguloLista(i,getWF(elemento), getHF(elemento) ,getXF(elemento) , getYF(elemento), getScale(elemento),getFillF(elemento), getStrokeF(elemento));
            }
            if(getForma(elemento) == 't'){
                novoElemento = textoLista(i,getXF(elemento) , getYF(elemento) , getScale(elemento), getFillF(elemento),getStrokeF(elemento),getTextoF(elemento));
            }
            if(getForma(elemento) == 'l'){
                novoElemento = linhaLista(i,getXF(elemento) , getYF(elemento) , getX2F(elemento) , getY2F(elemento), getScale(elemento), getStrokeF(elemento));
            }

            rd = insertAfter(l, getInfo(ro), novoElemento);
            break;
        }

        node = getNext(node);
    }

    return rd;
}

void da(No registrador,Lista l){

    if(getPrevious(registrador) != NULL){
        removeElemento(l, getInfo(getPrevious(registrador)));
    }
}

void dd(No registrador,Lista l){

    if(getNext(registrador) != NULL){
        removeElemento(l, getInfo(getNext(registrador)));
    }
}

void dpl(int i, double dx,double dy,double prop,double incprop, Lista l, Lista lista){
    No node = getFirst(l);
    Info elemento, novoElemento;
    double scale = prop;

    while (node != NULL){
        elemento = getInfo(node);

        if(getForma(elemento) == 'c'){
            novoElemento = circuloLista(i, getRaioF(elemento), (getXF(elemento) + dx) , (getYF(elemento) + dy) , scale, getFillF(elemento), getStrokeF(elemento));
        }
        if(getForma(elemento) == 'r'){
            novoElemento = retanguloLista(i,getWF(elemento), getHF(elemento) ,(getXF(elemento) + dx) , (getYF(elemento) + dy) , scale,getFillF(elemento), getStrokeF(elemento));
        }
        if(getForma(elemento) == 't'){
            novoElemento = textoLista(i,(getXF(elemento) + dx) , (getYF(elemento) + dy) , scale, getFillF(elemento),getStrokeF(elemento),getTextoF(elemento));
        }
        if(getForma(elemento) == 'l'){
            novoElemento = linhaLista(i, (getXF(elemento) + dx) , (getYF(elemento) + dy) , (getX2F(elemento) + dx), (getY2F(elemento) + dy), scale, getStrokeF(elemento));
        }

        insere(lista, novoElemento);

        scale = scale + incprop;
        node = getNext(node);
    }

    esvaziaLista(l);
    
}