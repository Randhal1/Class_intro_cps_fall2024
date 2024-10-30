// Define a Newton-Raphson function.
double newrap(double a){

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
