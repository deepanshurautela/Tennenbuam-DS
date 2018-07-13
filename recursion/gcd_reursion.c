#include <stdio.h>

/*
Conditions:
	gcd(x,y) = y			if ((y <=x ) && (x % y == 0))
	gcd(x,y) = gcd(y,x)		if (x < y)
	gcd(x,y) = gcd(y, x%y)	otherwise
*/

int gcd(int x,int y){
	if ((y <=x ) && (x % y == 0))
		return y;
	if (x<y)
		return gcd(y,x);
	else
		return gcd(y, x % y);
}


int main(int argc, char const *argv[])
{
	printf("%d\n",gcd(50,113));
	return 0;
}