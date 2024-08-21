#include <stdio.h>

/*
QUESTÃO 05:
Fazer uma função que exiba a tabuada de
potências de um número n, no intervalo de 1 a
9. Se o número não estiver neste intervalo, o
código 0 deve ser retornado; caso contrário,
retorna-se 1.

Para ilustrar, abaixo é apresentada como a
tabuada de potências de 2 deveria ser exibida:

2^0 = 1
2^1 = 2
2^2 = 4
2^3 = 8
2^4 = 16
2^5 = 32
2^6 = 64
2^7 = 128
2^8 = 256
2^9 = 512
*/

// prototipo da função
void tabuada(int alg);

// main
int main(void) {

  // declaração de variaveis
  int alg;

  printf("Digite um número de 1 a 9: ");
  scanf("%d", &alg);

  if (alg >= 1 && alg <= 9) {
    // chamando a função
    tabuada(alg);
    return 1;
  } else {
    return 0;
  }

  return 0;
}
// função
void tabuada(int alg) {
  int i, j = 1;

  // Andando até o Expoente 9
  for (i = 0; i <= 9; i++) {

    // Imprimindo a tabuada
    printf("%d^%d = %d\n", alg, i, j); // 1 2 4 8 16 32 64 128 256 512
    j *= alg;                          // 2 4 8 16 32 64 128 256 512 1024 // finaliza e mostra até o 512
  }
}
