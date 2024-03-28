#ifndef _IMPRIME_QRY_
#define _IMPRIME_QRY_
#include "includes.h"


/* esta funcao percorre a lista de qrys,
le as informacoes de cada elemento na lista,
e chama a funcao para imprimir o respectivo elemento passando
essas informações por parametro
ela recebe a lista a ser percorria e o nome do arquivo svg
junto ao diretorio de saida*/
void imprimeListaQRY(Lista l, char saida[]);

/* esta funcao imprime uma linha e o cep no arquivo svg
ela recebe como parametro os dados do linha e o cep
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeLinha(double x, double y, double x2, double y2, double scale,char cor[], char saida[]);

/* esta funcao imprime um circulo no arquivo svg
ela recebe como parametro os dados do circulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeCirculoQry(double x, double y, double raio, char cor[], char saida[]);



/* esta funcao imprime o id no arquivo svg
ela recebe como parametro os dados do circulo
e o nome do arquivo svg junto ao diretório de saida*/
void imprimeIdQRY(double x, double y, int id, char cor[], char saida[]);

#endif