#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for forest node
struct ForestNode {
    struct TreeNode* tree;
    struct ForestNode* next;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new forest node
struct ForestNode* createForestNode(struct TreeNode* tree) {
    struct ForestNode* newNode = (struct ForestNode*)malloc(sizeof(struct ForestNode));
    newNode->tree = tree;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a tree into the forest
struct ForestNode* insertTree(struct ForestNode* head, struct TreeNode* tree) {
    struct ForestNode* newNode = createForestNode(tree);
    if (head == NULL) {
        return newNode;
    } else {
        struct ForestNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

// Function to print the forest
void printForest(struct ForestNode* head) {
    struct ForestNode* temp = head;
    while (temp != NULL) {
        struct TreeNode* tree = temp->tree;
        printf("Tree: ");
        printTree(tree);
        temp = temp->next;
    }
}

// Function to print a tree in inorder traversal
void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

int main() {
    // Create some trees
    struct TreeNode* tree1 = createTreeNode(1);
    tree1->left = createTreeNode(2);
    tree1->right = createTreeNode(3);

    struct TreeNode* tree2 = createTreeNode(4);
    tree2->left = createTreeNode(5);
    tree2->right = createTreeNode(6);

    struct TreeNode* tree3 = createTreeNode(7);
    tree3->left = createTreeNode(8);
    tree3->right = createTreeNode(9);

    // Create a forest and insert the trees
    struct ForestNode* forest = NULL;
    forest = insertTree(forest, tree1);
    forest = insertTree(forest, tree2);
    forest = insertTree(forest, tree3);

    // Print the forest
    printf("Forest:\n");
    printForest(forest);
    printf("\n");

    return 0;
}
