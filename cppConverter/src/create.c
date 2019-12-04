#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "manipulate.h"
#include "fileio.h"
#include "helper.h"

char ** generateArray (int arraySize, int dataLength) {
	char ** array = malloc(sizeof(char*) * arraySize);
	int i;
	for(i = 0; i < arraySize; i++){
		array[i] = malloc(sizeof(char)*dataLength);
	}
	return array;
}
char* createParameterList(char* line){ /*reads in a function definition*/
	int i = 0, intCount = 0, floatCount = 0, charCount = 0;
	char* paramList = malloc(100);
	while(line[i] != ')' ){
		if(line[i] == 'i' && line[i+1] == 'n' && line[i+2] == 't' && line[i+3] == ' '){
			intCount++;
		} else if (line[i] == 'f' && line[i+1] == 'l' && line[i+2] == 'o' && line[i+3] == 'a'){
			floatCount++;
		} else if (line[i] == 'c' && line[i+1] == 'h' && line[i+2] == 'a' && line[i+3] == 'r'){
			charCount++;
		}
	}
 	paramList[0] = intCount;
	paramList[1] = floatCount;
	paramList[2] = charCount;
	return paramList;
}
char* createFunctionPointer(char* className, char* functionName, char* paramList, char* type){
	char* functionPointer;
	functionPointer = malloc(1000);
	char* startOfType = "(";
	char* endOfType = ")";
	char* symbol1 = "*";
	char* endOfFunctionPointer = "();";
	strcat(functionPointer, startOfType);
	strcat(functionPointer, type);
	strcat(functionPointer, endOfType);
	strcat(functionPointer, startOfType);
	strcat(functionPointer, symbol1);
	strcat(functionPointer, functionName);
	strcat(functionPointer, endOfFunctionPointer);
	return functionPointer;
}
ClassDef * createClassDef(){
	int i;
	ClassDef * myClassDef = malloc(sizeof(ClassDef));
	for(i = 0; i < 10; i++){
		myClassDef->classVariables[i] = malloc(sizeof(char*)* 10 +1);
		myClassDef->memberDefinitions[i] = malloc(sizeof(char*)*10 +1);
		myClassDef->classParameters[i] = malloc(sizeof(char*)* 10 +1);
		myClassDef->functionPointers[i] = malloc(sizeof(char*)* 10 +1);
		myClassDef->classConstructurs[i] = malloc(sizeof(char*)* 10 +1);
		myClassDef->nextDef = NULL;
	}
	for(i = 0; i < 100; i++){
		myClassDef->validCode[i] = malloc(sizeof(char*)* 100 +1);
	}
	return myClassDef;
}
ClassDef* createInputModel(char** charArray, ClassDef * myClass){
	int i; /* class iterator*/
	int v = 0; /*class variable iterator*/
	int validCodeIterator = 0;
	/* int f = 0; */ /* function list iterator*/
	ClassDef * temp = myClass;
	Boolean insideClass = false;
	for(i = 0; i < 100; i++) {
		/* need to consider global variables */
		/* need to consider comments */
		/* need to consider main */
		/* need to consider functions not in classes */

		if(strcmp(charArray[i], "class") == 0 && (strcmp(charArray[i+2],"{") == 0 || charArray[i+1][1] == '{')){
			/*class state*/
			insideClass = true;
			while(insideClass == true){
				strcpy(temp->className,charArray[i+1]);
				if(strcmp(charArray[i+3], "int") == 0 && charArray[i+5][(strlen(charArray[i])-1)] == ';'){
					temp->classVariables[v]  = appendClassToFrontVariable(temp->className ,charArray[i+4], "int ");
					v++;
				} else if (strcmp(charArray[i+3], "char") == 0 && charArray[i+5][(strlen(charArray[i])-1)] == ';'){
					temp->classVariables[v]  = appendClassToFrontVariable(temp->className ,charArray[i+4], "char ");
					v++;
				} else if (strcmp(charArray[i+3], "float") == 0 && charArray[i+5][(strlen(charArray[i])-1)] == ';'){
					temp->classVariables[v]  = appendClassToFrontVariable(temp->className ,charArray[i+4], "float ");
					v++;
				}
				if(strcmp(charArray[i], "void") == 0 ){
					while(1){
						/*need to find where the function declaration ends
						the i need to send that string to param List function*/
					}
				} else if (strcmp(charArray[i], "int") == 0){

				} else if (strcmp(charArray[i], "float") == 0){

				}
				/* function to figure out rest of data*/
				/* More ifs to figure out the amout of data before the functions
				also figure out how many functions,
				in that function, it should use the countParameters function*/
			}
		} else if (strcmp(charArray[i], "int") == 0 && strcmp(charArray[i+1], "main") == 0){
			/*In main I need to change variable names but i dont need class info because its already there*/
		} else {
			/*Add valid c code to print to file except class names*/
			if(strcmp(charArray[i], "class") == 0){
				strcpy(charArray[i], "struct");
			}
			temp->validCode[validCodeIterator] = charArray[i];
			validCodeIterator++;
		}
		temp = temp->nextDef;
	}
	return myClass;
}
