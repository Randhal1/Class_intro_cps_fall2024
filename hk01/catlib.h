// A function to define if an integer is within a list.
int is_in(int *arr, int size, int value){
	int exist = 0;
	for(int i=0; i < size; i++){
		if(value == arr[i]){
			exist = 1;
		}// if statement.
	}//for loop.
	return exist;
}// is_in function.


// A function to define the quantity of unique values.
int unique_qty(int *arr, int size){
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
int kdelta(int *arr, int size, int value){

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


int max(int *arr, int size) {
	
	int maximum = arr[0]; // Assume the first element is the maximum.

	int pos = 0; // the position of the maximum.

	for(int i=0; i < size; i++){
		if(arr[i] > maximum){
			maximum = arr[i]; 
			pos = i;
		} // if statement
	} // for loop.

	return pos;
} // max 
