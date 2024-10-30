// Define a secant method function.
double secant(double x0, double x1){

    double x2 = x1 - fun(x1)*((x1-x0)/(fun(x1)-fun(x0)));

    int q = 0;

    for (int i = 0; i < M; i++){

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
