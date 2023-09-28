#include <stdio.h>
#include <string.h>

int main(void)
{

    //nome do hospede
    char name[100];

    // tipo do apartamento
    char aptType;

    // valores referentes a diaria
    int hotelRatesValue;
    int dailyNum;
    float hotelRatesTotalValue;

    // referente ao valor consumido dentro das dependencias do hotel
    float internalConsumeValue;

    // valores totais de custo do cliente
    float subTotal;
    float TotalCost;
    //float diff = TotalCost - subTotal; // valor da taxa aplicada

    // Ask the user name
    printf("Inserir o nome do hospede: ");
    scanf("%s", &name);

    // Ask the user to type the apartment type
    printf("\nInsira o tipo do apartamento (A, B, C, D): ");
    scanf(" %c", &aptType);
    
    // Ask the user to type the number of reserved days
    printf("\nInsira o numero de dias reservados: ");
    scanf("%d", &dailyNum);

    // Ask the user to type the consume total value in the hotel dependencies
    printf("\nInsira o valor do consumo interno total do cliente: ");
    scanf("%f", &internalConsumeValue);

    switch (aptType)
    {
    case 'A':
        hotelRatesValue = 350;        
        break;
    case 'B':
        hotelRatesValue = 275;
        break;
    case 'C':
        hotelRatesValue = 200;
        break;
    case 'D':
        hotelRatesValue = 150;
        break;
    default:
        printf("Invalido");
        break;
    }

    //recebe o valor base da diaria do hotel * o numero de diarias para calcular o valor total
    hotelRatesTotalValue = (float) hotelRatesValue * dailyNum;

    subTotal = hotelRatesTotalValue + internalConsumeValue;
    TotalCost = subTotal + (subTotal * 0.1);


    printf("\nNome do Hospede: %s", name);
    printf("\nTipo de apartamento escolhido: %c\n", aptType);
    printf("\nValor da diaria do apartamento: %d", hotelRatesValue);
    printf("\nValor total da diaria do apartamento: %.2f",hotelRatesTotalValue);
    printf("\nvalor do consumo interno: %.2f", internalConsumeValue);
    printf("\nSubtotal: %.2f + %.2f (Taxa de Serviços)", subTotal, TotalCost - subTotal);
    printf("\nTotal: %.2f", TotalCost);
}