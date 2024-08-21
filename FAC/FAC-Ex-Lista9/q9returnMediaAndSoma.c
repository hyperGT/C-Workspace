/*
QUEST�O 09:
Implementar uma fun��o que, dado um
n�mero inteiro, calcule (e retorne) a soma e a
m�dia de seus divisores.

parametros de entrada: int n
retorno: *media e *soma (via parametros de sa�da)
*/

#include <stdio.h>

// prototipo das fun��es
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
	
	int s = 1, // come�ando soma com 1 pq todos os numeros tem 1 como divisor
	i, 
	cont=0; 
	float m;
	
	// variando de i at� n para verificar os divisores
	for(i=2; i<=n; i++){
		
		// verificando se � divisor de n
		if(n%i==0){
			// somando os divisores
			s+=i;
			// incrementando na contagem a quantidade de divisores de n
			cont++;
		}
		
	}		
	
	// calculando a m�dia de seus divisores
	m = (float)s/cont;
	
	// alocando os valores as suas respectivas refer�ncias de mem�ria
	*media = m;
	*soma = s;	
}
