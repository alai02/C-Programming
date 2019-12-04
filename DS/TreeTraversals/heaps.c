/*
 * Author: Alex L
 * This is a program that takes in a 20x10 array and heap sorts the sum
 * of the first 3 numbers into a min-heap. The program then displays the 
 * contents of the file in the new sorted order
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ob{ //treats each line as an object 
	int key; //the first the vals of the line
	int data[]; //all the data of the line (last 7 numbers are the data)
} Ob; //typedefs the struct for easy initalization

int keys[20];

Ob* parseObject(char* theLine); //function definitions to avoid implicit declaration
void displayData(Ob *objectList[]);
void heapSort();
void swap(int *parent, int *child);

int main(int argc, char* argv[]){ //main function and parameters allows for grabing users input

	
	Ob *objectList[20]; //create a list of objects
	Ob *newList[20]; //second list of objects that are going to be stored when sorted
	int i = 0;
	FILE *fp = fopen(argv[1], "r"); //opens the file to be read from
	if (fp == NULL) {
		printf("ERROR: File not opened, please enter a file after ./a.out\n"); //error message incase file not found
	} else {
    	char line[100]; //line long enough to hold all data in the line and some to protect from reaching array out of bounds
    	char* data; //data to be sent to create an object
    	char lineEnd[1] = "\n"; //makes sure index never reaches end of file
    	while(fgets(line, sizeof(line), fp)){ 
    		data = strtok(line, lineEnd); //grab the enture line
			Ob* ptr; //create a object instance
			ptr = parseObject(data); //set the data in the object
			objectList[i] = ptr; //store the object in the list
			keys[i] = ptr->key; //store a seperate key list
			i++; //increment the index
    	}
    	int j;
    	int i = 0;
    	int k = 0;


    	heapSort(); //calls heap sort, no parameters needed since keys are global
    	
		for(j = 0; j < 20; j++){ //loop through objects 
    	
			for(i = 0; i < 20; i++){ //loop through all keys
    	
				if(objectList[j]->key == keys[i]){
					newList[k] = objectList[j]; //stores the objects in a new list that is sorted using min heap algorithm 
    				k++; //increment final list
    				keys[i] = -1; //set already set keys to -1
    			}
    		}
    	}
    	printf("\n");
    	displayData(newList); //display all the data in the array
	}

	return 0; //end program
}

void displayData(Ob *objectList[]){ //takes in an object list and displays all the data in a 20x10 array
	
	int i,j;
	
	for(i = 0; i < 20; i++){ //loops through all objects
		Ob *node = objectList[i];  //sets a temp object
		for(j = 0; j < 10; j++){ //loops through all the data elements in int array
			printf("%d ", node->data[j]); //prints all the data
		}
		printf("\n"); //new line for formatted output
	}
}


//This function takes in a char pointer and returns an object 
Ob* parseObject(char* theLine){ //takes in a line which holds object info
	int numKey; //create a temp var to add the keys together
	int i,j = 0; //iterators
	Ob *newObject = malloc(sizeof(Ob)*100); //malloc enough memory for the objects

	newObject->key = 0; //init incase of errors
	newObject->data[0] = 0;
	numKey = ((theLine[0] - '0') *10) + (theLine[1] - '0'); //set all the values
	numKey += ((theLine[3] - '0') *10) + (theLine[4] - '0'); 
	numKey += ((theLine[6] - '0') *10) + (theLine[7] - '0');
	newObject->key = numKey; //put vals in object
	
	for (i = 0; i < 10; i++) {
		newObject->data[i] = ((theLine[j] - '0') *10) + (theLine[j+1] - '0');
		j += 3;
	}
	return newObject; //return the newly created object
}

//min heap sort algorithm. 
void heapSort(){
	int i;


	for(i = 0; i < 20; i++){// If parent is less than both children 

	    if(keys[i+1] < keys[2*(i+1)] && keys[i+1] < keys[(2*(i+1))+1]){//  Check which child is smallest 

	        if(keys[2*(i+1)] < keys[(2*(i+1))+1]){//Parent is assigned smallest node
	            swap(&keys[i+1],&keys[2*(i+1)]);
	        } else{
	        	swap(&keys[i+1],&keys[(2*(i+1))+1]);
	        }

	    } else if(keys[(i+1)] < keys[2*(i+1)]){ //If parent is less than left child
	        swap(&keys[i+1],&keys[2*(i+1)]);
	    } else if(keys[i+1] < keys[(2*(i+1))+1]){ //If parent is less than right child
	        swap(&keys[i+1],&keys[(2*(i+1))+1]);
	    }
	}
}

void swap(int *pNode, int *cNode){ //simple swap function
    int temp;
    temp = *cNode;
    *cNode = *pNode;
    *pNode = temp; 
}
