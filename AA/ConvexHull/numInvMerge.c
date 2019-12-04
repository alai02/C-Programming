

/* Author: Alex l
 * Date: Feburary 13th, 2017
 * Description: This is a program that takes in a file of numbers
 * and uses the merge sort algorithm to count the number of inversions in the file in nlogn time
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
/* Max vals set to 50000 because of size of input file provided by the prof*/
#define MAX_VALUES 50000

int mergeSort(int A[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int main(int argc, char* argv[]) {

    int i = 0, j = 0;
    int n = MAX_VALUES;
    int A[MAX_VALUES];
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
    struct timeb t_startMERGE, t_endMERGE;
    int t_diffMERGE;
    
    ftime(&t_startMERGE); //get start time
    mergeResult =  mergeSort(A, temp, 0, n - 1);
    ftime(&t_endMERGE); //get end time
    
    t_diffMERGE = (int) (1000.0 * (t_endMERGE.time - t_startMERGE.time) + (t_endMERGE.millitm - t_startMERGE.millitm));

    printf("Number of inversions (merge): %d, this algorithm took %d time units to compute\n", mergeResult, t_diffMERGE);
    
    free(temp);
    fclose (fp);
    
    return 0;


}


/*
 * Function name: mergeSort
 * Input: An array of numbers, a temp array that can hold n numbers. a left and right to support recursion
 * Description: This Function breaks up the array into 2 smaller sub arrays and merges them together to solve the task
 * This function calls the function merge which
 * Output: Returns the amount of inversions in the array of numbers
 */
int mergeSort(int A[], int temp[], int left, int right) {

  int middle, inversionCount = 0;
  
  if (right > left) {
    middle = (right + left)/2;
    inversionCount  = mergeSort(A, temp, left, middle);
    inversionCount += mergeSort(A, temp, middle + 1, right);
    inversionCount += merge(A, temp, left, middle + 1, right);
  }

  return inversionCount;
}


/*
 * Function name: merge
 * Input: An array of numbers, a temp array that can hold n numbers. a left, right and middle integers representing indexes of the array
 * Description: This Function merges 2 smaller sub arrays
 * Output: Returns the amount of inversions in the array of numbers
 */
int merge(int A[], int temp[], int left, int mid, int right) {

  int i, j, k;
  int inversionCount = 0;

  i = left;
  j = mid;
  k = left;


  while ((i <= mid - 1) && (j <= right)) {
    if (A[i] <= A[j]) {
      temp[k++] = A[i++];
    } else {
      temp[k++] = A[j++];
      inversionCount = inversionCount + (mid - i);
    }
  }

  while (i <= mid - 1) {
    temp[k++] = A[i++];
  }

  while (j <= right){
    temp[k++] = A[j++];
  }

  for (i=left; i <= right; i++){
    A[i] = temp[i];
  }

  return inversionCount;


}
