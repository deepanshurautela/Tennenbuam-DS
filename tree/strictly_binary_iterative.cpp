#include <iostream>
#include <queue>

using namespace std;	

typedef struct node{
	struct node *left, *right;
	int data;
}Node;


Node *getNode(int data){
	Node *newNode = new Node;
	newNode -> left = newNode -> right = NULL;
	newNode -> data = data;
	return newNode;
}

bool strictly_binary(Node *root){
	if (root == NULL)	//Null tree always binary
		return false;
	queue<Node *>q;
	q.push(root); //To begin with root 

	while(!q.empty()){
		Node *temp = q.front();
		q.pop();	

		//Tried using ^ for XOR, but wont work with pointers
		if(((!temp->left) && (!temp->right)) || ((temp -> left) && (temp -> right))){
			if(temp -> left == NULL) // right and left are null, reached leaf node 
				return true;
			else{
				q.push(temp -> left);	//have both right and left, pushing left and right
				q.push(temp -> right);
				}
		}
	}
	return false; 	//If if condition not satisfied 
				  	//Ex:- node -> right exists but node -> left = null 
}

void print_status(Node *root){
	if(strictly_binary(root))
		cout << "Strictly binary " << endl;
	else
		cout << "Not strictly binary " << endl;
}

int main(int argc, char const *argv[])
{	int size, temp;
	Node *root = getNode(2);
	root->left     = getNode(7);
    root->right     = getNode(5);
    root->left->right = getNode(6);
    root->left->right->left = getNode(1);
    root->left->right->right = getNode(11);
    root->right->right = getNode(9);
    root->right->right->left = getNode(4);
    print_status(root);
	return 0;
}