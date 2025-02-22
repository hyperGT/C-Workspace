/*
QUEST�O 08: Fa�a um programa que leia
um n�mero real x e um n�mero inteiro y.
Em seguida, o programa deve ler 100
n�meros reais e calcular *quantos* destes
est�o no intervalo definido por [x-y,x+y].
*/

#include<stdio.h>

int main(){
	
	float x, valor;
	int y, i, cont=0;
		
	//ler um n�mero real x e um n�mero inteiro y. <------- Intervalo [x-y,x+y]
	printf("Insira X: ");
	scanf("%f", &x);
	
	printf("Insira Y: ");
	scanf("%d", &y);
	
	//o programa vai ler 10 numeros	
	for(i=1; i<=10; i++){
		
		printf("\nInsira um numero: ");
		scanf("%f", &valor);
		
		if((valor>=x-y) && (valor<=x+y)){
			printf("%.2f", valor);
			cont++;
		}
	}
	printf("Quantidade de valores que estao dentro do intervalo: %d", cont);
}
