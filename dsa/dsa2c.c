#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* removeAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* prevNode = NULL;
    Node* currNode = head;
    int count = 0;

    while (currNode != NULL && count < position) {
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }

    if (currNode == NULL) {
        printf("Invalid position\n");
        return head;
    }

    prevNode->next = currNode->next;
    free(currNode);
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    printf("Initial list: ");
    printList(head);

    int position = 2;  // Remove element at position 2 (index starts from 0)

    head = removeAtPosition(head, position);

    printf("List after removing element at position %d: ", position);
    printList(head);

    return 0;
}
N
