#include<stdio.h>

// Function to find the maximum value in an array
int findMaximum(int arr[], int lenght)
{
    // Assume the first element is the maximum
    int max = arr[0];
    int index;

    // Loop through the array to find the maximum
    for (long i = 1; i < lenght; i++) {
        if (arr[i] > max) {
            // Update maximum if a smaller element is found
            max = arr[i];
	    index = i;
        }
    }

    return index;
}


int main() {

	int array[] = {0, 5, 1, 7, 4, 2};
	int lenght = *(&array + 1)-array;
	printf("The maximum is %d \n", array[findMaximum(array, lenght)]);
}
