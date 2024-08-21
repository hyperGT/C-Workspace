/*
* 
*/

#include <stdio.h>

// functions
float somaMediaDivisores (int n, int *somaDiv){
	
	// declara��o de vari�veis
	int i, soma = 0, cont = 0;
	float media;
	
	// percorrendo valores de 1 at� 6 
	for(i=1; i<=n; i++){
		
		// verificando se � divisor de n
		if(n%i==0){
			// somando os divisores
			soma += i;
			// atualizando a quantidade de divisores
			cont++;
		}
	}
	
	*somaDiv = soma; // guardando a soma
	media = (float)soma/cont; // realizando a m�dia
	
	return media; // retornando a m�dia
}

int main(){
	
	// declara��o de vari�veis
	int n, soma;
	float media;
	
	// obtendo dados
	printf("Insira N: ");
	scanf("%d", &n);
	
	// chamando fun��o
	media = somaMediaDivisores(n, &soma);
	
	// exibindo resultados
	printf("Soma: %d\n", soma);
	printf("Media: %.1f", media);
}
