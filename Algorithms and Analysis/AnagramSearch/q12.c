/*
 * Name: Alex Lai
 * Student ID: 0920158
 *	Date: Monday March 13th, 2017
 * Assingment: A3 - Part 1.2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>

#define MAX_VALUES 30000

bool anagramSol(char* s1, char* s2);

int main(int argc, char* argv[]){

	char* data[MAX_VALUES];
	int i = 0;
	for(i = 0; i < MAX_VALUES; i++){
		data[i] = malloc(sizeof(char)*10 +1);
	}
	int j = 0;
    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Failed to open the file\n");
        exit(1);
    } else {
        char *value;
        char line[128];
        while(fgets(line, 128, fp)){
            value = strtok(line, " ");
            //printf("Data: %s\n", value);
            strcpy(data[j++], value);
        }
        fclose(fp);
    }

    printf("Please enter a string you would like to find the anagrams for: \n");
    char userInput[10]; 
    scanf("%s", userInput);
    int anagramCount = 0;
    int k;
    char temp1;
    for(i = 0; i < strlen(userInput)-1; i++){
        for(k = i+1; k < strlen(userInput); k++){
            if(userInput[i] > userInput[k]){
                temp1 = userInput[k];
                userInput[k] = userInput[i];
                userInput[i] = temp1;
            }
        }
    }



    struct timeb t_startPRESORT, t_endPRESORT;
    int t_diffPRESORT;
    ftime(&t_startPRESORT);
    
    for(i = 0; i < j; i++){
    	
    	if(anagramSol(data[i], userInput) == true){
    		printf("Anagram: %s\n", data[i]);
    		anagramCount++;
    	}
    	
    }
	ftime(&t_endPRESORT);
    t_diffPRESORT = (int) (1000.0 * (t_endPRESORT.time - t_startPRESORT.time) + (t_endPRESORT.millitm - t_startPRESORT.millitm));

    printf("Total number of anagrams: %d\n", anagramCount);
    printf("Total running time of this search: %d time units.\n", t_diffPRESORT);
	return 0;
}

bool anagramSol(char* s1, char* s2){

  //  printf("Unsorted: %s\n", s1);
  //  printf("Unsorted: %s\n", s2);

    int i = 0, j = 0;
    char temp1, temp2;
    char temp1String[10];
    char temp2String[10];
    strcpy(temp1String, s1);
    strcpy(temp2String, s2);

    for(i = 0; i < strlen(temp1String)-1; i++){
        for(j = i+1; j < strlen(temp1String); j++){
            if(temp1String[i] > temp1String[j]){
                temp1 = temp1String[j];
                temp1String[j] = temp1String[i];
                temp1String[i] = temp1;
            }
        }
    }

   // printf("Sorted: %s\n", temp1String);
  //  printf("Sorted: %s\n", temp2String);

    int pos = 0;
    bool matches = true;

    while(pos <= strlen(temp1String) && matches == true){
        if(temp1String[pos] == temp2String[pos]){    
            pos++;
        } else {
            matches = false;
        }
    }
    return matches;
}