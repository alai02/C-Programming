 /*
 * Name: Alex L
 * Date: Monday March 13th, 2017
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>
 #include <sys/timeb.h>

#define MAX_STRINGS 44049

 int main(int argc, char* argv[]){
 	int i, j = 0, k = 0, x = 0;
 	char* data[MAX_STRINGS];
 	char * line = NULL;
    size_t len = 0;
    ssize_t read;

    struct timeb t_startPRESORT, t_endPRESORT;
    int t_diffPRESORT;

 	for(i = 0; i < MAX_STRINGS; i++){
 		data[i] = malloc(sizeof(char)*128+1);
 	}
    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Failed to open the file\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("%s", line);
        strcpy(data[j++], line);
    }
    fclose(fp);
    
    char* userInput = malloc(sizeof(char)*128+1);
    printf("Please enter a pattern you would like to search for: ");
    scanf("%s", userInput);
   

    ftime(&t_startPRESORT);

    int stringCount = 0;

    for(i = 0; i < j; i++){

    	for(k = 0; k < strlen(data[i]); k++){
    		x = 0;

            if(data[i][k] == userInput[0]){

        		while( x < strlen(userInput) && data[i][k+x] == userInput[x]){
        			x++;
        		}

        		if(x == strlen(userInput)){
        			printf("String found in: %s\n", data[i]);
        			stringCount++;
        		}
            }
    	}
    }

	ftime(&t_endPRESORT);
    t_diffPRESORT = (int) (1000.0 * (t_endPRESORT.time - t_startPRESORT.time) + (t_endPRESORT.millitm - t_startPRESORT.millitm));

    printf("There are: %d occurances of that string in this text\n", stringCount);
    printf("Total running time of this search: %d time units.\n", t_diffPRESORT);
	return 0;
}

