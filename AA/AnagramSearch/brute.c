/*
 * Name: Alex L
 * Date: Monday March 13th, 2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>
#include <math.h>

#define MAX_VALUES 30000

bool anagramSol(char* s1, char* s2);

int main(int argc, char* argv[]){
	FILE * fp = fopen(argv[1], "r");
	int i = 0, j = 0, t_diffBRUTE, anagramCount = 0;
	char* data[MAX_VALUES];
	char *value;
	char userInput[11]; 
    char line[128];
    struct timeb t_startBRUTE, t_endBRUTE;

	for(i = 0; i < MAX_VALUES; i++){
		data[i] = malloc(sizeof(char)*10 +1);
	}
	
    
    if(fp == NULL){
        printf("Failed to open the file\n");
        exit(1);
    }

    while(fgets(line, 128, fp)){
        value = strtok(line, " ");
        strcpy(data[j++], value);
    }
    fclose(fp);

    printf("Please enter a string you would like to find the anagrams for: \n");
    scanf("%s", userInput);
    
    ftime(&t_startBRUTE);
    
    for(i = 0; i < j; i++){
    	if(anagramSol(data[i], userInput) == true){
    		printf("Anagram: %s\n", data[i]);
    		anagramCount++;
    	}
    	
    }

	ftime(&t_endBRUTE);
    t_diffBRUTE = (int) (1000.0 * (t_endBRUTE.time - t_startBRUTE.time) + (t_endBRUTE.millitm - t_startBRUTE.millitm));

    printf("Total number of anagrams: %d\n", anagramCount);
    printf("Total running time of this search: %d time units.\n", t_diffBRUTE);
	return 0;
}

bool anagramSol(char* s1, char* s2){

	int numCountA[10];
	int numCountB[10];
	int i;

	for (i = 0; i < 10; ++i){
		numCountA[i] = 0;
		numCountB[i] = 0;
	}

	for(i = 0; i < 10; i++){
		switch(s1[i]){
			case '0': numCountA[0]++;
				break;
			case '1': numCountA[1]++;
				break;
			case '2': numCountA[2]++;
				break;
			case '3': numCountA[3]++;
				break;
			case '4': numCountA[4]++;
				break;
			case '5': numCountA[5]++;
				break;
			case '6': numCountA[6]++;
				break;
			case '7': numCountA[7]++;
				break;
			case '8': numCountA[8]++;
				break;
			case '9': numCountA[9]++;
				break;
			default:
				break;
		}
	}
	for(i = 0; i < 10; i++){
		switch(s2[i]){
			case '0': numCountB[0]++;
				break;
			case '1': numCountB[1]++;
				break;
			case '2': numCountB[2]++;
				break;
			case '3': numCountB[3]++;
				break;
			case '4': numCountB[4]++;
				break;
			case '5': numCountB[5]++;
				break;
			case '6': numCountB[6]++;
				break;
			case '7': numCountB[7]++;
				break;
			case '8': numCountB[8]++;
				break;
			case '9': numCountB[9]++;
				break;
			default:
				break;
		}
	}

	bool allGood = true;
	for(i = 0; i < 10; i++){
		if(numCountA[i] != numCountB[i]){
			allGood = false;
		}
	}

	return allGood;
}
