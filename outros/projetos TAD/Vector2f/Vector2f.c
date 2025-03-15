#include "Vector2f.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Implementação do TAD: Vector2f */
struct vect{	
	float x, y;
};

/* Implementação das funções */
Vector2f * vect_criar(float x, float y){
	
	Vector2f *vec = (Vector2f *) malloc(sizeof(Vector2f));
	
	if(vec == NULL)	exit(1);
	
	vec->x = x;
	vec->y = y;
	
	return vec;
}

void vect_libera(Vector2f *v){	
	free(v);
}

void vect_exibe(Vector2f *v){
	
	if(v == NULL) {
		printf("\n Nenhum valor atribuido \n");
		return;
		//exit(1);
	}
	
	printf("\n | %.1f %.1f | ", v->x, v->y);
}

char * vect_getVec(Vector2f *v){
	char* vec;
	// espaço na memória que ocupa o vetor de 2 dimensões (x,y) + 8 bits de caracteres
	int tam = sizeof(*v)+8; 
	// aloca o espaço na memória que esse array de caracteres vai ocupar
	vec = (char*) malloc(tam);
	sprintf(vec, "| %.1f , %.1f |", v->x, v->y);
	return vec;
}

void vect_atribui(Vector2f *v, float x, float y){
	
	
	if(v == NULL) {
		printf("\n Vetor vazio \n");
	}
	
	v->x = x;
	v->y = y;
}

Vector2f * vect_copia(Vector2f *v){
	Vector2f * tVec = vect_criar(v->x, v->y);
	
	
	tVec->x = v->x;
	tVec->y = v->y;
	
	return tVec;
}

/* add function: retorna o produto de dois vetores A e B como um novo vetor */
Vector2f * vect_add (Vector2f *v1, Vector2f *v2){
	Vector2f * vecSoma = vect_criar(0, 0);
	
	vecSoma->x = v1->x + v2->x;
	vecSoma->y = v1->x + v2->y;
	
	return vecSoma;	
}

/* scale function: retorna o produto de um vetor por uma escalar (que pertence ao conjunto dos naturais) */
Vector2f * vect_scale (Vector2f *v, float s){
	Vector2f *vecScale = vect_criar(0, 0);
	
	vecScale->x = v->x * s;
	vecScale->y = v->y * s;
	
	return vecScale;
}
