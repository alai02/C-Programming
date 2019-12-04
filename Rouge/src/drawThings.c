#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "drawThings.h"
#include "playGame.h"
#include "heroMove.h"

Room* parseRoom(char* wholeRoom);
void drawScreen(Room* allRooms[6]);
void drawItems(Room* allRooms[6]);
Hero* initHero(char* wholeRoom);

Room* parseRoom(char* wholeRoom){  //parse the file that you read in

    Room* ptr = malloc(sizeof(Room)); //create memory for all the structs
    ptr->gol = malloc(sizeof(Gold) * 10); 
    ptr->itm = malloc(sizeof(Items) * 10);
   
    int gLoop;
    int itemLoop;
    int i;
    gLoop = 0;
    itemLoop = 0;
	
    for(i = 0; i < 70; i++){
		
		if(i == 0){
		    if(wholeRoom[i+1] == 'X'){
		    	ptr->xDim = wholeRoom[i] - '0';
	        } else{
				ptr->xDim = (((wholeRoom[i] - '0') * 10) + (wholeRoom[i+1]) - '0');
		    }	
		}

		if(wholeRoom[i] == 'X'){
		    if(wholeRoom[i+2] == ' '){
		    	ptr->yDim = wholeRoom[i+1] - '0';
	        } else{
				ptr->yDim = (((wholeRoom[i+1] - '0') * 10) + (wholeRoom[i+2]) - '0');    
		    }
		}
		if(wholeRoom[i] == 'd')
		{	
			switch(wholeRoom[i+1])
			{
			    	case 'n':
						ptr->itm[itemLoop].yLoc = 0;
						ptr->itm[itemLoop].xLoc = wholeRoom[i+2] - '0';
						ptr->itm[itemLoop].symb = '+';
						break;
			    	case 's':
						ptr->itm[itemLoop].yLoc = ptr->yDim +1; 
						ptr->itm[itemLoop].xLoc = wholeRoom[i+2] - '0';
						ptr->itm[itemLoop].symb = '+';
						break;
			    	case 'e':
						ptr->itm[itemLoop].xLoc = ptr->xDim +1;
						ptr->itm[itemLoop].yLoc = wholeRoom[i+2] - '0';
						ptr->itm[itemLoop].symb = '+';
						break;
			    	case 'w':
						ptr->itm[itemLoop].xLoc = 0;
						ptr->itm[itemLoop].yLoc = wholeRoom[i+2] - '0';
						ptr->itm[itemLoop].symb = '+';
						break;
			    	default:
						break;
			}
			itemLoop++;
		}
		if(wholeRoom[i] == 'G' || wholeRoom[i] == 'g'){
		     ptr->gol[gLoop].xLoc = wholeRoom[i+1] - '0';
		     ptr->gol[gLoop].yLoc = wholeRoom[i+3] - '0';
		     if(wholeRoom[i] == 'G'){
		     	ptr->gol[gLoop].amount = rand() % 201 + 50; //betweeb 0 and 200 
                ptr->gol[gLoop].symb = '8';
		     } else{
		     	ptr->gol[gLoop].amount = rand() % 51;
                ptr->gol[gLoop].symb = '*';
		     }
		     gLoop++;
		}
		if(wholeRoom[i] == 'e' && wholeRoom[i-1] != 'd'){
            if(wholeRoom[i+2] == ','){
			     ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
            } else{
                ptr->itm[itemLoop].xLoc = (((wholeRoom[i+1] - '0') * 10) + (wholeRoom[i+2]) - '0'); 
            }
            if(wholeRoom[i+5] == ' '){
			     ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
            } else{
                ptr->itm[itemLoop].yLoc = (((wholeRoom[i+4] - '0') * 10) + (wholeRoom[i+5]) - '0'); 
            }
			ptr->itm[itemLoop].symb = ']';
			itemLoop++;
		}
		if(wholeRoom[i] == 'p'){
			ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
			ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
			ptr->itm[itemLoop].symb = '!';
			itemLoop++;
		}
		if(wholeRoom[i] == 'w' && wholeRoom[i-1] != 'd'){
            if(wholeRoom[i+2] == ','){
			     ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
                if(wholeRoom[i+4] == ' '){
                    ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
                } else{
                    ptr->itm[itemLoop].yLoc = (((wholeRoom[i+3] - '0') * 10) + (wholeRoom[i+4]) - '0'); 
                }
			} else{
                ptr->itm[itemLoop].xLoc = (((wholeRoom[i+1] - '0') * 10) + (wholeRoom[i+2]) - '0'); 
                if(wholeRoom[i+5] == ' '){
                    ptr->itm[itemLoop].yLoc = wholeRoom[i+4] - '0';
                 } else{
                    ptr->itm[itemLoop].yLoc = (((wholeRoom[i+4] - '0') * 10) + (wholeRoom[i+5]) - '0'); 
                }
            }
			ptr->itm[itemLoop].symb = ')';
			itemLoop++;
		}
		if(wholeRoom[i] == 'W'){
			ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
			ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
			ptr->itm[itemLoop].symb = '(';
			itemLoop++;
		}
		if(wholeRoom[i] == 'm'){
            int randMonster;
            randMonster = rand() % 4 +1;
            if(wholeRoom[i+2] == ','){
			     ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
            } else{
                ptr->itm[itemLoop].xLoc = (((wholeRoom[i+1] - '0') * 10) + (wholeRoom[i+2]) - '0'); 
            }
            if(wholeRoom[i+4] == ' ' ){
			     ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
            } else{
                ptr->itm[itemLoop].yLoc = (((wholeRoom[i+4] - '0') * 10) + (wholeRoom[i+5]) - '0'); 
            }
            if( randMonster == 1 ){
                ptr->itm[itemLoop].symb = 'A';
            }
           if( randMonster == 2 ){
                ptr->itm[itemLoop].symb = 'B';
            }
            if( randMonster == 3 ){
                ptr->itm[itemLoop].symb = 'S'; 
            }
            if( randMonster == 4 ){
                ptr->itm[itemLoop].symb = 'Z';
            }
			itemLoop++;
		}
		if(wholeRoom[i] == 'M'){
			ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
			ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
			ptr->itm[itemLoop].symb = 'T';
			itemLoop++;
		}
		if(wholeRoom[i] == 'a'){
			ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
			ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
			ptr->itm[itemLoop].symb = '>';
			itemLoop++;
		}
		if(wholeRoom[i] == 'z'){
			ptr->itm[itemLoop].xLoc = wholeRoom[i+1] - '0';
			ptr->itm[itemLoop].yLoc = wholeRoom[i+3] - '0';
			ptr->itm[itemLoop].symb = '<';
			itemLoop++;
		}
    }
    ptr->itm->itemAmount = itemLoop;
    ptr->gol->goldAmount = gLoop;
    return ptr; 
}

