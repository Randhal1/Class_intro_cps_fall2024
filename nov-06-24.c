#include<stdio.h>

/* array = {0, 0, 0, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2};
 * find the most recurring entry of the array. 
 * counter = 0;
 * int i, j;
 * for (i = 0; i < SIZE; i++){
 *		
 * }
 */

int unique(int *arr, int size){
	
	int uqty = 1;

	for(int i; i < size; i++){
		for(int j; j < size; j++){
	
			if(arr[i] != arr[j]){
				uqty++;
			}

		}//j-loop	
	}//i-loop
	
	return uqty;

}//end func

int main(){

	int array[] = {0, 0, 0, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2};
		
	int size = sizeof(array)/sizeof(array[0]);

	int counter = 1;

	/*for(int i; i < size; i++){
		for(int j; j < size; j++){
			if(j!= i);			
		}//j-loop
	}//i-loop*/
	 
	printf("%d", unique(array, size));

	return 0; 
}