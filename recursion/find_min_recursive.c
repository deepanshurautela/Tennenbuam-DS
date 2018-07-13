#include <stdio.h>

int min(int a, int b){
	return (a < b) ? a : b;
}

int find_min_element(int *arr, int len){
	if (len == 1)
		return arr[0];
	return min(find_min_element(arr, len - 1), arr[ len -1 ]);
}


int main(){
	int nums[] = {1,2,3,4,5,6,7,8,9,10};
	int min = find_min_element(nums, (sizeof(nums)/sizeof(nums[0])));

	printf("The minimum element is %d\n",min);
	return 0;
}