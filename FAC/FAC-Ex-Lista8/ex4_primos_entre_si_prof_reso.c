/*
	FAETERJ-Rio
	Fundamentos de Algoritmos de Computação
	Professor Leonardo Vianna
	
	2023/2 - Turmas A e B
	
	Lista de Exercícios VIII
	
	Questão 04:
	Na matemática, dois números são chamados de primos entre si quando o 
	seu único divisor em comum é a unidade (ou seja, o número 1). 
	Considerando este conceito, implementar um programa que, dados dois 
	números inteiros, determine se são ou não primos entre si
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int n1, n2, menor, i, primos;
	
	//obtendo os valores de n1 e n2
	printf ("Entre com dois numeros: ");
	scanf ("%d %d", &n1, &n2);
	
	//determinando o menor entre 'n1' e 'n2'
	menor = (n1<n2)?n1:n2;
	
	primos = 1;  //inicialmente, consideraremos que são primos entre si.
	             //Porém, casomum divisor comum seja encontrado, 'primos'
	             //receberá o valor 0.
		
	//para que 'n1' e n2' sejam primos entre si, não podem existir
	//divisores comuns entre eles no intervalo de 2 a 'menor'
	for (i=2;i<=menor;i++)
	{
		//verificando se um divisor comum foi encontrado
		if ((n1%i==0) && (n2%i)==0)
		{
			primos = 0;
		}	
	}	
	
	//verificando se 'n1' e 'n2' são primos
	if (primos == 1)
	{
		printf ("\nOs numeros %d e %d sao primos entre si!", n1, n2);
	}
	else
	{
		printf ("\nOs numeros %d e %d NAO sao primos entre si!", n1, n2);
	}
}
