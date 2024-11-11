int main(int argc, char* argv[])
{
  // data is an array of floats: data[0], ..., data[4]
  float data[5]; 
	
  // grid is a 3x3 array arranged in column primary order
  double grid[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  	
	
  // pointer to floating point data, uninitialized
  float *floatPointer; 
	
  // variable of type pointer to float data initialized to point to the
  // start of the data array.
  float* anotherPointer = data; 
	
  // pointer to double precision data, it points to the start of the 
  // grid array
  double *dblPointer = &(grid[0][0]);	
  float* x;
  float y;
	
  anotherPointer[2] = 3.;     		// this will set data[2] to 3.
  *anotherPointer = 7;         		// this will set data[0] to 7.
  data[3] = *anotherPointer + 1;	// this will set data[3] to 8.
	
  // this assigns the memory address for y to the pointer x 
  // so that x points to the value of y.
  x = &y;          
}
