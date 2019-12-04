#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

Food* parseFood(FILE* file);
void totalCalories(Food* theList);
void averageCalories(Food* theList);
void lengthOfList(Food* theList);

int main(int argc, char* argv[]){

	FILE* file = fopen(argv[1], "r");
	if(file == NULL){
		printf("File Not opened\n");
		exit(1);
	}
	Food* theList = parseFood(file);
	
	totalCalories(theList);
	averageCalories(theList);
	lengthOfList(theList);
	printList(theList);

	destroyList(theList);
	fclose(file);
	return 0;
}
/**
 * parseFood 
 * This function takes in a file and converts the data into seperate variables
 * Next passing it to a createRecord function where a food item is returned if good data is given
 * IN: FILE* file, is a csv file that follows the A4 spec 
 * OUT: Food* head, this function returns the head of a linked list of food items
 * POST: If bad data is passed into createRecord, nothing will be added to the list.
 * ERROR: Function will return NULL if all data read in file is bad data, also
 * 		  since the data is separated by commas, function will have errors if there are 2 commas in a row
 */

Food* parseFood(FILE* file){

	Food* head = NULL;
	int i; 
	int num;
	char type; 
	char line[255];
	char* name;
	char* foodGroup;
	char* cal;
	char* junk;
	char c[2] = ",";
	while(fgets(line, sizeof(line), file) != NULL){
		for(i = 0; i < strlen(line); i++){
			if(line[i] == ','){
				name = strtok(line, c);
				foodGroup = strtok(NULL, c);
				cal = strtok(NULL, c);
				junk = strtok(NULL, c);
				num = atoi(cal);
				type = junk[0];
				Food* food = createRecord(name, foodGroup, num, type);
				if(food->type == 'h'){
					head = addToFront(head, food); 
				} 
				else if(food->type == 'j'){
					head = addToBack(head, food);
				}
				
			}
		}
	}
	return head; 
}

/**
 * totalCalories 
 * This is a function that calculates the total amountof calories in the list of food items. 
 * IN: Food* theList, this is a pointer to a linked list of Food items that contains members calories that will be added up
 * OUT: Void function, no return. Function just prints to stdout. 
 * POST: If the total calories exceeds the number than an integer can hold, function will not work.
 * Aviod large data sets that will result in a total over 2 billion.
 * ERROR: No known errors present in this function.
 */

void totalCalories(Food* theList){

	if(theList != NULL){
		int i; 
		i = 0;
		Food* temp = theList;
		while(temp != NULL){
			i += temp->calories;
			temp = temp->next;
		}
		printf("%d\n", i);
	}
	else{
		printf("%d\n", 0);
	}
}

/**
 * averageCalories
 * This is a function that calculates the average calories of the different food groups that are 
 * in the list. The five groups are vegfruit, meat, dairy, grains, fat
 * IN: Food* theList, this is a pointer to a linked list of food items
 * OUT: Void function, no return. Prints to stdout
 * POST: If value that is stored in temp->foodGroup is not one of the five food groups with proper 
 * spacing and are not all lower case letters, function will not work.  
 * ERROR: No known errors present in this function.
 */

void averageCalories(Food* theList){

	double veg, meat, dairy, grains, fat;
	double v, m, d, g, f;
	double total; 
	veg = 0;
	v = 0;
	meat = 0;
	m = 0;
	dairy = 0;
	d = 0;
	grains = 0;
	g = 0;
	fat = 0;
	f = 0;

	Food* temp = theList;
	while(temp != NULL){
		if(strcmp(temp->foodGroup, "vegfruit") == 0){
			veg += temp->calories;
			v++;
		} 
		if(strcmp(temp->foodGroup, "meat") == 0){
			meat += temp->calories;
			m++;
		} 
		if(strcmp(temp->foodGroup, "dairy") == 0){
			dairy += temp->calories;
			d++;
		} 
		if(strcmp(temp->foodGroup, "grains") == 0){
			grains += temp->calories;
			g++;
		}
		if(strcmp(temp->foodGroup, "fat") == 0){
			fat += temp->calories;
			f++;
		}
		temp = temp->next;
	}
	if(v != 0){
		total = veg/v;
		printf("%.2f\n", total);
	} else{
		printf("%.2f\n", 0.00);
	}
	if(m != 0){
		total = meat/m;
		printf("%.2f\n", total);
	} else{
		printf("%.2f\n", 0.00);
	}
	if(d != 0){
		total = dairy/d;
		printf("%.2f\n", total);
	} else{
		printf("%.2f\n", 0.00);
	}
	if(g != 0){
		total = grains/g;
		printf("%.2f\n", total);
	} else{
		printf("%.2f\n", 0.00);
	}
	if(f != 0){
		total = fat/f;
		printf("%.2f\n", total);
	} else{
		printf("%.2f\n", 0.00);
	}
}


/**
 * lengthOfList
 * This function counts the number of nodes in the linked list and prints the number to stdout.
 * IN: Food* theList, this is a pointer to a linked list of Food items. 
 * OUT: Void function, no return. Function just prints to stdout. 
 * POST: If list is longer than 2 billion variable i will break because it cant count that high. 
 * ERROR: No known errors present in this function.
 */

void lengthOfList(Food* theList){
	if(isEmpty(theList) == 1){
		printf("%d", 0);
	} 
	else{
		int i;
		i = 0;
		Food* temp = theList;
		while(temp != NULL){
			i++;
			temp = temp->next;
		}
		printf("%d\n", i);
	}
}

