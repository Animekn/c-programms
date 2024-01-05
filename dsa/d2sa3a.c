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

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void printTreeInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printTreeInOrder(root->left);
    printf("%d ", root->data);
    printTreeInOrder(root->right);
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes in a skewed manner
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);

    // Printing the tree in in-order traversal
    printf("Skewed Tree: ");
    printTreeInOrder(root);
    printf("\n");

    return 0;
}
