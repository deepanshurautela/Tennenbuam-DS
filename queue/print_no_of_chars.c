#include <stdio.h>
#include <stdlib.h>

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