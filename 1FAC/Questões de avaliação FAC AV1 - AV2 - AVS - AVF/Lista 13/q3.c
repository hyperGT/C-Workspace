#include <stdio.h>
#include <limits.h>

// prototipos
void maiorMenorAlg(int n, int *maior, int *menor);

int main(){
	int n, maiorAlg, menorAlg;
	
	printf("insira n: ");
	scanf("%d", &n);
	
	maiorMenorAlg(n, &maiorAlg, &menorAlg);
	
	printf("Maior algarismo: %d\n", maiorAlg);
	printf("Menor algarismo: %d\n", menorAlg);
}

void maiorMenorAlg(int n, int *maior, int *menor){
	
	int digito;
	
	*maior = INT_MIN; // maior começa com o menor inteiro existente para poder receber os valores maiores
	
	*menor = INT_MAX; // menor começa com o maior inteiro existente para receber os menores valores
	
	// 1 passo: transformar o valor em algarismos
	/*
	* Em um loop, ir guardando o ultimo digito e depois removendo-o para assim ir comparando. 
	*/
	// 2 passo: obter o maior e menor algarismo
	/*
	* Uma variavel menor com um valor alto e uma variavel maior com um valor baixo, os valores rapidamente 
	* substituidos servirão para serem comparados com os próximos
	*/
	
	while(n>0){
	
		// 1.1 obter e guardar o último dígito
		digito = n % 10;
		
		// 1.2 remover o último dígito
		n = n / 10;
		
		// 2.1 obtendo o menor algarismo
		if(digito<*menor){
			*menor = digito;
		}
		
		// 2.2 obtendo o maior algarismo
		if(digito>*maior){
			*maior = digito;
		}	
	}
}
