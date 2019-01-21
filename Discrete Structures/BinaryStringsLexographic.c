#include <stdio.h>
#include <string.h>

void printAllBitStrings(int n, char* binary){
       if (n == 1) {
        printf("%d\n", 0);
        printf("%d\n", 1);
       } else {
        printAllBitStrings(n - 1, binary  );
        binary[n] = '0';
        printAllBitStrings(n - 1, binary  );
        binary[n] = '1';
     }
} 
    
int main(){
    
    char* binary;
    int n;
    scanf("%d", &n);
   int i;
    for( i = 0; i < n; i++){
            binary += "0";
            printAllBitStrings( n, binary);
            printf("\n" );
             } 
    return 0;  
}