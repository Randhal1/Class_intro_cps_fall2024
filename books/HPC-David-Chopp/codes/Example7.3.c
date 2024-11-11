#include <stdio.h>
#include <lapacke.h>  // The C interface for LAPACK

/*
  int main(int argc, char* argv[])

  The main program creates a statically allocated linear system, 
  and then solves Ax = b.  
  The original problem with the solution is printed out at the end.

  Inputs: none

  Outputs: Prints the original problem with the solution
*/

int main(int argc, char* argv[])
{
  // The dimension of the matrix A
  // lapack_int is a special type defined for LAPACK, 
  //      it is usually the same as int
  lapack_int n = 5;
        
  // The number of columns of b.  nrhs can be >= 1 if multiple solutions
  //      for the same A are desired.
  lapack_int nrhs = 1;
        
  // The tridiagonal matrix A stored as 3 diagonals
  double ald[5] = {2.0, 1.0, 1.0, 1.0, 0.0};
  double ad[5] = {-2.0, -2.0, -2.0, -2.0, -2.0};
  double aud[5] = {1.0, 1.0, 1.0, 1.0, 0.0};
  double auud[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
        
  // The factorization will not preserve the diagonals, so we will keep
  //      a copy of the original diagonals so that we can print it out
  //      at the end.
  double aorig[3][5];
  for (int i=0; i<5; ++i) {
    aorig[0][i] = ald[i];
    aorig[1][i] = ad[i];
    aorig[2][i] = aud[i];
  }
                        
  // This is the right hand side, also stored in column-major format.
  double b[5] = {1., 2., 3., 4., 5.};
  double c[5] = {5., 4., 3., 2., 1.};
        
  // Upon return, the answer will be stored in b, so we have to keep
  //      a copy of b so we can print the original problem at the end.
  double borig[5], corig[5];
  for (int i=0; i<5; ++i) {
    borig[i] = b[i];
    corig[i] = c[i];
  }
                
  // Variable ipiv is an array for storing the row order.  
  // If there are row interchanges during Gaussian elimination, 
  //      that info is stored in ipiv.  
  // The data will be initialized within LAPACK, so we only have to
  //      create it, and it has to have storage for as many integers as
  //      the rows in A.
  lapack_int ipiv[5];
        
  // If there is an error, a code indicating the type of error will be
  // stored in info upon return.
  lapack_int info = 0;

  // This is where the matrix A is factored.
  // Upon return ald, ad, aud, auud and ipiv will have the encoded LU
  // decomposition for use with the companion function dgttrs.
  info = LAPACKE_dgttrf(n, ald, ad, aud, auud, ipiv);

  // To solve Ax=b, we set the transpose character to 'N' 
  char trb = 'N';

  // To solve A'x=c, we set the transpose character to 'T'
  char trc = 'T';

  // This is where the backsubstitution is done.  
  // This function does not alter the factorization so it can be reused.
  info = LAPACKE_dgttrs(LAPACK_COL_MAJOR, trb, n, nrhs, ald, ad, aud,
			auud, ipiv, b, n);
  info = LAPACKE_dgttrs(LAPACK_COL_MAJOR, trc, n, nrhs, ald, ad, aud,
			auud, ipiv, c, n);

  // Print out the original system Ax = b replacing x with the solution
  printf("Check Ax=b:\n");
  for (int i=0; i<5; ++i) {
    printf("[");
    for (int j=0; j<5; ++j) {
      switch (j-i) {
      case -1: printf("%9.3f", aorig[0][i-1]); break;
      case  0: printf("%9.3f", aorig[1][i]); break;
      case  1: printf("%9.3f", aorig[2][i]); break;
      default: printf("%9.3f", 0.); break;
      }
    }
    printf("] [%9.3f]", b[i]);
    if (i==2)
      printf(" = ");
    else
      printf("   ");
    printf("[%5f]\n", borig[i]);
  }

  // Print out the original system A'x = c replacing x with the solution
  printf("\nCheck A'x=c:\n");
  for (int i=0; i<5; ++i) {
    printf("[");
    for (int j=0; j<5; ++j) {
      switch (j-i) {
      case -1: printf("%9.3f", aorig[2][i-1]); break;
      case  0: printf("%9.3f", aorig[1][i]); break;
      case  1: printf("%9.3f", aorig[0][i]); break;
      default: printf("%9.3f", 0.); break;
      }
    }
    printf("] [%9.3f]", c[i]);
    if (i==2)
      printf(" = ");
    else
      printf("   ");
    printf("[%5f]\n", corig[i]);
  }
  return 0.;
}
