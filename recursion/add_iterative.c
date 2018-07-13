#include <stdio.h>

int add_iterative(int *array, int size){
	int ans = 0;
	for(int i = 0; i < size; i++)
	ans += array[i];
return ans;
}

int main(){
	int num[] = {1,2,3,4,5,6,7,8,9,10};
	int ans = add_iterative(num, (sizeof(num)/sizeof(num[0])));
	//printf("%d", ans);
return 0;
}
