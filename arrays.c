#include<stdio.h>

int main() {

	int dog[2] = {-90,8};
	int *ptr2dog = &dog[0];
	int *ptr2dog2 = &dog[0];

	printf("dog[0] = %d \n", dog[0]); 
	printf("ptr2dog[0] = %d \t ptr2dog next entry = %d \n", *ptr2dog, *(ptr2dog+1)); 
	//dor loop
	//for (int i = 0; i < 2; i++)
		//printf("dog[%d] = %d \n", i, dog[i]); 
		//scope of i is only the first line following the for loop. 
	


	return 0;
}
