/*
Questão 01:
	Suponha que não existissem as funções strlen,
	strcpy, strcat e strcmp. Pede-se, então, a
	implementação de funções que tenham o
	mesmo objetivo daquelas.
*/

#include <stdio.h>
#include <string.h>

void strgCat(char *s, char *s1, char *s2){
	
	int i, j = strlen(s1);
	
	strcpy(s, s1);
	
	i = 0;	
	while(s2[i]){
		
		s[j] = s2[i]; // abcd efgh
		
		i++;
		j++;	
	}
	
}

int main(){
	
	char text[100], t1[20], t2[80];
	
	printf("Insira um texto: ");
	fflush(stdin);
	gets(t1);
	
	printf("Insira outro texto: ");
	fflush(stdin);
	gets(t2);
		
	strgCat(text, t1, t2);
	
	printf("Bem vindo, %s", text);
}
