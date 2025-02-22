/*

Dois vetores.
Um que vai conter os caracteres existentes na string str,
e outro de inteiros, que vai conter, na posi��o equivalente, a quantidade de ocorr�ncias de
cada caracter.
*/

// biblioteca
#include <stdio.h>
#include <string.h>

#define TAM 11

int contagemCaracteres(char *st, char vetSt[], int vetQnt[], int tam);
void exibirInfo(char vSt[], int vQnt[], int tam);

void main(){
	
	int qnt = TAM, vet[qnt], novoTam;
	char str[qnt], vtStr[qnt];
	
	printf("Insira uma string: ");
	fflush(stdin);
	gets(str);
	
	novoTam = contagemCaracteres(str, vtStr, vet, qnt);
	exibirInfo(vtStr, vet, novoTam);
}

int contagemCaracteres(char *st, char vetSt[], int vetQnt[], int tam){
	
	int i, k, j, achou = 0;
	
	// tacando os caracteres presentes em str em um outro vetor de strings
	i = 0;
	k = 0;
	while(st[i] != '\0'){
		
		// inicializando variavel auxiliar de verifica��o
		achou = 0;
		
		// verificando se um caracter C j� est� presente no novo vetor de strings
		for(j = 0; j < tam; j++){
			
			if(st[i] == vetSt[j]){
				vetQnt[j]++; // incrementando toda vez que esbarrar em caracteres iguais
				achou = 1; // caracter repetido encontrado
				break; // encerra o loop
			}
		}
		
		// caso seja a primeira ocorr�ncia do caracter
		if(achou == 0){
			vetSt[k] = st[i]; // copia o caracter para o vetor que contem as strings
			vetQnt[k] = 1; // atualiza a posi��o com a quantidade de ocorrencias
			k++; // atualiza a posi��o e quantidade de elementos nos vetores
		}
		
		i++;
	}
	return k; // Retorna o novo tamanho do vetor de caracteres �nicos
}

void exibirInfo(char vSt[], int vQnt[], int tam){
	
	int i;
	
	printf("\n\n%s\n", vSt);
	
	for(i=0;i<tam;i++){
		printf("%d ", vQnt[i]);
	}
	printf("\n\n");		
}
