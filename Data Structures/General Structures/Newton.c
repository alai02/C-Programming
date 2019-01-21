#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void recursive(int value, int accuracy){

	int a = value /2;
	int betterA = ((a + value) / a)/2;
	if(betterA < 0){
		betterA = betterA * -1;
	}

	if(abs((betterA*betterA) - value) <= accuracy) {
		printf("Square root: %d\n", betterA);
	} else {
		recursive(betterA, accuracy);
	}
}

void newtonMath(){

	int accuracy;
	int value;
	int approx;

	printf("Enter a number you would like to know the square root of:\n");
	scanf("%d", &value);

	printf("Please enter an epsilon value: \n");
	scanf("%d", & accuracy);

	approx = value /2;

	int newVal = ((approx*approx) - value);

	if(newVal < 0){
		newVal = newVal * -1; 
	}

	if(newVal <= accuracy) {
		printf("Square root: %d\n", approx);
	} else {
		recursive(value, accuracy);
	}

}