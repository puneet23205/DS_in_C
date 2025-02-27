#include <stdio.h>

#define MAX 10  // Define the maximum size of the array

int arr[MAX]; // Single array for both stacks
int top1 = -1, top2 = MAX; // Stack 1 starts from -1, Stack 2 starts from MAX

// Push into Stack 1
void push1(int data) {
    if (top1 + 1 < top2) {  // Check for space
        arr[++top1] = data;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Push into Stack 2
void push2(int data) {
    if (top1 + 1 < top2) {  // Check for space
        arr[--top2] = data;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Pop from Stack 1
int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("Stack 1 Underflow!\n");
        return -1;
    }
}

// Pop from Stack 2
int pop2() {
    if (top2 < MAX) {
        return arr[top2++];
    } else {
        printf("Stack 2 Underflow!\n");
        return -1;
    }
}

// Display both stacks
void display() {
    printf("Stack 1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nStack 2: ");
    for (int i = MAX - 1; i >= top2; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    push1(5);
    push1(10);
    push2(20);
    push2(30);
    
    display();

    printf("Popped from Stack 1: %d\n", pop1());
    printf("Popped from Stack 2: %d\n", pop2());

    display();

    return 0;
}
