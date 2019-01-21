#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursion(int m, int n) {

        if (!m) {
        	return n + 1; //if m is false return n+1 (base case)
        }
        if (!n) {
        	return recursion(m - 1, 1); //if n is false return
        }
        return recursion(m - 1, recursion(m, n - 1));
}


void ackermann(){

	int mValue, nValue;
	int m,n;

	printf("Enter a value for m: ");
	scanf("%d", &mValue);
	printf("Enter a value for n: ");
	scanf("%d", &nValue);

	for (m = 0; m <= mValue; m++){
		for (n = 0; n < nValue - m; n++){
		    printf("A(%d, %d) = %d\n", m, n, recursion(m, n));
		}
	}
}
 
