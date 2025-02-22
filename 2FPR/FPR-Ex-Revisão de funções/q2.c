/*
* Make a function thats converts the temperature scaling Celcius to fahrenheit 
* and returns the result
*/

#include <stdio.h>

// functions
float celciusFahrenheit (float c)
{
	return (c*9/5)+32;	
}


int main(){
	float c, f;
	
	printf("Insert the temperature degrees in Celcius: ");
	scanf("%f", &c);
	
	f = celciusFahrenheit (c);
	
	printf("The equivalent in Fahrenheit: %.1f", f);
}
