/*
	Quest�o 03:
		Desenvolver uma fun��o que, dada uma string
		s, crie uma substring que inicie na posi��o p de
		s e contenha n caracteres.
		
		
		Observa��es: se p e/ou n forem inv�lidos, a
		substring ser� vazia; ii) se s n�o possuir n
		caracteres al�m de p, a substring a ser criada
		come�ar� em p e terminar� no final de s.
*/
#include <stdio.h>
#include <string.h>

int cutString (char *s, char *subS, int p, int n){
	
	int i, j, strTam = strlen(s);
	
	i = p;
	j = 0;
	
	while((i<=n) || (i<strTam)){
		
		if((p<0) || (n<0)){
			subS = "";
			return 0;
		}
		
		subS[j] = s[i];
		
		i++;
		j++;
	}
	return 1;	
}


int main(){
	char str[10], subStr[20];
	int inicio, fim;
	
	printf("Insira um texto: ");
	fflush(stdin);
	gets(str);
	
	printf("Insira p: ");
	scanf("%d", &inicio);
	
	printf("Insira n: ");
	scanf("%d", &fim);
	
	cutString(str, subStr, inicio, fim);
	
	printf("String: %s\nSubString: %s", str, subStr);
}
