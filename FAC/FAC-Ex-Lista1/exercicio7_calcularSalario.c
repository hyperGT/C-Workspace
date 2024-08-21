#include <stdio.h>

int main(void)
{

    /*
    Escreva um algoritmo para calcular o salário
semanal de uma pessoa, determinado pelas
condições que seguem: se o número de horas
trabalhado for inferior ou igual a 40, a pessoa
recebe x reais por hora; caso contrário, a
pessoa recebe um adicional de 50% para cada
hora trabalhada acima das 40 iniciais.
    */

    // numero de horas trabalhadas
    int hoursWorked;

    // valor de horas trabalhadas
    int moneyPerHour;

    // valor do salario semanal
    int weeklySalary;

    printf("Insira a quantidade de horas que o usuario trabalhou: ");
    scanf("%d", &hoursWorked);

    printf("Insira a valor de reais que se recebe por hora trabalhada: ");
    scanf("%d", &moneyPerHour);

    if (hoursWorked <= 40)
    {
		// calculando o salario semanal sem o extra das horas trabalhadas acima de 40        
        weeklySalary = moneyPerHour * hoursWorked;
    }
    else 
    {
        // para cada hora trabalhada acrescentamos 50% de adicional
        weeklySalary = moneyPerHour * 40 + (hoursWorked - 40) * (moneyPerHour * 1.5);
    }

    printf("Quantidade de horas trabalhadas: %d", hoursWorked);
    printf("\nO salario semanal do funcionario: %d", weeklySalary);
}
