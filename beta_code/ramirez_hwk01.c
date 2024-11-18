#include <stdio.h>
/* This code calculates modes for multimodal list of numbers. 
 *
 * Randhal Ramirez 11/17/2024
 *
 */

// A function to define if an integer is within a list.
int is_in(int arr[], int size, int num){
	int exist = 0;
	for(int i=0; i < size; i++){
		if(num == arr[i]){
			exist = 1;
			break;
		}// if statement.
	}//for loop.
	return exist;
}// is_in function.


// A function to define the quantity of unique values.
int unique_qty(int arr[], int size){
	int unique_a[size];
	int unique_count = 1;

	unique_a[0] = arr[0];

	for(int i = 0; i < size; i++) {
		if(is_in(unique_a, size, arr[i]) != 1){
			unique_a[unique_count] = arr[i];
			unique_count++;
		}
	}// for loop.
	return unique_count;
}// unique_qty function.


// A function to define Kronecker-Delta and the sumation
int kdelta(int arr[], int size, int value){

	int tmp[size]; // temporal array to compare elements.
	int magnitude = 0; // the magnitude of the count.

	for(int i=0; i < size; i++){
		if(arr[i] == value){
			tmp[i] = 1;
		} else {
			tmp[i] = 0;
		} // if-else statement.
	} // for-loop. 

	for(int i=0; i < size; i++){
		magnitude = magnitude + tmp[i];
	}
	
	return magnitude;
}// kdelta function.


int max(int arr[], int size) {
	
	int maximum = arr[0]; // Assume the first element is the maximum.

	int pos; // the position of the maximum.

	for(int i=0; i < size; i++){
		if(arr[i] > maximum){
			maximum = arr[i]; 
			pos = i;
		} // if statement
	} // for loop.

	return pos;
} // max 


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
	     list_test[i] = number;
             //printf("We just read %d \n", list_test[i]);
	     i++;
           }

	//int list_test[] = {1,1,1,2,1,3,4,2,2,5,4,3,3,5,5};
	

        // 2. Get the list of unique elements:
	//int size_list = sizeof(list_test)/sizeof(list_test[0]); // size of the original list.
	int size_list = 30; // size of the original list.
	int size_unqy = unique_qty(list_test, size_list); // number of unique elements.

	int unique[size_unqy]; // list containing the unique elements.

	unique[0] = list_test[0]; // since the list must contain at least one element the first 
				  // element in the list must be unique.
	
	int unique_count = 1; // count the total of unique elements list.
	//printf("Added to unique: %d at index %d \n", unique[0], unique_count-1);

	for(int i = 0; i < size_list; i++) {
		if(is_in(unique, size_unqy, list_test[i]) != 1){
			int q = list_test[i];
			unique[unique_count] = q; 
			unique_count++;
			//printf("Added to unique: %d at index %d \n", unique[i], unique_count-1);
		}
	}// for loop

	/*for(int i=0; i<unique_count; i++){
		//printf("%d \n", unique[i]);
	}*/


	// 3. Count the occurrences of the elements within the original list:

	int quanty[size_unqy]; // list contianing the count of the unique elements.
	
	for(int i=0; i < size_unqy; i++){
		quanty[i] = kdelta(list_test, size_list, unique[i]);
		//printf("Value %d appears %d times. \n", unique[i], quanty[i]);
	}

	for(int i=0; i < size_unqy; i++){
		printf("%d --> %d \n", unique[i], quanty[i]);
	}

	// 4. print mode or multiple modes. 
	
	// This number represent the number of modes.
	int mode_number = 1; // Assuming the given list has at least one mode.
	int maxima = quanty[max(quanty, size_unqy)];

	for(int i = 0; i < size_unqy; i++){
		if(quanty[i] == maxima){
			printf("mode %d = %d appearing %d times. \n", mode_number, unique[i], quanty[i]);
			mode_number++;
		} // if-statement
	} // for-loop

	//printf("%d \n", is_in(list_test, 30, 29));
	//printf("%d \n", unique_qty(list_test, 30));
	//printf("%d \n", kdelta(list_test, 30, 29));
	//printf("%d \n", size_unqy);
	//printf("%d \n", maxima);

	return 0;
}// main func
