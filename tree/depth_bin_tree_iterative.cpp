#include <queue>
#include <iostream>

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


int max(int a, int b){
	return (a > b) ? a : b;
}

int getDepth(Node *root){
	int depth = -1;
	if (root == NULL)
		return 0;
	queue<Node *>q;
	q.push(root);
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		if (temp -> right)
		{
			q.push(temp -> right);
			depth ++;
		}
		else if(temp -> left){
			q.push(temp -> left);
			depth ++;
		}
	}
	return depth;
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