/*
Quest�o 01:
	Suponha que n�o existissem as fun��es strlen,
	strcpy, strcat e strcmp. Pede-se, ent�o, a
	implementa��o de fun��es que tenham o
	mesmo objetivo daquelas.
*/

#include <stdio.h>

int stringlenght(char str[]);

int main(){
	
	char st[100];	
	int tamanhoString;
	
	printf("Insira um texto: ");
	gets (st);
	// fgets (st, sizeof(st), stdin) // L� uma linha inteira, incluindo espa�os OBS: � mais seguro que o gets
	
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


