#include <iostream>

using namespace std;

typedef struct node{
	struct node *left, *right;
	int data;
}Node;

Node *getNode(int data){
	Node *newNode = new Node;
	newNode -> right = newNode -> left = NULL;
	newNode -> data = data;
	return newNode;
}


void preorder(Node *root){
	if(root != NULL){
		cout << "\n" << root -> data << endl;
		preorder(root -> left);
		preorder(root -> right);
	}
}

void inorder(Node *root){
	if(root != NULL){
		inorder(root -> left);
		cout << "\n" << root -> data << endl;
		inorder(root -> right);
	}
}

void postorder(Node *root){
	if(root != NULL){
		postorder(root -> left);
		postorder(root -> right);
		cout << "\n" << root -> data << endl;
	}
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
    cout << "Inorder\n" << endl;
    inorder(root);
    cout << "Postorder\n" << endl;
    postorder(root);
    cout << "Preorder\n" << endl;
    preorder(root);
	return 0;
}