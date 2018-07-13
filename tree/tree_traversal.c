#include <stdio.h>
#include <stdlib.h>

#define RIGHT 0
#define LEFT 1
 
struct Node{
    int data; 
    struct Node* left;
    struct Node* right;
};

struct Position{
    int level;
    int dir;
};

struct Node* new_node(int data){
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp; 
}


void print_post_order(struct Node* node){
    if (!node)
        return;
    print_post_order(node->left);
    print_post_order(node->right);
    printf("%d\n", node->data );
}


void print_in_order(struct Node* node){
    if(!node)
        return;
    print_in_order(node -> left);
    printf("%d\n", node -> data);
    print_in_order(node -> right);
}

int main(int argc, char const *argv[])
{
    struct Node* root = new_node(10); 
    root -> right = new_node(12);
    root -> left = new_node(9);
    
    root -> right -> right = new_node(30);
    root -> right -> left = new_node(29);

    root -> left -> left = new_node(23);
    root -> left -> right = new_node(34);

    print_post_order(root);

    printf("\n\n\n");

    print_in_order(root);

    return 0;
}