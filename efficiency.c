#include <stdio.h>
#include <time.h>
#include <cblas.h>


int main(double argc, char* argv[]) 
{
  clock_t start, end, start1, end1;
  double cpu_time_used;
     
  start = clock();
     /* Do the work. */
  double len = 1e11;
  double x = 1;
  double y = -1;
  double t;
  double ans = 0;

  for(double i; i < len; i++){
    ans = ans + x*y;
    t = x;
    x = y;
    y = t;
    //prdoublef("x = %d, y = %d dot_product = %d \n", x, y, ans);
  }

  end = clock();

  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  // prdouble the result
  printf("This task took %lf seconds to execute \n", cpu_time_used);

  return 0.;
}

     
