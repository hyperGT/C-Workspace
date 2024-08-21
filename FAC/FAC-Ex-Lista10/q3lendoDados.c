/*
QUESTÃO 03:
Fazer uma função leituraDados que permaneça
lendo valores reais até que o número 0 seja
digitado. Ao final, a função deve determinar a
quantidade de elementos fornecidos (excluindo
o 0) e o maior dentre eles.
*/

#include <stdio.h>

// prot das funções
void leituraDados(float *qntNum, float *maiorNum);

void main(){
	
	// declarando variaveis
	float totalValores, maiorValor;
	
	// chamando função
	leituraDados(&totalValores, &maiorValor);
	
	printf("Quantidade de valores digitados: %.0f\n", totalValores);
	printf("Maior valor digitado: %.0f", maiorValor);
}

void leituraDados(float *qntNum, float *maiorNum){
	
	// declarando variáveis
	float valor;
	*maiorNum = 0;
	*qntNum = 0;
	
	// entrando na repetição e depois verificando se o valor é 0, caso for o loop para.
	do{
		
		// lendo valor
		printf("Insira um valor: ");
		scanf("%f", &valor);
		
		if(valor != 0){
			// atualizando o maior valor
			if(*maiorNum < valor){
				*maiorNum = valor;		
			}
			(*qntNum)++;
		}
		
	}while(valor != 0);		
}
