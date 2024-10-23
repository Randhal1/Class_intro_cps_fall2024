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
    double f = pow(a, 6)-a-1;
    return f; 
}// End pointer


// Define a function to compute the first derivative of the given function
double dfun(double a){
    double df = 6*pow(a, 5)-1;
    return df; 
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

	} else if (abs(fun(c)) <= eps) {
	    break;

	} else if (abs(fun(c)-fun(b)) <= eps) {
	    break;

	} else if (abs(fun(c)-fun(a)) <= eps) {
	    break;
	}// End if
	
	q+=1;

    }// End for

    printf("Function x^6-x-1 solved using bisection algorithm \n answer = %lf in %d steps.\n", c, q);

}// End pointer


// Define a Newton-Raphson function.
double newrap(double a){

    double eps = 0.000001; 
    double c = a - fun(a)/dfun(a);;

    int q = 0;

    for (int i = 0; i < 50; i++){

	c = c - fun(c)/dfun(c);
	q+=1;

	if (abs(fun(c)) <= eps){
	    break;
	}// End if
	    

    }// End for

    printf("Function x^6-x-1 solved using Newton-Raphson algorithm \n answer = %lf in %d steps.\n", c, q);

}// End pointer



int main()
{
    /*double a = fun(1);
    printf("function at: %lf", a);*/

    //double a = fun(-1);
    bisection(-1,0);
    newrap(-0.5);
    //printf("%lf", a);

    /*
    int input;

    printf( "1. Play game\n" );
    printf( "2. Load game\n" );
    printf( "3. Play multiplayer\n" );
    printf( "4. Exit\n" );
    printf( "Selection: " );
    scanf( "%d", &input );
    switch ( input ) {
    */
}
