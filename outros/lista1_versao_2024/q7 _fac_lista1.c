/*
Escreva um algoritmo para calcular o salário
semanal de uma pessoa, determinado pelas
condições que seguem: se o número de horas
trabalhado for inferior ou igual a 40, a pessoa
recebe x reais por hora; caso contrário, a
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
