/*
Questão 03:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).
*/

#include <stdio.h>

int numQntLetrasArquivo (char *nomeArq);

void main(){
	
	int resp;
	
	resp = numQntLetrasArquivo ("teste.txt");
	
	if(resp > 0){
		printf("%d letras encontradas no arquivo\n", resp);
	}else if(resp == 0){
		printf("0 letras encontradas no arquivo\n");
	}else{
		printf("Erro ao abrir o arquivo\n");
	}
}

int numQntLetrasArquivo (char *nomeArq){
	
	FILE *arq;
	int cont = 0;
	char c;
	
	arq = fopen (nomeArq, "r"); //modo: r - read  /  w - write  /  a - append
	
	if(arq != NULL){
		
		// percorrendo os caracteres do arquivo até o final
		while(fscanf(arq, "%c", &c) != EOF) //modo: r - read  /  w - write  /  a - append
		{ 
			
			c = toupper(c);
			
			// verificando se é uma letra
			if(c >= 'A' && c <= 'Z')
			{
				cont++;
			}
		}
		
		fclose(arq);
		return cont;
				
	}else{		
		return -1;
	}
}
