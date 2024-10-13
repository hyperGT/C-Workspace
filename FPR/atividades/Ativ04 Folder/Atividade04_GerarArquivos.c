/*
Atividade 4 - Arquivos

Dado um arquivo texto, contendo n�meros inteiros, um por linha, 
criar um arquivo novo.txt apenas com os elementos
do original que, na ordem que foram lidos, 
fazem com que o novo arquivo esteja ordenado crescentemente. 
Todos os demais valores que �atrapalharam� essa ordena��o ser�o armazenados 
em no arquivo descartados.txt.

*/

// importa��o de bibliotecas
#include <stdio.h>
#include <limits.h>

// prot�tipos das fun��es
int gerarArquivoOrdenado (char *nomeArq);

void main(){
	
	if(gerarArquivoOrdenado("arq.txt") == 1){
		printf("Arquivos gerados com sucesso");
	}else{
		printf("Erro ao abrir os arquivos");
	}
	
}

// implementa��o das fun��es
int gerarArquivoOrdenado (char *nomeArq){
	
	FILE *arqOriginal, *novoArq, *descArq;
	int anterior = INT_MIN, v;
	
	arqOriginal = fopen(nomeArq, "r");
	novoArq = fopen("novo.txt", "a");
	descArq = fopen("descartados.txt", "a");
	
	if(arqOriginal && nomeArq && descArq){
				
		while(fscanf(arqOriginal, "%d", &v) != EOF){
			
			if(v > anterior){
				anterior = v;
				fprintf(novoArq, "%d\n", v);
			}else{
				fprintf(descArq, "%d\n", v);
			}
		}
		
		fclose(arqOriginal);
		fclose(novoArq);
		fclose(descArq);
		
		return 1;
	}else{
		
		fclose(arqOriginal);
		fclose(novoArq);
		fclose(descArq);
		
		return 0;
	}
	
}
