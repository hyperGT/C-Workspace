#include <stdio.h>

/*
Q04_lista_IX
Fazer uma função que calcule o MDC (mÃ¡ximo
divisor comum) entre dois números.

a será o maior valor sempre
b será o menor
a % b = r
*/

int mdc(int a, int b) {
  int resto;

  // a deve sempre ser maior, portanto:
  if (a < b) {
    int aux;
    aux = b; // b, que Ã© o maior valor
    b = a;   // b receba a que Ã© menor
    a = aux; // a recebe aux que Ã© o antigo valor de b
  }

  while (1) {
    resto = a % b;
    a = b; 
    b = resto; 
    printf("a=%d, b=%d, r=%d ", a, b, resto); 
    if (resto == 0) {
      break;
    }
  }
  return a;
}

int main(void) {

  int a, b;

  printf("Digite dois valores para calcular o MDC: ");
  scanf("%d %d", &a, &b);

  int resultado = mdc(a, b);
  printf("O MDC entre %d e %d e %d", a, b, resultado);

  return 0;
}


