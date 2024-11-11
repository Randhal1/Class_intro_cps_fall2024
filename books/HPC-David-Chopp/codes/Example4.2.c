#include <stdio.h>
#include <math.h>

/*
  int main(int argc, char* argv[])

  The program opens a new file with the given name, writes data to it, 
  then reads those numbers back in and prints them to the screen.

  Inputs: argc should be 2
  argv[1] will contain the filename to be created

  Outputs: creates the file and writes some data to it.
*/

int main(int argc, char* argv[])
{
  // Start by creating the data to be stored
  int num = 17;
  double pi = M_PI;
  char greeting[256] = "Hello World!";

  // First thing is to create the file we will use for storage
  // the "w" indicates we are opening the file for writing
  FILE *fileid = fopen(argv[1], "w");  

  // Once the file is open, we can write to it.  
  // fwrite is for writing the actual contents of memory.
  // Each write has to have a single address of memory, 
  //      so we'll do each variable separately.
  // First let's write a single integer.
  fwrite( &num, sizeof(int), 1, fileid);

  // Next we write the double precision value of pi
  fwrite( &pi, sizeof(double), 1, fileid);

  // Finally, let's write the whole string, 
  // Note that sizeof(greeting) will return 256
  fwrite( greeting, sizeof(char), sizeof(greeting), fileid);

  // When we're done writing, we must close the file so that it is
  //      terminated properly
  fclose(fileid);

  // The file is closed, so let's open it again, but this time use "r"
  //      to indicate that we will read the file
  fileid = fopen(argv[1], "r");

  // Now we use fread in the same order as we wrote the data
  //       to get it back.
  // Let's read the data into new variables so it's clear it's 
  //      not left over from above.
  int read_num;
  double read_pi;
  char read_greeting[256];

  // Read the number
  fread( &read_num, sizeof(int), 1, fileid);

  // Read pi
  fread( &read_pi, sizeof(double), 1, fileid);

  // Read the string
  fread( read_greeting, sizeof(char), sizeof(read_greeting), fileid);

  // All done reading, so close the file
  fclose(fileid);

  // Now print the results.  Did we get what we expected?
  printf("%d %lf %s\n", read_num, read_pi, read_greeting);
  return 0;
}
