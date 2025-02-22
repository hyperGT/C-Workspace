/*
QUEST�O 03:
Fazer uma fun��o leituraDados que permane�a
lendo valores reais at� que o n�mero 0 seja
digitado. Ao final, a fun��o deve determinar a
quantidade de elementos fornecidos (excluindo
o 0) e o maior dentre eles.
*/

#include <stdio.h>

// prot das fun��es
void leituraDados(float *qntNum, float *maiorNum);

void main(){
	
	// declarando variaveis
	float totalValores, maiorValor;
	
	// chamando fun��o
	leituraDados(&totalValores, &maiorValor);
	
	printf("Quantidade de valores digitados: %.0f\n", totalValores);
	printf("Maior valor digitado: %.0f", maiorValor);
}

void leituraDados(float *qntNum, float *maiorNum){
	
	// declarando vari�veis
	float valor;
	*maiorNum = 0;
	*qntNum = 0;
	
	// entrando na repeti��o e depois verificando se o valor � 0, caso for o loop para.
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
