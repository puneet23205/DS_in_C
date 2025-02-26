#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly circular linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node and link it in a circular manner
struct node* createNode() {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;
    return newnode;
}

// Function to print the doubly circular linked list
void printList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Doubly Linked list contents: ");
    do {
        printf("\t%d", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to count the number of nodes in the doubly circular linked list
int countNodes(struct node* head) {
    if (head == NULL) return 0;

    int count = 0;
    struct node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    
    return count;
}

// Function to insert a node at the beginning of the doubly circular linked list
void insert_begin(struct node** head) {
    struct node* newnode = createNode();

    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode->prev = newnode; // Point to itself
    } else {
        struct node* last = (*head)->prev;

        newnode->next = *head;
        newnode->prev = last;
        (*head)->prev = newnode;
        last->next = newnode;
        *head = newnode; // Update head to point to the new node
    }
}

// Function to insert a node at the end of the doubly circular linked list
void insert_last(struct node** head) {
    struct node* newnode = createNode();

    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode->prev = newnode;
    } else {
        struct node* last = (*head)->prev;

        last->next = newnode;
        newnode->prev = last;
        newnode->next = *head;
        (*head)->prev = newnode;
    }
}

// Function to insert a node at a specific position in the doubly circular linked list
void insert_position(struct node** head) {
    int pos, i = 1;
    printf("Enter the position after which you want to insert: ");
    scanf("%d", &pos);

    struct node* newnode = createNode();

    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode->prev = newnode; // Point to itself
        return;
    }

    struct node* temp = *head;
    while (i < pos && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

// Function to delete the node at the beginning of the doubly circular linked list
void delete_from_beg(struct node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

struct node* temp=(*head)->prev;
struct node*last=temp->prev;

(*head)->prev=last;
last->next=(*head);
free(temp);
}



// Function to delete the node at the end of the doubly circular linked list
void delete_from_last(struct node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* last = (*head)->prev;

    if (last == *head) { // Only one node
        free(last);
        *head = NULL;
    } else {
        struct node* second_last = last->prev;
        second_last->next = *head;
        (*head)->prev = second_last;
        free(last);
    }
}

// Function to delete a node at a specific position in the doubly circular linked list
void delete_from_pos(struct node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int pos, i = 1;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    struct node* temp = *head;
    if (pos == 1) {
        delete_from_beg(head);
        return;
    }

    while (i < pos && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == *head && i < pos) {
        printf("Invalid position.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Function to reverse the doubly circular linked list
void reverse(struct node** head) {
    if (*head == NULL) return;

    struct node *prev = NULL, *current = *head, *next = NULL;
    do {
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev;
    *head = prev;
}

int main() {
    struct node* head = NULL;
    struct node* temp = NULL;
    int choice = 1;

    // Create the doubly circular linked list
    while (choice) {
        struct node* newnode = createNode();
        
        if (head == NULL) {
            head = temp = newnode;
            newnode->next = newnode->prev = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = head;
            head->prev = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0, 1)?: ");
        scanf("%d", &choice);
    }

    // Print the doubly circular linked list
    printf("Doubly linked list before insertion:\n");
    printList(head);

    // Insert a node at the beginning
    insert_begin(&head);
    printf("Doubly linked list after insertion at the beginning:\n");
    printList(head);

    // Insert a node at the end
    insert_last(&head);
    printf("Doubly linked list after insertion at the last:\n");
    printList(head);

    // Insert a node at a specific position
    insert_position(&head);
    printf("Doubly linked list after insertion at a specific position:\n");
    printList(head);

    // Delete node from the beginning
    delete_from_beg(&head);
    printf("Doubly linked list after deletion at the beginning:\n");
    printList(head);

    // Delete node from the last
    delete_from_last(&head);
    printf("Doubly linked list after deletion at the last:\n");
    printList(head);

    // Delete node from a specific position
    delete_from_pos(&head);
    printf("Doubly linked list after deletion at a specific position:\n");
    printList(head);

    // Reverse the doubly circular linked list
    reverse(&head);
    printf("Doubly linked list after reversing:\n");
    printList(head);

    // Count and display the number of nodes
    int count = countNodes(head);
    printf("The number of nodes is: %d\n", count);

    return 0;
}
