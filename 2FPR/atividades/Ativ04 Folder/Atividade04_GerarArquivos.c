/*
Atividade 4 - Arquivos

Dado um arquivo texto, contendo números inteiros, um por linha, 
criar um arquivo novo.txt apenas com os elementos
do original que, na ordem que foram lidos, 
fazem com que o novo arquivo esteja ordenado crescentemente. 
Todos os demais valores que “atrapalharam” essa ordenação serão armazenados 
em no arquivo descartados.txt.

*/

// importação de bibliotecas
#include <stdio.h>
#include <limits.h>

// protótipos das funções
int gerarArquivoOrdenado (char *nomeArq);

void main(){
	
	if(gerarArquivoOrdenado("arq.txt") == 1){
		printf("Arquivos gerados com sucesso");
	}else{
		printf("Erro ao abrir os arquivos");
	}
	
}

// implementação das funções
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
