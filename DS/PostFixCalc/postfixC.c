#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct stack{ //using a struct to create the data structure
	int userData[MAX];
	int theTopOfTheStack;
} stack;

// do calculation
int evaluate(char i, int firstNum, int secondNum) { 

	if (i == '+') {
		return(firstNum + secondNum);
	}

	if (i == '-') {
		return(firstNum - secondNum);
	}

	if (i == '*') {
		return(firstNum * secondNum);
	}

	if (i == '/') {
		return(firstNum % secondNum);
	}

}

void initializeStack(stack* theStack){ //stack is created
	theStack->theTopOfTheStack = -1;
}

void push(stack * theStack, int i){ //push 
	theStack->theTopOfTheStack = theStack->theTopOfTheStack +1;
	theStack->userData[theStack->theTopOfTheStack] = i;
}

int pop(stack* theStack){
	int i;
	i = theStack->userData[theStack->theTopOfTheStack];
	theStack->theTopOfTheStack = theStack->theTopOfTheStack -1;
	return i;
}

int main(int argc, char* argv[]) {

	stack theStack;
	char x;
	int i;
	int firstNum;
	int secondNum;
	double result;
	
	initializeStack(&theStack);
	
	char* userInput = argv[1]; //get the expression from the command line argument
	printf("User input: %s\n", userInput);

	for(i = 0; i < strlen(userInput); i++){ //iterate through the char* array, getting each digit or operator
		if(isdigit(userInput[i])){
			push(&theStack, userInput[i]-48);
		} else{
			secondNum = pop(&theStack);
			firstNum = pop(&theStack);
			result = evaluate(userInput[i], firstNum, secondNum);
			push(&theStack, result);
		}
	}


	result = pop(&theStack);
	printf("Value of the expression: %.2f \n", result); 
	
	return 0;
}