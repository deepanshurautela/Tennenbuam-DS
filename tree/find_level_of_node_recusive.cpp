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
		left = right = nullptr;;
		this -> data = data;
	}
};


int find_level_of_node(Node *root, Node* find_level){
	if(!root || !find_level)
		return 0;

	if(root == find_level)
		return 1;

	else if(find_level -> data > root -> data)
		return 1 + find_level_of_node(root -> right, find_level);

	else if(find_level -> data < root -> data)
		return 1 + find_level_of_node(root -> left, find_level);

}



int main(int argc, char const *argv[])
{
	Node *root = new Node(2);
	root->left     = new Node(7);
    root->right     = new Node(5);
    root->left->right = new Node(6);
    root -> right -> left = new Node(10);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(11);
    root->right->right = new Node(9);
    root->right->right->left = new Node(4);
   	cout << find_level_of_node(root, root -> right -> right -> left) << endl;
	return 0;
}