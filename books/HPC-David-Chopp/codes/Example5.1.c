#include <stdio.h>

/*
  int main(int argc, char* argv[])

  Program illustrates the concept of the scope of the incrementing
  variable in the loop

  Inputs: none

  Outputs: shows the values of the incrementing variables for 
  different loop constructions
*/

int main(int argc, char* argv[])
{
  // In this loop, i is an undefined variable outside the loop itself
  for (int i=0; i<5;  ++i)
    printf("i = %d\n", i);
  printf("\n");

  // Here, j is declared outside the loop. j is again declared
  //      as an int inside the loop
  // The two j variables are different, and the one declared
  //      outside the loop remains unchanged.
  int j = 0;
  for (int j=0; j<5;  ++j)
    printf("j = %d\n", j);
  printf("j = %d\n", j);
  printf("\n");

  // Here, the outside loop j is used because it wasn't redeclared
  //      inside the for loop
  // This time, when the loop terminates the value of j is left with
  //      the value 5 that caused the loop to terminate.
  for (j=0; j<5;  ++j)
    printf("j = %d\n", j);
  printf("j = %d\n", j);
  return 0;
}
