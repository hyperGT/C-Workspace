/*
	Questão 02:
		Implementar uma função que, dadas duas
		strings s1 e s2, crie uma nova string – s3 –
		contendo todos os caracteres de s1 que não
		estejam em s2.
		Nota: em s3, não devem existir caracteres
		repetidos.
*/

#include <stdio.h>
#include <string.h>

void newString(char *s1, char *s2, char *s3);
int buscaChar(char *s, char c);

void main(){
	
	char st1[10], st2[10] = "mamis", st3[10];	
	
	printf("Insira uma palavra: ");
	fflush(stdin);
	gets(st1);
	
	newString(st1, st2, st3);
	
	printf("S1: %s\nS2: %s\nS3: %s", st1, st2, st3);
}

void newString(char *s1, char *s2, char *s3){
	
	// declarando as variáveis
	int i, j;
	
	// inicializa s3 como uma string vazia
	s3[0] = '\0';
	
	// inicializa o 'i'	com 0
	i = 0;
	// percorre a string s1
	while(s1[i]){
		
		// verifica se o caracter de s1[i] está em s2 && verifica se o caractere em questão já existe em s3
		if((buscaChar(s2, s1[i]) == 0) && ((buscaChar(s3, s1[i]) == 0))){
			
			// coloca o valor de s1 em s3
			s3[j] = s1[i];
			j++;
		}
		i++;
		s3[j] = '\0';
	}
}

int buscaChar(char *s, char c){
	
	// declarando as variáveis
	int i;
	
	// inicializa o 'i'	com 0
	i = 0;
	
	// percorrendo a string
	while(s[i]){
		
		// verifica a existencia do caracter nessa string comparando cada caracter dela
		if(s[i] == c){
			return 1; // retorna 1 caso encontre
		}
		i++;
	
	}
	return 0;
}
