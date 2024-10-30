#include<stdio.h>

/* write a C program that computes the product of two integers (provided by the user)
 * by calling a function mult.
 */

int mult( int a, int b){
	return a*b;
}

void swap(int x0, int x1){
	int x  = x0;
	    x0 = x1;
	    x1 = x;
}

int main ()
{
	int cat1 = 1; 
	int *ptr2cat1 = &cat1;
	printf("Value of ptr2cat1 %d \n", *ptr2cat1);
	int cat2;
	/*
	printf("Enter two integers: \n");
	scanf("%d %d", &cat1, &cat2 ); // intro to adress/location

	printf("Prod is %d \n", mult(cat1, cat2));

	printf("You've entered [%d, %d] \n", cat1, cat2);
	
	swap(cat1, cat2);

	printf("Swaped answer [%d, %d] \n", cat1, cat2);
	*/
	return 0;
}
