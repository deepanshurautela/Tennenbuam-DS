#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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


void pop(Node **head, Node **node_to_del){
	Node *temp = (*head);
		if ((*head) == NULL)
			return;
		while(temp -> next -> next != NULL && temp -> next != (*node_to_del))
			temp = temp -> next;
		temp -> next = temp -> next -> next;
}


int genarate_random_num(int range){
	time_t t;
	srand((unsigned) time(&t));
	return (rand() % range);
}

void print_all(Node *head){
	Node* temp = head;
		while(temp -> next!= head){
			printf("\n%s\n",temp -> name);
			temp = temp -> next;
		}
	}


char *get_random_string(int length){
	static int mySeed = 25011984;
	//char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!@&*()@#$#!@#$#";
	char *string = "Deepanshu";
	size_t stringLen = strlen(string);
	char *random_string = random_string = malloc(sizeof(char) * (length + 1));

	srand(time(NULL) * length + ++mySeed);

	if (length < 1)
		length = 1;

	if (random_string)
	{
		short key = 0;
		for (int i = 0; i < length; ++i)
		{
			key = rand() % stringLen;
			random_string[i] = string[key];
		}
		random_string[length] = '\0';
		return random_string;
	}

	else
		return NULL;

}

void josephus(Node **head, int size){
	int random_num = genarate_random_num(size);
	printf("Random number is %d\n",random_num);
	Node *last = NULL;
	Node *temp = (*head);
	Node *temp2 = NULL; 
		if (*head == NULL)
			return;
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = (*head);		//Joining to head to make it circular 
		temp = temp -> next;       //Setting to head
		while(temp -> next != NULL){
			for (int i = 1; i < random_num; ++i)
				temp = temp -> next;
				printf("Bye Bye %s\n",temp -> next -> name);
				temp -> next = temp -> next -> next;
				if(temp -> next == temp)			//Single Node only left
					break;
		}
		printf("You are going to party %s\n",temp -> name);										
}

int main(int argc, char const *argv[])
{
	Node *head = NULL;
	for (int i = 0; i < 10; ++i)
	{
		enQueue(&head, get_random_string(1));
	}
	//Before Josephus
	printf("Before Josephus\n");
	//print_all(head);
	josephus(&head, 10);
	printf("\n\n\n");
	return 0;	
}