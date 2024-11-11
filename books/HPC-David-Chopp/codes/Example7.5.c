#include <stdio.h>
#include <stdlib.h>

/*
  int main(int argc, char* argv[])

  Create an array of random values in the range [0,1]
  It uses a random seed unless a seed is given as an
  argument.

  Inputs: argc should be 1 or 2
  argv[1], if given, will be the value of the RNG seed 

  Outputs: Prints the contents of the array
*/

int main(int argc, char* argv[])
{
  long int seed;
	
  if (argc > 2) {
	
    // initial seed is given on the command line, use that one
    seed = atol(argv[2]);
		
  } else {
		
    // initial seed not given, so generate one from /dev/urandom
		
    // Open the source of random bits
    FILE* urand = fopen("/dev/urandom", "r"); 
		
    // Read enough random bits from the source to fill a long int
    fread( &seed, sizeof(long int), 1, urand); 
	
    // Close when done, just like a file.
    fclose(urand); 
  }
	
  // Print the seed value in case it is needed later
  printf("seed = %ld\n", seed); 
	
  // Set the seed value
  srand48(seed); 

  // Generate the N random values
  int N = atoi(argv[1]);
  double* data = (double*) malloc(sizeof(double)*N);
  int i;
  for (i=0; i<N; ++i) {
    data[i] = drand48(); 
    printf("%f\n", data[i]);
  }

  return 0;
}
