#include <stdio.h>
#define MAXSIZE 10

void delete_even_pos(int *arr){
	int x;
	for (int i = 0; i < MAXSIZE; ++i)
		if (i % 2 == 1)
		{	x = MAXSIZE - i;
			while(x -- ){
				for (int j = i; j < MAXSIZE; ++j)
				{
					arr[j] = arr[j + 1];
				}
			}
		}
}

int main(int argc, char const *argv[])
{	int arr[MAXSIZE];
	printf("Enter the %d elements\n", MAXSIZE);
	for (int i = 0; i < MAXSIZE; ++i)
		scanf("%d", &arr[i]);
	delete_even_pos(arr);
	for (int i = 0; i < MAXSIZE; ++i)
		printf("%d\n",arr[i]);
	return 0;
}