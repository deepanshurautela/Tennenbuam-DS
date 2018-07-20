#include <stack>
#include <queue>
#include <iostream>
#include <iterator>

using namespace std;

typedef struct node{
	struct node *left, *right;
	int data;
}Node;


Node *getNode(int data){
	Node *newNode = new Node;
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}


/* --- Algorithm -----
1. If root is NULL, then that means that it is mirror

2. Else we push the root into the queue

3. Then while the queue is not empty
	
	3.1. We take the front node out of the queue and then pop it. 
	3.2. If children of the node is present, then we push them to the queue.
	3.3. Then we take a stack and push the contents of queue without affecting queues orignal structure
	3.4. We then pop and compare the values fo stack and queue top/front.
		 3.4.1 If they are not equal then return false and break out of the condition.
4. Return true if never false was encountered.   

# We use stack here because it reverses the order of the sequence. 


							1
						  /   \
						 2     2
						/ \   / \
					   4   5  5  4

	reverse(2,2) = 2,2
	reverse(4,5,5,4) = 4,5,5,4
	

							1
						  /   \
						 2     2
						/ \     \
					   4   5    4
	Need to fix this will still return true even though its not mirror 

*/

bool isMirror(Node *root){
	queue<Node *>q;			
	stack<int>s;

	Node *temp, *temp1;
	int num_temp;
	
	unsigned int size = 0;
	
	if (root == NULL)
		return true;
	q.push(root);

	while(!q.empty()){
		temp = q.front();
		q.pop();

		if(temp -> left)
			q.push(temp -> left);
		if(temp -> right)
			q.push(temp -> right);
			
		size = q.size();
		cout << "Size is " << size << endl;

		while(size){
			temp = q.front();
			cout << "q.front = " << temp -> data << endl;
			q.pop();
			s.push(temp -> data);
			q.push(temp);
			size --;
		}

		size = s.size();
		printf("Stack size is %d\n",size);

		while(size){
			num_temp = s.top();
			cout << "Stack top is :- " << num_temp << endl;
			s.pop();
			temp1 = q.front();
			q.pop(); //If not popped goes into infinite loop
			cout << "Queue front is :- " << temp1 -> data << endl;
			if(temp -> data != num_temp){
				return false;
				break;
			}
			q.push(temp1);
			size --;
		}
	}
	return true;
}

void isMirrorOrNot(Node *root){
	bool val = isMirror(root);
	cout << endl << endl;
	if(val)
		cout << "It is a mirror image " << endl;
	else
		cout << "It is not a mirror image " <<endl;
}


void make_bin_tree(Node **head, int data){
	Node *newNode = getNode(data);
	Node *temp = (*head);
	//cout << "Entered " << endl;
	if((*head) == NULL)
		(*head) = newNode;
	while(temp -> left != NULL || temp -> right != NULL){
		if(temp -> data > data)
			temp = temp -> left;
		if(temp -> data < data)
			temp = temp -> right;
		else
			temp = newNode;
	}
}

int main(int argc, char const *argv[])
{	int size, temp;
	Node *root = getNode(10);
	root  -> left = getNode(2);
	root -> right = getNode(3);
	root -> left -> right = getNode(10);
	isMirrorOrNot(root);
	return 0;
}