/*
Escreva um algoritmo para calcular o sal�rio
semanal de uma pessoa, determinado pelas
condi��es que seguem: se o n�mero de horas
trabalhado for inferior ou igual a 40, a pessoa
recebe x reais por hora; caso contr�rio, a
pessoa recebe um adicional de 50% para cada
hora trabalhada acima das 40 iniciais.
*/

#include<stdio.h>

int main(){
	
	int reaisHora, totalHoras, addHoras, salSemanal;
	
	//recebendo os valores
	printf("Insira o valor de reais por hora: ");
	scanf("%d", &reaisHora);
	
	printf("Insira o total de horas trabalhadas: ");	
	scanf("%d", &totalHoras);
	
	
	
	if(totalHoras > 40){				
		addHoras = totalHoras - 40;	
		salSemanal = reaisHora * 40 + ((reaisHora * 1.5) * addHoras);
					
	} else{
		salSemanal = reaisHora * totalHoras;	
	}
	
	printf("Horas extras: %d\n", addHoras);
	printf("Salario semanal: %d", salSemanal);
	
}
