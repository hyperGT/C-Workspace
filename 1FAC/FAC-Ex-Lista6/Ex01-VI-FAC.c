/*
QUEST�O 01: 
Fa�a um programa que leia
um n�mero inteiro x e, em seguida, solicite
ao usu�rio outros 50 valores inteiros. Ao
final, o programa deve exibir o total de
m�ltiplos de x fornecidos.
*/

#include<stdio.h>

#define QNT 10

int main(){
	
	int x, v; 
	
	printf("Insira um valor inteiro: ");
	scanf("%d", &x);
	
	int i, contM; //contadores
	for(i=0, contM=0; i<QNT; i++){
		
		printf("Insira um valor: ");
		scanf("%d", &v);
		
		if(v%x==0){
			//printf("\nMultiplo: %d\n\n", v); //mostrando os multiplos na hora em que s�o digitados
			contM++;
		}		
	}	
		
	printf("Total de valores multiplos lidos: %d", contM);
}
