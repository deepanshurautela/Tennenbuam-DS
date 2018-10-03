#include <iostream>
#include <stack>
#define SUB_ARRAY_SIZE 3

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

void BubbleSort(int a[], int start, int end){
    std::cout << "Bubble Sort called " << std::endl;
    if(start >= end){
        return;
    }
    if(a[start] >= a[start + 1]){
        swap(&a[start], &a[start + 1]);
    }
    BubbleSort(a, start+1, end);
}

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = (low - 1); 
    
    for(int j = 0; j <= high -1; j++){
        if(a[j] <= pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    
    return(i+1);
}

void quicksort(int a[], int low, int high){
    if(high > low){
        std::cout << "Quick Sort called " << std::endl;
        if(high - low + 1 <= SUB_ARRAY_SIZE){
            BubbleSort(a, low, high);
        }
        else{
            int p = partition(a, low, high);
            quicksort(a, low, p - 1);
            quicksort(a, p + 1, high);
        }
    }
}



void PrintAll(int a[], int size){
    for(int i = 0; i < size; i++){
        std::cout << a[i] << " ";
    }
}

int main(){
    int arr[] = {3,2,1,2,4,100,11,45,66};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, size -1);
    PrintAll(arr, size);
    return 0;
}
