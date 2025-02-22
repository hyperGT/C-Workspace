/*
	Quest�o 03:
		Desenvolver uma fun��o, em C, que, dada uma
		string s e dada uma posi��o p desta string, crie duas
		novas strings: s1 com os caracteres de s das
		posi��es 0 a p-1; e s2 com os caracteres de s da
		posi��o p � �ltima.
	
		Nota: Caso p seja uma posi��o inv�lida, a fun��o
		dever� retornar o valor 0; caso contr�rio,
		proceder� com a cria��o das duas strings e
		retornar� o valor 1.
*/

#include <stdio.h>
#include <string.h>


int newStrings(char *s1, char *s2, char *s, int p);
//int buscaChar(char *s, char c);

void main(){
	
	// declara��o de variaveis
	char s[10], s1[10], s2[10];	
	int pos, ret;
	
	// entrando com a string s
	printf("Insira uma palavra: ");
	fflush(stdin);
	gets(s);
	
	// entrando com a posicao p
	printf("Insira a posicao: ");
	scanf("%d", &pos);
	
	// chamando a fun��o
	ret = newStrings(s1, s2, s, pos);
	
	// exibindo os resultados
	if(ret == 0){
		printf(" ---Posicao invalida--- ");
		printf("Retorno: %d\ns: %s\ns1: %s\ns2: %s", ret, s, s1, s2);
	}else{		
		printf("Retorno: %d\ns: %s\ns1: %s\ns2: %s", ret, s, s1, s2);
	}
}

int newStrings(char *s1, char *s2, char *s, int p){
	
	// declara��o de vari�veis
	int i, j, tam = strlen(s);
	
	
	// Caso p seja uma posi��o inv�lida, a fun��o dever� retornar o valor 0;
	if((p<0)||(p>tam)){
		return 0;
	}else{
		
		// s1 com os caracteres de s das posi��es 0 a p-1;
		for(i = 0; i < p; i++){
			s1[i] = s[i];
		}
		
		// s2 com os caracteres de s da  posi��o p � �ltima.
		for(j = 0; s[i]; i++, j++){
			s2[j] = s[i];
		}		
	}
	return 1; // retornado 1 pois tudo deu certo
}
