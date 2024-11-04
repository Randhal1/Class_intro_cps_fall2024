#include<stdio.h>

// Function to find the maximum value in an array

void findMaximum(int *arr)
{
    // Assume the first element is the maximum
    int max = arr[0];
    int index;

    // Loop through the array to find the maximum
    for (long i = 1; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (arr[i] > max) {
            // Update maximum if a smaller element is found
            max = arr[i];
	    index = i;
        }
    }

    return index;
}

int main() {

	int array[5] = {0, 5, 7, 6, 4};

	printf("%d \n", array[findMaximum(array)]);	
	printf("%ld \n", sizeof(array)/sizeof(int));
}