void drawScreen(Room* allRooms[6]){

    int offSet = 8; 
    int i;
    int j;

    allRooms[0]->xLoc = offSet;
    allRooms[0]->yLoc = offSet;
    for(i = offSet; i < allRooms[0]->xDim + offSet; i++){ //1
        for(j = offSet; j < allRooms[0]->yDim + offSet; j++){
                mvaddch(j+1, i+1, '.');
        }
    }
    for(i = offSet; i < allRooms[0]->yDim + offSet +1; i++){
        mvaddch(i, offSet , '|');
        mvaddch(i +1, offSet + allRooms[0]->xDim +1, '|');
    }
    for(i = offSet -1; i < offSet + allRooms[0]->xDim +1; i++){
        mvaddch(offSet  , i + 1, '-');
        mvaddch(offSet  + allRooms[0]->yDim +1, i +1 ,'-');
    }
    
    allRooms[1]->yLoc = allRooms[0]->xDim + 2*offSet +2;
    allRooms[1]->xLoc = offSet ;
    for(i = allRooms[0]->xDim + 2*offSet +2; i < 2+ allRooms[0]->xDim + allRooms[1]->xDim + 2*offSet +2; i++){//2
        for(j = offSet; j < allRooms[1]->yDim + offSet +1; j++){
            mvaddch(j, i, '.');
        }
    }
    for(i = 2*offSet + allRooms[0]->xDim +2; i < 4+ 2*offSet + allRooms[0]->xDim + allRooms[1]->xDim ; i++){
        mvaddch(offSet, i, '-');
        mvaddch(offSet + allRooms[1]->yDim +1, i ,'-');
    }
    for(i = offSet + 1; i < offSet + allRooms[1]->yDim +1; i++){
        mvaddch(i, 2*offSet + allRooms[0]->xDim +2, '|');
        mvaddch(i, 2*offSet + allRooms[0]->xDim + allRooms[1]->xDim +3, '|');
    }

    allRooms[2]->yLoc = allRooms[0]->xDim + allRooms[1]->xDim + 3*offSet +4;
    allRooms[2]->xLoc =  offSet +1;
    for(i = allRooms[0]->xDim + allRooms[1]->xDim + 3*offSet +5; i < 1+allRooms[0]->xDim + allRooms[1]->xDim + allRooms[2]->xDim + 3*offSet +4; i++){
        for(j = offSet +1; j < allRooms[2]->yDim + offSet +1; j++){
            mvaddch(j, i, '.');
        }
    }
    for(i = 3*offSet + allRooms[0]->xDim + allRooms[1]->xDim +4; i < 6+ 3*offSet + allRooms[0]->xDim + allRooms[1]->xDim + allRooms[2]->xDim; i++){
        mvaddch(offSet, i, '-');
        mvaddch(offSet + allRooms[2]->yDim +1, i, '-');
    }
    for(i = offSet +1; i < offSet + allRooms[2]->yDim +1; i++){
        mvaddch(i, 3*offSet + allRooms[0]->xDim + allRooms[1]->xDim + 4, '|');
        mvaddch(i, 3*offSet + allRooms[0]->xDim + allRooms[1]->xDim + 5 + allRooms[2]->xDim, '|');
    }

    allRooms[3]->yLoc = allRooms[0]->yDim + 2*offSet;
    allRooms[3]->xLoc = offSet;
    for(i = offSet; i < offSet + allRooms[3]->xDim +1; i++){
        for(j = 2*offSet + allRooms[0]->yDim +3; j < 4+2*offSet + allRooms[0]->yDim + allRooms[3]->yDim; j++){
            mvaddch(j, i, '.');
        }
    }
    for(i = 2*offSet + allRooms[0]->yDim +2; i < 3+2*offSet + allRooms[0]->yDim + allRooms[3]->yDim; i++){
        mvaddch(i +1, offSet, '|');
        mvaddch(i +1, offSet + allRooms[3]->xDim +1, '|');
    }
    for(i = offSet; i < offSet + allRooms[3]->xDim +2; i++){
        mvaddch(2*offSet + allRooms[0]->yDim +2, i,'-');
        mvaddch(2*offSet + allRooms[0]->yDim + allRooms[3]->yDim +3, i , '-');
    }

    allRooms[4]->yLoc = allRooms[1]->yDim + 2*offSet +2;
    allRooms[4]->xLoc = allRooms[3]->xDim + 2*offSet +2;
    for(i = allRooms[3]->xDim + 2*offSet +2; i < allRooms[3]->xDim + allRooms[4]->xDim + 2*offSet +4; i++){//2
        for(j = 2*offSet + allRooms[1]->yDim + 2; j < 2*offSet + allRooms[1]->yDim + allRooms[4]->yDim +3; j++){
            mvaddch(j, i, '.');
        }
    }
    for(i = 2*offSet + allRooms[1]->yDim +2; i < 3+ 2*offSet + allRooms[4]->yDim + allRooms[1]->yDim; i++){
        mvaddch(i, 2*offSet + allRooms[3]->xDim +2, '|');
        mvaddch(i, 2*offSet + allRooms[3]->xDim + allRooms[4]->xDim +3, '|');
    }
    for(i = 2*offSet + allRooms[3]->xDim +2; i < 4 +  2*offSet + allRooms[3]->xDim + allRooms[4]->xDim ; i++){
        mvaddch(2*offSet + allRooms[1]->yDim +2, i, '-');
        mvaddch(2*offSet + allRooms[4]->yDim +2+ allRooms[1]->yDim +1, i ,'-');
    }

    allRooms[5]->xLoc = allRooms[3]->xDim + allRooms[4]->xDim + 3*offSet +4;
    allRooms[5]->yLoc =  2*offSet + allRooms[2]->yDim +2;
    for(i = allRooms[3]->xDim + allRooms[4]->xDim + 3*offSet + 5; i < allRooms[3]->xDim + allRooms[4]->xDim + allRooms[5]->xDim + 3*offSet +5; i++){
        for(j = 2*offSet +1 + allRooms[2]->yDim +2; j < 2+ allRooms[2]->yDim + allRooms[5]->yDim + 2*offSet +1; j++){
            mvaddch(j, i, '.');
        }
    }
    for(i = 3*offSet + allRooms[3]->xDim + allRooms[4]->xDim +4; i < 6+ 3*offSet + allRooms[3]->xDim + allRooms[4]->xDim + allRooms[5]->xDim; i++){
        mvaddch(2*offSet+ allRooms[2]->yDim +2, i, '-');
        mvaddch(2*offSet + allRooms[2]->yDim +1 + allRooms[5]->yDim +2, i, '-');
    }
    for(i = 2*offSet +3 + allRooms[2]->yDim; i < 2*offSet + allRooms[2]->yDim +3 + allRooms[5]->yDim; i++){
        mvaddch(i, 3*offSet + allRooms[3]->xDim + allRooms[4]->xDim + 4, '|');
        mvaddch(i, 3*offSet + allRooms[4]->xDim + allRooms[4]->xDim + 3 + allRooms[5]->xDim, '|');
    }
    drawItems(allRooms);
}

