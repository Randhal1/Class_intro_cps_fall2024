#include <stdio.h>
#include <math.h>

// Define the function phi(x)
double phi(double x, double h, double fx (double) ) {
	return (fx(x+h)-fx(x-h))/(2*h);
}

// Define the function L which is f'(x)
double L(double x, double fx (double)) {
	double h = 1.0;
	printf("k \t h \t\t\t phi(h) \t\t L \n --- \t --- \t\t\t --- \t\t\t --- \n");
	double phi_i;
	double Li;
	for(int i=0; i < 20; i++){
		phi_i = phi(x, h, fx);	
		Li = 1.33333333333333333*phi(x, h, fx) - 0.33333333333333333*phi(x, 2*h, fx);
		printf("%d \t %.12lf \t %.12lf \t %.12lf \t \n", i, h, phi_i, Li);
		h = h/2;
	}// for loop.
}

// Define a custom function for item c.
double fsin(double x){
	return sin(x*x+0.33333333333333333*x);
}


int main(){

	//L(sqrt(2), atan); //Used during testing.
	
	// For item a. ln(x) at x = 3
	printf("--------------------------------------------------\n");
	printf("f(x) = ln(x) at x = 3 \n");
	printf("-------------------------------------------------- \n");
	L(3, log);

	// For item b. tan(x) at x = asin(0.8) this is 0.92729522 approx.
	printf("--------------------------------------------------\n");
	printf("f(x) = tan(x) at x = arcsin(0.8) = 0.92729522 \n");
	printf("-------------------------------------------------- \n");
	L(0.92729522, tan);

	// for item c. sin(x^2+1/3*x) at x = 0
	// A custom function was defined
	printf("--------------------------------------------------\n");
	printf("f(x) = sin(x^2+1/3*x) at x = 3 \n");
	printf("-------------------------------------------------- \n");
	L(0, fsin);
}
