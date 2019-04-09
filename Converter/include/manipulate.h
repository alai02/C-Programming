/*
 * This file contains an inteface for the functions defined by alex lai
 * This file contains a code relating to manipulating variale and function names
 * They were written for CIS*2750 Assignment 1 @ UoGuelph Winter 2017
*/
#ifndef __ALEXLAI__MANIPULATE__
#define __ALEXLAI__MANIPULATE__

/**
 * appendClassToFrontFunction
 * This function writes creates a c version of a function declaration in c++
 * IN: char* className, char* variableName, char* parameterList
 * RETURN: returns a valid c function declaration
 * note:
 * errors: No known errors found.
 */
char * appendClassToFrontFunction(char* className, char* variableName, char* parameterList);
/**
 * appendClassToFrontVariable
 * This function creates a valid c variable given c++ code
 * IN: char* className, char* variableName, char* type
 * RETURN: returns a proper c variable name
 * note: This function adds the class name to the front of the variable
 * errors: No known errors found.
 */
char * appendClassToFrontVariable(char* className, char* variableName, char* type);
/**
 * fixMainVariables
 * This function creates a c version of variables in main from the c++ light file
 * IN: char* className, char* variableName
 * RETURN: returns a proper c variable name
 * note: This function uses the class name and appends it to the front of the variable name
 * errors: No known errors found.
 */
char* fixMainVariables(char* className, char* variableName);
/**
 * fixMainFunctions
 * This function creates a c version of a function declaraion origionally in c++
 * IN: char* className, char* functionName, char* paramList
 * RETURN: returns a proper c function name (used in main)
 * note: This function uses the class name and param list to create a new var name
 * errors: No known errors found.
 */
char* fixMainFunctions(char* className, char* functionName, char* paramList);

#endif
/* defined __ALEXLAI__MANIPULATE__ */
