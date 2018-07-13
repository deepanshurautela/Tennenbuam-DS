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

void push_right(Node **head, Node **tail, int data){
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

void push_left(Node **head, Node **tail, int data){
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

void remove_right(Node **head, Node **tail, int *val){
	Node *temp = (*tail);
	if (temp == NULL)
	{
		printf("Cannot be removed doesn't point to anything\n");
		return;
	}

	else{
		*val = temp -> data;
		temp = temp -> prev;
		(*tail) = temp;
	}
	free(temp);

}

void remove_left(Node **head, Node **tail, int *val){
	Node *temp = (*head);
	if (temp == NULL)
	{
		printf("Cannot be removed doesn't point to anything\n");
		return;
	}

	else{
		*val = temp -> data;
		temp = temp -> next;
		(*tail) = temp;
	}
	free(temp);
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
{	int *val = NULL;
	Node *head = NULL;
	Node *tail = NULL;
	for (int i = 0; i < 10; ++i){
		push_right(&head, &tail,i);
		push_left(&head, &tail,i);
	}
	remove_left(&head, &tail, val);
	print_all(head);
	return 0;
}