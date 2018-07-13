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

void enQueue(Node **front, Node **rear, int data){
	Node *newNode = getNode(data);
	Node *front_temp = (*front);
	Node *rear_temp = (*rear);
		if (front_temp == NULL && rear_temp == NULL)
				front_temp = rear_temp = newNode;
		else{
			rear_temp -> next = newNode;
			newNode -> prev = rear_temp;
			(*rear) = newNode; 
		}
		
		free(front_temp);
		free(rear_temp);
}


int deQueue(Node **front, Node **rear){
	Node *front_temp = (*front);
	Node *rear_temp = (*rear);
	int val = 1;
		if (front_temp == NULL && rear_temp == NULL){
			printf("Underflow\n");
			return val;
		}

		else if (front_temp != NULL && rear_temp != NULL)
		{
			val  =  front_temp -> data;
			front_temp = front_temp -> next;
			(*front) = front_temp;
			return val;
		}

		else{
			printf("Chutiya kat gaya hai\n");
			return -1;
		}

		free(front_temp);
		free(rear_temp);
}

void print_queue(Node **front, Node **rear){
	Node *temp = (*front);
		while(temp != *rear){
			printf("%d", temp -> data);
			temp = temp -> next;
		}
}

int main(int argc, char const *argv[])
{
	Node *front = NULL;
	Node *rear = NULL;
	for (int i = 0; i < 100; ++i)
			enQueue(&front, &rear,i);
	print_queue(&front, &rear);
	return 0;
}