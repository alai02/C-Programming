/*
 * This file contains an inteface for the functions defined by alex lai
 *
 * These functions deal the ongoing game that updates the game in real time
 *
 * They were written for CIS*2500 Assignment 2 REDO @ UoGuelph
 *
*/
#ifndef __ALEXLAI__MOVE__
#define __ALEXLAI__MOVE__

#define character "@"

/**
 * moveHero
 * This function is responsible for finding out what key the user pressed and doing the
 * approprite action for that key press. 
 * IN: char input, int yLoc, int xLoc the input variable is the input character that the user
 * pressed and the x and y location are the location that the player wants to move to. 
 * Also the pointers to the room and hero struct are passed incase player hits a gold or 
 * wants to move to a different room. 
 * RETURN: returns a character, only important when the player runs into a staircase, will return letter q in this case
 * note: Nothing to note on in this funciton.
 * errors: No known errors in this function. 
 */
char moveHero(char input, int yLocation, int xLocation,Room* room[6], Hero* hero);

/**
 * canMove
 * This function takes in the coordinates that the player wants to move to and checks if
 * that location is a valid location that a player can move to. 
 * IN: int toGoY, int toGoX these are the cooridnates that the player wants to move to 
 * Also the Hero pointer to the struct is passed incase the player runs into a gold piece. 
 * RETURN: returns an integer which will tell moveHero function if they can move there or not
 * note: Returns 0 for walls and empty space, returns 1 for valid location and 2 for a stairs. Returns 3 for a door
 * errors: There is no known errors present in this function. 
 */
int canMove(int toGoY, int toGoX, Hero* hero);

/**
 * moveCharacter
 * This function prints the new character at the location and writes over the spot that the player was
 * at with the correct symbol if its either a door or a floor tile. 
 * IN: int newY, int newX which are the new location of the character. 
 * RETURN: this function is void and has no return. 
 * note: Nothing to note about this function.
 * errors: No known errors are present in this function. 
 */
void moveCharacter(int newY, int newX);

/**
 * moveRoom
 * This function is responsibe for moving the player to the next room in the game. 
 * IN: int newY, int newX, Room* allRooms[6] these are the x and y loctions where the player has
 * pressed and also the room structs that will tell which holds the info of the room that the player
 * is tring to move to.  
 * RETURN: this function is void and has no return. 
 * note: Nothing to note about this function.
 * errors: No known errors are present in this function. 
 */
void moveRoom(int newY, int newX, Room* allRooms[6]);

#endif
/* defined __ALEXLAI__MOVE__ */




