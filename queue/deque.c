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

void push_back(Node **head, Node **tail, int data){
	Node *newNode = getNode(data);
	Node *temp = (*head);
	if (temp == NULL){
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

void push_forward(Node **head, Node **tail, int data){
	Node *newNode = getNode(data);
	Node *temp = (*head);
	if (temp == NULL){
			*head = newNode;
		}
	
	else{

		newNode -> next = temp;
		newNode -> prev = NULL;
		(*head) = newNode;

	}
}

void print_all(Node *head){
	Node *temp = head;
		printf("\n");
		while(temp != NULL){
			printf("%d\n",temp->data);
			temp = temp -> next;
		}
}


int main(int argc, char const *argv[])
{
	Node *head = NULL;
	Node *tail = NULL;
	for (int i = 0; i < 10; ++i){
		push_back(&head, &tail,i);
		push_forward(&head, &tail,i);
	}
	print_all(head);
	return 0;
}