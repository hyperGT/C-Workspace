#include<stdio.h>

/*
Um banco conceder� um cr�dito especial aos
seus clientes, vari�vel com o saldo m�dio no
�ltimo ano. Fa�a um algoritmo que calcule o
valor do cr�dito de acordo com a tabela abaixo.
Saldo M�dio Percentual
Inferior a R$ 1000,00 nenhum cr�dito
De R$ 1000,00 a
R$ 1499,99 20% do saldo m�dio
De R$ 1500,00 a
R$ 2499,99 30% do saldo m�dio
R$ 2500,00 ou mais 40% do saldo m�dio
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
