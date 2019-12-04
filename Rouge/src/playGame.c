#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "drawThings.h"
#include "playGame.h"
#include "heroMove.h"

void initGame(int argc, char* argv[]);
void gameLoop(Room* allRooms[6], Hero* hero);
void endGame();
void freeStuff(Room* ptr[6], Hero* hero);
void displayGold(Hero* hero);

void initGame(int argc, char* argv[]){

	Room* allRooms[6];
    Hero* hero;
 	FILE* dimensions;
 	char line[150]; 
    int indexCounter;
    indexCounter = 0;
    dimensions = fopen(argv[1], "r");
    if(dimensions == NULL) {
	   printf("file not opened\n");
       exit(1);
    }
    initscr();
    noecho();
    while ((fgets(line, 150, dimensions) != NULL)) {
		allRooms[indexCounter] = parseRoom(line);
        if(indexCounter < 1){
            hero = initHero(line);
        }
        indexCounter++;
    }
    drawScreen(allRooms);
    refresh();
    gameLoop(allRooms, hero);
}

void gameLoop(Room* room[6], Hero* hero){

    int currentY;
    int currentX;
    char input;
    char result; 
    currentY = getcury(stdscr);
    currentX = getcurx(stdscr);
    mvprintw(hero->yLoc + room[0]->yLoc, hero->xLoc + room[0]->xLoc, character);
    move(hero->yLoc + room[0]->yLoc, hero->xLoc + room[0]->xLoc);
    do{
        result = moveHero(input, currentY, currentX, room, hero);
        currentY = getcury(stdscr);
        currentX = getcurx(stdscr);
        refresh();
        input = getch();
    
    } while (input != 'q' && result != 'q');
    endGame();
    displayGold(hero);
    freeStuff(room, hero);
    
}

void endGame(){
    endwin();
}

void freeStuff(Room* ptr[6], Hero* hero){
    int i;
    for (i = 0; i < 6; i++){
        free(ptr[i]->gol);
        free(ptr[i]->itm);
        free(ptr[i]);
    }      
    free(hero);
}

void displayGold(Hero* hero){
	printf("Total gold amount: %d\n", hero->goldAmount);
}
