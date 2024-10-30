// Define a fix point iteration method function.
double fixpoint(double x0){

    double x1 = pow(x0, 6)-1;

    int q = 0;

    for (int i = 0; i < M; i++){

	q+=1;

	if (fabs(fun(x1)) < eps){
	    break;
	}// End if
	
	x0 = x1;
	x1 = pow(x0, 6)-1;
	    

    }// End for

    printf("Function x^6-x-1 solved using Fix-Point algorithm \n answer = %.8lf in %d steps.\n", x1, q);

}// End pointer
