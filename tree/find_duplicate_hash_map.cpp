#include <iostream>
#include <unordered_set>
#include <iterator>

using namespace std;

typedef struct node{
	struct node *next;
	int data;
}Node;

Node *getNode(int data){
	Node *newNode = new Node;
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

void make_list(Node **head,int data){
	Node *temp = *head;
	Node *newNode = getNode(data);
	if(*head == NULL){
		*head = newNode;
		newNode -> next = newNode;
	}
	else{
			while(temp -> next != *head)
				temp = temp -> next;
			newNode -> next = temp -> next;
			temp -> next = newNode;
	}
}


bool contains_duplicate(Node *head){
	Node *temp = head;
	unordered_set<int>hash_map;
	while(temp -> next != head){
			//The last entry in the hash_map must be the most recent one 
			if(hash_map.find(temp -> data) != hash_map.end()){
				return true;
				break;
			}
			hash_map.insert(temp -> data);
		temp = temp -> next;
	}
	return false;
}

void duplicate(Node *head){
	if(contains_duplicate(head))
		cout << "Contains duplicate " << endl;
	else
		cout << "Doesn't contain duplicate " << endl;
}



int main(int argc, char const *argv[])
{	Node *head = NULL;
	for (int i = 0; i < 1000; ++i)
		make_list(&head, 1);
	duplicate(head);
	return 0;
}