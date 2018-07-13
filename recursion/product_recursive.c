#include <stdio.h>

int mult(int a, int b){
	return (a * b);
}

int find_product(int* array, int len){
	if (len == 1)
		return array[0];
	return(mult(find_product(array, len - 1), array[len - 1]));
}

int main(int argc, char const *argv[])
{
	
	int nums[] = {1,2,3,4,5,6,7,8,9,10};
	int product = find_product(nums, (sizeof(nums)/sizeof(nums[0])));
	printf("The sum of elements is %d\n",product);

	return 0;
}