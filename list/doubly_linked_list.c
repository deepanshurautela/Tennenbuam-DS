#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}Node;

Node *getNode(int data){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp -> next = temp -> prev = NULL;
	temp -> data = data;
	return temp;
}

void push(Node **head, Node **tail, int data){
	Node *newNode = getNode(data);
	Node *temp = (*head);
	if (temp == NULL){
			printf("Heas is null\n");
			*head = newNode;
		}
	
	else{
			while(temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> next = newNode;
			newNode -> prev = temp;
			*tail = newNode;

	}
}


void traverse_back(Node *tail){
	Node *temp = tail;
		while(temp != NULL){
			printf("%d\n", temp -> data);
			temp = temp -> prev;
		}
}

void traverse_forward(Node *head){
	Node *temp = head;
		while(temp!= NULL){
			printf("%d\n", temp -> data);
			temp = temp -> next;
		}
}

int main(int argc, char const *argv[])
{
	Node *head = NULL;
	Node *tail = NULL;
	for (int i = 0; i < 10; ++i)
		push(&head, &tail, rand());
	printf("\nForward\n");
	traverse_forward(head);
	printf("\nBackward\n");
	traverse_back(tail);
	return 0;
}