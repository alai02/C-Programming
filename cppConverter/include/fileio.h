/*
 * This file contains a code relating to file io
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
