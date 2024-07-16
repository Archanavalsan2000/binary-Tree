#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int value) {
    
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTree(struct node* root, int space) {
    if (root == NULL)
        return;
    space += 5;
    printTree(root->right, space);
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main() {
    struct node* root = create(10);
    root->left = create(5);
    root->right = create(15);
    root->left->left = create(3);
    root->left->right = create(7);
    root->right->right = create(20);
    printTree(root, 0);

    return 0;
}
