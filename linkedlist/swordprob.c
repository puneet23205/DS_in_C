#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int value) { 
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = value; 
    newnode->next = NULL; 
    return newnode;
}


void printList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Person in circle from 1 to 100 is:\n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); 
    printf("\n");
}


void deleteAlternateNodes(struct node** head) {
    struct node *current = *head, *temp;

    // Running the loop for the last node remaining
    while (current != current->next) {
        // Delete the node after the current node
        temp = current->next;
        current->next = temp->next;
        free(temp);

        // Move to the next node
        current = current->next;
    }

    *head = current; 
} 

void printList_last(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Last person standing is: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); 
    printf("\n");
}

int main() { 
    struct node *head = NULL, *temp = NULL, *newnode;
    
    // Create 100 nodes with data from 1 to 100
    for (int i = 1; i <= 100; i++) {
        newnode = createnode(i); 
        
        if (head == NULL) {
            head = temp = newnode; 
            newnode->next = head; 
        } else {
            temp->next = newnode; 
            newnode->next = head; 
            temp = newnode; 
        }
    }
    printList(head);

    deleteAlternateNodes(&head);

    // Print who is the person standing at end
    printList_last(head);
    return 0;
}
