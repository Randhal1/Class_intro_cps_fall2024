#include<stdio.h>

void fun(int *p){
	*p = 10;
}

int main() {

	int y = 5;

	fun(&y);
	printf("%d \n", y);
	return 0;
}
