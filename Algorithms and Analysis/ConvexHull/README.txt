Date: February 13th, 2017

Compile/Run instructions: to compile all programs: make
The programs will be called: q11, q12, q21, q22 respectively. All the programs require a text file to run

Description: The first question (1.1 to 1.3) are implemented in q11.c and q12.c
The brute force algorithm runs first and the merge sort algorithm runs after
The ftime() function was used to get the system clock time to calculate the
running time of the arrays in all 4 programs.

The first program q11, uses a brute force method to read in an array of integers in TestFile.txt and prints out
the amount of inversions that are present in the data set along with the calculated runtime of the implementation.
I got 6696 time units for this algorithms running time for this data set

The second program q12, uses a merge sort method to read in an array of integers in TestFile.txt and prints
out the number of inversions that are present in the data set along with the calculated runtime of the implementation.
I got 9 time units for this algorithms running time for this data set

The third program q21, uses a brute force sorting method to read in the data set of x,y coordinates from TestFile2.txt and
will determine the convex hull of the points. This algorithm took 4903 time units to complete its running time for this data set

The fourth program q22, uses a merge sort method to divide the points into smaller and smaller sets using the data from
TestFile2.txt and will determine the convex hull set with its running time. I got a running time of 24 time units for this algorithms running time for this data set
