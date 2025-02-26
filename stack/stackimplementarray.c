#include <stdio.h>
#define N 5 // Define stack size
int stack[N];
int top = -1;

void push() {
    int x;
    printf("Enter data: ");
    scanf("%d", &x);

    if (top == N - 1) { // Corrected the overflow condition
        printf("Overflow condition\n");
    } else {
        top++;
        stack[top] = x;
        printf("Pushed %d onto the stack\n", x);
    }
}

void pop() {
    int item;
    if (top == -1) { // Underflow condition
        printf("Underflow condition\n");
    } else {
        item = stack[top];
        top--;
        printf("The number deleted is %d\n", item);
    }
}

void peek() {
    if (top == -1) { // Stack empty check
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void display() {
    int i;
    if (top == -1) { // Stack empty check
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
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

