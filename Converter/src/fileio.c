#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "manipulate.h"
#include "fileio.h"
#include "helper.h"

void writeToFile(ClassDef* myEntireClass, char* fileName){
	int i;
	/* int indentation = 0*/
	printf("Inside write function\n");
	char* outFileName = fileName;
	FILE* fp;
	ClassDef* temp = myEntireClass;
	outFileName[strlen(outFileName)-1] = 0;
	fp = fopen(outFileName, "w+");
	printf("Starting to write, outFIle name: %s\n" , outFileName);
	fprintf(fp, "Outputted program\n" );
	if(fp == NULL){
		printf("Failed to create output file");
	}
	for(i = 0; i < 100; i++){
		if(temp->validCode[i] != NULL){
			fprintf(fp, "%s\n", temp->validCode[i]);
		}
	}
	printf("Do we make it here??\n" );
	while(temp != NULL){
		fprintf(fp, "%s\n", temp->className);/* struct name*/
		for(i = 0; i < 10; i++){ /*add struct vars into struct*/
			if(temp->classVariables[i] != NULL){
				fprintf(fp, "%s\n", temp->classVariables[i]);
			}
		}
		for(i = 0; i < 10; i++){ /*add funtion pointers to struct*/
			if(temp->functionPointers[i] != NULL){
				fprintf(fp, "%s\n", temp->functionPointers[i]);
			}
		}
		fprintf(fp, "%s\n", "};"); /*close struct*/
		for(i = 0; i < 10; i++) { /**/
			if(temp->memberDefinitions[i] != NULL){
				fprintf(fp, "%s\n", temp->memberDefinitions[i]);
			}
		}
		/*
		for(i = 0; i < 10; i++){
			if(temp->classData ){

			}
		}
		*/
		/*fputs("This is testing for fputs...\n", fp);*/
		temp = temp->nextDef;
		/* free the struct at the end*/
	}
	destroyList(myEntireClass);
	fclose(fp);
}
void parseFile(char* filePath){
	ClassDef* myClassDef = malloc(1000);
	char ** characterArray;
	char* theFilePath = malloc(100);
	strcpy(theFilePath, filePath);
	characterArray = generateArray(1000, 50);
	FILE * file;
	file = fopen(filePath, "r");
	if (file == NULL){
		exit(1);
	}
	char line[BUFFER_MAX_LENGTH];
	int tempChar;
	unsigned int tempCharIdx = 0U;
	char *token;
	int i = 0;
	while ( ( tempChar = fgetc ( file ) ) ) {
	    if (tempChar == EOF) {
	        line[tempCharIdx] = '\0';
			strcpy(characterArray[i], line);
	        i++;
	        break;
	    } else if (tempChar == '\n') {
	    	line[tempCharIdx] = '\0';
	    	tempCharIdx = 0U;
	    	strcpy(characterArray[i], line);
			printf("Line before Parse: %s\n", characterArray[i] );
			token = strtok(line, " \t\n");
			/*	printf("Tokens unextracted but parsed: %s\n", token); */
			while (token != NULL) {
				/*printf("The token: %s\n", token);*/
				strcpy(characterArray[i], token);
				token = strtok(NULL, " \t\n");
				printf("Data extracted: %s\n", characterArray[i]);
				i++;
			}
	    continue;
	    } else {
	        	line[tempCharIdx++] = (char)tempChar;
	    }
	}
	writeToFile(myClassDef, theFilePath);
	fclose(file);
}
