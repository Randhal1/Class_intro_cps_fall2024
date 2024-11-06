#include<stdio.h>

int array(int arr[], int len){
	/*for(int i; i < len; i++){
		printf("Value[%d] is: %d \n", i, arr[i]);
	}*/
	return arr;
}

int main(){
	int at[] = {3,5,7};
	int aa[] = array(at, 3);	
	for(int i; i < 3; i++){
		printf("Value[%d] is: %d \n", i, aa[i]);
	}
}
