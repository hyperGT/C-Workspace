#include <stdio.h>
#include "Vector2f.h"
#define TAM 4

/* Funções */

int main(){
	
	Vector2f *v1, *v2=vect_criar(5, 7), *v3=vect_criar(3, 4), *v4;
	char *vstr1, *vstr2, *vstr3, *vstr4;
	Vector2f *vet[TAM];
	
	printf("\n\n ###### V3: \n");
	vect_exibe(v3);
	vect_atribui(v3, 6, 5);		
	vect_exibe(v3);
	
	printf("\n\n ###### V2: \n");
	vect_exibe(v2);	
	vect_atribui(v2, 6, 3);	
	vect_exibe(v2);
	
	printf("\n\n ###### V1: \n");
	//vect_exibe(v1);
	v1 = vect_copia(v2);
	vect_exibe(v1);
	
	printf("\n\n ###### Soma de vetores: \n");
	v1 = vect_add(v1, v2);
	vect_exibe(v1);
	v1 = vect_add(v1, v3);
	vect_exibe(v1);	
	
	printf("\n\n ###### Mult por um Escalar: \n");
	vect_exibe(v2);
	v2 = vect_scale(v2, 2);
	vect_exibe(v2);
	v4 = vect_scale(v3, 3);
	vect_exibe(v4);
	
	printf("\n\n ###### Printando os valores no console como string: \n");
	vstr1 = vect_getVec(v1);
	vstr2 = vect_getVec(v2);
	vstr3 = vect_getVec(v3);
	vstr4 = vect_getVec(v4);
	
	printf("\n\n %s \n\n %s \n\n %s \n\n %s \n\n", vstr1, vstr2, vstr3, vstr4);		
	
	/* Limpa as variaveis da memoria */
	vect_libera(v1);
	vect_libera(v2);
	vect_libera(v3);		
	vect_libera(v4);
	
	return 0;
}
