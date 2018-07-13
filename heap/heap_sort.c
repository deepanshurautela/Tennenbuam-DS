#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define SIZE 4	

void swap(int *, int *);
void build_maxheap(int *, int);
void max_heapify(int *, int, int);
void heap_sort(int *);
void print_array(int *, int size);

int main(int argc, char const *argv[])
{
	int arr[MAXSIZE];
	printf("Enter %d numbers \n",SIZE);
	arr[0] = 0;
	for (int i = 1; i <= SIZE; ++i)
		scanf("%d", &arr[i]);
	heap_sort(arr);
	print_array(arr, SIZE);
	return 0;
}

void print_array(int *arr, int size){
	for (int i = 1; i <= size ; ++i)
		printf("%d\n",arr[i]);
}

void swap(int *a, int *b){
	int *temp;
	temp = a;
	a = b;
	b = temp;
}


void max_heapify(int *arr, int i, int N){
	int left = 2 * i;
	int right = 2 * i + 1;
	int largest;

	if (left <= N && arr[left] > arr[i])
		largest = left;
	else
		largest = i;
	if (right <= N && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(&arr[largest], &arr[i]);
		max_heapify(arr, largest, N);
	}
}

void build_maxheap(int *arr, int size){
	int N = size;
	for (int i = N/2; i >= 1 ; i--)
		max_heapify(arr, i, size);
}


void heap_sort(int *arr){
	int heap_size = SIZE;
	build_maxheap(arr, SIZE);
	for (int i = heap_size; i >=2 ; ++i)
	{
		swap(&arr[i], &arr[heap_size]);
		heap_size = heap_size - 1;
		max_heapify(arr, 1, heap_size);
	}
}