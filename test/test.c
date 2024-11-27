#include <stdio.h>

int main() {
	/*for(int i=0; i < 50; i++) {
		char * y = "gato";

		if(i == 10){
			printf("%c", *i);
			break;
		}
		printf("%d \n", i);
	}*/

	int myarr[20][20];
	double urarr[20][20];
	char *lrarr[20][20];
	array jkrr[20][20];

	myarr[10][5] = 6;
	urarr[7][11] = 7.28345;
	lrarr[7][11] = "L";
	
	printf("%d, %lf, %c", myarr[10][5], urarr[7][11], *lrarr[7][11]);

}
