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
/*
An almost complete binary tree is a strictly binary tree. 
Whose leaf nodes are at the max depth or max depth - 1.  
*/

bool almost_complete(Node *root){
	int size = 0;
	Node *temp = NULL;
	queue<Node*>q;
	if(root == NULL)
		return true;
	else{
		//Put the root in the queue
		q.push(root);

		while(!q.empty()){
			//Pop the and insert its child nodes.

			temp = q.front();
			q.pop();

			//It should either have no children (leaf node)
			//Or should have both children (left and right)
			if(((temp -> right) && (temp -> left)) || (!(temp -> right) && !(temp -> left))){
				if(temp -> right){
					q.push(temp -> right);
					q.push(temp -> left);
				}

				//If leaf node of one subtree is encountered.
				//Then we dequeue - check - enqueue the nodes.
				//Check whether temp -> next -> next == NULL
				//If false that means our binary tree is not almost complete.

				size = q.size();

				while(size){
					temp = q.front();
					q.pop();
						if(temp -> left )
					q.push(temp);
					size --;
				}

			}
			
		}
	}
 	return true;
}

void print_status(Node *head){
	if(almost_complete(head))
		cout << "almost_complete" << endl;
	else
		cout << "not almost_complete " << endl;
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