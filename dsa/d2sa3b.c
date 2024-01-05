#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* rightRotate(struct Node* node) {
    struct Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

struct Node* leftRotate(struct Node* node) {
    struct Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Original Tree: ");
    inorderTraversal(root);
    printf("\n");

    struct Node* rotatedRoot = rightRotate(root);

    printf("Tree after Right Rotation: ");
    inorderTraversal(rotatedRoot);
    printf("\n");

    rotatedRoot = leftRotate(rotatedRoot);

    printf("Tree after Left Rotation: ");
    inorderTraversal(rotatedRoot);
    printf("\n");

    return 0;
}
