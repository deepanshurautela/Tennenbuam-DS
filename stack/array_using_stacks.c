#include <stdio.h>

#ifndef MAXSIZE 
#define MAXSIZE 100
#endif  

#define TRUE 1
#define FALSE 0

typedef struct{
	int top; 
	int ele[MAXSIZE];
}STACK;

int pop(STACK *s, int underflow){
	if (s->top==-1)
		*underflow = TRUE;
	*underflow = FALSE;
	return (s->ele[s->top--]);
}


void push(STACK *s, int val, int overflow){
	if (s->top+1>= MAXSIZE)
		*overflow = TRUE;
	*overflow = FALSE;
	s->ele[s->++top] = val;

}

void initialise(STACK *s){
	s->top = -1;
}

int main(int argc, char const *argv[])
{
	STACK s1;

	static int overflow, underflow;
	
	initialise(&s1);
	push(&s1, 12, &overflow);
	printf("%d\n",pop(&s1, &underflow));

	return 0;
}


