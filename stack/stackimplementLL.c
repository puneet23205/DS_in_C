#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node* link;
};

struct node* top = NULL; // Initialize the stack as empty

void push() {
    int x;
    printf("Enter data: ");
    scanf("%d", &x);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = x;      // Set the data
    newnode->link = top;    // Link the new node to the current top
    top = newnode;          // Update top to point to the new node
    printf("%d pushed onto the stack.\n", x);
}

void display() {
    struct node* temp = top;

    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void peek() {
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

void pop() {
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        struct node* temp = top;
        printf("The deleted element is %d\n", top->data);
        top = top->link; // Move the top pointer to the next node
        free(temp);      // Free memory of the popped node
    }
}

int main() {
    int ch;
    do {
        printf("\nEnter choice: \n1: Push\n2: Pop\n3: Peek\n4: Display\n0: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 0);

    return 0;
}

