/*
 * This file contains an inteface for the functions defined by alex lai
 * This file contains a code relating to creating things that I need to solve this problem (assignment)
 * They were written for CIS*2750 Assignment 1 @ UoGuelph Winter 2017
*/
#ifndef __ALEXLAI__CREATE__
#define __ALEXLAI__CREATE__

typedef enum { false, true } Boolean;

typedef struct ClassDef{
	char* className;
	char* classVariables[10];
	char* memberDefinitions[10];
	char* classParameters[10];
	char* validCode[100];
	char* functionPointers[10];
	char* classConstructurs[10];
	struct ClassDef * nextDef;
} ClassDef;

/**
 * generateArray
 * This function generates a 2d array and allocates memory for it
 * IN: int arraySize, int dataLength
 * RETURN: returns a 2d char array
 * note:
 * errors: No known errors found.
 */
char ** generateArray (int arraySize, int dataLength);
/**
 * createFunctionPointer
 * This function creates a function pointer to be put in the struct
 * IN: char* className, char* functionName, char* paramList, char* type
 * RETURN: returns a proper function pointer
 * note:
 * errors: No known errors found.
 */
char* createFunctionPointer(char* className, char* functionName, char* paramList, char* type);
/**
 * createClassDef
 * This function creates a struct and allocates memory for all its members
 * IN: no params
 * RETURN: returns a pointer to a ClassDef struct
 * note:
 * errors: No known errors found.
 */
ClassDef * createClassDef();
/**
 * createInputModel
 * This function takes in a 2d array and returns a struct containing all class data
 * IN: char* charArray, ClassDef* myClass
 * RETURN: returns a struct pointer to my class strucutres that hold all the data
 * note: This function is massive
 * errors: No known errors found.
 */
ClassDef* createInputModel(char** charArray, ClassDef * myClass);
/**
 * createParameterList
 * This function figures out what the functions parameters are to create a unique function name
 * IN: char* line
 * RETURN: returns a string that represents the parameters of the function
 * note: the function param list will always be in the order int, char, float
 * errors: No known errors found.
 */
char* createParameterList(char* line);

#endif
/* defined __ALEXLAI__CREATE__ */
