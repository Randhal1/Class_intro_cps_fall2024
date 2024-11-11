#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

/*
  void diff(double* u, int N, double dx, double* du)

  Computes a finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the finite difference approximation
*/
void diff(double* u, int N, double dx, double* du) {

  int i;
  du[0] = (u[1]-u[N-1])/dx/2.;
  for (i=1; i<N-1; ++i) {
    du[i] = (u[i+1]-u[i-1])/dx/2.;
  }
  du[N-1] = (u[0]-u[N-2])/dx/2.;
  
}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs: 
  u: pointer to array will values will be stored
  N: length of the array
  dx: the space step size

  Outputs: 
  u: contains data for a sin function
*/
void init(double* u, int N, double dx)
{
  int i;
  for (i=0; i<N; ++i)
    u[i] = sin(i*dx);
}

/*
  int main(int argc, char* argv[])

  Function tests the timing accuracy of 4 different methods

  Inputs: argc should be 3
  argv[1] is the integer length of the data array
  argv[2] is the number of timing samples to take 

  Outputs: Prints the mean and variance of the measured execution time
*/
int main(int argc, char* argv[])
{
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  double* u = (double*)malloc(N*sizeof(double));
  double* du = (double*)malloc(N*sizeof(double));
  double dx = 2.*M_PI/N;

  init(u, N, dx);

  // Test the function clock()
  int i;
  double times[M];
  double total = 0.;
  // Run this once because the first time will take extra time
  diff(u, N, dx, du);
  for (i=0; i<M; ++i) {
    // start the timer
    clock_t begin1 = clock(); 
	
    // run some code where timing is desired
    diff(u, N, dx, du);
	  
    // stop the timer and print the results
    clock_t end1 = clock(); 
    times[i] = ((double)(end1-begin1))/CLOCKS_PER_SEC;
    total += times[i];
  }
  double mean = total/M;
  double var = 0.;
  for (i=0; i<M; ++i)
    var += (times[i]-mean)*(times[i]-mean);
  printf("mean elapsed time = %e, variance = %e\n", total/M, var/(M-1));

  // Test the function time()
  total = 0.;
  for (i=0; i<M; ++i) {
    // start the timer
    time_t begin2 = time(NULL); 
	
    // run some code where timing is desired
    diff(u, N, dx, du);
	
    // stop the timer and print the results
    time_t end2 = time(NULL); 
    times[i] = difftime(end2, begin2);
    total += times[i];
  }
  mean = total/M;
  var = 0.;
  for (i=0; i<M; ++i)
    var += (times[i]-mean)*(times[i]-mean);
  printf("mean elapsed time = %e, variance = %e\n", total/M, var/(M-1));

  // Test the function clock_gettime()
  total = 0.;
  for (i=0; i<M; ++i) {
    // start the timer
    struct timespec start3;
    clock_gettime(CLOCK_MONOTONIC, &start3); 
	  
    // run some code where timing is desired
    diff(u, N, dx, du);
	
    // stop the timer and print the results
    struct timespec end3;
    clock_gettime(CLOCK_MONOTONIC, &end3); 
    times[i] = (end3.tv_sec + end3.tv_nsec/1.0e9) 
      - (start3.tv_sec + start3.tv_nsec/1.0e9);
    total += times[i];
  }
  mean = total/M;
  var = 0.;
  for (i=0; i<M; ++i)
    var += (times[i]-mean)*(times[i]-mean);
  printf("mean elapsed time = %e, variance = %e\n", total/M, var/(M-1));

  // Test the function gettimeofday()
  total = 0.;
  for (i=0; i<M; ++i) {
    // start the timer
    struct timeval start4;
    gettimeofday(&start4, NULL); 
	
    // run some code where timing is desired
    diff(u, N, dx, du);
	
    // stop the timer and print the results
    struct timeval end4;
    gettimeofday(&end4, NULL); 
    times[i] = (end4.tv_sec + end4.tv_usec/1.0e6) 
      - (start4.tv_sec + start4.tv_usec/1.0e6);
    total += times[i];
  }
  mean = total/M;
  var = 0.;
  for (i=0; i<M; ++i)
    var += (times[i]-mean)*(times[i]-mean);
  printf("mean elapsed time = %e, variance = %e\n", total/M, var/(M-1));
	
  free(u);
  free(du);

  return 0;
}
