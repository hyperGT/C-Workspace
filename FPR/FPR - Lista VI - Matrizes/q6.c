/*
	QUESTÃO 06:
		Considere uma loja que mantém em uma
		matriz o total vendido por cada funcionário
		pelos diversos meses do ano. Ou seja, uma
		matriz de 12 linhas (uma por mês) e 10 colunas
		(10 funcionários). Pede-se o desenvolvimento
		de uma função para cada item abaixo:
		a. Calcular o total vendido durante o ano;
		b. Dado um mês fornecido pelo usuário,
		determinar o total vendido nesse mês;
		c. Dado um funcionário fornecido pelo
		usuário, determinar o total vendido por ele
		durante o ano;		
		d. Determinar o mês com maior índice de
		vendas;	
		e. Determinar o funcionário que menos
		vendeu durante o ano.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#define MES 12
#define FUN 10

float totalVendas (int l, int c, float m[l][c]);
float totalMes (int l, int c, int mes, float m[l][c]);
float totalFunc (int l, int c, int f, float m[l][c]);
int maiorIndiceVendas (int l, int c, float m[l][c]);
int funcMenorIndice (int l, int c, float m[l][c]);

// func auxiliares
void preencher (int l, int c, float m[l][c]);
void exibir (int l, int c, float m[l][c]);

int main(){
	
	// declaração de variáveis
	int lin = MES, col = FUN, mes, func, maiorIndice, funcM;
	float m[lin][col], somaAno, somaMes, somaFun;
	
	preencher (lin, col, m);
	exibir (lin, col, m);
	
	// a
	somaAno = totalVendas (lin, col, m);
	printf("total de vendas: %.0f\n", somaAno);
	
	// b
	printf("\n\nInsira um mes para exibir o total de vendas: ");
	scanf("%d", &mes);
	somaMes = totalMes (lin, col, mes, m);
	printf("Total de vendas do Mes %d: %.0f\n", mes, somaMes);
	
	// c
	printf("\n\nInsira o numero do funcionario para exibir o total de vendas: ");
	scanf("%d", &func);
	somaFun = totalFunc (lin, col, func, m);
	printf("Total de vendas do Funcionario %d: %.0f\n", func, somaFun);	
	
	// d
	maiorIndice = maiorIndiceVendas (lin, col, m);
	printf("\n\n----Exibindo Mes com maior indice de vendas: %d\n", maiorIndice);
	
	// e
	funcM = funcMenorIndice (lin, col, m);
	printf("\n\n----Exibindo Funcionario com menor indice de vendas: %d", funcM);
}

float totalVendas (int l, int c, float m[l][c]){
	
	int i, j, soma = 0;
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			soma += m[i][j];
		}
	}
	return soma;
}

float totalMes (int l, int c, int mes, float m[l][c]){
	
	int i, soma = 0;
	
	// percorrendo as linhas da coluna inserida
	for(i = 0; i < c; i++){
		//printf("%.0f ", m[i][mes]);
		soma += m[mes][i]; // somando todas as linhas da coluna 'mes'
	}
	
	return soma;
}

float totalFunc (int l, int c, int f, float m[l][c]){
	
	int i, soma = 0;
	
	for(i = 0; i < l; i++){
		soma += m[i][f];
	}
	
	return soma;
}

int maiorIndiceVendas (int l, int c, float m[l][c]){
	
	int i, j, mes = 0;
	float maior = FLT_MIN, somaMes;
	
	// mes ...
	
	for(i = 0; i < l; i++){
		somaMes = 0;
		for(j = 0; j < c; j++){
			somaMes += m[i][j];			
		}
		
		if(somaMes > maior){
			maior = somaMes;
			mes = i;
		}
	}
	
	return mes;
}

int funcMenorIndice (int l, int c, float m[l][c]){

	int i, j, fun;
	float menor = FLT_MAX, somaFunc;
	
	for(j = 0; j < c; j++){
		somaFunc = 0;
		for(i = 0; i < l; i++){
			somaFunc += m[i][j];
		}
		if(somaFunc < menor){
			menor = somaFunc;
			fun = j;
		}
	}
	
	return fun;
}

// auxiliares
void preencher (int l, int c, float m[l][c]){
	
	int i, j;
	
	srand(time(NULL));
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			m[i][j] = rand()%10;
		}
		printf("\n");
	}
}

void exibir (int l, int c, float m[l][c]){
	
	int i, j;
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%.0f ", m[i][j]);
		}
		printf("\n");
	}
}
