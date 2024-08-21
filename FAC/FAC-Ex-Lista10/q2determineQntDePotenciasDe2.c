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
	
	printf("Versao 1(Minha resolucao) exibindo potencias de um intervalo de A ate B\n");
	
	printf("a: ");
	scanf("%d", &a);
	
	printf("b: ");
	scanf("%d", &b);
		
	if(a>b){
		printf("A deve ser maior que B");
		return 1;
	}
	
	nPotenciasDe2(a, b, &maiorPot, &qntPotencias);
	
	printf("Quantidade de potencias de 2: %d\n", qntPotencias);
	printf("Maior potencia de 2 encontrada: %d", maiorPot);
	
	return 0;
}

void nPotenciasDe2(int a, int b, int *maiorPot, int *qntPot){
	
	int i, j=1;
	*qntPot=0;
	
	// variando j até a 
	while(j<a){
		j*=2;
	}
	
	// se a = 10, j vai ser igual a 16
	printf("Primeira potencia: %d\n", j);
	
	// variando de a até b
	for(i = a; i <= b; i++){
		
		// verificando se i é igual a j (é uma potencia)
		if(i==j){
			(*qntPot)++;
			*maiorPot=i;
			j*=2;
		}
	}
}
