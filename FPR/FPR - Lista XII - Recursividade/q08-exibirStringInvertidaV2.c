/*
Questão 08:
Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.
*/

#include <stdio.h>
#include <string.h>

void exibirStringInvertida(char *str);
void inverteStr(char *str, int i);

void main(){
	
	exibirStringInvertida("Hello World!");
	
}

void exibirStringInvertida(char *str){
	
	inverteStr(str, 0);
}

void inverteStr(char *str, int i){
	
	if(str[i] != '\0'){
		return inverteStr(str, i+1);
		printf("%c", str[i]);
		printf("\n");
	}
}
