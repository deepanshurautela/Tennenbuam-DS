#include <stdio.h>

void fib(int );

int main(int argc, char const *argv[])
{
	int size = 10;
	printf("The fibonnaci series of %d is \n", size);
	fib(size);
	return 0;
}

void fib(int size){
	int lowfib = 0;
	int highfib = 1;
	int temp = 0;
	printf(" %d %d ",lowfib, highfib);
	
	for (int i = 2; i < size ; ++i)
	{
		temp = lowfib;
		lowfib = highfib;
		highfib += temp;
		printf(" %d ",highfib);

	}
}