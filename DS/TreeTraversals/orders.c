/*
 * Author: Alex L
 * Description: takes in a fully parentasized
 * arithmetic expression and has various funcitons to evaluate, update,
 * print in certain order and display as a tree
 * Date: November 7th, 2016 
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct Tree { //Tree contains an operator and 2 nodes 
    char operator; //operator ex: +, -, *, /
    struct Tree *left; //branches that can either be operators or values
    struct Tree *right;
} Tree; 

void preOrder(Tree *root); 
void menu(char* expression);
char* parseArithmetic(char* arguement);
void inOrder(Tree *root);
void postOrder(Tree *root);

void menu(char* expression){ 

	int correct; //
	int choice;
	int q = 0;
	while(q == 0){ //loop the options
		printf("Pllease enter one of the following options: \n");
		printf("1.Display\n");
		printf("2. Preorder\n");
		printf("3. Inorder\n");
		printf("4. Postorder\n");
		printf("5. Update\n");
		printf("6. Calculate\n");
		printf("7. Exit\n");

		do{ //make sure user input is correct
			scanf("%d", &choice);
			if(choice < 1 || choice > 7){ //user needs to enter val from 1-7
				printf("Incorrect input, please enter another number: \n");
			} else{
				correct = 1; //exit the loop
			}
		} while(correct == 0);

		switch(choice){ //switch the user input
			case 1:
				//display(s); //functions to display 
				break;
			case 2: 
				//preOrder(s);
				break;
			case 3:
				printf("%s\n", expression);
				break;
			case 4:
				//postOrder(s);
				break;
			case 5:
				//update(s);
				break;
			case 6:
				//calculate(s);
				break;
			case 7:  //exit selected
				q = 1;
				printf("Exiting program...\n");
				break;
			default: //default case for bad vals
				break;
		}
	}
}

//this function removes all the parentesies for inorder notation
char* parseArithmetic(char* arguement){ 
	
	int i, j; //init iterators
	j = 0;
	char* array = malloc(100); //malloc memory for the array
	
	printf("%d\n",(int) strlen(arguement)); //strlen doesnt always work well so cast to int for certanty
	
	for (i = 0; i < strlen(arguement); i++){ //loop through all chars

		if (arguement[i] != '(' && arguement[i] != ')'){//find the brackets
			array[j] = arguement[i]; //set the value
			j++; //increment the array 
		}
	}
	return array; //return to calling function
}

//function to print in preorder 
void preOrder(Tree *root) {
   if (root){
       printf("%d\n", root->operator); //print out the operator/operand
       preOrder(root->left); //recursivly get the child nodes
       preOrder(root->right);
   }
}


// funtion to print in inOrder format
void inOrder(Tree *root) {
   if (root){
       inOrder(root->left); //recursive call to get child nodes
       printf("%d\n", root->operator); //print operator / operand
       inOrder(root->right); //recursive call to get later child nodes
  }
}
 
void postOrder(Tree *root) {
   if (root){
       postOrder(root->left);
       postOrder(root->right);
       printf("%d\n", root->operator);
   }
}


//main function grabs user input and sends to menu after parsing the input
int main(int argc, char* argv[]){

	Tree *s;
	if(argv[1] == NULL ){
		printf("Incorrect user input\n");
	} else{
		char* userInput = argv[1];
		userInput = parseArithmetic(argv[1]); //remove all perentisize
		menu(userInput); //loops and calls other function to the users pleasure
	}

	return 0; //end of program
}


