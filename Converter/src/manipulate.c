#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "manipulate.h"
#include "fileio.h"
#include "helper.h"

char * appendClassToFrontFunction(char* className, char* variableName, char* parameterList){
	char* nameToReturn = NULL;
	char* str1 = NULL;
	char* str2 = NULL;
	char* str3 = NULL;
	strcpy(str1, className);
	strcpy(str2, variableName);
	strcpy(str3, parameterList);
	strcat(str1, str2);
	strcat(str1, str3);
	strcpy(nameToReturn, str1);
	printf("New variable name: %s", str1);
	return nameToReturn;
}
char * appendClassToFrontVariable(char* className, char* variableName, char* type){
	char* endOfVar = ";";
	char* nameToReturn = NULL;
	strcat(className, variableName);
	strcat(type, className);
	strcat(type, endOfVar);
	strcpy(nameToReturn, type);
	printf("New variable name: %s", nameToReturn);
	return nameToReturn;
}
char* fixMainVariables(char* className, char* variableName){
	strcat(className, variableName);
	return className;
}
char* fixMainFunctions(char* className, char* functionName, char* paramList){
	strcat(className, functionName);
	strcat(className, paramList);
	return className;
}
