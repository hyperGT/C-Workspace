#include <stdio.h>

int main() {

  /*
  Escrever um algoritmo que, dada uma quantia
  em reais, calcule o menor numero possivel de
  notas/moedas (100, 50, 20, 10, 5, 2 e 1) em que
  o valor pode ser decomposto.
  */

  // C e uma linguagem de programacao estruturada, ou seja, os comandos sao
  // lidos de cima pra baixo, os dados são inseridos na ordem colocada. 
  // e necessario ler o valor antes de manipula-lo.

  int valor;
  int n100, n50, n20, n10, n5, n2, n1;
  int r100, r50, r20, r10, r5, r2, r1;

  printf("Insira um valor para ser decomposto: ");
  scanf("%d", &valor);

  n100 = valor / 100; // divide o vlr por 100
  r100 = valor % 100; 
  
  n50 = r100 / 50; // pega o resto e divide por 50 pra descobrir a qnt de cedulas de 50 
  r50 = r100 % 50;    
  
  n20 = r50 / 20;
  r20 = r50 % 20;	
  
  n10 = r20 / 10;
  r10 = r20 % 10;
  
  n5 = r10 / 5;
  r5 = r10 % 5;
  
  n2 = r5 / 2;
  r2 = r5 % 2;
  
  n1 = r2 / 1;
  r1 = r2 % 1;
  
	printf("\nCedulas de 100: %d", n100);
	printf("\nCedulas de 50: %d", n50);
	printf("\nCedulas de 20: %d", n20);
	printf("\nCedulas de 10: %d", n10);
	printf("\nCedulas de 5: %d", n5);
	printf("\nCedulas de 2: %d", n2);
	printf("\nCedulas de 1: %d", n1);
  
}
