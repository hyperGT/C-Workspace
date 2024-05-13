/*O custo ao consumidor de um carro novo é a
soma do custo de fábrica com a porcentagem
do distribuidor e dos impostos (aplicados ao
custo de fábrica). Desenvolver um algoritmo
que calcule o custo ao consumidor de
determinado carro.*/

// passos a seguir
/*
	1. Obter o custo de fabrica do carro (custo_fabrica)
	2. Calcular a porcentagem do distribuidor sobre o custo de fabrica (porcent_distribuidor)
	3. Calcular a porcentagem dos impostos sobre o custo de fabrica (porcent_impostos)
	4. Somar 
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int factory_cost; // custo de fabrica 
	float percent_distributor; // porcentagem distribuidor
	float percent_tax; // porcentagem imposto
	int consumer_cost; //custo do consumidor
	
	printf("Insira o custo de fábrica: ");
	scanf("%d", &factory_cost);
	
	printf("Insira a porcentagem do distribuidor: ");
	scanf("%f", &percent_distributor);
	
	printf("Insira a porcentagem do imposto: ");
	scanf("%f", &percent_tax);
	
	float distributor_cost;
	float tax_cost;
	
	distributor_cost = factory_cost * (percent_distributor / 100);
	tax_cost = factory_cost * (percent_tax / 100);
	
	consumer_cost = factory_cost + distributor_cost + tax_cost;
	
	printf("custo do distribuidor: %.2f\n", distributor_cost);
	printf("tax_cost: %.2f\n", tax_cost);
	
	printf("O custo final para o cliente fica: %d", consumer_cost);
}





