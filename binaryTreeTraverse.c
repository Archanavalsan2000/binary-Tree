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
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}

void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->data);
}

int main() {
    struct node* root = create(10);
    root->left = create(5);
    root->right = create(15);
    root->left->left = create(3);
    root->left->right = create(7);
    root->right->right = create(20);
    printTree(root, 0);
    printf("Traversal of the binary tree \n");
    printf("Inorder traversal --- ");
    inorderTraversal(root);

    printf("\nPreorder traversal --- ");
    preorderTraversal(root);


    printf("\nPostorder traversal --- ");
    postorderTraversal(root);

    return 0;
}
