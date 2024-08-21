/*
QUESTÃO 07:
Implementar uma função que, dado um
número inteiro n, e o intervalo definido pelos
números a e b, determine quantos valores do
intervalo possuem divisores (sendo estes
diferentes de 1) que também sejam divisores
de n.
Exemplo:
n = 6
a = 10 e b = 20
Resposta = 7 (pois os números 10, 12, 14,
15, 16, 18 e 20 possuem divisores em
comum com o número 6).

parametro: int n, int a, int b
retorno: int qntDiv
*/

#include <stdio.h>

// prototipos das funções 
int quantDivisores(int n, int a, int b);

void main(){
	
	int n, a, b;
	
	printf("Insira o valor de n: ");
	scanf("%d", &n);
	
	printf("Insira o valor inicial do intervalo: ");
	scanf("%d", &a);
	
	printf("Insira o valor final do intervalo: ");
	scanf("%d", &b);
	
	int qntDiv = quantDivisores(n, a, b);
	
	printf("\n\nA quantidade de valores no intervalo que possuem os mesmos divisores de n: %d", qntDiv);
}

int quantDivisores(int n, int a, int b){
	
	int i, cont=0, j;
	
	// variando de a até b
	for(i=a; i<=b; i++){
		
		// precisamos obter os divisores
		for(j=2; j<=n; j++){
			
			if((i%j==0)&&(n%j==0)){
				printf("\nValor: %d ", i);
				printf("\nDivisor: %d ", j);
				cont++;
				break;
			}
		}
	}
		
	return cont;
}
	

