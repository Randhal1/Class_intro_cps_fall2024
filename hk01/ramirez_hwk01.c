#include <stdio.h>
#include "catlib.h"
/* This code calculates modes for multimodal list of numbers. 
 *
 * Randhal Ramirez 11/17/2024
 *
 */
int main(){
        
	// 1. Input the list of element to be evaluated:
	
        int number;
	int list_test[30]; 
        FILE* in_file = fopen("data.txt", "r"); //only open a pre-exisiting file in read mode. 
        
        if (! in_file ) // equivalent to saying if ( in_file == NULL ) 
           {  
              printf("oops, file can't be read\n"); 
              //exit(-1); 
           } 
        // attempt to read the next line and store 
        // the value in the "number" variable
	
	int i = 0;

	while ( fscanf(in_file, "%d", &number ) == 1 )
           {
	     list_test[i] = number*1;
             //printf("We just read %d \n", list_test[i]);
	     i++;
           }


        // 2. Get the list of unique elements:
	int size_list = 30; // size of the original list.
	int size_unqy = unique_qty(list_test, size_list); // number of unique elements.

	int unique[size_unqy]; // list containing the unique elements.

	for(int i = 0; i < size_unqy; i++){
		unique[i] = list_test[0]; // since the list must contain at least one element. 
	}

	int unique_count = 1; // count the total of unique elements list.
	//printf("Added to unique: %d at index %d \n", unique[0], unique_count-1);

	for(int i = 0; i < size_list; i++) {
		if(is_in(unique, size_unqy, list_test[i]) == 0) {
			unique[unique_count] = list_test[i];
			unique_count++;
		}	
	}// for loop


	// 3. Count the occurrences of the elements within the original list:

	int quanty[size_unqy]; // list contianing the count of the unique elements.
	
	for(int i=0; i < size_unqy; i++){
		quanty[i] = kdelta(list_test, size_list, unique[i]);
		printf("Value %d appears %d times. \n", unique[i], quanty[i]);
	}

	// 4. print mode or multiple modes. 
	
	// This number represent the number of modes.
	int mode_number = 1; // Assuming the given list has at least one mode.
	int maxima = quanty[max(quanty, 17)];

	for(int i=0; i < size_unqy; i++) {
		if(quanty[i] == maxima) {
			printf("mode %d = %d and repeated %d times. \n", mode_number, unique[i], quanty[i]);
			mode_number++;
		} // if-statement
	} // for-loop

	return 0;
}// main func
