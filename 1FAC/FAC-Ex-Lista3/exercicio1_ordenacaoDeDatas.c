#include <stdio.h>

int main(){
    /*dadas duas datas, retorne a mais recente*/

  int dia1, dia2, ano1, ano2, mes1, mes2;

  printf("Insira o dia, mes e ano da primeira data: ");
  scanf("%d %d %d", &dia1, &mes1, &ano1);

  printf("Insira o dia, mes e ano da segunda data: ");
  scanf("%d %d %d", &dia2, &mes2, &ano2);

  // comparar ano primeiro
  if (ano1 > ano2) {
    printf("data 1 mais recente");
  } else if (ano1 < ano2) {
    printf("data 2 mais recente");
  } else { // comparar meses
    if (mes1 > mes2) {
      printf("data 1 mais recente");
    } else if (mes1 < mes2) {
      printf("data 2 mais recente");
    }      // comparar dias
    else { // caso os meses sejam iguais tambem
      if (dia1 > dia2) {
        printf("data 1 mais recente");
      } else if (dia1 < dia2) {
        printf("data 2 mais recente");
      }
    }
  } // caso os anos sejam iguais

  return 0;
}
