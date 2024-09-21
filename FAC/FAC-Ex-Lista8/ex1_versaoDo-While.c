/*
Quest�o 01:
Dados tr�s n�meros inteiros a, b e c,
implementar um programa que exiba os
n�meros do intervalo definido por a e b
(sempre come�ando em a e terminando em b),
com exce��o daqueles que sejam m�ltiplos de
c.
Exemplos:
a = 10, b = 20, c = 3
Sa�da: 10, 11, 13, 14, 16, 17, 19, 20
a = 25, b = 18, c = 5
Sa�da: 24, 23, 22, 21, 19, 18
Nota: devem ser apresentadas tr�s vers�es do
programa, uma para cada estrutura de
repeti��o estudada.


Vers�o atual: do-while
*/

#include <stdio.h>

int main(){
	
	// inicializando as vari�veis
	int a, b, c, aux, i;
	
	// obtendo os valores
	printf("Insira o valor de A: ");
	scanf("%d", &a);
	
	printf("Insira o valor de B: ");
	scanf("%d", &b);
	
	printf("Insira o valor de C: ");
	scanf("%d", &c);
	
	i = a;
	if(b > a){
		
		
		do{	
							
			if(i%c!=0){
				printf("%d, ", i);
			}
			
			i++;
			
		}while(i<=b);
		
		printf("...");
		
	}
	else{
		
		do{
			
			if(i%c!=0){
				printf("%d, ", i);				
			}
			i--;
		}while(i>=b);
		
		printf("...");
	}
}