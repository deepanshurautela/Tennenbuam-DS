#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

int count = 0;

Node *getNode(int data){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp -> data = data;
	temp -> next = NULL;
	return temp;
}

void enQueue(Node **head, int data){
	Node *newNode = getNode(data);
	Node *temp = (*head);

	if ((*head) == NULL){
		(*head) = newNode;
	}
	//Didn't get this one correct the first time
	else
	{
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = newNode;
	}
}

void print_all(Node **head){
	Node *temp = (*head);
		if (temp == NULL)
		{
			printf("There is nothing to show!\n");
			return;
		}
	while(temp != NULL){
		printf("%d\n", temp -> data);
		temp =  temp -> next;
	}
}

void swap(Node *a,Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubble_sort(Node **head){
	Node *start = *head;
	Node *aux = NULL;
	int swapped;

	if (start == NULL)
		return;

	do{
		swapped = 0;
		start = (*head);
		while(start ->next != aux){
			if (start -> data > start->next->data )
			{
				swap(start, start -> next);
				swapped = 1;
			}
			start = start -> next;
		}
		aux = start;
	}while(swapped);
}


int main(int argc, char const *argv[])
{
	Node *head = NULL;
	enQueue(&head, 40);
	enQueue(&head, 10);
	enQueue(&head, 20);
	bubble_sort(&head);
	print_all(&head);
	return 0;
}
