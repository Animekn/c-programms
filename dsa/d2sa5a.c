#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure for a 3-4 B-tree node
struct Node {
    bool isLeaf;
    int numKeys;
    int keys[3];
    struct Node* children[4];
};

// Function to create a new node
struct Node* createNode(bool isLeaf) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->isLeaf = isLeaf;
    newNode->numKeys = 0;
    for (int i = 0; i < 4; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to search for a key in the B-tree
bool search(struct Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }
    if (i < root->numKeys && key == root->keys[i]) {
        return true;
    } else if (root->isLeaf) {
        return false;
    } else {
        return search(root->children[i], key);
    }
}

// Function to split a full child of a node during insertion
void splitChild(struct Node* parent, int index) {
    struct Node* child = parent->children[index];
    struct Node* newNode = createNode(child->isLeaf);
    newNode->numKeys = 1;
    newNode->keys[0] = child->keys[2];

    if (!child->isLeaf) {
        newNode->children[0] = child->children[2];
        newNode->children[1] = child->children[3];
    }

    child->numKeys = 1;

    for (int i = parent->numKeys; i > index; i--) {
        parent->keys[i] = parent->keys[i - 1];
    }

    parent->keys[index] = child->keys[1];

    for (int i = parent->numKeys + 1; i > index + 1; i--) {
        parent->children[i] = parent->children[i - 1];
    }

    parent->children[index + 1] = newNode;
    parent->numKeys++;
}

// Function to insert a key into the B-tree
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* newNode = createNode(true);
        newNode->keys[0] = key;
        newNode->numKeys = 1;
        return newNode;
    }

    if (root->numKeys == 3) {
        struct Node* newRoot = createNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Function to insert a key into a non-full node
void insertNonFull(struct Node* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        if (node->children[i]->numKeys == 3) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Function to print the keys in the B-tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    int i;
    for (i = 0; i < root->numKeys; i++) {
        if (!root->isLeaf) {
            inorderTraversal(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }

    if (!root->isLeaf) {
        inorderTraversal(root->children[i]);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert keys into the B-tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 25);

    // Print the keys in the B-tree
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a key in the B-tree
    int key = 15;
    if (search(root, key)) {
        printf("%d is found in the B-tree.\n", key);
    } else {
        printf("%d is not found in the B-tree.\n", key);
    }

    return 0;
}
