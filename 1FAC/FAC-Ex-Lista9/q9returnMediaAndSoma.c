/*
QUESTÃO 09:
Implementar uma função que, dado um
número inteiro, calcule (e retorne) a soma e a
média de seus divisores.

parametros de entrada: int n
retorno: *media e *soma (via parametros de saída)
*/

#include <stdio.h>

// prototipo das funções
void somaMediaDivisores(int n, int *soma, float *media);

void main(){
	
	int n, soma;
	float media;
	
	printf("Insira um valor inteiro n: ");
	scanf("%d", &n);
	
	somaMediaDivisores (n, &soma, &media);
	
	printf("soma dos divisores: %d\n", soma);
	printf("media dos divisores: %.1f", media);
}

void somaMediaDivisores(int n, int *soma, float *media){
	
	int s = 1, // começando soma com 1 pq todos os numeros tem 1 como divisor
	i, 
	cont=0; 
	float m;
	
	// variando de i até n para verificar os divisores
	for(i=2; i<=n; i++){
		
		// verificando se é divisor de n
		if(n%i==0){
			// somando os divisores
			s+=i;
			// incrementando na contagem a quantidade de divisores de n
			cont++;
		}
		
	}		
	
	// calculando a média de seus divisores
	m = (float)s/cont;
	
	// alocando os valores as suas respectivas referências de memória
	*media = m;
	*soma = s;	
}
