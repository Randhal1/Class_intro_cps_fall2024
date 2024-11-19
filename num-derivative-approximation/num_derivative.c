#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gato_libv0.0.1.h"

int main(int argc, char* argv[]) {
	int N = atoi(argv[1]); // Number of intervals.
	
	double h = 2*M_PI/N;
	double x[N+1]; 	    // string which stores x values.
	double y[N+1]; 	    // string which stores y values.
	double dy[N]; 	    // string which stores forward differentiation of y. 
	double uy[N-1];     // string which stores central differentiation of y.
	double errorf[N];   // string which stores error in forward differentiation of y.
	double erroru[N-1]; // string which stores error in central differentiation of y.

	steps(N, x, y);
	fdiff(N, h, y, dy, x, errorf);
	udiff(N, h, y, uy, x, erroru);

	int lf = min(errorf, N);   // minimum error using forward diff.
	int mf = max(errorf, N);   // maximum error using forward diff.
	int lc = min(erroru, N-1); // minimum error using central diff.
	int mc = max(erroru, N-1); // maximum error using central diff.

	printf("\t \t \t x \t \t y \t \t dy \t \t abs_err \t dy_central \t abs_err \n");
	for(int i = 0; i < N+1; i++){
		if(i >= N){
			printf("\t \t \t %lf \t %lf \n", x[i], y[i]);
		} else if (i >= N-1){
			printf("\t \t \t %lf \t %lf \t %lf \t %lf\n", x[i], y[i], dy[i], errorf[i]);
		} else {
		printf("\t \t \t %lf \t %lf \t %lf \t %lf \t %lf \t %lf	\n", x[i], y[i], dy[i], errorf[i], uy[i], erroru[i]);
		}
	} // for loop
	printf("\n\t \t \t x \t \t y \t \t dy \t \t abs_err\n \t \t \t ---- \t \t ---- \t \t ---- \t \t ---- \n");
	printf("min error forward: \t %lf \t %lf \t %lf \t %lf \n", x[lf], y[lf], dy[lf], errorf[lf]);
	printf("max error forward: \t %lf \t %lf \t %lf \t %lf \n \n", x[mf], y[mf], dy[mf], errorf[mf]);
	printf("min error central: \t %lf \t %lf \t %lf \t %lf \n", x[lc+1], y[lc+1], uy[lc], erroru[lc]);
	printf("max error central: \t %lf \t %lf \t %lf \t %lf \n", x[mc+1], y[mc+1], uy[mc], erroru[mc]);
} // main func.
