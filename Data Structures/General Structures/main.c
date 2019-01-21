#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * main 
 * This is the main function that is responsible with communicating with the user and is resposonsible
 * for calling 3 different c files which do various tasks.
 * IN: NONE
 * OUT: 0
 * ERROR: None that are known
 */
 
int main(){

	int exit = 1;
	int choice = 0;	

	while(exit == 1){

		printf("Pick 1, 2, or 3 for Carbon.c, Ackermann.c, or Newton.c, Press 0 for exit\n");
		scanf("%d", &choice);
	
		switch (choice) {

			case 0:
				exit = 0;
				break;
			case 1:
				carbon();
				break;
			case 2:
				ackermann();
				break;
			case 3: 
				newtonMath();
				break;
			default:
				break;
		}
	}
	return 0;
}