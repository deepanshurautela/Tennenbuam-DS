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

		void push(Node **head, Node **tail, int data){
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

		void print_all(Node *head){
			Node *temp = head;
				printf("\n");
				while(temp != NULL){
					printf("%d\n",temp->data);
					temp = temp -> next;
				}
		}

		Node *search_for_val(Node **head, int x){
			Node *temp = (*head);
			if(temp == NULL)
				return 0;
			else{
				//Will not work without the break 
				while(temp -> data != x && temp -> next!= NULL){
					temp = temp -> next;
					if (temp -> next == NULL){
						temp = NULL;
						break;
					}
				}
				return temp;
			}
		}

		Node *searchinsrt(Node **head, int x){
			Node *newNode = getNode(x);
			Node *temp = (*head);
			if(temp == NULL)
				return 0;
			else{
				//Will not work without the break 
				while(temp -> data != x && temp -> next!= NULL){
					temp = temp -> next;
					if (temp -> next == NULL){
						temp  -> next = newNode;
						return newNode;
					}
				}
				return temp;
				
		}
	}


		int main(int argc, char const *argv[])
		{	
			Node *val1 = NULL;
			Node *val2 = NULL;
			Node *head = NULL;
			Node *tail = NULL;
			for (int i = 0; i < 10; ++i)
				push(&head, &tail,i);
			print_all(head);
			val1 = search_for_val(&head, 2);
				if (val1)
					printf("The value of val is %d and is at address %p\n", val1 -> data, val1);
				else
					printf("The value searched for doesn't exist\n");
			val2 = searchinsrt(&head, 30);
				if (val2)
					printf("The value of val is %d and is at address %p\n", val2 -> data, val2);
				else
					printf("The value searched for doesn't exist\n");
			print_all(head);

			return 0;
		}