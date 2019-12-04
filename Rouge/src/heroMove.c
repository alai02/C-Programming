#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "drawThings.h"
#include "playGame.h"
#include "heroMove.h"

char moveHero(char input, int yLocation, int xLocation,Room* room[6], Hero* hero);
int canMove(int toGoY, int toGoX, Hero* hero);
void moveCharacter(int newY, int newX);
void moveRoom(int newY, int newX, Room* allRooms[6]);


char moveHero(char input, int yLocation, int xLocation, Room* room[6], Hero* hero) {
    char gameEnd;
    gameEnd = 'p';

    if(input == 'a'){
      if (canMove(yLocation, xLocation -1, hero) == 1){
        moveCharacter(yLocation, xLocation - 1);
      } else if(canMove(yLocation, xLocation -1, hero) == 2){
          gameEnd = 'q';
      } else if(canMove(yLocation, xLocation -1, hero) == 3){
          moveRoom(yLocation, xLocation - 1, room);
      }
    }
    else if (input == 's'){
      if (canMove(yLocation + 1, xLocation, hero) == 1){
        moveCharacter(yLocation + 1, xLocation);
      } else if(canMove(yLocation + 1, xLocation, hero) == 2){
          gameEnd = 'q';
      } else if(canMove(yLocation + 1, xLocation, hero) == 3){
          moveRoom(yLocation + 1, xLocation, room);
      }
    }
    else if (input == 'd'){
      if (canMove(yLocation, xLocation + 1, hero) == 1){
        moveCharacter(yLocation, xLocation + 1);
      } else if(canMove(yLocation, xLocation + 1, hero) == 2){
          gameEnd = 'q';
      } else if(canMove(yLocation, xLocation + 1, hero) == 3){
          moveRoom(yLocation, xLocation + 1, room);
      }
    }
    else if (input == 'w'){
      if (canMove(yLocation - 1, xLocation, hero) == 1){
        moveCharacter(yLocation - 1, xLocation);
      } else if(canMove(yLocation - 1, xLocation, hero) == 2){
          gameEnd = 'q';
      } else if(canMove(yLocation - 1, xLocation, hero) == 3){
          moveRoom(yLocation - 1, xLocation, room);
      }
    }
    return gameEnd; 
}
int canMove (int newY, int newX, Hero* hero) {
  
  int yLocation;
  int xLocation;
  char value;
  srand(time(NULL));
  yLocation = getcury(stdscr);
  xLocation = getcurx(stdscr);
  value = (char)mvinch(newY, newX);
  move(yLocation, xLocation);
  if (value == '-' || value == '|' || value == ' ') {
    return 0;
  } else if(value == '>' || value == '<'){
      return 2;
  } else if(value == '+'){
      return 3;
  }
  if (value == '*' ){
    hero->goldAmount = rand() % 51;
  }
  if (value == '8'){
    hero->goldAmount = rand() % 201 + 50;
  }
  return 1;
}
void moveCharacter(int newY, int newX){

  printw(".");
  mvprintw(newY, newX, character);
  move(newY, newX);

}

void moveRoom(int newY, int newX, Room* allRooms[6]){

  int randy; //randomly moves to a random door; 
  randy = rand() % 5 + 1;
  int k;
  printw("+");
  for(k = 0; k < allRooms[randy]->itm->itemAmount; k++){
                    if(allRooms[randy]->itm[k].symb == '+'){
						mvprintw(allRooms[randy]->itm[k].yPos, allRooms[randy]->itm[k].xPos, character);
						break;
					}
                }
   mvprintw(allRooms[randy]->itm[k].yPos, allRooms[randy]->itm[k].xPos, "+");
   move(allRooms[randy]->itm[k].yPos, allRooms[randy]->itm[k].xPos);
}
