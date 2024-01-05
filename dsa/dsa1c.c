#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the specified position 'p'
void insert(struct Node** head, int value, int position) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty or position is 1
    if (*head == NULL || position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        int count = 1;

        // Traverse the list to find the position
        while (count < position - 1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }

        // If position is beyond the length of the list,
        // insert at the end
        if (temp->next == NULL && count == position - 1) {
            temp->next = newNode;
        } else if (count == position - 1) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Invalid position.\n");
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting elements in the list
    insert(&head, 10, 1);
    insert(&head, 20, 2);
    insert(&head, 30, 3);
    insert(&head, 40, 4);

    // Printing the list
    printf("List: ");
    printList(head);

    // Inserting element at position 3
    insert(&head, 50, 3);

    // Printing the updated list
    printf("Updated List: ");
    printList(head);

    return 0;
}
