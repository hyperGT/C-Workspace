#include <stdio.h>

int main() {

  /*
  Escrever um algoritmo que, dada uma quantia
  em reais, calcule o menor número possível de
  notas/moedas (100, 50, 20, 10, 5, 2 e 1) em que
  o valor pode ser decomposto.
  */

  // C é uma linguagem de programação estruturada, ou seja, os comandos são
  // lidos de cima pra baixo, os dados são inseridos na ordem colocada. É
  // necessário ler o valor antes de manipulá-lo.

  int valor;
  int n100 = 100, n50 = 50, n20 = 20, n10 = 10, n5 = 5, n2 = 2, n1 = 1;
  int r100, r50, r20, r10, r5, r2, r1, q, teste;

  printf("Insira um valor para ser decomposto: ");
  scanf("%d", &valor);

  r100 = valor % n100; // divide o vlr por 100
  r50 = r100 % n50;    // pega o resto e divide pelo 50
  r20 = r50 % n20;
  r10 = r20 % n10;
  r5 = r10 % n5;
  r2 = r5 % n2;
  r1 = r2 % n1;
  q = r2 / n1;

  printf("Resto: %d Quociente: %d", r1, q);
}
