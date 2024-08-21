/*
Questão 01:
	Suponha que não existissem as funções strlen,
	strcpy, strcat e strcmp. Pede-se, então, a
	implementação de funções que tenham o
	mesmo objetivo daquelas.
*/

#include <stdio.h>

void stcpy(char s1[], char s2[]){
	
	int i = 0, j = 0;
	
	/*
	while(s2[i]){
		
		s1[i] = s2[j];
		
		i++;
		
		j++;
	}*/
	
	// ou 
	for(i = 0, j = 0; s2[i] != '\0'; i++, j++){
		s1[i] = s2[j];
	}
	
	s1[i] = '\0';
}

int main(){
	
	char strC[100], str[30];
	
	printf("Insira um texto: ");
	gets(str);
	
	stcpy(strC, str);
	
	printf("Texto copiado: %s\nTexto 2: %s\n", strC, str);
	
	printf("Insira um novo texto para substituir a string original: ");
	gets(str);
	
	printf("Texto copiado: %s\nTexto 2: %s\n", strC, str);
	
}
