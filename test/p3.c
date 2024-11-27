#include <stdio.h>

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;

	printf("Swap a = %d b = %d \n", *a, *b);
}

int main() {

	int cat1 = 5;
	int cat2 = 8;
	printf("Values before %d and %d", cat1, cat2);

	swap(&cat1, &cat2);

	printf("Values after %d and %d", cat1, cat2);
}
