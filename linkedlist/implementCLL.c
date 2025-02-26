#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node* next;
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
    newnode->next = NULL;  // Next will be updated later
    return newnode;
}

// Function to print the circular linked list
void printList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Linked list contents: ");
    do {
        printf("\t%d", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we come back to the head
    printf("\n");
}

// Function to count the number of nodes in the circular linked list
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

// Function to insert a node at the beginning of the circular linked list
void insert_begin(struct node** head) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d", &newnode->data);

    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode; // Point to itself, making the list circular
    } else {
        struct node* temp = *head;
        
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        newnode->next = *head; // New node points to current head
        temp->next = newnode;  // Last node points to new node
        *head = newnode;       // Update head to point to the new node
    }
}

// Function to insert a node at the last of the circular linked list
void insert_last(struct node** head) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data you want to insert at the last: ");
    scanf("%d", &newnode->data);

    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode; // Point to itself
    } else {
        struct node* temp = *head;
        
        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode; // Last node points to the new node
        newnode->next = *head; // New node points to head
    }
}

// Function to insert a node at a specific position in the circular linked list
void insert_position(struct node** head) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int pos, i = 1;
    printf("Enter the position after which you want to insert: ");
    scanf("%d", &pos);

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode; // Point to itself, making the list circular
        return;
    }

    struct node* temp = *head;
    
    // Traverse to the node before the given position
    while (i < pos-1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to delete the node at the beginning of the circular linked list
void delete_from_beg(struct node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = *head;

    if (temp->next == *head) { // If only one node is present
        free(temp);
        *head = NULL;
    } else {
        // Traverse to the last node
        struct node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        *head = (*head)->next;
        last->next = *head; // Update the last node's next pointer to the new head
        free(temp);
    }
}

// Function to delete the node at the last of the circular linked list
void delete_from_last(struct node** head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    struct node* temp = *head;

    if (temp->next == *head) { // If only one node is present
        free(temp);
        *head = NULL;
    } else {
        struct node* prev = NULL;

        // Traverse to the last node
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = *head; // Previous node now points to head
        free(temp); // Free the last node
    }
}

// Function to delete a node at a given position in the circular linked list
void delete_from_pos(struct node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int pos, i = 1;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_from_beg(head);
        return;
    }

    struct node* temp = *head;
    struct node* nextnode;

    // Traverse to the node before the position to delete
    while (i < pos - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == *head) {
        printf("Invalid position.\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

// Function to reverse the circular linked list
void reverse(struct node** head) {
    if (*head == NULL) return;

    struct node *prev = NULL, *current = *head, *next = NULL, *last = *head;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    last->next = prev;
    *head = prev;
}

int main() {
    struct node* head = NULL;
    struct node* temp = NULL;
    int choice = 1;

    // Create the circular linked list using createNode
    while (choice) {
        struct node* newnode = createNode();
        
        if (head == NULL) {
            head = temp = newnode;
            newnode->next = head; // Make it circular
        } else {
            temp->next = newnode;
            newnode->next = head; // Make it circular
            temp = newnode;
        }

        printf("Do you want to continue (0, 1)?: ");
        scanf("%d", &choice);
    }

    // Print the circular linked list before any operations
    printf("Linked list before insertion at the beginning:\n");
    printList(head);

    // Insert a new node at the beginning
    insert_begin(&head);

    // Print the circular linked list after insertion at the beginning
    printf("Linked list after insertion at the beginning:\n");
    printList(head);
    
    insert_last(&head);
     printf("Linked list after insertion at the last:\n");
    printList(head);

    // Insert a new node at a specific position
    insert_position(&head);
    printf("Linked list after insertion at a specific position:\n");
    printList(head);

    // Delete node from the beginning
    delete_from_beg(&head);
    printf("Linked list after deletion at the beginning:\n");
    printList(head);

    // Delete node from the last
    delete_from_last(&head);
    printf("Linked list after deletion at the last:\n");
    printList(head);

    // Delete node from a specific position
    delete_from_pos(&head);
    printf("Linked list after deletion at a specific position:\n");
    printList(head);

    // Reverse the circular linked list
    reverse(&head);
    printf("Linked list after reversing:\n");
    printList(head);

    // Count and display the number of nodes
    int count = countNodes(head);
    printf("The number of nodes is: %d\n", count);

    return 0;
}
