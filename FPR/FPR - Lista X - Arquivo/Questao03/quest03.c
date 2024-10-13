/*
Quest�o 03:
Desenvolver uma fun��o que, dado um arquivo
texto, verifique o n�mero de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e s�mbolos).
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
		
		// percorrendo os caracteres do arquivo at� o final
		while(fscanf(arq, "%c", &c) != EOF) //modo: r - read  /  w - write  /  a - append
		{ 
			
			c = toupper(c);
			
			// verificando se � uma letra
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
