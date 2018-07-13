#include <stdio.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct{
	int head_even;
	int head_odd; 
	int element[MAXSIZE];
	int current_pos_even;
	int current_pos_odd;
}STACK;

STACK s1;

int initialize(STACK *s){
	s -> head_even = s -> head_odd = -1;
	s -> current_pos_even = 0;
	s -> current_pos_odd = 1; 
	for (int i = 0; i < MAXSIZE; ++i)
	{
		s -> element[i++] = 0;
	}
}

void print_combined_stack(STACK *s){
	int last_count = (s->current_pos_even > s-> current_pos_odd) ? s->current_pos_even : s->current_pos_odd;
	for (int i = 0; i < last_count; ++i)
	{
		printf("\n%d",s->element[i]);
	}
}

void push_even(STACK *s, int value, int *overflow){
	if (s -> head_even > MAXSIZE)
		*overflow = TRUE;
	*overflow = FALSE;
	s -> element[ s-> current_pos_even + 2] = value;
	s -> head_even += 1;
}

void push_odd(STACK *s, int value, int *overflow){
	if (s -> head_odd > MAXSIZE)
		*overflow = TRUE;
	*overflow = FALSE;
	s -> element[ s-> current_pos_odd + 2] = value;
	s -> head_odd += 1;
}

int pop_even(STACK *s, int *underflow){
	int temp;
	if (s -> head_even <= 0)
		*underflow = TRUE;
	*underflow = FALSE;
	temp = s -> element[ s-> head_even ];
	s-> head_even -= 2; 
	return temp;
}

int pop_odd(STACK *s, int *underflow){
	int temp;
	if (s -> head_even <= 1)
		*underflow = TRUE;
	*underflow = FALSE;
	temp = s -> element[ s-> head_even ];
	s-> head_even -= 2;
	return temp; 
}


int main(int argc, char const *argv[])
{
	STACK s1;
	int underflow = FALSE, overflow = FALSE;
	int temp_input;
		initialize(&s1);
		push_odd(&s1, 10, &overflow);
		push_even(&s1, 11, &underflow);
		print_combined_stack(&s1);
	return 0;
}


