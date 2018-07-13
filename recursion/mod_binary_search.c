#include <stdio.h>

int binary_search(int *arr, int low, int high, int search_num){
	int mid;

	if (low > high)
		return -1;
	
	mid = (high + low) / 2;

	if (search_num == arr[mid])
		return mid + 1;


	if (search_num > arr[mid])
		return binary_search(arr, mid + 1, high, search_num);

	else
		return binary_search(arr, low, mid - 1, search_num);
}


int main(int argc, char const *argv[])
{
	int num[] = {1,2,3,4,5,6,7,8,9,10};
	int search_num;
	int pos; 

	int low = 0;
	int high = (sizeof(num)/sizeof(num[0]));

	printf("Enter the element to search for\n");
	scanf("%d", &search_num);

	pos = binary_search(num, low, high, search_num);
	
	if (pos != -1)
		printf("The number was found at position %d\n",pos);
	printf("The number couldn't be found\n");

	return 0;
}