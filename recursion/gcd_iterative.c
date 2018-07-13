#include <stdio.h>

/*
Conditions:
	gcd(x,y) = y			if ((y <=x ) && (x % y == 0))
	gcd(x,y) = gcd(y,x)		if (x < y)
	gcd(x,y) = gcd(y, x%y)	otherwise
*/



int gcd(int x,int y){
	if (x < y)
	{	//gcd(x,y) = gcd(y,x)  if (x < y)
		int temp;
		temp = y;
		y = x;
		x = temp;
	}
	//Here always  x > y
	//Never using third condition 
	//Its always the otherwise condition that causes recursion 
	//Since no other condtion meets, so will call itself in recursion 
	while(!(y <= x && x%y == 0)){
		int temp;
		temp = x;
		x = y;
		y = temp % y;
	}
	return y;
}

int main(int argc, char const *argv[])
{
	printf("%d\n",gcd(19,17));
	return 0;
}