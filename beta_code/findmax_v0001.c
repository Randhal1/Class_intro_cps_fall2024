#include<stdio.h>

/* This mthod uses data struct contruction in  order to 
 * simplify array operations, because of it the majority of
 * definitions are imported from custom libraries.
 * Randhal Ramirez 11/04/2024
 */

/* I followed examples from provided materials in class but also from 
 * the book "C Programmimg Laguaje" by Brian Kernighan and Dennis Ritchie 
 * The second edition. 
 */

// Inspiration in this link from StackOverflow 
// https://stackoverflow.com/questions/17590226/finding-length-of-array-inside-a-function

// Define the custom imports 

typedef struct
{
	int *values;
	int capacity;
} GatoArray;


int main() {
	int arraya[] = {1, 2, 5, 7, 4, 1, 0, 3};
	GatoArray array;
	array.values = arraya;
	printf("The value 3 is: %d \n", array.values[3]);
}
