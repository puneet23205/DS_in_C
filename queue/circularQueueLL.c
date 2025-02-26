#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node* next;
};

struct node* front = 0; 
struct node* rear = 0; 

// Function to add an element to the queue
void enqueue(int x) { 
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = x;      // Set the data
    newnode->next = 0;   
    if (front == 0 && rear == 0) { // First element being added
        front = rear = newnode;
        rear->next = front; // Circular link
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front; // Maintain circular link
    }
    printf("%d enqueued.\n", x);
}

// Function to display the queue elements
void display() {
    if (front == 0 && rear == 0) {
        printf("The queue is empty.\n");
    } else {
        struct node* temp = front;
        printf("Queue elements are: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

// Function to display the front element of the queue
void peek() {
    if (front == 0 && rear == 0) {
        printf("The queue is empty.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == 0 && rear == 0) {
        printf("The queue is empty.\n");
    } else if (front == rear) { // Single element in the queue
        printf("The deleted element is: %d\n", front->data);
        free(front);
        front = rear = 0;
    } else {
        struct node* temp = front;
        printf("The deleted element is: %d\n", front->data);
        front = front->next;  // Move front to the next element
        rear->next = front;   // Maintain circular link
        free(temp);
    }
}

int main() {
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    display();
    dequeue();
    display();
    peek();
    enqueue(15);
    display();

    return 0;
}
