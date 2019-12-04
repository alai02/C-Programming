#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {false = 0, true = 1} bool;

typedef struct G{
	int edgeCount;
	int largestDegree;
	bool isEularian;
} Graph;

void displayGraph(){

}

Graph* initGraph(Graph* G){

	G = (Graph*)malloc(sizeof(G));
	G->edgeCount = 0;
	G->largestDegree = 0;
	G->isEularian = false;
	return G;
}

int main(int argc, char* argv){
	
	Graph *G1, *G2, *G3, *G4, *G5;
	G1 = initGraph(G1);
	G2 = initGraph(G2);
	G3 = initGraph(G3);
	G4 = initGraph(G4);
	G5 = initGraph(G5);


	return 0;
}