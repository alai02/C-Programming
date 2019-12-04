#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "manipulate.h"
#include "fileio.h"
#include "helper.h"

void destroyClass(ClassDef* classToDestroy){
	int i;
	for(i = 0; i < 10; i++){
		free(classToDestroy->classVariables[i]);
		free(classToDestroy->memberDefinitions[i]);
		free(classToDestroy->classParameters[i]);
		free(classToDestroy->functionPointers[i]);
		free(classToDestroy->classConstructurs[i]);
		free(classToDestroy->nextDef);
	}
	for(i = 0; i < 100; i++){
		free(classToDestroy->validCode[i]);
	}
	free(classToDestroy);
}
void destroyList(ClassDef * theList){
	while(theList != NULL){
			ClassDef* temp = theList;
			theList = theList->nextDef;
			destroyClass(temp);
	}
}
void printArray (char** array) {
	int i;
	for(i = 0; i < 65; i++){
		printf("  %s  ", array[i]);
		printf("\n");
	}
}
