#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack* next;
};

// Function to create a new node
struct Stack* createNode(int value) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Stack** top, int value) {
    struct Stack* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Stack* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to insert an element at the bottom of the stack
void insert_at_bottom(struct Stack** top, int x) {
    if (*top == NULL) {
        push(top, x);
    } else {
        int a = pop(top);
        insert_at_bottom(top, x);
        push(top, a);
    }
}

// Function to print the stack
void printStack(struct Stack* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    int n, x;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    struct Stack* top = NULL;

    printf("Enter the elements of the stack:\n");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(&top, value);
    }

    printf("Enter the element to be inserted at the bottom: ");
    scanf("%d", &x);

    insert_at_bottom(&top, x);

    printf("Stack after inserting at the bottom: ");
    printStack(top);

    return 0;
}
