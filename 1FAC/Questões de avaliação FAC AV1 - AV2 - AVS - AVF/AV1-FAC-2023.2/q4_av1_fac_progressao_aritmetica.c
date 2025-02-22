/*

Solicita-se o desenvolvimento de um programa que
leia n valores inteiros, onde n também é fornecido
pelo usuário.
Ao final, o programa deve informar se os valores, na
ordem na qual foram informados, representam uma
Progressão Aritmética (PA).
Nota: uma PA consiste em uma sequência de
valores iniciada por a1 (primeiro termo) e cada
novo termo é calculado a partir da soma do
anterior com um número especial e constante para
a sequência, chamado razão da PA.

*/

/*

Primeiro o usuario entra com o valor que será o tamanho da P.A indicando a quantidade de numeros inteiros que se vai ler.

Um loop vai fazer com que o usuário possa entrar com n numeros inteiros, assim construindo uma sequencia de valores.

mas...como fazer uma verificar se é ou não uma P.A?

5, 10, 15, 

guarde o primeiro valor e pegue a diferença com o segundo, no caso acima 10 - 5 = 5. 
Pegue essa diferença e some com o segundo 

observe o prox valor.

quebrar essa sequencia em partes(pares: a1 com a2, a2 com a3)
*/

#include<stdio.h>

int main(){
	
	int n; 
	int valorInserido; // a3 (desnecessário mas o importante é estar funcionando)
	int diff1, diff2; // penultima diferença vs diferença atual
	int verify = 1; // verify = 0(false) ou 1(true) booleana
	int a1, a2;
	
	
	if(n <= 2){
		verify = 1; // sequencia de 1 ou 2 termos é sempre uma P.A
	}else{
		
		printf("Insira o valor de n: ");
		scanf("%d", &n);
		
		printf("Insira o 1° valor(a1): ");
		scanf("%d", &a1); // 5
		
		printf("Insira o 2° valor(a2): ");
		scanf("%d", &a2); // 5
		
		diff1 = a2 - a1;
		
		//printf("\nDiferença inicial: %d", diff1);
				
		//segundo passo: sequencia de valores
		int i = 1, cont = 3; // esse cont aí é só pra fins de contagem
		while(i <= (n-2)){
			
			printf("\nInsira o %dº valor(a%d): ", cont, cont);
			scanf("%d", &valorInserido); // 10, 15, 20, 25
			
			//printf("\nValor inserido: %d", valorInserido);
			
			diff2 = valorInserido - a2;
			a2 = valorInserido;		
			
			//terceiro passo: verificar se é P.A ou n
			if(diff1 == diff2){
				verify = 1; // Isso significa que é uma P.A
				diff1 = diff2;
			}
			else{
				verify = 0; // deu false, logo não é uma P.A								
			}
	
			cont++;		
			i++;				
		}
	}
	
	if(verify == 1){
		printf("\nA sequencia digitada E uma P.A");
	}
	else if(verify == 0){
		printf("\nA sequencia digitada NAO e uma P.A");
	}
		
}

