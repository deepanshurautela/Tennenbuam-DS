#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int count; 
	char a;
	struct node *next;
}Node;

Node *getNode(char c){
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode -> a = c;
	newNode -> count = 1;
	newNode -> next = NULL;
	return newNode;
}

void char_list(Node **head, char c){
	printf("Char list was called\n");
	Node *newNode = getNode(c);
	Node *temp = (*head);
	if (temp == NULL){
			(*head) = newNode;
			printf("Just set null node to new node containing %c\n", newNode -> a);
	}
	else{
		while(temp -> next != NULL && temp -> a != c)
			temp = temp -> next;
				if (temp -> next == NULL && temp ->a != c){ //Added the second condition otherwise will create nodes for the same alphabet. 
					temp -> next = newNode;
					printf("Reached the end couldn't find anything. Creating a new node for %c \n", newNode ->a);
					return;
				}
				printf("Current count of %c is %d\n",temp -> a ,temp -> count);
				temp -> count++;
				free(newNode);
		
	}
}


void print_all(Node *head){
	Node *temp = head;
	if (head == NULL)
	{
		printf("Nothing to show!\n");
		return;
	}
	while(temp != NULL){
		printf("Alphabet :%c Count: %d\n", temp -> a, temp -> count);
		temp = temp -> next;
	}
}


int main(int argc, char const *argv[])
{
	Node *head = NULL;
	char arr[] = {'c','a','a','a','c','c','c','p','g','t','w','g','g','g','g'};
	int size = (sizeof(arr)/sizeof(arr[0]));
	for (int i = 0; i < size; ++i)
	{
		char_list(&head, arr[i]);
	}
	print_all(head);
	return 0;
}