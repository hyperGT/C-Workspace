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


Vers�o atual: for
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
	
	// verificando se b � maior que a
	if(b > a){
		
		// variando ate o valor chegar a b (sendo 'b' o maior valor)
		for(i = a; i<=b; i++){
			
			// mostrando todos os valores (exceto os multiplos de c) dentro do intervalo a-b
			if(i%c!=0){
				printf("%d, ", i);
			}
		}

	} else{ // caso n�o seja
		
		// variando ate o valor chegar a b (sendo o 'a' o maior valor)
		for(i = a; i>=b; i--){
			
			// mostrando todos os valores (exceto os multiplos de c) dentro do intervalo a-b
			if(i%c!=0){
				printf("%d, ", i); 
			}
		}
		
	}
	
	
	
	
}
