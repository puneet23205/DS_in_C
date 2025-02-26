#include <stdio.h>
#define N 5 // Maximum size of the queue

int queue[N];
int front = -1;
int rear = -1;

// Function to add an element to the queue
void enqueue(int x) {
    if ((rear + 1) % N == front) { // Check if the queue is full
        printf("Queue is full.\n");
    } else if (front == -1 && rear == -1) { // First element being added
        front = rear = 0;
        queue[rear] = x;
        printf("%d enqueued.\n", x);
    } else {
        rear = (rear + 1) % N; // Update rear in circular fashion
        queue[rear] = x;
        printf("%d enqueued.\n", x);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("The queue is empty.\n");
    } else if (front == rear) { // Single element in the queue
        printf("The deleted element is %d.\n", queue[front]);
        front = rear = -1; // Reset the queue
    } else {
        printf("The deleted element is %d.\n", queue[front]);
        front = (front + 1) % N; // Update front in circular fashion
    }
}

// Function to display the queue elements
void display() {
    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("The queue is empty.\n");
    } else {
        printf("Queue is: ");
        int i = front;
        while (i != rear) { // Traverse from front to rear
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]); // Print the last element
    }
}

// Function to display the front element of the queue
void peek() {
    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("The queue is empty.\n");
    } else {
        printf("The data at the front is %d.\n", queue[front]);
    }
}

int main() {
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    enqueue(7);
    enqueue(9);
    display();
    dequeue();
    display();
    peek();
    enqueue(15); // Test enqueue after dequeuing
    display();
    return 0;
}
