/*
Questão 01:
	Suponha que não existissem as funções strlen,
	strcpy, strcat e strcmp. Pede-se, então, a
	implementação de funções que tenham o
	mesmo objetivo daquelas.
*/

#include <stdio.h>

int stringlenght(char str[]);

int main(){
	
	char st[100];	
	int tamanhoString;
	
	printf("Insira um texto: ");
	gets (st);
	// fgets (st, sizeof(st), stdin) // Lê uma linha inteira, incluindo espaços OBS: é mais seguro que o gets
	
	// st[strcspn(st, "\n")] = "\0"; // Remove o caractere de nova linha '\n', se houver
	
	tamanhoString = stringlenght(st);
	
	printf("%s tem %d letras", st, tamanhoString);
}

int stringlenght(char str[]){
	
	int i = 0;
	
	while(str[i] != '\0'){
		i++;
	}
	
	return i;
}


