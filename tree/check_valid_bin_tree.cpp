#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
	int data; 
	Node *left,*right;

	Node(){
		left = right = NULL;
	}

	Node(int data){
		this -> data = data;
		left = right = NULL;
	}
};


bool check_bin(Node *root){
	bool flag = false;
	queue<Node *>q;
	Node *temp = root;
	//Adding all the nodes to the queue including the root
	while(temp -> left != NULL){
		q.push(temp);
		temp = temp -> left;
	}

	//Now popping and testing for only leaves or both child present 
	//If only one child present then exit

	while(!q.empty()){
		temp = q.front();
		q.pop();

		if(temp -> right && temp -> left){
			q.push(temp -> left);
			q.push(temp -> right);
		}

		if(temp -> right == NULL && temp -> left == NULL);
		
		else 
			flag = false;

	}
	return flag;
}


int main(){
	Node *root = new Node(1);
	root -> left = new Node(0);
	root -> right = new Node(10);
	root -> right -> left = new Node(200);
	if(check_bin(root))
		cout << "Binary Tree" << endl;
	else
		cout << "Not binary tree" << endl;
	return 0;
}

