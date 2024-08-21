#include <stdio.h>

int main()
{

    /*
    Um banco concederá um crédito especial aos
    seus clientes, variável com o saldo médio no
    último ano. Faça um algoritmo que calcule o
    valor do crédito de acordo com a tabela abaixo. (que n vai dar pra mostrar)
    */

    float averageBalance; //saldo médio

    printf("Insert your average balance: ");
    scanf("%f", &averageBalance);

    if (averageBalance < 1000)
    {
        printf("None bonus to earn");
    }
    else if (averageBalance <= 1499.99)
    {
        averageBalance += (averageBalance*0.2); 
        printf("Your received a 20 bonus \nYour balance: %.2f", averageBalance);
    }
    else if (averageBalance <= 2499.99)
    {
        averageBalance += (averageBalance*0.3); 
        printf("Your received a 30% bonus \nYour balance: %.2f", averageBalance);
    }
    else
    {
        averageBalance += (averageBalance*0.4); 
        printf("Your received a 40% bonus \nYour balance: %.2f", averageBalance);
    }
    
    

    
}