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
	Node *newNode = getNode(data); //Changed to correct pointers
	Node *temp = (*head);
	if (temp == NULL){
			*head = newNode;
		}
	
	else{	

		while(temp -> next != NULL) //Added this later. Thought that use only tail but each requires to set tail. 
				temp = temp -> next;
			temp -> next = newNode;
			newNode -> prev = temp;
			*tail = newNode;

	}
}

void push_left(Node **head, Node **tail, int data){
	Node *newNode = getNode(data); //Changed to correct pointers
	Node *temp = (*head);
	if (temp == NULL)
			*head = newNode;
	
	else{

		newNode -> next = temp;
		newNode -> prev = NULL;
		(*head) = newNode;

	}
}

void remove_right(Node **head, Node **tail, int *val)   // modified This function.
{
    Node *temp = (*tail);
    if (temp == NULL)
    {
        printf("Cannot be removed doesn't point to anything\n");
        return;
    }

    else
    {
        *val = temp->data;
        temp->prev->next = NULL;
        (*tail) = temp->prev;
    }
    free(temp);
}

void remove_left(Node **head, Node **tail, int *val)   // modified This function.
{
    Node *temp = (*head);
    if (temp == NULL)
    {
        printf("Cannot be removed doesn't point to anything\n");
        return;
    }

    else
    {
        *val = temp->data;
        temp->next->prev = NULL;
        (*head) = temp->next;
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
{	int ival = -1;
	int rval = -2;
	Node *head = NULL;
	Node *tail = NULL;
	for (int i = 0; i < 10; ++i){
		push_right(&head, &tail,i);
		push_left(&head, &tail,i);
	}
	remove_left(&head, &tail, &ival);
	printf("%d was removed\n",ival);
	remove_right(&head, &tail, &rval);
	remove_right(&head, &tail, &rval);
	printf("%d was removed\n",rval);
	print_all(head);
	return 0;
}