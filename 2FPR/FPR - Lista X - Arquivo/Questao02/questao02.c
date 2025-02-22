/*
Questão 02:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.
*/

// bibliotecas
#include <stdio.h>

// funções
int qntVezesCaracter (char *nomeArquivo, char c);

void main(){
	
	char *nomeArq = "questao02.txt";
	int qntVzs;
	char ch = 'r';
	
	qntVzs = qntVezesCaracter(nomeArq, ch);
	
	printf("Exibindo quantidade de vezes que o caracter '%c' apareceu: %d vezes", ch, qntVzs);
}

// implementações
int qntVezesCaracter (char *nomeArquivo, char c){
	
	FILE *arq;
	int cont = 0;
	char c1;
	
	// abrindo o arquivo para leitura
	arq = fopen(nomeArquivo, "r");
	
	// verificando se o arquivo foi aberto 
	if(arq != NULL){
	
		while(fscanf(arq, "%c", &c1) != EOF){
			if(c1 == c){
				cont++;
			}
		}
		fclose(arq);
		return cont;
	}else{
		return 0;
	}
}
