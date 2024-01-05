#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for multi-list
struct MultiList {
    struct TreeNode* tree;
    struct MultiList* next;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new multi-list node
struct MultiList* createMultiListNode(struct TreeNode* tree) {
    struct MultiList* newNode = (struct MultiList*)malloc(sizeof(struct MultiList));
    newNode->tree = tree;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a tree into the multi-list
struct MultiList* insertTree(struct MultiList* head, struct TreeNode* tree) {
    struct MultiList* newNode = createMultiListNode(tree);
    if (head == NULL) {
        return newNode;
    } else {
        struct MultiList* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

// Function to print the multi-list
void printMultiList(struct MultiList* head) {
    struct MultiList* temp = head;
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

    // Create a multi-list and insert the trees
    struct MultiList* multiList = NULL;
    multiList = insertTree(multiList, tree1);
    multiList = insertTree(multiList, tree2);
    multiList = insertTree(multiList, tree3);

    // Print the multi-list
    printf("Multi-List:\n");
    printMultiList(multiList);
    printf("\n");

    return 0;
}
