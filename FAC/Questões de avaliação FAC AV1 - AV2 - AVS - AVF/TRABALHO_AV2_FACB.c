/*

Observações:
a. Os elementos do vetor devem estar
ordenados crescentemente;
b. Cada operação realizada deve garantir
que o vetor se mantenha ordenado;
c. Nenhum algoritmo de ordenação deve
ser utilizado;
d. São permitidos valores duplicados;
e. Não são permitidas variáveis globais;

Pede-se o desenvolvimento de um programa
que, através de um menu, permita ao usuário
realizar as seguintes operações sobre o vetor
(para cada operação, uma função deve ser
implementada):
1) Inserção de um novo número;
2) Remoção de determinado valor;
3) Remoção do elemento que encontra-se
em uma dada posição;
4) Alteração de um valor por outro;
5) Busca de determinado número,
retornando a sua posição (caso exista
no vetor) ou o valor -1 se não for
encontrado;
6) Exibição de todos os elementos do vetor.
A execução do sistema deve consistir na
exibição do menu seguida da execução da
operação escolhida, repetidas vezes, até que o
usuário opte pela saída do programa.
*/

// importando as bibliotecas
#include <stdio.h>

// declarando as constantes
#define CAP 6

// protótipos das funções
int inserirElemento01(int vet[], int *qnt, int cap, int elemento); // operação #1
void removerOcorrencias02(int vet[], int *qnt, int elemento); // operação #2
int removerValor03(int vet[], int *qnt, int posicao); // operação #3
void alterarValor04(int vet[], int qnt, int valorAntigo, int valorNovo); // operação #4
int buscarElemento05(int vet[], int qnt, int elemento); // operação #5
int buscarInsercao(int vet[], int qnt, int elemento); // operação #5 (retornar posicao para inserir um valor)
void exibir06(int vet[], int qnt); // operação #6

int main(){
	
	int vet[CAP], escolha=0, quant=0, valor, resp=1, remocao, vNovo, posicao;
	
	
	
	
	do{
		
		//exibir(vet, quant);
		printf("\n");
		
		printf("\n 1) Inserir um novo numero");
		printf("\n 2) Remover um determinado valor");
		printf("\n 3) Remover elemento em uma determinada posição");
		printf("\n 4) Alterar um valor por outro");
		printf("\n 5) Buscar um determinado numero");
		printf("\n 6) Exibir vetor");
		printf("\n\n 7) Encerrar Programa");
		printf("\n\n	Escolha uma operacao: ");
		scanf("%d", &escolha);				
				
		
		// menu	
		switch (escolha)
		{
			case 1:				
				if (quant < CAP) {
                    printf("\n\nOperacao escolhida: %d\n\n", escolha);
                    printf("Insira o valor que deseja inserir: ");
                    scanf("%d", &valor);
                    resp = inserirElemento01(vet, &quant, CAP, valor);
                } else {
                    printf("\nNao e possivel adicionar mais elementos\nMotivo: vetor cheio\n");
                }                
				break;
				
			case 2: 
				printf("\n\n");
				if(quant>0){			
					printf("Operacao escolhida: %d", escolha); 
					printf("\n\n");
					exibir06(vet, quant);
					printf("Insira o valor que deseja remover: ");
					scanf("%d", &valor);
					removerOcorrencias02(vet, &quant, valor);
				}else{
					printf("\nNao e possivel realizar a operacao\nMotivo: o vetor esta vazio\n");					
				}
				
				break;
				
			case 3:
				printf("\n\n");
				printf("Operacao escolhida: %d\n\n", escolha); 
				printf("Insira a posicao do valor que deseja remover: ");
				scanf("%d", &valor);
				remocao = removerValor03(vet, &quant, valor);
				if(remocao > 0){					
					printf("\n\n");
					printf("Operacao realizada com sucesso\n\n");					
					printf("Elemento removido: %d\n", remocao);
				}else{
					printf("Valor nao encontrado");
				}
				
				break;
				
			case 4:								
				printf("\n\nOperacao: %d\n\n", escolha);
				printf("Insira o valor a ser trocado: ");
				scanf("%d", &valor);
				printf("\n");
				printf("Insira o valor que vai entrar: ");
				scanf("%d", &vNovo);
				printf("\n");
				alterarValor04(vet, quant, valor, vNovo);
				break;
				
			case 5:				
				printf("\n\nInsira um elemento para buscar: ");
				scanf("%d", &valor);
				posicao = buscarElemento05(vet, quant, valor); 
				if(posicao >= 0){
					printf("Valor a ser encontrado: %d\nPosicao da primeira ocorrencia: %d", valor, posicao);
				}else{
					printf("Valor a ser encontrado: %d\nValor inexistente", valor);
				}
				break;
				
			case 6:											
				printf("\n------------VETOR----------------\n");
				exibir06(vet, quant); // exibindo vetor
				printf("\nQuantidade de elementos: %d", quant);
				printf("\nCapacidade maxima: %d", CAP);
				break;
			case 7:
				printf("Programa Encerrado");
				break;				
			default: 				
				printf("\n\nValor invalido, nenhuma operacao sera realizada.\n\n");				
		}
		
	}while(escolha!=7);
	
	
}


