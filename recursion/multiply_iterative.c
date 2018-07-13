#include <stdio.h>

int multiply(int a, int b){
	int c = 0;
	for(int i = 0; i < b; i++)
		c+=a ;
return c;
}
int main(){
	printf("%d", multiply(10,9));
return 0;
}
