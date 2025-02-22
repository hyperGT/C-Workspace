/*
Questão 01:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.
*/

#include <stdio.h>

int verificaNumeroCaracteres (char *nomeArq);

void main(){
	
	int qntTotalCaracteres;
	char *nomeArquivo = "arq.txt";
	
	qntTotalCaracteres = verificaNumeroCaracteres(nomeArquivo);
	
	printf("Quantidade total de caracteres: %d\n", qntTotalCaracteres);
}

int verificaNumeroCaracteres (char *nomeArq){
	
	FILE *arq;
	int cont = 0;	
	char c;
	
	// abrindo o arquivo para leitura
	arq = fopen(nomeArq, "r");
	
	// verificando se o arquivo foi aberto
	if(arq != NULL){
		
		// lendo individualmente cada caracter até o final do arquivo
		while(fscanf(arq, "%c", &c) != EOF){ // EOF - End Of File
			
			if(!isspace(c)){
				cont++;				
			}
		}
		
		fclose(arq);		
		return cont;		
	}else{		
		return 0;
	}
}
