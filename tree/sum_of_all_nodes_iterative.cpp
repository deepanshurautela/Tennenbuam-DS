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

int sum_of_all_nodes(Node *root){
	int count = 0;
	if(root == NULL)
		return 0;
	queue <Node *>q;
	q.push(root);

	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
			count += temp -> data;
		if(temp -> right != NULL){
			q.push(temp -> right);
		}
		if(temp -> left != NULL){
			q.push(temp -> left);
		}
	}
	return count;
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
	cout << "The count is:- " << sum_of_all_nodes(root) << endl;
	return 0;
}