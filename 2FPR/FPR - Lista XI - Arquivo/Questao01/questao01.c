/*
Questão 01:
Considere a existência de um arquivo texto,

contendo números inteiros, um por linha. Pede-
se a implementação de uma função que, dado

um arquivo como especificado, crie um segundo
arquivo texto contendo, para cada elemento do
original, o seu valor e a quantidade de
ocorrências naquele arquivo (ambos os dados
na mesma linha do novo arquivo).


arquivo 1 
10	
12
7
10
15
2
7
15
7
8
10
14
12
8
15

Arquivo 2
10 3
12 2
7 3
15 3
2 1
8 2
14 1
*/

#include <stdio.h>
#define TAM 100

int contaValoresArquivo(char *nomeArq, char *novoArq);

int main() {
    int resultado = contaValoresArquivo("arqA.txt", "arqB.txt");

    if (resultado == 1) {
        printf("Arquivo gerado com sucesso!\n");
    } else {
        printf("Erro ao abrir os arquivos!\n");
    }

    return 0;
}

int contaValoresArquivo(char *nomeArq, char *novoArq){
	
	/*
	k/i/j/cont/qnt == representa uma variavel de contagem 
	achou/verify/found == representa uma variavel do tipo booleana, porem representada com os valores inteiros 1 e 0
	*/

	FILE *arqA, *arqB;
	int v1, k, i, vetAux[TAM], vetCont[TAM], achou;
	
	
	arqA = fopen(nomeArq, "r");
	arqB = fopen(novoArq, "a");
	
	if(arqA && arqB){ // se conseguir abrir o arquivo (arq != NULL)
		
		k = 0;
		// percorrendo o arquivo principal
		while(fscanf(arqA, "%d", &v1) != EOF){
			
			
			achou = 0;
			// verificando se o valor já existe no vetor (novo arquivo)
			for(i = 0; i < k; i++){
				
				// registra mais uma ocorrencia do valor no vetor auxiliar de contagem
				if(vetAux[i] == v1){
					vetCont[i]++;
					achou = 1;
					break;
				}
			}
						
			if(achou == 0){
			    vetAux[k] = v1;   // Adiciona novo valor ao vetor auxiliar
			    vetCont[k] = 1;   // Inicializa a contagem desse valor
			    k++;              // Atualiza a posição
			}
		}
		
		// percorrendo os vetores
		for(i = 0; i < k; i++){
			// escreve os valores armazenados nos vetores no novo arquivo
			fprintf(arqB, "%d %d\n", vetAux[i], vetCont[i]);
		}
		
		fclose(arqA);
		fclose(arqB);
		
		return 1; // sucesso		
	}else{		
		fclose(arqA);
		fclose(arqB);
		return 0; // erro ao abrir o arquivo
	}
}
