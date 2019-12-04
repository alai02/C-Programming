/*
 * Name: Alex L
 * Date: March 13th, 2017
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
	 }

	 printf("Please enter a string you would like to find the anagrams for: \n");
	 char userInput[20]; 
	 scanf("%s", userInput);
	 int anagramCount = 0;

  struct timeb t_startPRESORT, t_endPRESORT;
  int t_diffPRESORT;
  ftime(&t_startPRESORT);
	 
	HORSPOOL(1, 1, "A", 1);
	
	ftime(&t_endPRESORT);
	t_diffPRESORT = (int) (1000.0 * (t_endPRESORT.time - t_startPRESORT.time) + (t_endPRESORT.millitm - t_startPRESORT.millitm));

	 printf("Total running time of this search: %d time units.\n", t_diffPRESORT);
	return 0;
}


void HORSPOOL(char *x, int m, char *y, int n) {
	int j, bmBc[100];
	char c;

	/* Preprocessing */
	preBmBc(x, m, bmBc);

	/* Searching */
	j = 0;
	while (j <= n - m) {
		c = y[j + m - 1];
		if (x[m - 1] == c && memcmp(x, y + j, m - 1) == 0)
			OUTPUT(j);
		j += bmBc[c];
	}
}

void preBmBc(char *x, int m, int bmBc[]) {
	
	int i;
 
	for (i = 0; i < 100; ++i) {
		bmBc[i] = m;
	}
		

	for (i = 0; i < m - 1; ++i) {
		bmBc[x[i]] = m - i - 1;
	}
		

}