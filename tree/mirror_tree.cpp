#include <iostream>

using namespace std;

class Node{
public:
	Node *left, *right;
	int data;

	Node(){
		left = right = nullptr;
	}

	Node(int data){
		left = right = nullptr;
		this -> data = data;
	}
};

void inorder(Node* root){
	if(root != NULL){
		inorder(root -> left);
		cout << root -> data << endl;
		inorder(root -> right);
	}
}


void interchange(Node *a, Node *b){
	Node *temp = b;
	if(a && b){
		b = a;
		a = temp;
	}
	delete temp;
}

void mirror_tree(Node *root){
	if(!root)
		return;

	else
			interchange(root -> right, root -> left);
			mirror_tree(root -> right);
			mirror_tree(root -> left);
}


int main(int argc, char const *argv[])
{	Node *mirror = NULL;
	Node *root = 				new Node(2);
	root->left = 				new Node(7);
    root->right	=	 			new Node(5);
    cout << "\nBefore inorder traversal" << endl; 
    inorder(root);
    mirror_tree(root);
    cout << "\nAfter inorder traversal" << endl; 
    inorder(root);
	return 0;
}