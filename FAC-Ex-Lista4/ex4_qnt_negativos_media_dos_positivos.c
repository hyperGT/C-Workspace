/*
Fa�a um programa que leia
300 n�meros reais. Ao final, devem ser
exibidas as seguintes informa��es:
a) A quantidade de valores negativos
digitados;
b) A m�dia dos valores positivos.
*/

#include<stdio.h>

int main(){
	
	int x = 5, i=1, contPos=0, contN=0;
	float nReal, somaPos, mediaPos;
	
	
	while(i<=x){
		printf("Insira um valor real: ");
		scanf("%f", &nReal);
		
		//item A: quantidade de valores negativos digitados;
		if(nReal<0){
			contN++;
		}
		
		//item B: M�dia dos valores positivos
		if(nReal>=0){
			contPos++;
			somaPos += nReal;
		}
		i++;
	}
	
	mediaPos = somaPos/contPos;
	
	//exibindo a m�dia dos valores positivos
	printf("Media dos valores positivos: %.1f\n\n", mediaPos);

	//exibindo a quantidade de valores negativos digitados
	printf("Quantidade de valores negativos digitados: %d", contN);
	
}
