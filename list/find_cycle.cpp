#include <iostream>
#include <unordered_set>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *getNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

void push(Node **head, int data){
	Node *newNode = getNode(data);
	Node *temp = (*head);
		if (*head == NULL)
			(*head) = newNode;
		else{
			while(temp -> next != NULL)
				temp = temp -> next;
			temp -> next = newNode;
		}
}


void print_nodes(Node *head){
	Node *temp = head;
		while(temp -> next!= head){
			cout << temp -> data << endl;
			temp = temp -> next;
		}
		cout << temp -> data << endl;
}

bool detect_loop(Node *head){
	Node *temp = head;
	unordered_set<Node *> nodes;
		while(temp!= NULL){
			if (nodes.find(temp) != nodes.end())
				return true;
			nodes.insert(temp);
			temp = temp -> next;
		}
		return false;
}

int main(){
	Node *head = NULL;
	push(&head, 20);
	push(&head, 20);
	push(&head, 20);
	push(&head, 20);
	push(&head, 20);
	//Why commenting below causes segmentation fault
	head -> next -> next -> next -> next = head;
	if (detect_loop(head))
		cout << "Loop present" << endl;
	else
		cout << "Loop not present" << endl;
	print_nodes(head);	
	return 0;
}
