/*
QUESTÃO 02:
Implementar uma função que converta
determinada temperatura em graus Celsius
para graus Fahrenheit.

para isso basta multiplicar a temperatura em graus Celsius por 1,8 e somar 32.

formula: (t * 1.8) + 32

t em graus celsius
*/


#include <stdio.h>

// f prototypes
float celsiusToFahrenheit(float t);

void main(){
	
	float t;
	
	printf("Insira a temperatura em graus Celsius: ");
	scanf("%f", &t);
	
	
	int f = celsiusToFahrenheit(t);
	
	printf("Temperatura em graus Fahrenheit: %d", f);
	
}

float celsiusToFahrenheit(float t){
	
	return (t * 1.8) + 32;
}
