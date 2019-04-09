/*
 * This file contains an inteface for the functions defined by alex lai
 * This file contains a code relating to file io
 * They were written for CIS*2750 Assignment 1 @ UoGuelph Winter 2017
*/
#ifndef __ALEXLAI__FILEIO__
#define __ALEXLAI__FILEIO__

#define BUFFER_MAX_LENGTH 1024

/**
 * writeToFile
 * This function writes all data from my linkedList to a c file
 * IN: ClassDef* myEntireClass, char* fileName
 * RETURN: no return, void function
 * note:
 * errors: No known errors found.
 */
void writeToFile(ClassDef* myEntireClass, char* fileName);
/**
 * parseFile
 * This function parses a c++(light) file and stores the data in structs
 * IN: char* filePath
 * RETURN: void functon, no retur
 * note: stores data in a 2d character array
 * errors: No known errors found.
 */
void parseFile(char* filePath);

#endif
/* defined __ALEXLAI__FILEIO__ */
