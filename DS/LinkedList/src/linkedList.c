#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

Food * createRecord(char * name, char * group, int calories, char theType){
	
	if(!(strlen(name) > 50) && !(strlen(group) > 50) && (calories > 0) && (theType == 'j' || theType == 'h')){
		Food* n = malloc(sizeof(Food));
		n->name = malloc(sizeof(char) * (strlen(name) +1));
		strcpy(n->name, name);
		n->foodGroup = malloc(sizeof(char) * (strlen(group) +1));
		strcpy(n->foodGroup, group);
		n->calories = calories;
		n->type = theType;
		n->next = NULL;
		return n;
	} 
	else{
		return NULL;
	}
}

char * printRecord(Food * toPrint){
	
	if(toPrint != NULL){
		char* record = malloc(sizeof(char)*(strlen(toPrint->name) + strlen(toPrint->foodGroup) + 10));
		sprintf(record, "%s (%s):%d[%c]",  toPrint->name, toPrint->foodGroup, toPrint->calories, toPrint->type); 
		return record; 
	} 
	else{
		return NULL;
	}
}

void destroyRecord(Food * toDie){
		free(toDie->name);
		free(toDie->foodGroup);
		free(toDie);
}

Food * addToFront(Food * theList, Food * toBeAdded){

	if(theList ==  NULL){
		return toBeAdded; 
	}
	if(toBeAdded != NULL){
		toBeAdded->next = theList;
		theList = toBeAdded;
		return toBeAdded;	
	} 
	else{
		return theList; 
	}
}


Food * addToBack(Food * theList, Food * toBeAdded){

	if(theList == NULL){
		return toBeAdded;
	}
	if(toBeAdded != NULL){
		Food *temp = theList; 
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = toBeAdded;
		return theList;
	}
	else{
		return theList; 
	}
}

Food * removeFromFront(Food * theList){

	if(theList != NULL){
		Food* temp = theList;
		temp = temp->next;
		return temp;
	}
	else{
		return NULL;
	}
}

Food * removeFromBack(Food * theList){
	
	if(theList != NULL){
		Food* temp = theList;
		Food* end = theList;
		while(end->next != NULL){
			temp = end;
			end = end->next;
		}
		temp->next = NULL;
		return end;
	}
	else{
		return NULL;
	}
}

Food * getLastItem(Food * theList){
	if(theList != NULL){
		Food* temp = theList;
		while(temp->next != NULL){
			temp = temp->next;
		}
		return temp;
	} 
	else{
		return NULL;
	}
}

Food * getFirstItem(Food * theList){
	if(theList != NULL){
		return theList;
	} 
	else{
		return NULL;
	}
}

int isEmpty(Food * theList){

	if(theList == NULL){
		return 1;
	} 
	else{
		return 0;
	}
}

void printList(Food * theList){
	
	if(theList != NULL){
		Food* temp = theList; 
		while(temp != NULL){
			char* record; 
			record = printRecord(temp);
			printf("%s\n", record);
			temp = temp->next; 
			free(record);
		}
	} 
}

void destroyList(Food * theList){

	while(theList != NULL){
			Food* temp = theList;
			theList = theList->next;
			destroyRecord(temp);
	}
}
