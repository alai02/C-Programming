/*
 * This file contains an inteface for the functions defined by alex
 * This file contains a bunch of helper functons
 * They were written for CIS*2750 Assignment 1 @ UoGuelph Winter 2017
*/
#ifndef __ALEXLAI__HELPER__
#define __ALEXLAI__HELPER__

/**
 * destroyClass
 * This function frees up all memory in the struct ClassDef
 * IN: ClassDef* classToDestroy
 * RETURN: no return, void function
 * note: DestroyList Calls this function since it is in a linked list
 * errors: No known errors found.
 */
void destroyClass(ClassDef* classToDestroy);
/**
 * destroyList
 * This destroys all memory in the classes
 * IN: ClassDef* theList
 * RETURN: void functon, no return
 * note: Calls function destroy class to free memory
 * errors: No known errors found.
 */
void destroyList(ClassDef * theList);
/**
 * printArray
 * Prints out the 2d array of characters with a fixed length
 * IN: char** array
 * RETURN: void function, no return
 * note: This is a function that is used for strictly testing
 * errors: No known errors found.
 */
void printArray (char** array);

#endif
/* defined __ALEXLAI__HELPER__ */
