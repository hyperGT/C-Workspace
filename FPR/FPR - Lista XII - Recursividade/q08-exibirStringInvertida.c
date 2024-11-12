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
	
	inverteStr(str, strlen(str)-1);
}

void inverteStr(char *str, int i){
	
	if(i<0){
		return;
	}else{
		
		printf("%c", str[i]);
		return inverteStr(str, i-1);
	}
	
}
