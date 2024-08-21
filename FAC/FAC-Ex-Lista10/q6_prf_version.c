/*
	FAETERJ-Rio
	Fundamentos de Algoritmos de Computa��o
	Professor Leonardo Vianna
	2023/2 - Turma A
	
	Data: 16/11/2023
	
	Lista de Exerc�cios X
	
	QUEST�O 06:
	Desenvolver uma fun��o que, dado um n�mero inteiro N, calcule o valor do 
	seguinte somat�rio:

		S= 1+((n-1)^1)/1! + (n-2)^2/2! + (n-3)^3/3! + ... +1^(n-1)/((n-1)!)
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int potencia (int base, int expoente);
int fatorial (int n);
float soma (int n);

//main
void main ()
{
	//declara��o de vari�veis
	int numero;
	float resultado;
	
	//obtendo o n�mero
	printf ("Entre com um numero: ");
	scanf ("%d", &numero);
	
	//chamando a fun��o
	resultado = soma (numero);
	
	//exibindo o resultado
	printf ("\nResultado = %.1f\n", resultado);
	
}

//implementa��o das fun��es
int potencia (int base, int expoente)
{
	//declara��o de vari�veis]
	int i, pot = 1;
	
	//a cada itera��o, o resultado ser� multiplicado pela 'base'
	for (i=1;i<=expoente;i++)
	{
		pot *= base;
	}	
	
	//retornando o resultado
	return pot;
}

int fatorial (int n)
{
	//declara��o de vari�veis
	int i, fat = 1;
	
	//a cada itera��o, o valor de 'i' ser� multiplicado e acumulado ao resultado
	for (i=2;i<=n;i++)
	{
		fat *= i;
	}
	
	//retornando o resultado
	return fat;
}

float soma (int n)
{
	//declara��o de vari�veis
	float s = 1;
	int i;
	
	//variando 'i' para o c�lculo de cada parcela do somat�rio
	for (i=1;i<n;i++)
	{
		s += (float)potencia (n-i,i)/fatorial(i);
	}
	
	//retornando o resultado
	return s;
}
