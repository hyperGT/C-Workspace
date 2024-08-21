/*
	FAETERJ-Rio
	Fundamentos de Algoritmos de Computação
	Professor Leonardo Vianna
	2023/2 - Turma A
	
	Data: 16/11/2023
	
	Lista de Exercícios X
	
	QUESTÃO 06:
	Desenvolver uma função que, dado um número inteiro N, calcule o valor do 
	seguinte somatório:

		S= 1+((n-1)^1)/1! + (n-2)^2/2! + (n-3)^3/3! + ... +1^(n-1)/((n-1)!)
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int potencia (int base, int expoente);
int fatorial (int n);
float soma (int n);

//main
void main ()
{
	//declaração de variáveis
	int numero;
	float resultado;
	
	//obtendo o número
	printf ("Entre com um numero: ");
	scanf ("%d", &numero);
	
	//chamando a função
	resultado = soma (numero);
	
	//exibindo o resultado
	printf ("\nResultado = %.1f\n", resultado);
	
}

//implementação das funções
int potencia (int base, int expoente)
{
	//declaração de variáveis]
	int i, pot = 1;
	
	//a cada iteração, o resultado será multiplicado pela 'base'
	for (i=1;i<=expoente;i++)
	{
		pot *= base;
	}	
	
	//retornando o resultado
	return pot;
}

int fatorial (int n)
{
	//declaração de variáveis
	int i, fat = 1;
	
	//a cada iteração, o valor de 'i' será multiplicado e acumulado ao resultado
	for (i=2;i<=n;i++)
	{
		fat *= i;
	}
	
	//retornando o resultado
	return fat;
}

float soma (int n)
{
	//declaração de variáveis
	float s = 1;
	int i;
	
	//variando 'i' para o cálculo de cada parcela do somatório
	for (i=1;i<n;i++)
	{
		s += (float)potencia (n-i,i)/fatorial(i);
	}
	
	//retornando o resultado
	return s;
}
