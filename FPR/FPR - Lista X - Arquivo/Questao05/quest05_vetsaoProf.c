/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turmas Manhã e Noite
	Data: 28/09/2024 (aula extra)
	
	Lista de Exercícios X (Arquivos)
	
	Questão 05:
	Faça uma função que, dado um arquivo A contendo números reais, um por linha, crie um novo arquivo B 
	contendo os mesmos elementos de A, porém ordenados decrescentemente e sem repetição.
*/

//importação de bibliotecas
#include <stdio.h>
#include <limits.h>

//protótipos das funções
int criarArquivoOrdenado (char nomeArqOriginal[], char nomeArqNovo[]);
int calcularMaiorValor (char nomeArq[], int limite, int *maior);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivoOriginal[30], nomeArquivoNovo[30];;
	int resp;
	
	//lendo os nomes dos arquivos
	printf ("Nome do arquivo original: ");
	fflush (stdin);
	gets (nomeArquivoOriginal);
	
	printf ("Nome do novo arquivo: ");
	fflush (stdin);
	gets (nomeArquivoNovo);
	
	//chamando a função
	resp = criarArquivoOrdenado (nomeArquivoOriginal, nomeArquivoNovo);
	
	//exibindo o resultado
	if (resp == 1)
	{
		printf ("\n\nArquivo %s gerado com sucesso!", nomeArquivoNovo);
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos!");
	}
}

//implementação das funções
int criarArquivoOrdenado (char nomeArqOriginal[], char nomeArqNovo[])
{
	//declaração de variáveis
	FILE *arqN;
	int limite = INT_MAX, maior;
	
	//tentando abrir o arquivo novo
	arqN = fopen (nomeArqNovo, "w");
	
	//verificando se houve erro na abertura
	if (!arqN)
	{		
		return 0;
	}
	else
	{
		while (calcularMaiorValor (nomeArqOriginal, limite, &maior) == 1)
		{
			//escrevendo no novo arquivo o maior elemento retornado
			fprintf (arqN, "%d\n", maior);
			
			//atualizando o limite
			limite = maior;
		}
		
		//fechando o arquivo
		fclose (arqN);
		
		return 1;
	}
}

int calcularMaiorValor (char nomeArq[], int limite, int *maior)
{
	//declaração de variáveis
	FILE *arq;
	int numero, achou;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");	
	
	//verificando se houve erro no arquivo
	if (!arq)
	{
		return -1;
	}
	else	
	{
		//inicializando '*maior'
		*maior = INT_MIN;
		
		//inicializando 'achou' com 0, representando que nenhum valor foi encontrado até o momento
		achou = 0;
		
		//lendo os elementos do arquivo
		while (fscanf (arq, "%d", &numero) != EOF)
		{
			if ((numero < limite) && //verificando se o valor lido é menor do que o limite ...
			    (numero > *maior))   //... e se é o maior até o momento
			{
				*maior = numero;
				
				//atualiza 'achou'
				achou = 1;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		return achou;
	}
}
