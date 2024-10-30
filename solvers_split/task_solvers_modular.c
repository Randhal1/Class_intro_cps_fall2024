#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define eps 0.000001 
#define M 50

#include"functions.h"
#include"bisection.h"
#include"fix_point_x6-x-1.h"
#include"newton_raphson.h"
#include"secant.h"

/* Task proposed on 10/21/2024 
 * working with 
 * Bisection method
 * Newton's method
 * Secant method
 * Fixed-Point iteration
 * Default
 */

int main()
{
    int input;
    printf( "1. Bisection method.\n" );
    printf( "2. Newton method.\n" );
    printf( "3. Secant method.\n" );
    printf( "4. Fix point iteration.\n" );
    printf( "Selection: " );
    scanf( "%d", &input );
    switch ( input ) {
        case 1:
	    bisection(-1,0);
	    break;
	case 2:
	    newrap(-0.5);
	    break;
	case 3:
	    secant(-1,0);
	    break;
	case 4:
	    fixpoint(-0.5);
	    break;
	default:
	    newrap(-0.5);}

}