void drawItems(Room* allRooms[6]) {

    int i;
    int j;
    int k; 
    int x;

   for(i = 0; i < allRooms[0]->xDim +2; i++){
        for(j = 0; j < allRooms[0]->yDim +2; j++){
            for(k = 0; k < allRooms[0]->itm->itemAmount; k++){
                if(allRooms[0]->itm[k].xLoc == i && allRooms[0]->itm[k].yLoc == j){
                    mvaddch(j + allRooms[0]->xLoc, i + allRooms[0]->yLoc, allRooms[0]->itm[k].symb);
                    if(allRooms[0]->itm[k].symb == '+'){
							allRooms[0]->itm[k].yPos = j + allRooms[0]->xLoc;
							allRooms[0]->itm[k].xPos = i + allRooms[0]->yLoc;
					}
                }
            }
            for(x = 0; x < allRooms[0]->gol->goldAmount; x++){
                if(allRooms[0]->gol[x].xLoc == i && allRooms[0]->gol[x].yLoc == j){
                    mvaddch(j + allRooms[0]->yLoc, i + allRooms[0]->xLoc, allRooms[0]->gol[x].symb);
                }
            }
        }
   }
   for(i = 0; i < allRooms[1]->xDim +2; i++){
        for(j = 0; j < allRooms[1]->yDim +2; j++){
            for(k = 0; k < allRooms[1]->itm->itemAmount; k++){
                if(allRooms[1]->itm[k].xLoc == j && allRooms[1]->itm[k].yLoc == i){
                    mvaddch(allRooms[1]->xLoc + i, allRooms[1]->yLoc +j, allRooms[1]->itm[k].symb);
                    if(allRooms[1]->itm[k].symb == '+'){
							allRooms[1]->itm[k].yPos = allRooms[1]->xLoc + i;
							allRooms[1]->itm[k].xPos = allRooms[1]->yLoc +j;
					}					
                }
            }
            for(x = 0; x < allRooms[1]->gol->goldAmount; x++){
                if(allRooms[1]->gol[x].xLoc == i && allRooms[1]->gol[x].yLoc == j){
                    mvaddch(j + allRooms[1]->yLoc, i + allRooms[1]->xLoc, allRooms[1]->gol[x].symb);
                }
            }
        }
   }
    for(i = 0; i < allRooms[2]->xDim +6; i++){
        for(j = 0; j < allRooms[2]->yDim +6; j++){
            for(k = 0; k < allRooms[2]->itm->itemAmount; k++){
                if(allRooms[2]->itm[k].xLoc == j && allRooms[2]->itm[k].yLoc == i){
                    mvaddch(i + allRooms[2]->xLoc -1, j + allRooms[2]->yLoc, allRooms[2]->itm[k].symb);
					if(allRooms[2]->itm[k].symb == '+'){
							allRooms[2]->itm[k].yPos = i + allRooms[2]->xLoc -1;
							allRooms[2]->itm[k].xPos = j + allRooms[2]->yLoc;
					}
                }
            }
            for(x = 0; x < allRooms[2]->gol->goldAmount; x++){
                if(allRooms[2]->gol[x].xLoc == i && allRooms[2]->gol[x].yLoc == j){
                    mvaddch(j + allRooms[2]->yLoc, i + allRooms[2]->xLoc, allRooms[2]->gol[x].symb);
                }
            }
        }
   }
    for(i = 0; i < allRooms[3]->xDim +2; i++){
        for(j = 0; j < allRooms[3]->yDim +2; j++){
            for(k = 0; k < allRooms[3]->itm->itemAmount; k++){
                if(allRooms[3]->itm[k].xLoc == i && allRooms[3]->itm[k].yLoc == j){
                    mvaddch(j + allRooms[3]->yLoc +2, i + allRooms[3]->xLoc, allRooms[3]->itm[k].symb);
					if(allRooms[3]->itm[k].symb == '+'){
							allRooms[3]->itm[k].yPos = j + allRooms[3]->yLoc +2;
							allRooms[3]->itm[k].xPos = i + allRooms[3]->xLoc;
					}
                }
            }
            for(x = 0; x < allRooms[3]->gol->goldAmount; x++){
                if(allRooms[3]->gol[x].xLoc == i && allRooms[3]->gol[x].yLoc == j){
                    mvaddch(j + allRooms[3]->yLoc +2, i + allRooms[3]->xLoc, allRooms[3]->gol[x].symb);
                }
            }
        }
   }
    for(i = 0; i < allRooms[4]->xDim +2; i++){
        for(j = 0; j < allRooms[4]->yDim +2; j++){
            for(k = 0; k < allRooms[4]->itm->itemAmount; k++){
                if(allRooms[4]->itm[k].xLoc == j && allRooms[4]->itm[k].yLoc == i){
                    mvaddch(allRooms[4]->yLoc + i, allRooms[4]->xLoc +j, allRooms[4]->itm[k].symb);
					if(allRooms[4]->itm[k].symb == '+'){
							allRooms[4]->itm[k].yPos = allRooms[4]->yLoc + i;
							allRooms[4]->itm[k].xPos = allRooms[4]->xLoc +j;
					}
                }
            }
            for(x = 0; x < allRooms[4]->gol->goldAmount; x++){
                if(allRooms[4]->gol[x].xLoc == j && allRooms[4]->gol[x].yLoc == i){
                    mvaddch(j + allRooms[4]->yLoc, i + allRooms[4]->xLoc, allRooms[4]->gol[x].symb);
                }
            }
        }
   }
    for(i = 0; i < allRooms[5]->xDim +2; i++){
        for(j = 0; j < allRooms[5]->yDim +2; j++){
            for(k = 0; k < allRooms[5]->itm->itemAmount; k++){
                if(allRooms[5]->itm[k].xLoc == j && allRooms[5]->itm[k].yLoc == i){
                    mvaddch(allRooms[5]->yLoc + i, allRooms[5]->xLoc +j, allRooms[5]->itm[k].symb);
					if(allRooms[5]->itm[k].symb == '+'){
							allRooms[5]->itm[k].yPos = allRooms[5]->yLoc + i;
							allRooms[5]->itm[k].xPos = allRooms[5]->xLoc +j;
					}
                }
            }
            for(x = 0; x < allRooms[5]->gol->goldAmount; x++){
                if(allRooms[5]->gol[x].xLoc == j && allRooms[5]->gol[x].yLoc == i){
                    mvaddch(j + allRooms[5]->yLoc, i + allRooms[5]->xLoc, allRooms[5]->gol[x].symb);
                }
            }
        }
   }
}

Hero* initHero(char* wholeRoom){

    Hero* hero = malloc(sizeof(Hero));
    int i;
    for(i = 0; i < strlen(wholeRoom); i++){
        if(wholeRoom[i] == 'h'){
            hero->xLoc = wholeRoom[i+1] - '0';
            hero->yLoc = wholeRoom[i+3] - '0';
            hero->goldAmount = 0;
        }
    }
    return hero;
}


