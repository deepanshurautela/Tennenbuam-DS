#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}Node;


Node *getNode(int data){
	Node *newNode = (Node *)malloc(sizeof(newNode));
	newNode -> data = data;
	newNode -> next = newNode -> prev = NULL;
	return newNode;
}

void push(Node **head, int data){
	Node *newNode = getNode(data);
	Node *temp = (*head);

	if (temp == NULL)
		(*head) = newNode;
	else{
		newNode -> next = (*head);
		(*head) = newNode;
	}
	free(temp);
}

int pop(Node **head){
	Node *temp = (*head);
	if (temp == NULL)
	{
		printf("Underflow\n");
		return -1;
	}
	else{
		(*head) = temp -> next;
		return temp -> data;
	}
	free(temp);
}

void printall(Node *head){
	Node *temp = head;
		while(temp -> next!= NULL){
			printf("%d\n",temp -> data);
			temp = temp -> next;
		}
}

int main(int argc, char const *argv[])
{	int op, val;
	Node *head = NULL;
	while(1){
		printf("1.Enter an element\n2.Pop an element\n3.View the stack\n\n");
		scanf("%d", &op);
		switch(op){
			case 1: printf("Enter a number\n");
					scanf("%d", &val);
					push(&head, val);
					printf("%d added succesfully\n",val);
					break;
			case 2: printf("%d popped from the stack\n",pop(&head));
					break;
			case 3:	printall(head);
					break;

			default: printf("Wrong option\n");
					 break;
		}
	}
	return 0;
}
