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

int getCount(Node *root){
	int count = 0;
	if (root == NULL)
		return 0;
	queue <Node *> q;
	q.push(root);

	while(!q.empty()){
		Node *temp = q.front();
		q.pop();

		if (temp -> left && temp -> right)
			count ++;
		if (temp -> left)
			q.push(temp -> left);
		if (temp -> right)
			q.push(temp -> right);
	}
	return count;
}

void make_bin_tree(Node *root, int data){
	Node *newNode = getNode(data);
	Node *temp = root;
	if (root == NULL)
		root = newNode;
	else{
		if(temp -> data > data){
			make_bin_tree(temp -> left, data);
		}
		if(temp -> data <= data){
			make_bin_tree(temp -> right, data);
		}	
	}
}

int main(int argc, char const *argv[])
{	int size, temp;
	/*cout << "Enter the no of elements" << endl;
	cin >> size;
	cout << "Enter " << size << " elements" << endl;
	for (int i = 0; i < size; ++i)
	{
			cin >> temp;
			make_bin_tree(root, temp);
	}*/

	
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
	cout << "The count is:- " << getCount(root) << endl;
	return 0;
}