int inserirElemento01(int vet[], int *qnt, int cap, int elemento){	
	
	int i, posicao;
	
	if(*qnt<cap){
		// obtendo a posição na qual o elemento deve ser inserido
		posicao = buscarInsercao(vet, *qnt, elemento);
		
		// deslocando os valores para a direita
		for(i=*qnt-1; i>=posicao ; i--){
			vet[i+1] = vet[i];
		}
		
		// adicionando o novo elemento no vetor na posição retornada, depois de deslocar os valores e alocar espaço
		vet[posicao] = elemento;
		
		// atualizando a quantidade de elementos do vetor
		(*qnt)++;
		
		// a insercao foi um sucesso
		return 1;		
						
	}else{
		// extrapolou a capacidade do vetor, logo, não é possível acrescentar mais elementos.
		return 0;
	}	

}


void removerOcorrencias02(int vet[], int *qnt, int elemento){
	
	int i, j;
	
	// inicializando o 'i'
	i=0;
	
	// variando o 'i' até a quantidade atual total de elementos do vetor
	while(i<(*qnt)){
	
		if(vet[i] == elemento){

			// percorre a partir do i até o tamnho atual do vetor -1 
			for(j=i; j<(*qnt-1); j++){
				// deslocando todos os valores para esquerda
				vet[j] = vet[j+1];
			}
			// atualiza a quantidade de elementos existentes no vetor
			(*qnt)--;
			
			// decrementando o 'i' para testar o valor anterior novamente			
		}else{
			i++;
		}
	}
	
}


int removerValor03(int vet[], int *qnt, int posicao){
	
	int i, valorRemovido;
		
	if(posicao<*qnt){
		
		valorRemovido = vet[posicao];
		
		// deslocando os valores para esquerda
		for(i=posicao; i<*qnt - 1; i++){
			vet[i]=vet[i+1];  
		}
		// atualizando a qnt de valores no vetor
		(*qnt)--;
		
		return valorRemovido; // retornando o valor removido
		 
	}else{
		return -1; // valor não encontrado no vetor		
	}
		
}

void alterarValor04(int vet[], int qnt, int valorAntigo, int valorNovo){		
	
	// NOTA: manter os vetores ordenados e adicionar a mesma quantidade de valores que foram removidos
	int qntAntiga = qnt, i, j;
	
	// Removendo todas as ocorrências do valor antigo
    removerOcorrencias02(vet, &qnt, valorAntigo);
	
	j = qntAntiga - qnt; // obtendo a quantidade de valores removidos para inserir a mesma quantidade
	for(i=0; i<j; i++){		
    	// Usando a função pronta para Inserir o novo valor na posição correta 
    	inserirElemento01(vet, &qnt, CAP, valorNovo);
	}
		
}

int buscarElemento05(int vet[], int qnt, int elemento){
	
	int i;
	
	// varrendo o vetor para verificar a existencia do elemento requisitado
	for(i=0; i<qnt; i++){
		if(vet[i] == elemento){
			return i; // retornando sua posição caso encontre
		}
	}
	return -1; // retornando -1 caso não encontre			
}

int buscarInsercao(int vet[], int qnt, int elemento){
	
	int i;
	// percorrendo o vetor inteiro
	for(i=0;i<qnt;i++){			 
		
		// se o valor do vetor na posição 'i' chegar a ser maior que elemento, retorna a posição 'i'
		if(vet[i]>=elemento){
			return i; // retornando a posicao no qual está ou deveria estar o valor
		}
	}
	// retornando a posição de 'i' no caso do elemento a ser inserido ser o maior valor do vetor
	return i;					
}


void exibir06(int vet[], int qnt){
	
	int i;
		
	printf("\nVetor: ");
	
	for(i=0;i<qnt;i++){
		printf("%d ", vet[i]);
	}
	
	printf("\n\n");
}
