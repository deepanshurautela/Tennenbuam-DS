//Q. 4.3.9 (b) Tennenbuam

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 1024 * 1024

typedef struct node{
	char c; 
	struct node *next;
	struct node *prev;
}Node;


Node* getNode(char c){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode -> next = newNode -> prev = NULL;
	newNode -> c = c;
	return newNode;		
}


void add_to_list(Node **head, char c){
	if (c != ' ') // To remove white spaces
	{
		Node *temp = (*head);
		Node *newNode = getNode(c);
			if (temp == NULL)
			(*head) = newNode;
				else
				{
					while(temp -> next != NULL)
						temp = temp -> next;
					temp -> next = newNode;
				}
	}
}

void print_all(Node *head){
	Node *temp = head;
		while(temp)
		{
			printf("%c ----- ",temp -> c);
			temp = temp -> next;
		}
		printf("\n");
}


char *convert_form_list_to_string(Node **head){
	int count = 0;
	int alloc_size;

	char *error = (char *)malloc(sizeof(char));
	*error = 'e';
	Node *temp = (*head);

	if (temp == NULL){
		printf("Nothing in the list\n");
		return error;
	}

	while(temp!= NULL){
		count ++;
		temp = temp -> next;
	}

	alloc_size = sizeof(char) * count;

	char *str = (char *)malloc(sizeof(alloc_size));

	for (int i = 0; i < count; ++i)
	{
			str[i] = temp -> c;
			temp = temp -> next;
	}

	return str;

}



int main(int argc, char const *argv[])
{
	Node *head = NULL;
	char str[MAXSIZE];
	printf("Enter the string:\n");
	fgets(str, MAXSIZE, stdin);
	for (int i = 0; i < strlen(str); ++i)
		add_to_list(&head, str[i]);
	print_all(head);
	printf("%s\n",convert_form_list_to_string(&head));
	return 0;
}