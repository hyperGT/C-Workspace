#include <stdio.h>

int main()
{

    /*
    Fazer um algoritmo que determine a ordem de
    uma data (dia e mês) no ano.
    Exemplos:
    01/01 - 1o dia do ano
    03/02 - 34o dia do ano
    */

    int mes;
    int dia;
    int ordemData = 0;

    printf("Insira o mes: ");
    scanf("%d", &mes);

    printf("Insira o dia: ");
    scanf("%d", &dia);

    // Exemplo: mes = 3, diasPorMes = 28.
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes >= 1 && mes <= 12 && dia >= 1 && dia <= diasPorMes[mes])
    {
        // precisamos percorrer o calendario e somar esses valores, vamos montar a lógica:
        for (int i = 1; i < mes; i++)
        {
            // OD = 0; OD += OD + DM[posicao a cada loop até chegar no mes]
            // 1 loop: i = 1, ou seja, 31. OD = 31. 2 loop: i = 2, ou seja: OD = 59. [...]
            ordemData += diasPorMes[i];
        }
        ordemData += dia;

        printf("A ordem da data no ano inserida pelo usuario e: %d", ordemData);
    }
    else
    {
        printf("Data inserida inválida");
    }
}