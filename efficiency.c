#include <stdio.h>
#include <time.h>
#include <cblas.h>


int main(int argc, char* argv[]) 
{
  clock_t start, end, start1, end1;
  int cpu_time_used;
     
  start = clock();
     /* Do the work. */
  int len = 1e6;
  int x = 1;
  int y = -1;
  int t;
  int ans = 0;

  for(int i; i < len; i++){
    ans = ans + x*y;
    t = x;
    x = y;
    y = t;
    //printf("x = %d, y = %d dot_product = %d \n", x, y, ans);
  }

  end = clock();

  cpu_time_used = ((int) (end - start)) / CLOCKS_PER_SEC;
  // print the result
  printf("This task took %d seconds to execute \n", cpu_time_used);

  return 0.;
}

     
