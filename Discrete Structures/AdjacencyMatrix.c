#include <stdio.h>
#define MAX 20

int main (int argc, char* argv[]) { 

    int i, j, k;
    int n1, n2;
    int deg, different;
    int G1[MAX][MAX], G2[MAX][MAX];
    int seq1[MAX], seq2[MAX];
    FILE *InputGraphs;
    InputGraphs = fopen("input-file.txt", "r");
    for(k=1; k<=5; k++) {
        for(i=0; i<MAX; i++) {
            seq1[i] = seq2[i] = 0;
        }
        fscanf(InputGraphs, "%d", &n1);
        for(i=0; i<n1; i++) {
            deg = 0;
            for(j=0; j<n1; j++) {
                fscanf(InputGraphs, "%d", &G1[i][j]);
                if(G1[i][j] == 1) {
                    deg++;
                }
            }
            seq1[deg]++;
        }
        fscanf(InputGraphs, "%d", &n2);
        for(i=0; i<n2; i++) {
            deg = 0;
            for(j=0; j<n2; j++) {
                fscanf(InputGraphs, "%d", &G2[i][j]);
                if(G2[i][j] == 1) {
                    deg++;
                }
            }
            seq2[deg]++;
        }       
        printf("Degree seq for G1: ");
        for(i=0; i<n1; i++) {
            for(j=0; j< seq1[i]; j++) {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("Degree seq for G2: ");  
        for(i=0; i<n2; i++) {
            for(j=0; j< seq2[i]; j++) {
                printf("%d ", i);
            }
        }                   
        printf("\n");
        if(n1 == n2) {
            different = 0;
            for(i=0; i<n1; i++) {
                if(seq1[i] != seq2[i]){
                    different = 1;
                }
            }
        } else {
            different = 1;
            if (different == 0) {
                printf("The graphs have the same degree sequence.\n\n");
            } else {
                printf("The graphs do NOT have the same degree sequence.\n\n");
            }
        }
    }
    fclose(InputGraphs);
}