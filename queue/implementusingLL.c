#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node* next;
};

struct node* front= 0; 
struct node* rear= 0; 
void enqueue(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = x;      // Set the data
    newnode->next= 0;   
    if(front==0&&rear==0)
    {
     front=rear=newnode;
    }
    else {
      rear->next=newnode;
      rear=newnode;
    }
   
}

void display() {
    struct node* temp;

    if (front==0 && rear==0) {
        printf("The stack is empty.\n");
    } else {
      temp=front;
        printf("Stack elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek() {
    if (front==0 && rear==0) {
        printf("The stack is empty.\n");
    } else {
        printf("Top element is: %d\n", front->data);
    }
}

void dequeue() {
    if (front==0 && rear==0) {
        printf("The stack is empty.\n");
    } else {
        struct node* temp = front;
        printf("The deleted element is %d\n", front->data);
        front= front->next; // Move the top pointer to the next node
        free(temp);      // Free memory of the popped node
    }
}

int main() {
enqueue(5);
enqueue(0);
enqueue(-3);
display();
dequeue();
peek();

return 0;
}