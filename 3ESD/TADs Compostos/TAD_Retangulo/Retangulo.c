/*
*   Gabriel Teixeira Charles da Silva
*   TAD Retangulo
*/

#include "Ponto.h"
#include "Retangulo.h"
#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
struct retangulo{
    Ponto* vert;
    float base;
    float altura;
};

/* Funções exportadas */
/* cria - Aloca e retorna um Retangulo com vertice(x,y) e altura e base */
Retangulo* ret_cria(float x, float y, float altura, float base){
    
    Retangulo* c = (Retangulo*)malloc(sizeof(Retangulo));
    c->vert = pto_cria(x,y);
    c->altura = altura;
    c->base = base;
    return c;
}

/* libera - Libera a memória de um retangulo previamente criado */
void ret_libera(Retangulo* c){
    pto_libera(c->vert);
    free(c);
}

/* area - Retorna o valor da área do retangulo */
float ret_area(Retangulo* c){
    return c->base * c->altura;
}

/* mostra os valores de um retangulo */
void ret_exibe(Retangulo* c){
    printf("Base: %.2f \nAltura: %.2f \nVertice: %s", c->base, c->altura, pto_getPonto(c->vert));
}

char* ret_getRetangulo(Retangulo *r){
    char* strPto = pto_getPonto(r->vert);
    int tamRet = sizeof(*r) + sizeof(*strPto) + 29;
    char* strRet = (char*) malloc(tamRet);
    sprintf(strRet, "Vertice: %s , Base: %.2f, Altura: %.2f", strPto, r->base, r->altura);
    free(strPto);
    return strRet;
}

/* copia - Aloca e retorna um retangulo com dados iguais a outro retangulo */
Retangulo* ret_copia(Retangulo*r){
    Retangulo *tempRet = (Retangulo*) malloc(sizeof(Retangulo));
    
    tempRet->vert = pto_copia(r->vert);
    tempRet->base = r->base;
    tempRet->altura = r->altura;
    
    return tempRet;
}

/* Acessa elementos do retangulo */
float ret_base(Retangulo* c){
    return c->base;
}

float ret_altura(Retangulo* c){
    return c->altura;
}

Ponto* ret_vertice(Retangulo* c){
    return c->vert;
}


