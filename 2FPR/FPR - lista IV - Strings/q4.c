/*
	Questão 04:
	Implementar uma função que remova todas as
	ocorrências de determinado caracter em uma
	string.
*/

#include <stdio.h>
#include <string.h>

void removerOcorrencias(char *s, char c);

int main(){
	
	char str[20], caracter;
	
	printf("Insira um texto: ");
	fflush(stdin);
	gets(str);
	
	printf("Insira um caractere para remover: ");
	fflush(stdin);
	scanf("%c", &caracter);
	
	removerOcorrencias(str, caracter);
	
	printf("Texto atualizado: %s\nCaracter removido: %c", str, caracter);
}

void removerOcorrencias(char *s, char c){
	
	int i, pos, strTam = strlen(s);
	
	i = 0;
	while(i<strTam){
		
		if(s[i] == c){
			for(pos = i; pos < strTam; pos++){
				s[pos] = s[pos+1];
			}
		}else{
			i++;
		}
	}
}
