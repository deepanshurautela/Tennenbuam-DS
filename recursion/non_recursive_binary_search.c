#include <stdio.h>

int binary_search(int *, int, int search_val);

int main(int argc, char const *argv[])
{	int search_val = 10;
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d is at position %d\n", search_val, binary_search(a, 10, search_val));
	return 0;
}


int binary_search(int *arr, int size, int search_val){
	//Assuming that the array is sorted in ascending order
	int low = 0;
	int high = size;
	int mid = (low + high) / 2;
	while(arr[mid] != search_val){
		if (search_val > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	mid = (low + high) / 2;
	}
	return mid + 1;
}