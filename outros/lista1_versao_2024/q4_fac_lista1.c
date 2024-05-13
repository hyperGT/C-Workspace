#include<stdio.h>

/*
Um banco concederá um crédito especial aos
seus clientes, variável com o saldo médio no
último ano. Faça um algoritmo que calcule o
valor do crédito de acordo com a tabela abaixo.
Saldo Médio Percentual
Inferior a R$ 1000,00 nenhum crédito
De R$ 1000,00 a
R$ 1499,99 20% do saldo médio
De R$ 1500,00 a
R$ 2499,99 30% do saldo médio
R$ 2500,00 ou mais 40% do saldo médio
*/

int main(){
	
	float saldoM;
	float cred;
	
	//quanto a pessoa tem de saldo?
	printf("Insira o valor do saldo medio: ");
	scanf("%f", &saldoM);
	
	if(saldoM >= 1000 && saldoM <= 1499.99){
		cred = ((20*saldoM)/100);
	}
	else if(saldoM >= 1500 && saldoM <= 2499.99){
		cred = ((30*saldoM)/100);
	}
	else if(saldoM >= 2500){
		cred = ((40*saldoM)/100);
	}
	else{
		cred = 0;
	}		
	
	
	printf("saldo medio: %.2f creditos: %.2f saldo total: %.2f", saldoM, cred, saldoM+cred);
	
}
