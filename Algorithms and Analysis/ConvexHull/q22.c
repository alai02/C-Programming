/* Author: Alex lai
 * Student info: Alai02@mail.uoguelph.ca -  0920158
 * Date: Feburary 13th, 2017
 * Assignment: A2 - q2.2 - Merge Sort algorithm for convex hull problem
 * Description: This program computes the convex hull on a set of points using a mergeSort approach
 * This method is generally very fast, even for a large data set. Will run on Theta(n*logn) time
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <math.h>

#define MAX 30000

typedef struct coord{
    float x;
    float y;
} coord;

void readFile(char* argv);
coord* mergeSort(coord* points);
coord* merge(coord* points, coord min, coord max, int count, coord* convexHull, int size);

void readFile(char* argv){
    int i;
    FILE* fp;
    fp = fopen(argv, "r");
    if(fp == NULL){
        printf("File not found\n");
        exit(1);
    }
    coord *points = malloc(sizeof(coord*) *MAX);
    coord* convexHull = malloc(sizeof(coord*)*MAX);
    int index = 0;
    while(fscanf(fp, "%f %f", &points[index].x, &points[index].y) == 2) {
        index++;
    }
    fclose(fp);

    struct timeb t_startMERGE, t_endMERGE;
    int t_diffMERGE;
    ftime(&t_startMERGE); //get start time
    convexHull = mergeSort(points);
    ftime(&t_endMERGE); //get end time
    t_diffMERGE = (int) (1000.0 * (t_endMERGE.time - t_startMERGE.time) + (t_endMERGE.millitm - t_startMERGE.millitm));

    printf("This algorithm took %d time units to compute.\n", t_diffMERGE);
    int x;

    free(points);
}

/*
 * Function name: mergeSort
 * Input: An array of coordinates
 * Description: This Function breaks up the array into 2 smaller sub arrays and merges them together to solve the task
 * This function calls the function merge which
 * Output: returns a convex hull set of points for the data set
 */
coord* mergeSort(coord* points){

    int count = 0;
    int i;
    float maxX = -1, minX = 10000;
    coord min;
    coord max;
    coord* upperHull = malloc(sizeof(coord*)*MAX/2);
    coord* lowerHull = malloc(sizeof(coord*)*MAX/2);
    coord* convexHull = malloc(sizeof(coord*)*MAX);
    for(i = 0; i < MAX; i++){
        if(min.x > points[i].x){
            min.x = points[i].x;
            min.y = points[i].y;
        }
        if(max.x < points[i].x){
            max.x = points[i].x;
            max.y = points[i].y;
        }
    }
    int yLoc;
    int j = 0, k = 0;
    double slope = (max.y - min.y) / (max.x - min.x);
    double yInt = min.y - (slope * min.x);
    for(i = 0; i < MAX; i++){
        yLoc = 0;
        yLoc = (points[i].x * slope) + yInt;
        if (points[i].y > yLoc) {
            upperHull[j].x = points[i].x;
            upperHull[j].y = points[i].y;
            j++;
        } else {
            lowerHull[k].x = points[i].x;
            lowerHull[k].y = points[i].y;
            k++;
        }
    }
    convexHull[count].x = min.x;
    convexHull[count].y = min.y;
    count++;
    convexHull[count].x = max.x;
    convexHull[count].y = max.y;

    convexHull = merge(upperHull, min, max, count, convexHull, MAX/2);
    convexHull = merge(lowerHull, max, min, count, convexHull, MAX/2);
    return convexHull;
}

coord* merge(coord* points, coord min, coord max, int count, coord* convexHull, int size){

    if(size < 3){
        return convexHull;
    }

    int i;
    int maxDistance;
    coord c;
    coord* upperHull = malloc(sizeof(coord*)* size +1);
    coord* lowerHull = malloc(sizeof(coord*)* size +1);
    for(i = 0; i < size; i++){
        int currentDist = sqrt( ( (max.y - min.y) * (points[i].x - min.x) ) + ( (max.x - min.x) * pow( (points[i].y - min.y ), 2.0) )
                                / ( pow ( (max.x - min.x), 2.0) + pow( (max.y - min.y), 2.0) ) ) ;
        if(currentDist > maxDistance){
            convexHull[count].x = c.x = points[i].x;
            convexHull[count].y = c.y = points[i].y;
            count++;
        }
    }
    convexHull = merge(upperHull, min, c, count, convexHull, size/2);
    convexHull = merge(lowerHull, c, max, count, convexHull, size/2);
    return convexHull;
}

int main(int argc, char* argv[]) {
    readFile(argv[1]);
    return 0;
}
