#include <stdio.h>
#include <stdlib.h> // need this include for the atoi function

/*
  int main(int argc, char* argv[])

  The main program is the starting point for a C program.
  This program displays the size requirements in bytes for each
  of the basic data types.

  Inputs: argc should be 4
  argv[1] will contain the number of rows 
  argv[2] will contain the number of columns
  argv[3] will contain the number of grid layers

  Outputs: Prints the contents of the array
*/

int main(int argc, char* argv[])
{
  // We've assumed that args are set up correctly
  int numberOfRows = atoi(argv[1]); 
	
// atoi is a function that converts strings into integers
  int numberOfCols = atoi(argv[2]); 
int numberOfLayers = atoi(argv[3]);
	
// malloc "memory allocation" creates the memory for the array
int (*array)[numberOfCols] = malloc(sizeof(*array) * numberOfRows); 
	
// This sets pointer to be the first entry in the doubly indexed array
int* pointer = &(array[0][0]);  

printf("Example of double array storage:\n");
for (int i=0; i<numberOfRows; ++i) {
  for (int j=0; j<numberOfCols; ++j) {
    array[i][j] = 100*i + j;
    printf("array[%d][%d] = %d\n", i, j, array[i][j]);
    }
}

for (int i=0; i<numberOfRows*numberOfCols; ++i) {
  printf("pointer[%d] = %d\n", i, pointer[i]);
 }

// Dynamically allocated memory must be freed so it can be used again.
free(array);   

printf("\nExample of triple array storage:\n");
int (*array3D)[numberOfCols][numberOfLayers] 
= malloc(sizeof(*array3D) * numberOfRows);
					
// This sets pointer to be the first entry in the doubly indexed array
int* pointer3D = &(array3D[0][0][0]);   

for (int i=0; i<numberOfRows; ++i) {
  for (int j=0; j<numberOfCols; ++j) {
    for (int k=0; k<numberOfLayers; ++k) {
      array3D[i][j][k] = 10000*i + 100*j + k;
      printf("array3D[%d][%d][%d] = %d\n", i, j, k, array3D[i][j][k]);
      }
 }
}

for (int i=0; i<numberOfRows*numberOfCols*numberOfLayers; ++i) {
  printf("pointer3D[%d] = %d\n", i, pointer3D[i]);
 }

// Dynamically allocated memory must be freed so it can be used again.
free(array3D);   

return 0;
}
