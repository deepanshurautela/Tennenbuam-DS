#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 1000

//Nice Line - StackOverFlow
//typedef struct string { char x[MAXSIZE]; } string;

typedef struct node{
	struct node *next;
	char *name;
}Node;

Node* getNode(char *name){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode -> next = NULL;
	newNode -> name = name;
	return newNode;
}


void enQueue(Node **head, char* name){
	Node *temp = (*head);
	Node *newNode = getNode(name);
		if ((*head) == NULL)
			(*head) = newNode;
		else{
			while(temp -> next != NULL)
				temp = temp -> next;
			temp -> next = newNode;
		}
}

void pop(Node **head, Node **del_node){
	printf("Pop was called\n");
	Node *temp = (*head);
		if (*head == NULL)
			return;
		while(temp -> next != (*del_node) && temp != NULL){
				printf("Passed %s\n",temp -> name);
				temp = temp -> next;
			}
			temp -> next = temp -> next -> next;
}

void print_all(Node *head){
	Node* temp = head;
		while(temp != NULL){
			printf("%s\n",temp -> name);
			temp = temp -> next;
		}
}


void josephus(Node** head, int size){
	time_t t;
	srand((unsigned) time(&t));
	int random = rand() % size + 1;
	printf("Random number is %d\n",random);
	Node *temp = (*head);
		while(temp -> next != NULL){
		for (int i = 0; i < random; ++i)
			temp = temp -> next;
		printf("Just called pop\n");
		pop(head, &temp);
		if (temp  == NULL)
			temp = (*head);
		}
	}

int main(int argc, char const *argv[])
{
	Node *head = NULL;
	enQueue(&head, "One");
	enQueue(&head, "Two");
	enQueue(&head, "Three");
	enQueue(&head, "Four");
	print_all(head);
	printf("\n\n\n");
	josephus(&head, 4);
	return 0;	
}