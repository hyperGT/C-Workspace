#include <stdio.h>

// ================== //

int main(void) {
  // variaveis | tipos: int: 1,2,3,10 ; float: 1.2, 3.5 ; char: 'a', 'b' ;
  // string: "texto" ;
  int idade = -1; // idade do usuario
  char pais;      // verificação dos pais

  // peça alguma informação ao usuario | // leia a informação %d int %f float %c
  // char %s string
  printf("Digite sua idade: ");
  scanf("%d", &idade);

  // if
  if (idade < 0) {

    printf("idade invalida");

  } else {

    if (idade >= 18) {

      printf("Você tem %d anos. TÁ LIBERADO...", idade);

    } else {
      printf("Você tem %d anos.\n", idade);
      printf("Está acompanhado dos seus responsáveis? (s/n): ");
      scanf(" %c", &pais);
      if (pais == 's') {
        printf("BELEZA, PODE COMPRAR...");
      } else {
        if (pais == 'n') {
          printf("SE FODEU, MENÓ");
        } else {
          printf("TU É RETARDADO, MENÓ? METE O PÉ!");
        }
      }
    }
    // se tiver menos de 18 anos, nao pode entrar, mas se tiver acompanhada com
    // um responsavel, pode entrar.

    // fim if
  }

  return 0;
}
	
	
	
	