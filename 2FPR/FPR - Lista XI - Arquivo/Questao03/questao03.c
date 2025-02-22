/*
Quest�o 03:
Desenvolver uma fun��o que, dados os nomes
de dois arquivos textos, contendo n�meros
inteiros, um por linha, determine se o primeiro
arquivo est� contido no segundo (ou seja, se
todos os elementos do primeiro tamb�m est�o
no segundo).


arq1 
1
3
2


arq2
2
1
4
*/

#include <stdio.h>

int arqEstaContido (char *nomeArq1, char *nomeArq2);

void main(){
	
	int r;
	r = arqEstaContido ("arqTeste2.txt", "arqB.txt"); // esta contido
	// r = arqEstaContido ("arqTeste1.txt", "arqB.txt"); // Nao esta contido
	
	switch(r){
		case 1:
			printf("O arquivo A esta contido no arquivo B");
			break;
		case 0:
			printf("O arquivo A NAO esta contido no arquivo B");
			break;
		default:
			printf("Erro ao abrir um dos arquivos(ou os dois)");
			break;
	}
}

int arqEstaContido (char *nomeArq1, char *nomeArq2){
	
	FILE *arqA, *arqB;
	int vA, vB, achou;
	
	// abre arquivos para leitura
	arqA = fopen(nomeArq1, "r");
	arqB = fopen(nomeArq2, "r");
	
	if(arqA && arqB){
		
		// percorre o arquivo A
		while(fscanf(arqA, "%d", &vA) != EOF){
			
			achou = 0; 
			
			
			rewind(arqB); // reposiciona o ponteiro de leitura para o in�cio do arquivo B
			// percorre o arquivo B
			while(fscanf(arqB, "%d", &vB) != EOF){
				
				// verifica a existencia do elemento vA no arquivo B
				if(vA == vB){
					achou = 1;
					break;
				}
			}
			
			// verifica se foi encontrado
			if(achou == 0){
				return 0; 
			}
		}
		
		fclose(arqA);
		fclose(arqB);
		return 1;
				
	}else{
		
		if(arqA != NULL) fclose(arqA);
		if(arqB != NULL) fclose(arqB);
		return -1;
	}
}

