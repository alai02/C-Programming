/* Author: Alex lai
 * Student info: Alai02@mail.uoguelph.ca -  0920158
 * Date: Feburary 13th, 2017
 * Assignment: A2 - q2.1 - Brute force algorithm for convex hull problem
 * Description: This program computes the convex hull on a set of points using a brute force approach
 * This method is generally very slow, espeically for a large data set. Will run on Theta(n^3) time
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
/*Max is set to 30000 because of size of input file provided*/
#define MAX 30000
typedef struct coord{
    float x;
    float y;
} coord;

void readFile(char* argv);
coord* bruteForce(coord* points);

int main(int argc, char* argv[]) {
    readFile(argv[1]);
    return 0;
}
void readFile(char* argv){

    int i;
    FILE* fp;
    fp = fopen(argv, "r");
    if(fp == NULL){
        printf("File not found\n");
        exit(1);
    }
    coord *points = malloc(sizeof(coord) *MAX);
    coord *hull = malloc(sizeof(coord) *MAX);
    int index = 0;
    while(fscanf(fp, "%f %f", &points[index].x, &points[index].y) == 2) {
        index++;
    }
    fclose(fp);

    struct timeb t_startBRUTE, t_endBRUTE;
    int t_diffBRUTE;
    ftime(&t_startBRUTE); //get start time
    hull = bruteForce(points);
    ftime(&t_endBRUTE); //get end time
    t_diffBRUTE = (int) (1000.0 * (t_endBRUTE.time - t_startBRUTE.time) + (t_endBRUTE.millitm - t_startBRUTE.millitm));

    printf("This algorithm took %d time units to compute. Not correct\n", t_diffBRUTE);
    free(points);
}
/*
 * Input: An array of Coordinates
 * Desciption: This program loops through the coordinates and creates a line segment
 * to devide the coordinates to determine which points belong to the convex hull set
 * Output: returns a convex hull set of coordinates for the give data set
 */
coord* bruteForce(coord* points){
    coord * segments = malloc(sizeof(coord) * MAX );
    int i = 0, j = 0, k = 0;
    int a = 0, b = 0, c = 0;
    int found = 0, check = 0, index = 0;
    for(i = 1; i <= 1000; i++){
        for(j = i+1; j < 1000; j++){
        	a = points[j].y - points[i].y;
        	b = points[j].x - points[i].x;
        	c = (points[i].x * points[j].y) - (points[i].y * points[j].x);
        	found = 0;
        	for(k = 1; k < 1000; k++) {
        	    check = (int) (a * points[k].x) + (b * points[k].y) - c;
        		if(check == 0) {
        			found = 1;
        		}
        	}
        	if(found == 1){
        		segments[index].x = points[i].x;
        		segments[index].y = points[i].y;
                index++;
        		segments[index].x = points[j].x;
        		segments[index].y = points[j].y;
                index++;
        	}
        }
    }
    return segments;
}
