#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

int main(){
	
	double num1, num2;
	
	printf("Calculation!\n");
	printf("first ? : ");
	scanf("%lf",&num1);
	printf("second ? : ");
	scanf("%lf",&num2);
	
	printf("%lf + %lf = %lf\n", num1, num2, add(num1,num2));
	printf("%lf - %lf = %lf\n", num1, num2, subtract(num1,num2));
	printf("%lf * %lf = %lf\n", num1, num2, multiply(num1,num2));
	printf("%lf / %lf = %lf\n\n", num1, num2, divide(num1,num2));

	printf("thanks.\n");
	
	return 0;
	
	}
