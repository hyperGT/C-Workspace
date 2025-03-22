/*
*   Gabriel Teixeira Charles da Silva
*   TAD Retangulo
*/

#include "Ponto.h"

/* Tipo exportado */
typedef struct retangulo Retangulo;

/* Funções exportadas */
/* cria - Aloca e retorna um Retangulo com vertice(x,y) e altura e base */
Retangulo* ret_cria(float x, float y, float altura, float base);
/* libera - Libera a memória de um retangulo previamente criado */
void ret_libera(Retangulo* c);
/* area - Retorna o valor da área do retangulo */
float ret_area(Retangulo* c);
/* mostra os valores de um retangulo */
void ret_exibe(Retangulo* c);
/* copia - Aloca e retorna um retangulo com dados iguais a outro retangulo */
Retangulo* ret_copia(Retangulo*r);
/* Acessa elementos do retangulo */
float ret_base(Retangulo* c);
float ret_altura(Retangulo* c);
Ponto* ret_vertice(Retangulo* c);


