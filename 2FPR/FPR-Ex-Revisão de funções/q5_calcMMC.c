/*
* Calculate the MMC between v1 and v2
*/

#include <stdio.h>

// functions
int mmc(int n1, int n2);


int main(){
	int v1, v2, res;
	
	printf("Insira v1: ");
	scanf("%d", &v1);
	
	printf("Insira v2: ");
	scanf("%d", &v2);
	
	res = mmc(v1, v2);
	
	printf("MDC(%d, %d) = %d", v1, v2, res);
}

int mmc(int n1, int n2){
	
	int maior, menor, aux, i;
	
	if(n1>n2){
		maior = n1;
		menor = n2;
	}else{
		maior = n2;
		menor = n1;
	}
	
	
	for(i=1;i<=10;i++){
		
		aux = 0; // resetando a variavel auxiliar 
		aux = maior * i; // guardando o multiplo do valor 
		
		// verificando se esse multiplo tambem e multiplo do menor valor
		if(aux%menor==0){
			return aux; // retornando o primeiro valor que for multiplo de ambos
		}
	}
	return aux;	
}

