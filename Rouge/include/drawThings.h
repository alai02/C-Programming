/*
 * This file contains an inteface for the functions defined by alex
 *
 * These functions deal with creating the game on screen
 *
 * They were written for CIS*2500 Assignment 2 REDO @ UoGuelph
 *
*/
#ifndef __ALEXLAI__DRAW__
#define __ALEXLAI__DRAW__

 typedef struct Hero{ //hero struct, holds location and various things
    int xLoc;
    int yLoc;
    int goldAmount;
 }Hero;

typedef struct Gold{ //gold struct, includes various things.
    int xLoc;
    int yLoc;
    int amount; 
    char symb;
    int goldAmount;
}Gold;

typedef struct Items{
    int xLoc;
    int yLoc;
    int itemAmount;
    char symb;
    int xPos;
    int yPos;
}Items;

typedef struct Room{
    int xDim;
    int yDim;
    int xLoc;
    int yLoc;
    struct Gold* gol;
    struct Items* itm;
}Room;

/**
 * parseRoom
 * Accepts a line which is one level room and stores all info in structs
 * IN: char* wholeRoom
 * RETURN: Returns a pointer to the location of where the room is stored
 * note: To correctly parse the room input, line must be in specific order and spec
 * errors: If incorrect level file is passed in,  structs will not be created correctly. 
 */
Room* parseRoom(char* wholeRoom);

/**
 * drawScreen
 * Draws the rooms using the dimensions that are stored in the room structs
 * IN: Room* allRooms[6]
 * RETURN: void function, no return
 * note: nothing to note on. 
 * errors: In example easy.txt, 6th room has a dimensions problem. 
 */
void drawScreen(Room* allRooms[6]);

/**
 * drawItems
 * draws the game objects to the rooms that the player will interact with.
 *
 * IN: Room* allRooms[6]
 * RETURN: void function, no return
 * note: Nothing to note
 * errors: No known errors in this function. 
 */
void drawItems(Room* allRooms[6]);

/**
 * initHero
 * Finds where in the level file the hero is supposed to start and allocate the memory for the hero struct
 *
 * IN: char* wholeRoom
 * RETURN: returns a hero pointer
 *
 * note: To correctly parse the room input, line must be in specific order and spec
 * errors: No known errors found. 
 */
Hero* initHero(char* wholeRoom);

#endif
/* defined __ALEXLAI__DRAW__ */
