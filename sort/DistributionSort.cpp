#include <iostream>

using namespace std; 

class DistributionSort{
public:
    DistributionSort(int arr[], int a , int b, int size){
        int size_sorted = (b - a + 1);
        int size_arr = size;
        int sorted[size_sorted]; 
        
        for(int i = 0; i < size_sorted; i++)
            sorted[i] = 0;
        
        for(int i = 0; i < size_arr; i++){
            if(arr[i] > a && arr[i] < b){
                int pos = arr[i] % size_sorted;
                sorted[pos] += 1;
            }
        }
        
        for(int i = 0; i < size_sorted; i++){
            if(sorted[i] == 0){
                
            }
            else{
                for(int j = 0; j < sorted[i]; j++){
                    cout << i + a << " ";
                }
            }
        }
    }
};




int main(){
    int arr[] = {1,6,6,6,4,4,1,1,2,2,9,8};
    int a = 0; 
    int b = 10;
    int size = sizeof(arr)/sizeof(arr[0]);
    DistributionSort d(arr, a, b, size);
    return 0;
}