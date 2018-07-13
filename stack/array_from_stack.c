#include <stdio.h> 

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0


//{% start custom %}

typedef  struct{
	int top; 
	int ele[MAXSIZE];
}STACK;

STACK s1, s2; 

int isEmpty(STACK *s){
	return (s -> top == -1); 
}

int pop (STACK *s, int *underflow){
	if(isEmpty(s))
		*underflow = TRUE;	
	*underflow = FALSE;
	return (s -> ele[s -> top --]);
}

void push(STACK *s,int val ,int  *overflow){
	if(s -> top == MAXSIZE - 1){
		*overflow = TRUE;
	}
		*overflow = FALSE;
	s -> top += 1;
	s->ele[s->top] = val;  
}

int initializeStack(STACK *s, int *overflow, int value){
	s -> top = -1;
	for (int i = 0; i < MAXSIZE; ++i)
	{
		push(s, value , overflow);
	}
}

int peek(STACK *s, int *underflow, int *overflow){
	int temp;
	temp = pop(s, underflow);
	push(s, temp, overflow);
	return temp;
}

int get_stack_top_pos(STACK *s){
	return s->top;
}

int emptyTheStack(STACK *s, int *underflow){
	while(!isEmpty(s))
	printf("\n%d\n", pop(s, underflow));	 
}

//{% end custom %}

//{code for array operations}

void add_to_array_index(STACK *s1, STACK *s2, int val, int pos, int *underflow, int *overflow){
	if (pos == get_stack_top_pos(s1) + 1)
	{
		push(s1, val, overflow);
	}
	else{
		while(pos != get_stack_top_pos(s1) + 1){
			int temp;
			temp = pop(s1, underflow);
			push(s2, temp, overflow);
		}
		pop(s2, underflow);
		pop(s1, underflow);
		push(s1, val, overflow);

		while(get_stack_top_pos(s2) != 0){
			int temp; 
			temp = pop(s2, underflow);
			push(s1, temp, overflow);
		}

	}
}

int main(int argc, char const *argv[])
{	

	int overflow;
	int underflow;

	int temp_pos;
	int temp_num;

	while(!underflow || !overflow){
	initializeStack(&s1, &overflow, 1);
	initializeStack(&s2, &overflow, 2);
	
	//Adding to the array
	printf("Please enter the position\n");
	scanf("%d", &temp_pos);

	printf("Please enter the number\n");
	scanf("%d", &temp_num);

	add_to_array_index(&s1, &s2, temp_num, temp_pos, &underflow, &overflow);

	emptyTheStack(&s1, &underflow);
	
	}

	if (underflow || overflow)
	{
		printf("\nEither underflow or overflow has occured .....\n");
	}

	return 0;
}
