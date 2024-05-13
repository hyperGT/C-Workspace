/*
Questão 08:
Fazer um programa que auxilie o órgão
regulador no cálculo do total de recursos

arrecadados com a aplicação de multas de
trânsito.

O programa deve ler as seguintes
informações para cada motorista:
- O número da carteira de motorista;
- Número de multas;
- Valor de cada uma das multas.
Deve ser exibido o valor da dívida de cada
motorista e ao final da leitura o total de
recursos arrecadados (somatório de todas
as multas). O programa também deverá
apresentar o número da carteira do
motorista que obteve o maior número de
multas.
*/

#include<stdio.h>

int main(){		
	
	int cnh, qntMultas, qntMotoristas=3, 
	i, j, 
	maiorNumMultas=0, carteiraMaior;
	float vMulta, somaDivida, totalArrecadado=0;
	
	//TODO: lendo quantos motoristas serão lidos pelo sistema 
	
	for(i=1; i<=qntMotoristas; i++){
				
		//lendo o numero da carteira do motorista
		printf("Insira o numero da carteira do motorista: ");
		scanf("%d", &cnh);
		
		//lendo a qnt de multas
		printf("Insira a quantidade de multas: ");
		scanf("%d", &qntMultas);
		
		//obtendo o número da carteira do motorista que obteve o maior número de multas.
		if(qntMultas > maiorNumMultas){
			maiorNumMultas = qntMultas;
			carteiraMaior = cnh;
		}
		
		// Valor de cada uma das multas.
		somaDivida=0;
		for(j=1; j<=qntMultas; j++){
			
			printf("valor da %da. multa: ", j);
			scanf("%f", &vMulta);
			
			somaDivida+=vMulta;
		}
		
		//exibindo o valor da dívida de cada motorista
		printf("\nValor da Divida do Motorista (cnh: %d): %.2f\n\n", cnh, somaDivida);
		
		//calculando o total arrecadado
		totalArrecadado+=somaDivida;			
	}
	
		//e ao final da leitura o total de recursos arrecadados (somatório de todas as multas)
		printf("\nTotal de recursos arrecadados: %.2f", totalArrecadado);
		
		//exibindo o número da carteira do motorista que obteve o maior número de multas.
		printf("\nCarteira do motorista que obteve o maior numero de multas: %d", carteiraMaior);
			
}


