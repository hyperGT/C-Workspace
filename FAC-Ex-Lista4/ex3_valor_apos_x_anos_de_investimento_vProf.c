/*
	FAETERJ-Rio
	Fundamentos de Algoritmos de Computação
	Turma B
	
	Data: 27/03/2024
	
	Lista de Exercícios IV
	
	QUESTÃO 03: Joãozinho investiu Q reais em uma aplicação com rendimento 
	fixo de R% ao mês. Pede-se a implementação de um programa que calcule 
	o valor (e exiba-o) disponível na conta de Joãozinho após A anos de 
	investimento.
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	float quantia, taxa, rendimento;
	int i, tempo, meses;
	
	//obtendo os valores de entrada
	printf ("Quantia investida: ");
	scanf ("%f", &quantia);
	
	printf ("Taxa de rendimento ao mes: ");
	scanf ("%f", &taxa);
	
	printf ("Tempo de investimento (em anos): ");
	scanf ("%d", &tempo);
	
	//convertendo o tempo para meses
	meses = tempo*12;
	
	//calculando o valor acumulado
	for (i=1;i<=meses;i++)
	{
		/*rendimento = (taxa/100)*quantia;
		quantia = quantia + rendimento;*/
		
		quantia = quantia + (taxa/100)*quantia;
		//quantia += (taxa/100)*quantia;
		//quantia = quantia * (1 + taxa/100);   =>  quantia *= (1 + taxa/100);
	}
	
	//exibindo o valor ao final
	printf ("\n\nValor acumulado: R$ %.2f", quantia);
}
