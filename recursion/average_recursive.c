#include <stdio.h>

int add(int a, int b){
	return (a + b);
}

int find_product(int* array, int len){
	if (len == 1)
		return array[0];
	return(add(find_product(array, len - 1), array[len - 1]));
}

int main(int argc, char const *argv[])
{
	
	int nums[] = {1,2,3,4,5,6,7,8,9,10};
	int initial_size = sizeof(nums)/sizeof(nums[0]);
	int average = find_product(nums, initial_size);
	printf("The average of elements is %d\n",average);

	return 0;
}