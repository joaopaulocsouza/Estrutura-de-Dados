#ifndef __PONTO_H__
#define __PONTO_H__

typedef void* Ponto;

/* está funcao cria um ponto para um elemento,
ela recebe como parametro x e y,
retorna o ponto alocado na memoria*/
Ponto criaPonto(double x, double y);

/* está funcao retorna o ponto x de um ponto,
ela recebe como parametro o ponto */
double getXPonto(Ponto ponto);

/* está funcao retorna o ponto y de um ponto,
ela recebe como parametro o ponto */
double getYPonto(Ponto ponto);


#endif