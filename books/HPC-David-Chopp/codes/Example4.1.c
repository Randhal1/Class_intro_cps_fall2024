#include <stdio.h>
#include <math.h>

/*
  int main(int argc, char* argv[])

  The program opens a new file with the given name, writes some data to 
  it, then reads those numbers back in and prints them to the screen.

  Inputs: argc should be 2, 
  argv[1] will contain the filename to be created

  Outputs: creates the file and writes some data to it.
*/

int main(int argc, char* argv[])
{
  // First thing is to create the file we will use for storage
  // the "w" indicates we are opening the file for writing
  FILE *fileid = fopen(argv[1], "w");  

  // Once the file is open, we can write to it with fprintf functions
  //      that act the same as the printf commands we learned earlier
  // Note the use of M_PI. This is a useful macro that defines the
  //      number pi and is found in the header file math.h
  fprintf( fileid, "%d %6.3f %s", 17, M_PI, "Hello World!\n");

  // When we're done writing, we must close the file so that it is
  //      terminated properly
  fclose(fileid);

  // To read the data back in, we must define the variables
  int num;
  double pi;
  char greeting[256];

  // The file is closed, so let's open it again, but this time 
  //      use "r" to indicate that we will read the file
  // Note that we don't have to redeclare fileid because 
  //      we did it already
  fileid = fopen(argv[1], "r");

  // Now we use fscanf the same way we learned scanf
  // Note that greeting does not have an ampersand because greeting is 
  //      an array, so greeting has type char* already
  fscanf( fileid, "%d %lf %s", &num, &pi, greeting);

  // All done reading, so close the file
  fclose(fileid);

  // Now print the results.  Did we get what we expected?
  printf("%d %lf %s\n", num, pi, greeting);
  return 0;
}
