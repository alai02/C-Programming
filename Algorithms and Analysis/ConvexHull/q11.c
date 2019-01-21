/* Author: Alex lai
 * Student info: Alai02@mail.uoguelph.ca 0920158
 * Date: Feburary 13th, 2017
 * Assignment: A2
 * Description: This is a brute force algorithm that takes in a file of numbers
 * and uses a brute force algorithm to count the number of inversions in the file
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

#define MAX_VALUES 50000

int bruteForce(int A[], int n);

int main(int argc, char* argv[]) {

    int i = 0, j = 0;
    int n = MAX_VALUES;
    int A[MAX_VALUES];
    int bruteResult = 0;
    int mergeResult = 0;
    int numVals = 0;
    int *temp = (int *)malloc(sizeof(int)*n);
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("No input file detected\n");
        exit(1);
    }
    fscanf (fp, "%d", &i);
    while (!feof (fp)) {
        numVals++;
        A[j++] = i;
        fscanf (fp, "%d", &i);
    }
    n = numVals;
    struct timeb t_startBRUTE, t_endBRUTE;
    int t_diffBRUTE;
    ftime(&t_startBRUTE);
    bruteResult = bruteForce(A, n);
    ftime(&t_endBRUTE);
    t_diffBRUTE = (int) (1000.0 * (t_endBRUTE.time - t_startBRUTE.time) + (t_endBRUTE.millitm - t_startBRUTE.millitm));

    printf("Number of inversions (bruteforce) : %d, this algorithm took %d time units to compute\n", bruteResult, t_diffBRUTE);
    free(temp);
    fclose (fp);
    return 0;
}

/*
 * Input: An array of numbers, and the size
 * This algorithm loops through the entire array and compares the values to see if they are in ascending order
 * This algorithm uses a brute force approach, testing all values which runs on Theta(n^2) time
 * Output: This algorithm returns the number of inversions in the array of elements
 */
int bruteForce(int A[], int n) {
  int i, j;
  int inversion = 0;
  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (A[i] > A[j]) {
        inversion++;
      }
    }
  }
  return inversion;
}
