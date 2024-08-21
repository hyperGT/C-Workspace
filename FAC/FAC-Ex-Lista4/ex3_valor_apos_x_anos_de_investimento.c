/*
Jo�ozinho investiu Q reais em
uma aplica��o com rendimento fixo de R% ao
m�s. Pede-se a implementa��o de um
programa que calcule o valor (e exiba-o)
dispon�vel na conta de Jo�ozinho ap�s A anos
de investimento.

Valor futuro = Valor principal x (1 + taxa de juros) ^ tempo.
Os rendimentos seriam a diferen�a entre o valor futuro e o valor principal.
*/


#include<stdio.h>

int main(){
	
	float quantia, taxa, rendimento;
	int tempo, meses;
	
	//obtendo o valor investido em reais
	printf("Insira o valor investido em reais: ");
	scanf("%f", &quantia);
	
	//obtendo o valor do rendimento fixo
	printf("Insira o valor do rendimento fixo: ");
	scanf("%f", &taxa);
		
	//obtendo a quantidade de anos que ficar� o valor investido
	printf("Insira a quantidade de tempo que ficara o valor investido (em anos): ");
	scanf("%d", &tempo);
	
	meses = tempo*12;

	/*
	Valor futuro = Valor principal x (1 + taxa de juros) ^ tempo.
Os rendimentos seriam a diferen�a entre o valor futuro e o valor principal.
	*/	
	
	int i;
	for(i = 1; i<=meses; i++){ //elevando a 12 j�
		quantia *= (1 + taxa/100);
	}
	
	printf("\n\nTotal: %.2f", quantia);
	
	
	
}
