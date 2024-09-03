/*
	Questão 01:
		Implementar uma função que, dada uma string
		s, determine a quantidade de caracteres
		distintos em s.
*/

#include <stdio.h>
#include <string.h>

int qntDistintos(char *s);

void main(){
	
	char s[10];
	int qntD;
	
	printf("Insira uma palavra: ");
	fflush(stdin);
	gets(s);
	
	qntD = qntDistintos(s);
	
	printf("Quantidade de caracteres distintos: %d", qntD);
}

int qntDistintos(char *s){
	
	int i, j, cont=0, distinto;
	
	i = 0;
	while(s[i]){
		
		distinto = 1;
		for(j=i-1; j>=0; j--){
			
			if(s[j]==s[i]){
				distinto = 0;
				break;
			}
		}
		
		if(distinto == 1){
			cont++;
		}
		i++;
	}
	return cont;
}
