/*
	Questão 04:
		Desenvolver uma função que remova de uma
		string s os caracteres compreendidos entre as
		posições p1 e p2.
		Caso p1 ou p2 seja uma posição inválida, a
		função deverá retornar o valor 0 e a remoção de
		caracteres solicitada não será realizada; caso
		contrário, deverá retornar 1 e proceder com o
		que foi pedido.
*/

#include <stdio.h>
#include <string.h>

int removerCaracteres(char *s, int p1, int p2);

void main(){
	
	char s[10];
	int pos1, pos2, ret;
	
	printf("Insira uma palavra: ");
	fflush(stdin);
	gets(s);
	
	printf("Insira p1: ");
	scanf("%d", &pos1);
	
	printf("Insira p2: ");
	scanf("%d", &pos2);
	
	ret = removerCaracteres(s, pos1, pos2);
	
	if(ret == 0){
		printf("Posicoes invalidas");
	}else{
		printf("s: %s\nposicao 1: %d\nposicao 2: %d", s, pos1, pos2);	
	}
}

int removerCaracteres(char *s, int p1, int p2){
	
	int i = p1, j = p2+1, tam = strlen(s);
	
	if((p1<0) || (p1>p2) || (p2>=tam)){
		return 0;
	}else{				
		// percorre o intervalo p1 a p2
		while(i<=p2){ // outras condições possíveis: s[j] == '\0' ou só s[j]
			
			// copia os valores que vem depois do intervalo nas respectivas posições a serem removidas
			s[i] = s[j];		
			i++;
			j++;
		}
		s[i] = '\0';
	}
	return 1;
}
