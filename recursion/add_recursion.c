#include <stdio.h>

int add (int *array, int size){
	if(size <= 0)
		return 0;
	return (add(array,size-1) + array[size-1]);
}

int main(){

int arr[] = {1,2,3,4,5,6,7,8,9,10};
int ans = add(arr, (sizeof(arr)/sizeof(arr[0])));
//printf("%d", ans);
return 0;
}
