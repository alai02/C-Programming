/*
 * Name: Alex L
 * Date: Monday March 13th, 2017
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>
 #include <sys/timeb.h>

 int main(int argc, char* argv[]){

    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Failed to open the file\n");
        exit(1);
    }

    char *value;
    char line[128];
    while(fgets(line, 128, fp)){
        value = strtok(line, " ");
        printf("Data: %s\n", value);
        strcpy(data[j++], value);
    }
    fclose(fp);

    struct timeb t_startPRESORT, t_endPRESORT;
    int t_diffPRESORT;
    ftime(&t_startPRESORT);
    //Do something
	ftime(&t_endPRESORT);
    t_diffPRESORT = (int) (1000.0 * (t_endPRESORT.time - t_startPRESORT.time) + (t_endPRESORT.millitm - t_startPRESORT.millitm));

    printf("Total running time of this search: %d time units.\n", t_diffPRESORT);
	return 0;
}

void HorspoolMatching(char* Pattern[], char* Text[]){
	//Implements horspools algorithm for string matching
	//Input: Pattern: P[0...m-1] and text T[0...n-1]
	//Output: The index of the left end of the first matching substring 
	//	or -1 if there are no matches 
	char* Table;
	Table = ShiftTable(char* Pattern[0...m-1]);	 //Generate table of shifts
	int i, k;							
	i = m-1;		//positions of the patterns right end
	while(i <= n -1){
		k = 0;	//number of matched characters
		while(k < m-1 && Pattern[m-1-k] == Text[i-k]){
			k++;
		}
		if(k == m){
			return i - m + 1;
		} else {
			i = i + Table[T[i]];
		}
	}
	return -1;
}

char* ShiftTable(char* Pattern[0...m-1]){
	//Fills the shift table used by Horspools and Boyer-Moore algorithms
	//Input: Pattern P[0...m-1] and an alphabet of possible characters
	//Output: Table[0...size-1] indexed by the alphabet's characters and filled 
	//	out with shift sizes computed by foruma
	char* Table;
	for(i = 0; i < size-1; i++){
		for(j = 0; j < m-2; j++){
			Table[Pattern[j]] = m - 1 - j;
		}
	}
	return Table;
}