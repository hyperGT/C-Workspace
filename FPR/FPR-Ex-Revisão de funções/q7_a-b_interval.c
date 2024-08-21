/*
* 
*/

#include <stdio.h>

int divInterval(int n, int a, int b){
	int i, j, cont=0;
	
	// percorrer o intervalo de a à b
	for(i=a; i<=b; i++){
		
		//percorrendo de 2 até n para fazer as divisões e comparar se tem pelo menos 1 divisor em comum
		for(j=2; j<=n; j++){
			if(n%j==0 && i%j==0){
				cont++;
				break;
			}
		}
	}
	return cont;
}


int main(){
	int n, a, b;
	
	printf("Insira o n: ");
	scanf("%d", &n);
	
	printf("Insira o a: ");
	scanf("%d", &a);
	
	printf("Insira o b: ");
	scanf("%d", &b);
	
	int resp = divInterval(n, a, b);
	
	printf("\n");
	printf("Qnt de numeros dentro do intervalo que possuem divisor em comum com n: %d", resp);
	
}
