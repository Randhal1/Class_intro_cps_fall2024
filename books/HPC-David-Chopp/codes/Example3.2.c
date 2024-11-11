#include <stdio.h>

int main(int argc, char* argv[])
{
  // We'll use two integer variables: val and i
  // val will show the result of the equation, and
  //      i will be the variable being incremented or decremented
  int val = 0;
  int i = 1;

  // Before/after each operation, you can see the resulting values of 
  //      the increment and decrement operators
  printf("Initial values:\nval = %d, i = %d\n\n", val, i);
  val =  ++i;
  printf("After val =  ++i:\nval = %d, i = %d\n\n", val, i);
  val = i++;
  printf("After val = i++:\nval = %d, i = %d\n\n", val, i);
  val = --i;
  printf("After val = --i:\nval = %d, i = %d\n\n", val, i);
  val = i--;
  printf("After val = i--:\nval = %d, i = %d\n\n", val, i);


  return 0;
}
