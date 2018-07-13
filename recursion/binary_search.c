#include <stdio.h>

int binary_search(int *array, int high, int low, int search_num){
   int mid;
   
   if(low > high){
      return -1;
   }

   mid = (high + low) / 2;

   if (search_num == array[mid])
   {
      return mid + 1;
   }

   if (search_num > array[mid]){
      return binary_search(array, high, mid + 1, search_num);
   }
   
   else{
      return binary_search(array, mid - 1, low, search_num);
   }
}

int main(int argc, char const *argv[])
{
   int num[] = {1,2,3,4,5,6,7,8,9,10};
   int pos; 
   int search_num;

   int low = 0;
   int high = (sizeof(num)/sizeof(num[0]));
   
   printf("Enter the number to search for\n");
   scanf("%d", &search_num);
   pos = binary_search(num,high,low,search_num);
   if (pos != -1)
      printf("The postion of %d is %d\n", search_num, pos);
   else
      printf("The number couldn't be found\n");

   return 0;
}