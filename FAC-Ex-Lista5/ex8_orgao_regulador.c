/*
Quest�o 08:
Fazer um programa que auxilie o �rg�o
regulador no c�lculo do total de recursos

arrecadados com a aplica��o de multas de
tr�nsito.

O programa deve ler as seguintes
informa��es para cada motorista:
- O n�mero da carteira de motorista;
- N�mero de multas;
- Valor de cada uma das multas.
Deve ser exibido o valor da d�vida de cada
motorista e ao final da leitura o total de
recursos arrecadados (somat�rio de todas
as multas). O programa tamb�m dever�
apresentar o n�mero da carteira do
motorista que obteve o maior n�mero de
multas.
*/

#include<stdio.h>

int main(){		
	
	int cnh, qntMultas, qntMotoristas=3, 
	i, j, 
	maiorNumMultas=0, carteiraMaior;
	float vMulta, somaDivida, totalArrecadado=0;
	
	//TODO: lendo quantos motoristas ser�o lidos pelo sistema 
	
	for(i=1; i<=qntMotoristas; i++){
				
		//lendo o numero da carteira do motorista
		printf("Insira o numero da carteira do motorista: ");
		scanf("%d", &cnh);
		
		//lendo a qnt de multas
		printf("Insira a quantidade de multas: ");
		scanf("%d", &qntMultas);
		
		//obtendo o n�mero da carteira do motorista que obteve o maior n�mero de multas.
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
		
		//exibindo o valor da d�vida de cada motorista
		printf("\nValor da Divida do Motorista (cnh: %d): %.2f\n\n", cnh, somaDivida);
		
		//calculando o total arrecadado
		totalArrecadado+=somaDivida;			
	}
	
		//e ao final da leitura o total de recursos arrecadados (somat�rio de todas as multas)
		printf("\nTotal de recursos arrecadados: %.2f", totalArrecadado);
		
		//exibindo o n�mero da carteira do motorista que obteve o maior n�mero de multas.
		printf("\nCarteira do motorista que obteve o maior numero de multas: %d", carteiraMaior);
			
}


