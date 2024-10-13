/*
Questão 02:
Dados um arquivo texto arq e uma string s,
desenvolver uma função que exclua de arq
todos as ocorrências dos caracteres que estão
em s.
*/

#include <stdio.h>
#include <string.h>

int excluirOcorrenciasStr (char *s, char *nomeArq);

void main(){
	
	int resp; 
		
	resp = excluirOcorrenciasStr ("rato", "arq.txt");
	
	if(resp == 1){
		printf("Deu tudo certo");
	}else{
		printf("Erro na abertura dos arquivos");
	}
}

int excluirOcorrenciasStr (char *s, char *nomeArq){
	
	FILE *arq, *arqAux;
	char c;
	int found, i;
		
	arq = fopen(nomeArq, "r"); // abre o arquivo para leitura
	arqAux = fopen("temp.txt", "w");
	
	if(arq && arqAux){
		
		// percorrendo todos os caracteres do arquivo
		while(fscanf(arq, "%c", &c) != EOF){
			
			found = 0;
			// percorrendo a string s
			for(i=0; s[i]; i++){
				
				// verificando se esse caracter está presente na string s
				if(s[i] == c){
					found = 1;
					break;
				}				
			}
			
			if(found == 0){
				fprintf(arqAux, "%c", c);
			}
		}
		
		fclose(arq);
		fclose(arqAux);
		
		remove(nomeArq); // deleta o arquivo original
		rename("temp.txt", nomeArq); // renomeia o arquivo temporário para o nome do arquivo original
		
		return 1;
	}else{
		
		fclose(arq);
		fclose(arqAux);		
		return 0;
	}
}
