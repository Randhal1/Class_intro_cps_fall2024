#include <stdio.h>
#include <time.h>
#include <cblas.h>


int main(int argc, char* argv[]) 
{
  clock_t start, end, start1, end1;
  double cpu_time_used;
     
  start = clock();
     /* Do the work. */
  int len = 1000000;
  int x[len];
  int y[len];
  int ans;

  for(int i; i <= len; i++){
    x[i] = (-1)^i;
    y[i] = (-1)^(i+1);
    ans = ans + x[i]*y[i];
    //printf("x = %d, y = %d dot_product = %d \n", x[i], y[i], ans);
  }

  end = clock();

  start1 = clock();
     /* Do the work. */
  int len = 1000000;
  int x[len];
  int y[len];
  int ans;

  for(int i; i <= len; i++){
    x[i] = (-1)^i;
    y[i] = (-1)^(i+1);
  }
  


  end1 = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
  // print the result
  printf("This task took %f seconds to execute \n", cpu_time_used);
  printf("This task took %f seconds to execute \n with BLAS", cpu_time_used1);

  return 0.;
}

     
