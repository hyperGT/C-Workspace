/*
QUEST�O 04: 
A prefeitura de uma cidade
fez uma pesquisa com 300 de seus
habitantes, coletando dados sobre o
sal�rio e n�mero de filhos. A prefeitura
deseja saber:
a) m�dia do sal�rio da popula��o;
b) m�dia do n�mero de filhos;
c) maior sal�rio;
d) percentual de pessoas com sal�rio at�
R$ 1.000,00.
*/

#include<stdio.h>

#define QNT 4

int main(){
	
	//variaveis
	int nFilhos, 
		i, somaFilhos, cont1000=0;
	float salario,
		somaSalario, mediaSalario, mediaFilhos, maiorSalario=0, perc1000;
	
	//TODO:lendo quantas pessoas participaram da pesquisa
	
	for (i=1;i<=QNT;i++)
	{
		printf ("Salario: ");
		scanf ("%f", &salario);
		
		printf ("Numero de filhos: ");
		scanf ("%d", &nFilhos);
		
		//somando todos os sal�rios
		somaSalario += salario;
		
		//somando a qnt de filhos total da populacao
		somaFilhos += nFilhos;
		
		//obtendo pessoas com salario acima de 1000
		if(salario>1000.00){
			cont1000++;
		}
		
		//obtendo o maior sal�rio;
		if(salario>maiorSalario){
			maiorSalario=salario;
		}
	}
	
	//calculando as m�dias
	mediaSalario = somaSalario/QNT;
	mediaFilhos = (float)somaFilhos/QNT;
	
	//obtendo a porcentagem
	perc1000 = ((float)cont1000/QNT)*100;
	
	//exibindo os resultados
	printf ("\nMedia salarial da populacao: R$ %.2f\n", mediaSalario);
	printf ("\nMedia de natalidade da populacao: %.1f\n", mediaFilhos);
	printf ("\nMaior salario registrado: R$ %.2f\n", maiorSalario);
	printf ("\nPorcentagem de pessoas com salario acima de 1000: %.2f%%\n", perc1000);
}
