#ifndef __FORMAS_H__
#define __FORMAS_H__

typedef void* Formas;

/* esta funcao imprime um circulo no arquivo svg
ela recebe como parametro os dados do circulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeCirculo(double raio, double x, double y, double scale,char corb[], char corp[],char saida[]);

/* esta funcao imprime um retangulo no arquivo svg
ela recebe como parametro os dados do retangulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeRetangulo(double width, double heigth, double x, double y, double scale,char corb[], char corp[],char saida[]);

/* esta funcao imprime um texto no arquivo svg
ela recebe como parametro os dados do texto
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeTexto(double x, double y, double scale,char corb[],char corp[], char texto[],char saida[]);

/* esta funcao aloca espaço na memoria e armazena os dados do circulo
e retorna o elemento criado*/
Formas linhaLista(int id, double x1, double y1, double x2, double y2, double scale,char cor[]);

/* esta funcao aloca espaço na memoria e armazena os dados do circulo
e retorna o elemento criado*/
Formas circuloLista(int id, double raio, double x, double y, double scale,char corb[], char corp[]);

/* esta funcao aloca espaço na memoria e armazena os dados do retangulo
e retorna o elemento criado*/
Formas retanguloLista(int id, double w, double h, double x, double y, double scale,char corb[], char corp[]);

/* esta funcao aloca espaço na memoria e armazena os dados do texto
e retorna o elemento criado*/
Formas textoLista(int id, double x, double y, double scale,char corb[], char corp[], char text[]);

/* esta funcao retorna o ponto de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
Formas getPontoFormas(Info elemento);

/* esta funcao retorna o ponto 2 de uma forma,
essa função é usada para as linhas,
ela recebe o elemento onde a forma esta
armazenado como parametro */
Formas getPonto2(Info elemento);

/* esta funcao retorna o id de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
int getIdF(Info elemento);

/* esta funcao retorna o forma de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
char getForma(Info elemento);

/* esta funcao retorna o x de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getXF(Info elemento);

/* esta funcao retorna o y de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getYF(Info elemento);

/* esta funcao retorna o x2 de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getX2F(Info elemento);

/* esta funcao retorna o y2 de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getY2F(Info elemento);

/* esta funcao retorna o width de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getWF(Info elemento);

/* esta funcao retorna o height de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getHF(Info elemento);

/* esta funcao retorna o raio de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getRaioF(Info elemento);

/* esta funcao retorna o preenchimento de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
char *getFillF(Info elemento);

/* esta funcao retorna o borda de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
char *getStrokeF(Info elemento);

/* esta funcao retorna o text de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
char *getTextoF(Info elemento);

/* esta funcao altera a borda de uma forma
ela recebe o elemento onde a forma esta
armazenado e o novo valor da borda como parametro */
void setStrokeF(Info elemento, char stroke[]);
            
/* esta funcao altera a preenchimento de uma forma
ela recebe o elemento onde a forma esta
armazenado e o novo valor da preenchimento como parametro */            
void setFillF(Info elemento,char fill[]);


/* esta funcao retorna a escala de uma forma
ela recebe o elemento onde a forma esta
armazenado como parametro */
double getScale(Info elemento);

/* esta funcao percorre a lista de formas,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir a respectiva
forma passando essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeListaFormas(Lista l,char saida[]);

#endif