#include <queue>
#include <iostream>

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
	//If empty tree
	if (root == NULL)
		return true;
	
/*	if(root->left == NULL || root -> right == NULL)
		cout << "Not strictly binary" << endl;

	was thinking this condition to check for subtrees
*/

	//If right and left child present 
	//Check whether they are strictly binary or not
	if ((root -> right) && (root -> left))
		return(strictly_binary(root -> left) && strictly_binary(root -> right));

	//If leaf node
	if(root->left == NULL && root -> right == NULL)
		return true;

	//If none of the condtions apply 
	return false;
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
    root->right->right->left->right = getNode(4);
    if(strictly_binary(root))
    	cout << "strictly binary" << endl;
    else
    	cout << "not strictly binary" << endl;

}