#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int priority;
	struct node *next;
}Node; 

Node *newNode(int data, int priority){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp -> data = data;
	temp -> priority = priority;
	temp -> next = NULL;
	return temp;
}

int peek(Node ** head){
	return (*head) -> data;
}

void pop(Node ** head){
	Node *temp = *head;
	(*head) = (*head) -> next;
	free(temp);
}

void push(Node **head, int data, int priority){
	Node *temp = newNode(data, priority);
	Node *start = *head;

	
	/*
	Element to be inserted has the priority less than the head
	*/
	if ((*head) -> priority > priority){
		temp -> next = (*head);
		(*head) = temp;
	}

	else
	{
		while(start -> next != NULL && start -> next -> priority < priority)
			start = start -> next;

		temp -> next = start -> next;
		start -> next = temp;
	}
}

int isEmpty(Node **head){
	return (*head) == NULL;
}

int main()
{
    // Create a Priority Queue
    // 7->4->5->6
   	Node *p = newNode(12,13);
   	for (int i = 0; i < 1000; ++i)
   	{
   		push(&p,i,i%30);
   	}
    while (!isEmpty(&p)) {
        printf("%d ", peek(&p));
        pop(&p);
    }

    free(p);
 
    return 0;
}