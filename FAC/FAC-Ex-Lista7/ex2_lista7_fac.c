/*
QUEST�O 02: Um fazendeiro realizou um
tratamento sobre sua planta��o de caf�
que gerou um *crescimento constante de C
% em sua produ��o, por ano*.
Considerando que atualmente sua
produ��o anual seja de M u.p.,
implementar um programa que determine
a quantidade de anos necess�ria para que
a produ��o duplique.
*/

#include<stdio.h>

int main(){
	
	float m; //produ��o anual atual 
	float taxaCresc; //taxa de crescimento anual
	int anos=0;
	
	float prod; 
	
	printf("Insira a producao anual atual: ");
	scanf("%f", &m);
	
	printf ("Taxa de crescimento anual: ");
	scanf ("%f", &taxaCresc);	
	
	prod = m; 
	
	while(prod<m*2){
		prod += (prod*(taxaCresc/100));
		anos++;
	}
	printf ("\n\nForam necessarios %d anos para a producao inicial (= %.1f u.p.) duplicar e chegar a %.1f u.p.", anos, m, prod);
}
