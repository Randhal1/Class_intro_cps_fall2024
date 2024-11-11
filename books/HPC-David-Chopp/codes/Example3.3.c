#include <stdio.h>

int main(int argc, char* argv[])
{
  double a = 0.15 + 0.15;
  double b = 0.10 + 0.20;
	
  if (a == b) {
    printf("They are equal.\n");
  } else {
    printf("They are unequal.\n");
  }
	
  return 0;
}
