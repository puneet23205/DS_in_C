
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node
struct node* createNode() {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    printf("Linked list contents: ");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to count the number of nodes in the linked list
int countNodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a node at the beginning of the linked list
void insert_begin(struct node** head) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data you want to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newnode;  // Update the previous head's prev pointer
    }

    *head = newnode;  // Update head to point to the new node
}

// Function to insert a node at the last of the linked list
void insert_last(struct node** head) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data you want to insert at the last: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (*head == NULL) {
        newnode->prev = NULL;
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

// Function to insert a node at a given position
void insert_position(struct node** head) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int pos, i = 1;
    printf("Enter the position where you want to insert (1-based index): ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position. Position must be 1 or greater.\n");
        free(newnode);
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        insert_begin(head);
        return;
    }

    struct node* temp = *head;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
    printf("Node inserted at position %d.\n", pos);
}

// Function to delete from the beginning
void delete_from_beg(struct node** head) {
    struct node* temp;
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete the last node
void delete_from_last(struct node** head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    struct node* temp = *head;

    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Function to delete from a given position
void delete_from_pos(struct node** head) {
    struct node* temp;
    int pos, i = 1;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_from_beg(head);
        return;
    }

    temp = *head;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

// Function to reverse the doubly linked list
void reverse(struct node** head) {
    struct node* temp = NULL;
    struct node* currentnode = *head;

    while (currentnode != NULL) {
        temp = currentnode->prev;
        currentnode->prev = currentnode->next;
        currentnode->next = temp;

        currentnode = currentnode->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;
    int choice = 1;

    while (choice) {
        struct node* newnode = createNode();

        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Do you want to continue (0, 1)?: ");
        scanf("%d", &choice);
    }

    printf("Linked list before insertion at the beginning:\n");
    printList(head);

    insert_begin(&head);
    printf("Linked list after insertion at the beginning:\n");
    printList(head);

    insert_last(&head);
    printf("Linked list after insertion at the last:\n");
    printList(head);

    insert_position(&head);
    printf("Linked list after insertion at a specific position:\n");
    printList(head);

    delete_from_beg(&head);
    printf("Linked list after deletion from the beginning:\n");
    printList(head);

    delete_from_last(&head);
    printf("Linked list after deletion from the last:\n");
    printList(head);

    delete_from_pos(&head);
    printf("Linked list after deletion at a specific position:\n");
    printList(head);

    reverse(&head);
    printf("Linked list after reversing:\n");
    printList(head);

    int count = countNodes(head);
    printf("The number of nodes is: %d\n", count);

    return 0;
}




