#include <queue>
#include <iostream>
#define MIN 0
#define MAX 1

using namespace std;

typedef struct node{
	int data;
	struct node *left, *right;
}Node;

Node *getNode(int data){
	Node *newNode = new Node;
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}


int min_max(int a, int b, int op){
	if (op == MIN)
		return (a > b) ? b : a;
	if (op == MAX)
		return (a > b) ? a : b;		 
	else
		exit(0);
}

int getDepth(Node *root){
	//Assuming root height be 1
	//Corner Case
	if (root == NULL)
		return 0;
	//If this this is leaf node
	if (!(root -> left) && !(root -> right))
		return 1; //returning 1 and not 0 because checking roots subtree

	if(!root->left)	//check the right subtree
		return getDepth(root -> right) + 1;

	if(!root->right)//check left subtree
		return getDepth(root -> left) + 1;
	
	return min_max(getDepth(root -> right), getDepth(root -> left), MAX) + 1;
}

int main(int argc, char const *argv[])
{	int size, temp;


	/*Node *root = NULL;
	root -> data = 12; #This wont won't work since no memory alloc #*/
	Node *root = getNode(2);
	root->left     = getNode(7);
    root->right     = getNode(5);
    root->left->right = getNode(6);
    root->left->right->left = getNode(1);
    root->left->right->right = getNode(11);
    root->right->right = getNode(9);
    root->right->right->left = getNode(4);
    root->right->right->left->right = getNode(4);
	cout << "The depth is:- " << getDepth(root) << endl;
	return 0;
}