/*
* 
*/

#include <stdio.h>

// functions
float somaMediaDivisores (int n, int *somaDiv){
	
	// declaração de variáveis
	int i, soma = 0, cont = 0;
	float media;
	
	// percorrendo valores de 1 até 6 
	for(i=1; i<=n; i++){
		
		// verificando se é divisor de n
		if(n%i==0){
			// somando os divisores
			soma += i;
			// atualizando a quantidade de divisores
			cont++;
		}
	}
	
	*somaDiv = soma; // guardando a soma
	media = (float)soma/cont; // realizando a média
	
	return media; // retornando a média
}

int main(){
	
	// declaração de variáveis
	int n, soma;
	float media;
	
	// obtendo dados
	printf("Insira N: ");
	scanf("%d", &n);
	
	// chamando função
	media = somaMediaDivisores(n, &soma);
	
	// exibindo resultados
	printf("Soma: %d\n", soma);
	printf("Media: %.1f", media);
}
