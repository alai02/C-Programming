/*
 * This file contains an inteface for the functions defined by alex lai
 *
 * These functions deal the ongoing game that updates the game in real time
 *
 * They were written for CIS*2500 Assignment 2 REDO @ UoGuelph
 *
*/
#ifndef __ALEXLAI__PLAY__
#define __ALEXLAI__PLAY__

/**
 * initGame
 * This fuction initializes the game and draws the level onto the ncurses window. 
 * IN: int argc, char* argv[] the argc is passing the amount of variables that are passed in when the program starts and the second is a pointer to a character array that stores the level file. 
 * RETURN: Void function, no return. 
 * note: Must pass a valid level file to this fuction that follows the A2 spec.
 * errors: No known errors in this function.  
 */
void initGame(int argc, char* argv[]);

/**
 * gameLoop
 * This is a function that loops until the user quits the game. 
 * IN: Room* ptr[6], Hero* hero which are pointers to the structs. 
 * RETURN: void function, no return. 
 * note: Only pressing the lower case q function will end this loop. 
 * errors: no known errors in this function. 
 */
void gameLoop(Room* allRooms[6], Hero* hero);

/**
 * endGame
 * This game stops ncurses and is called at the very end of the program when the game is done. 
 * IN: no parameters necessary. 
 * RETURN: void function, no return. 
 * note: This function just uses the ncurses function that ends the screen
 * errors: No known errors in this function. 
 */
void endGame();

/**
 * freeStuff
 * this function takes pointers to a array of Room structs and A hero struct and frees all memory that was allocated. 
 * IN: Room* ptr[6], Hero* hero which are pointers to the structs. 
 * RETURN: Void function no return
 * note: This function only frees memory that was allocated at the start of the game for the level. 
 * errors: If memeory was somehow not allocated properly, function might cause a double free corruption or some other error. 
 */
void freeStuff(Room* ptr[6], Hero* hero);

/**
 * displayGold
 * This function displays the amount of gold that the player has collected throughout the level. Prints to stdout. 
 * IN: Herp* hero which is a pointer to a hero struct
 * RETURN: Void function no return, just prints to standard out.
 * note: Players gold is set to zero and will print zero if no gold is collected. 
 * errors: There are no known errors in this function. 
 */
void displayGold(Hero* hero);

#endif
/* defined __ALEXLAI__PLAY__ */
