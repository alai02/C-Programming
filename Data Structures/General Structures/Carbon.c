#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char* x, char* y){
	
	char temp;
	temp = *x; //swaps the value at the correct addresses
	*x = *y;
	*y = temp;
}

void allStrings(char* theString, int beginning, int end){

	int i;
	if(beginning == end){
		printf("%s\n", theString);
	} else {
		for (i = beginning; i <= end; i++){
			swap((theString+1), (theString+i)); //swaps the values
			allStrings(theString, beginning + 1, end); //recursive call for next
			swap( ( theString + beginning), ( theString + i )); //swap back
		}
	}

}

void carbon(){
	
	int x = 0;
	char theWord[] = "Carbon"; //string to be displayed
	x = strlen(theWord); //length of word

	allStrings(theWord, 0, x-1); //first call
}