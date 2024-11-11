#include <stdio.h>
#include <stdlib.h> // need this include for the atoi function

/* unsigned int squareOf(int n)

   returns the square of the input integer

   Input: number to be squared

   Output: square of input value
*/
// Note that squareOf is defined before it is called in main
unsigned int squareOf(int n)	
{
  return n*n;
}


/*
  int main(int argc, char* argv[])

  Function prints the square of the integer argument

  Inputs: argc should be 2
  argv[1] will contain the integer input, can be positive or negative

  Outputs: Prints the square of the input
*/
int main(int argc, char* argv[])
{
  int n = atoi(argv[1]); // Get the input number

  printf("%d^2 = %u\n", n, squareOf(n));

  return 0;
}
