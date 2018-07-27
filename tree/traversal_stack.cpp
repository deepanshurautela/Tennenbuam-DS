#include <iostream>
#include <stack>

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


void inorder(Node *root){
	stack<Node*>s;
	Node *temp = root;
	do{
		while(temp != NULL){
		s.push(temp);			//Visit the left subtree leftly
		temp = temp -> left;   //At leaf node temp = null and will exit
		}
		if(!s.empty()){
		temp = s.top();
		s.pop();
		cout << temp -> data << endl;
		temp = temp -> right; //Now will move on to the right subtree 
		}
	}while(!s.empty() || temp!= NULL);
}

void postorder(Node *root){
	stack <Node*> s;
	Node *temp = root;

	do{

		while((temp -> left -> right!= NULL) && (temp -> left -> left!= NULL)){ 
			s.push(temp);	//No child nodes
			temp = temp -> left;
		}

		if(!s.empty()){
			temp = s.top();
			s.pop();
		}

	}while();
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
    /*cout << "Postorder\n" << endl;
    postorder(root);
    cout << "Preorder\n" << endl;
    preorder(root);*/
	return 0;
}