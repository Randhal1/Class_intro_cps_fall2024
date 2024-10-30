// Dfine a bisection function.
double bisection(double a, double b){

    double c = (a+b)/2;

    int q = 0;

    for (int i = 0; i < M; i++){
    	
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
