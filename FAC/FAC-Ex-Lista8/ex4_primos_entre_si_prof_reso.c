/*
	FAETERJ-Rio
	Fundamentos de Algoritmos de Computa��o
	Professor Leonardo Vianna
	
	2023/2 - Turmas A e B
	
	Lista de Exerc�cios VIII
	
	Quest�o 04:
	Na matem�tica, dois n�meros s�o chamados de primos entre si quando o 
	seu �nico divisor em comum � a unidade (ou seja, o n�mero 1). 
	Considerando este conceito, implementar um programa que, dados dois 
	n�meros inteiros, determine se s�o ou n�o primos entre si
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declara��o de vari�veis
	int n1, n2, menor, i, primos;
	
	//obtendo os valores de n1 e n2
	printf ("Entre com dois numeros: ");
	scanf ("%d %d", &n1, &n2);
	
	//determinando o menor entre 'n1' e 'n2'
	menor = (n1<n2)?n1:n2;
	
	primos = 1;  //inicialmente, consideraremos que s�o primos entre si.
	             //Por�m, casomum divisor comum seja encontrado, 'primos'
	             //receber� o valor 0.
		
	//para que 'n1' e n2' sejam primos entre si, n�o podem existir
	//divisores comuns entre eles no intervalo de 2 a 'menor'
	for (i=2;i<=menor;i++)
	{
		//verificando se um divisor comum foi encontrado
		if ((n1%i==0) && (n2%i)==0)
		{
			primos = 0;
		}	
	}	
	
	//verificando se 'n1' e 'n2' s�o primos
	if (primos == 1)
	{
		printf ("\nOs numeros %d e %d sao primos entre si!", n1, n2);
	}
	else
	{
		printf ("\nOs numeros %d e %d NAO sao primos entre si!", n1, n2);
	}
}
