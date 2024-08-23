/*
	Exercício: desenvolver uma função que, dada uma string 's', 
	determine se é ou não um palíndromo.
*/

#include <stdio.h>
#include <string.h>

int 
palindromo (char *s);

int main(){
	
	char str[10], r;
	
	printf("Insira um texto: ");
	fflush(stdin);
	gets(str);
	
	r = palindromo(str);
	
	if(r > 0){
		printf("E um palindromo");
	}else{
		printf("NAO e um palindromo");
	}
}

palindromo (char *s){
	
	int i, j = strlen(s) -1;
	
	i = 0;
	while(i < j){
		
		if(s[i] != s[j]){
			return -1;
		}		
		
		j--;
		i++;
	}
	return 1;
}
