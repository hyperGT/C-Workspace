#include <stdio.h>

int main(void)
{
    //exemplo de valores
    char itemName[20] = "Iphone 10";
    int itemId = 1122303842;
    float itemValue;
    int choosePayment;

    printf("Informe o valor do produto: ");
    scanf("%f", &itemValue);

    printf("Id do produto: %d\nNome do produto: %s\nValor: %.2lf\n", itemId, itemName, itemValue);

    printf("1) O valor com 10 por cento de desconto para pagamento a vista\n");
    printf("2) O valor da prestacao para parcelamento sem juros, em 5x;\n");
    printf("3) O valor da prestacao para parcelamento com juros, em 10x, com 0 p/cento de acrescimo no valor do produto.\n");


    printf("\n\nEscolha as seguintes opcoes de pagamento (selecione de 1 a 3): ");
    scanf("%d", &choosePayment);

    float valueToPay;

    switch (choosePayment)
    {
    case 1:
        //valorFinal = (100-10) * valorProduto    
        valueToPay = ((100-10) * itemValue)/100;
        printf("Valor a ser pago: %.2f", valueToPay);
        break;
    case 2: 
        //valorPrestacoes = valorProduto / 5
        valueToPay = itemValue/5;
        printf("Valor a ser pago: %.2lf x5", valueToPay);
        break;
    case 3: 
        //valorPrestacao = valorProduto + (20/100) * valorProduto 
        //valorPrestacao = valorPrestacao/10
        valueToPay = (itemValue + (20/100) * itemValue);
        float currentValue = valueToPay;
        valueToPay /= 10;
        printf("Valor a ser pago: %.2lf x10\nNovo valor a ser pago: %.2lf", valueToPay, currentValue);
        break;
    default:
        printf("Numero invalido inserido");
        break;
    }


}