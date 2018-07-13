#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 100


void readstr(char*, int);
char getsymb(char*, int, int*);
int expr(char*, int, int*){




int main(int argc, char const *argv[])
{
	char str[MAXSIZE];
	int pos = 0, length;

	printf("Enter the size of the array\n");
	scanf("%d", &length);
	readstr(str,length);

	if ()

	return 0;
}

void readstr(char* str, int length){
	for (int i = 0; i < length; ++i)
		scanf("%d", &str[i]);
}

char getsymb(char* str, int length, int* pos){
	char c;
	if (length > *pos)
		c = str[*pos]
	else
		c = ' '
		(*pos)++;
		return c;
}

int expr(char *arr, int length, int *pos){
	
}