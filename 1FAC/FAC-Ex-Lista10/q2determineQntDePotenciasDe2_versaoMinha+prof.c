/*
QUESTÃO 02:
Dados dois números inteiros A e B, fazer uma
função que determine o número de potências
de 2 existentes no intervalo definido pelos dois
valores, assim como a maior delas.

parametros de entrada: int a, int b
retorno: int qntPotencias, int maiorPot
*/

#include <stdio.h>

// prot das funções
void nPotenciasDe2(int a, int b, int *maiorPot, int *qntPot);

void main(){
	
	int a, b, maiorPot, qntPotencias;
	
	printf("Exibindo potencias de um intervalo de A ate B\n");
	
	printf("a: ");
	scanf("%d", &a);
	
	printf("b: ");
	scanf("%d", &b);
	
	// testando se os valores são válidos
	if(a<1){
		a = 1;
	}
	
	if(a>b){
		printf("A deve ser menor que B!");
		return 1;
	}
	
	
	nPotenciasDe2(a, b, &maiorPot, &qntPotencias);
	
	printf("Quantidade de potencias de 2: %d\n", qntPotencias);
	printf("Maior potencia de 2 encontrada: %d", maiorPot);
	
	return 0;
}

void nPotenciasDe2(int a, int b, int *maiorPot, int *qntPot){
	
	int i, j=a;	// 3.784 s vs media(2.500s)
	*qntPot=0;		
	
	// variando j até chegar a b
	while(j<b){
		
		// se j for maior que A, só ir contando até chegar e ser maior que B
		if(j>a){
			(*qntPot)++;
			*maiorPot=j;
		}
		
		j*=2;
	}
}
