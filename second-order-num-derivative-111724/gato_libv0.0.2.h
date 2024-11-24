// Define a function to calculate the forward difference
void fdiff(int N, double h, double *arr, double *arr1, double *x, double *error) {
	for(int i = 0; i<N; i++) {
		arr1[i] = (arr[i+1]-arr[i])/h;
		error[i] = fabs(cos(x[i]) - arr1[i]);
	} // for loop.
} // fdiff.


// Define a function to calculate the central difference
void udiff(int N, double h, double *arr, double *arr1, double *x, double *error) {
	for(int i = 1; i<N; i++) {
		arr1[i-1]  = (arr[i+1]-arr[i-1])/(2*h);
		error[i-1] = fabs(cos(x[i]) - arr1[i-1]);
	} // for loop.
} // udiff.


// Define a function to calculate the central difference
void diff2(int N, double h, double *arr, double *arr1, double *x, double *error) {
	for(int i = 1; i<N; i++) {
		arr1[i-1]  = (arr[i+1]-2*arr[i]+arr[i-1])/(h*h);
		error[i-1] = fabs(-sin(x[i]) - arr1[i-1]);
	} // for loop.
} // diff2.


// Define a function to break x and form different steps.
// Also compute the values of y.
void steps(int N, double *arr, double *arr1) {
	for(int i=0; i<=N; i++){
		arr[i] = 2*M_PI/N*i;
		arr1[i] = sin(arr[i]);
	} // for loop.
} // x_intervals.


double max(double *arr, double size) {
	
	double maximum = arr[0]; // Assume the first element is the maximum.

	double pos = 0; // the position of the maximum.

	for(int i=0; i < size; i++){
		if(arr[i] > maximum){
			maximum = arr[i]; 
			pos = i;
		} // if statement
	} // for loop.

	return pos;
} // max


double min(double *arr, double size) {
	
	double minimum = arr[0]; // Assume the first element is the maximum.

	double pos = 0; // the position of the maximum.

	for(int i=0; i < size; i++){
		if(arr[i] < minimum){
			minimum = arr[i]; 
			pos = i;
		} // if statement
	} // for loop.

	return pos;
} // max
