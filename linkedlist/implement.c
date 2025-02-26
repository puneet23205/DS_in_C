#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node* next;
};

// Global head pointer
struct node* head = NULL;

// Function to create a new node
struct node* createNode() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

// Function to print the linked list
void printList() {
    struct node* temp = head;
    printf("Linked list contents: ");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to count the number of nodes in the linked list
int countNodes() {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a node at the beginning
void insert_begin() {
    struct node* newnode = createNode();
    newnode->next = head;
    head = newnode;
}

// Function to insert a node at the last
void insert_last() {
    struct node* newnode = createNode();
    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to insert at a given position
void insert_position() {
    int pos, i = 1;
    printf("Enter the position at which you want to insert: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insert_begin();
        return;
    }

    struct node* temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct node* newnode = createNode();
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted at position %d.\n", pos);
}

// Delete from beginning
void delete_from_beg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from last
void delete_from_last() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete from a given position
void delete_from_pos() {
    int pos, i = 1;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_from_beg();
        return;
    }

    struct node* temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct node* nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    printf("Node at position %d deleted.\n", pos);
}

// Function to reverse the linked list
void reverse() {
    struct node* prevnode = NULL;
    struct node* currentnode = head;
    struct node* nextnode = NULL;

    while (currentnode != NULL) {
        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

int main() {
    struct node* temp = NULL;
    int choice = 1;

    // Create the linked list
    while (choice) {
        struct node* newnode = createNode();
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0 for No, 1 for Yes)?: ");
        scanf("%d", &choice);
    }

    // Operations on linked list
    printf("Linked list before insertion at the beginning:\n");
    printList();

    insert_begin();
    printf("Linked list after insertion at the beginning:\n");
    printList();

    insert_last();
    printf("Linked list after insertion at the last:\n");
    printList();

    insert_position();
    printf("Linked list after insertion at a position:\n");
    printList();

    delete_from_beg();
    printf("Linked list after deletion at the beginning:\n");
    printList();

    delete_from_last();
    printf("Linked list after deletion at the last:\n");
    printList();

    delete_from_pos();
    printf("Linked list after deletion at a position:\n");
    printList();

    reverse();
    printf("Linked list after reversing:\n");
    printList();

    printf("The number of nodes is: %d\n", countNodes());

    return 0;
}


