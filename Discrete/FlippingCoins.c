#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
    
    int i = 0; 
    int numHeads = 0;
    int numTails = 0;
    int longRun = 0;
    int headsRun, tailsRun;
    
  for(i = 0; i < 1000; i++){  
      
    if(rand() % 2 == 0){
      
        numHeads++;
        headsRun++;
        
        if(headsRun > tailsRun){
            longRun += headsRun;
            tailsRun = 0;
        }
        
    } else {
        
        numTails++;
        tailsRun++;
        
        if (tailsRun > headsRun) {
            
            longRun += tailsRun;
            headsRun = 0;
            
        }
    }
      
  }
    
    printf("Number of heads: %d\n", numHeads);
    printf("Number of tails: %d\n", numTails);
    printf("Longest Run: %d\n", longRun);
    
    return 0;
    
}
