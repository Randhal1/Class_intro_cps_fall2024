#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ArrayLess(int arr[], int size, int compare)
{
    int low[size];
    int magnitude = 0;
    //add all elements to the variable sum.
    for(int i = 0; i < size; i++){
          if (arr[i] != compare) {
		low[i] = 1;
	  } //End if
	  else {
		low[i] = 0;
	  } //End else
    }

    for(int i = 0; i < size; i++){
	  magnitude +=low[i];
    }

    return magnitude;
}

// Function to find the minimum value in an array
int findMinimum(double arr[], int size)
{
    // Assume the first element is the minimum
    double min = arr[0];
    int index;

    // Loop through the array to find the minimum
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            // Update minimum if a smaller element is found
            min = arr[i];
	    index = i;
        }
    }

    return index;
}

int main(){
	
	int x[5];
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
	double sum = 0.0;//sum 41
	for (int i = 0 ;i < 5; ++i)
		{
		sum +=x[i];
		printf(" for i = %d, sum = %lf \n ", i, sum );
			
		} //End for

	avg = sum/5;
	
	double std[5];
	sum = 0.0;
	for (int i = 0; i < 5; ++i)
		{
		std[i] = pow((x[i]-avg),2);
		sum +=std[i];
		}//End for
	
	double sstd = sqrt(sum/5);

	// We can define the median as follows:
	// For any given set with a normal distribution 
	// the median will be the closest value to the average
	// 
	// We can define the mode as follows:
	// For any given set the mode will be a unique value such that 
	// when compared to other elements (returning 0 if equal, 1 if different)
	// the adition of all terms returns the lowest possible value. 
	
	// We can then write the following code
	
	//int median = x[findMinimum(std,5)];//this code needs revision <-- Randhal  

	double collections[5]; 

	for (int i = 0; i < 5; ++i)
		{
		collections[i] = ArrayLess(x, 5, x[i]); 
		}//End for

	int mode = x[findMinimum(collections, 5)-1];

	// Print the results 
	printf(" the average score is: %lf \n", avg);
	//printf(" the median score is : %d \n", median);
	printf(" the mode score is : %d \n", mode);
	printf(" the std is	     : %lf \n", sstd);
}
