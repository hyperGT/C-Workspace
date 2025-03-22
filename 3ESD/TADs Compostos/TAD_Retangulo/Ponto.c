/*
*   Gabriel Teixeira Charles da Silva
*   Dever 1: alterar a implementação de TAD Ponto para que os atributos (x, Y) sejam armazenados em um vetor
*/

#include "Ponto.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Implementação TAD: Ponto (x,y) */
/*definição do tipo exportado*/ 
struct ponto {
   double coord[2];
   
};

/*definição das funções exportadas*/ 
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y){
   Ponto* p = (Ponto*) malloc(sizeof(Ponto));
   if (p == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
   }
   p->coord[0] = x;
   p->coord[1] = y;
   return p;
}

/* Função copia -  retorna um novo  ponto com coordenadas do ponto recebido*/
Ponto* pto_copia(Ponto*p){
    return pto_cria(p->coord[0], p->coord[1]);
}

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p) {
  free(p);
}

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y) {
  *x=p->coord[0];
  *y=p->coord[1];
}

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y) {
  p->coord[0]=x;
  p->coord[1]=y;
}

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2) {
  float dx = p2->coord[0] - p1->coord[0];
  float dy = p2->coord[1] - p1->coord[1];
  return sqrt(dx*dx + dy*dy);

  
}

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p1) {
  char* pt;
  int tam = sizeof(*p1)+ 8;
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f , %.2f )", p1->coord[0], p1->coord[1]);
  return pt;

}

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p) {
  printf(" (%f,%f) ",p->coord[0],p->coord[1]);
}

int pto_menorque(Ponto* pt1,Ponto* pt2){
/* Função menorque -recebe dois pontos e retorna 1 se o pt1 está mais pr´ximo da origem, 0 cc*/
  Ponto * origem=pto_cria(0,0);
  float distpt1_Orig=pto_distancia(pt1,origem);
  float distpt2_Orig=pto_distancia(pt2,origem);
  pto_libera(origem);
 
  return distpt1_Orig<distpt2_Orig;
}