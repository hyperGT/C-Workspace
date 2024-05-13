/*
Faça um programa que leia
300 números reais. Ao final, devem ser
exibidas as seguintes informações:
a) A quantidade de valores negativos
digitados;
b) A média dos valores positivos.
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
		
		//item B: Média dos valores positivos
		if(nReal>=0){
			contPos++;
			somaPos += nReal;
		}
		i++;
	}
	
	mediaPos = somaPos/contPos;
	
	//exibindo a média dos valores positivos
	printf("Media dos valores positivos: %.1f\n\n", mediaPos);

	//exibindo a quantidade de valores negativos digitados
	printf("Quantidade de valores negativos digitados: %d", contN);
	
}
