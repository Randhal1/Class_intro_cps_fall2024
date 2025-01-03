#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Return the magnitude of the sum of all elements of an array
// when a substatraction is done
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


int main()
    {
          int number;
	  int x[20]; 
          FILE* in_file = fopen("scores-data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
          if (! in_file ) // equivalent to saying if ( in_file == NULL ) 
             {  
                printf("oops, file can't be read\n"); 
                exit(-1); 
             } 
          // attempt to read the next line and store 
          // the value in the "number" variable
	
	  int i = 0;

	  while ( fscanf(in_file, "%d", & number ) == 1 )
             {
	       x[i] = number;
               printf("We just read %d \n", x[i]);
	       i++;
             }
		
	double avg=0;
	double sum = 0.0;//sum 41

	for (int i = 0 ;i < 20; ++i)
		{
		sum +=x[i];
		printf(" for i = %d, sum = %lf \n ", i, sum );
			
		} //End for

	avg = sum/20;
	
	double std[20];
	sum = 0.0;
	for (int i = 0; i < 20; ++i)
		{
		std[i] = pow((x[i]-avg),2);
		sum +=std[i];
		}//End for
	
	double sstd = sqrt(sum/20);

	// We can define the median as follows:
	// For any given set with a normal distribution 
	// the median will be the closest value to the average
	// 
	// We can define the mode as follows:
	// For any given set the mode will be a unique value such that 
	// when compared to other elements (returning 0 if equal, 1 if different)
	// the adition of all terms returns the lowest possible value. 
	
	// We can then write the following code
	
	//float median = 59.5; //x[findMinimum(std,20)]; //This code need revision. 

	double collections[20]; 

	for (int i = 0; i < 20; ++i)
		{
		collections[i] = ArrayLess(x, 20, x[i]); 
		}//End for

	int mode = x[findMinimum(collections, 20)];

	// Print the results 
	printf(" the average score is: %lf \n", avg);
	//printf(" the median score is : %f \n", median);
	printf(" the mode score is   : %d \n", mode);
	printf(" the std is	     : %lf \n", sstd);
}
