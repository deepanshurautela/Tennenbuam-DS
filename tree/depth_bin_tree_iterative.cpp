#include <queue>
#include <iostream>

using namespace std;

typedef struct node{
	int data;
	struct node *left, *right;
}Node;

typedef struct q_n{
	Node *node;
	int level;
}queue_node;

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
	//Fringe Case 
	if(root == NULL)
		return 0;

	queue<queue_node> qi;
	
	//Adding root to the queue
	queue_node q = {root, 1};
	qi.push(q);

	while(!qi.empty())
	{
		q = qi.front();		//Storing and poping the queue front 
		qi.pop();

		Node *node= q.node;		
		int level = q.level;	//Getting level of that queue front 

		if(node->left == NULL && node->right == NULL) //if no subtree, then must be leaf node 
			//This will hit eventually thats why return 0, save from warnings
			return level;	//returning the max depth

		if (node -> left)		//if node has left subtree 
		{
			q.node = node -> left; //increasing the depth and pushing it to the queue
			q.level = level + 1;
			qi.push(q);
		}
	
		if (node -> right)
		{
			q.node = node -> right;	
			q.level = level + 1;
			qi.push(q);
		}
	}
	return 0;
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