#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
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