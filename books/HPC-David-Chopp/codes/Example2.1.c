/*
  Hello World

  Demonstration showing a simple program that is self-contained.

  Program written by David Chopp

  Editing History:

  2/14/14: Initial draft
  7/29/17: Changed formatting of comments
*/

// Programs often require functions from built-in libraries, 
//    or user-written files
// Interface information for those functions are stored in header files
//    and loaded before the code is compiled.  
// This program uses terminal I/O, so it uses the stdio library. 
//    This is very common...

#include <stdio.h>

/*
  int main(int argc, char* argv[])

  The main program is the starting point for a C program.
  There can only be one "main" function.  All others must be
  uniquely named something else.

  Inputs:
  int argc: When the program is run, argc contains the number of 
  arguments given to the program, e.g. if you type 
  "hello there" to the command line, then argc will have
  the value 2.

  char* argv[]: When the program is run, argv contains an array of
  strings, where each string is what was typed, e.g. if
  you type "hello there" to the command line, then 
  argv[0] will have the value "hello" and argv[1] will
  have the value "there"

  Outputs:
  int: The main program should return 0 if successful, and return
  a non-zero value if it encountered an error.
*/

int main(int argc, char* argv[])
{
  // It is important to get in the habit of thoroughly commenting
  // your code.

  printf("Hello World!\n");

  // All done, no errors, so return 0

  return 0;
}
