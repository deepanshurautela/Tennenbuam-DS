#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

/*
STACK OVERFLOW SOL FOR SPLITTING THE STRING INTO TWO

#define MAXLEN 80

int
main(int argc, char *argv[])
{
    char buf[MAXLEN];
    printf("what is the string?: ");
    fgets (buf, MAXLEN, stdin);
    for(int i = 0; i<strlen(buff); i++)
      printf("buff[%d]: %c\n", i, buf[i]);
    return(0);
}

*/


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
	//printf("Char list was called\n");
	Node *newNode = getNode(c);
	Node *temp = (*head);
	if (temp == NULL){
			(*head) = newNode;
			//printf("Just set null node to new node containing %c\n", newNode -> a);
	}
	else{
		while(temp -> next != NULL && temp -> a != c && c != '\n') //3rd condition so doesn't make node for null char
			temp = temp -> next;
				if (temp -> next == NULL && temp ->a != c){ //Added the second condition otherwise will create nodes for the same alphabet. 
					temp -> next = newNode;
					//printf("Reached the end couldn't find anything. Creating a new node for %c \n", newNode ->a);
					return;
				}
				//printf("Current count of %c is %d\n",temp -> a ,temp -> count);
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
	//char arr[] = {'c','a','a','a','c','c','c','p','g','t','w','g','g','g','g'};
    char buf[MAXLEN];
    printf("what is the string?:\n");
    fgets (buf, MAXLEN, stdin);
    for(int i = 0; i<strlen(buf); i++)
		char_list(&head, buf[i]);
	print_all(head);
	return 0;
}