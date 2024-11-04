#include<stdio.h>

/* write a C program that computes the product of two integers (provided by the user)
 * by calling a function mult.
 */

int mult( int a, int b){
	return a*b;
}

/*
void swap(int x0, int x1){
	int x  = x0;
	    x0 = x1;
	    x1 = x;
}*/

void swap(int *ptr2a, int *ptr2b){
	int c; //temp var
	    c = *ptr2a; //temp var
	    *ptr2a = *ptr2b;
	    *ptr2b = c;
	    printf("[%d, %d] \n", *ptr2a, *ptr2b);
}

int main ()
{
	int cat1 = 45; 
	int *ptr2cat1 = &cat1;
	int cat2 = 87;
	int *ptr2cat2 = &cat2;
	printf("Value of cat1 %d and value to cat2 %d \n", cat1, cat2);
	printf("Value of ptr2cat1 %d and value to ptr2cat2 %d \n", *ptr2cat1, *ptr2cat2);

	swap(ptr2cat1, ptr2cat2);

	printf("Value of cat1 %d and value to cat2 %d \n", cat1, cat2);
	printf("Value of ptr2cat1 %d and value to ptr2cat2 %d \n", *ptr2cat1, *ptr2cat2);

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
