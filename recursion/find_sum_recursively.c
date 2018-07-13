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
	int sum = find_product(nums, (sizeof(nums)/sizeof(nums[0])));
	printf("The sum of elements is %d\n",sum);

	return 0;
}