#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Task proposed on 10/21/2024 
 * working with 
 * Bisection method
 * Newton's method
 * Secant method
 * Fixed-Point iteration
 * Default
 */


// Define a function to compute main function 
double fun(double a){
    return (pow(a, 6)-a-1);
}// End pointer


// Define a function to compute the first derivative of the given function
double dfun(double a){
    return (6*pow(a, 5)-1);
}// End pointer


// Define a bisection function.
double bisection(double a, double b){

    double eps = 0.000001; 
    double c = (a+b)/2;

    int q = 0;

    for (int i = 0; i < 50; i++){
    	
	if (fun(c)*fun(b) < 0){
	    a = c;
	    c = (a+b)/2;

	} else if (fun(c)*fun(b) > 0){
	    b = c;
	    c = (a+b)/2;

	}

	
	if (fabs(fun(c)) < eps) {
	    break;

	} /*else if (fabs(fun(c)-fun(b)) < eps) {
	    break;

	} else if (fabs(fun(c)-fun(a)) < eps) {
	    break;
	}// End if*/
	
	q+=1;

    }// End for

    printf("Function x^6-x-1 solved using bisection algorithm \n answer = %.8lf in %d steps.\n", c, q);

}// End pointer


// Define a Newton-Raphson function.
double newrap(double a){

    double eps = 0.000001; 
    double c = a - fun(a)/dfun(a);;

    int q = 0;

    for (int i = 0; i < 50; i++){

	c = c - fun(c)/dfun(c);
	q+=1;

	if (fabs(fun(c)) < eps){
	    break;
	}// End if
	    

    }// End for

    printf("Function x^6-x-1 solved using Newton-Raphson algorithm \n answer = %.8lf in %d steps.\n", c, q);

}// End pointer


// Define a secant method function.
double secant(double x0, double x1){

    double eps = 0.000001; 
    double x2 = x1 - fun(x1)*((x1-x0)/(fun(x1)-fun(x0)));

    int q = 0;

    for (int i = 0; i < 50; i++){

	q+=1;

	if (fabs(fun(x2)) < eps){
	    break;
	}// End if
	
	x0 = x1;
	x1 = x2;
	x2 = x2 = x1 - fun(x1)*((x1-x0)/(fun(x1)-fun(x0)));
	    

    }// End for

    printf("Function x^6-x-1 solved using secant algorithm \n answer = %.8lf in %d steps.\n", x2, q);

}// End pointer


// Define a secant method function.
double secant(double x0, double x1){

    double eps = 0.000001; 
    double x2 = x1 - fun(x1)*((x1-x0)/(fun(x1)-fun(x0)));

    int q = 0;

    for (int i = 0; i < 50; i++){

	q+=1;

	if (fabs(fun(x2)) < eps){
	    break;
	}// End if
	
	x0 = x1;
	x1 = x2;
	x2 = x2 = x1 - fun(x1)*((x1-x0)/(fun(x1)-fun(x0)));
	    

    }// End for

    printf("Function x^6-x-1 solved using secant algorithm \n answer = %.8lf in %d steps.\n", x2, q);

}// End pointer
int main()
{
    bisection(-1,0);
    newrap(-0.5);
    secant(-1,0);
}
