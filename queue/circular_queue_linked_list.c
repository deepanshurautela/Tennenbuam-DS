//Tennenbuam

#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 1024 * 1024

typedef struct node{
	char *name;
	struct node *next;
}Node;

Node *getNode(char *name){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode -> name = name;
	newNode -> next = NULL;
	return newNode;
}

void enQueue(Node **last, char *name){
	Node *newNodeTemp = getNode(name);
	Node *temp = (*last);

	if ((*last) == NULL)
	{
		newNodeTemp -> next = newNodeTemp;
		(*last) = newNodeTemp;
	}

	else{
		newNodeTemp -> next = temp -> next;
		temp -> next = newNodeTemp;
		(*last) = newNodeTemp;
	}
}

void printall(Node *last){
	Node *temp = last;
		while(temp -> next != temp)
			printf("%s\n",temp -> name);
}

int main(int argc, char const *argv[])
{	char buf[MAXSIZE];
	Node *head = NULL;
	for (int i = 0; i < 2; ++i)
	{
		printf("Enter a name:- \n");
		fgets(buf, MAXSIZE, stdin);
		enQueue(&head, buf);
	}
	printall(head);
	return 0;
}