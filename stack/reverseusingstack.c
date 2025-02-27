#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Function to push a character onto the stack
void push(struct Stack* stack, char c) {
    stack->items[++stack->top] = c;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char str[]) {
    struct Stack stack;
    stack.top = -1;  // Initialize stack as empty

    int len = strlen(str);

    // Step 1: Push each character onto the stack
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    // Step 2: Pop characters from stack and replace in string
    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}

// Main function
int main() {
    char str[MAX];

    printf("Enter a string: ");
    gets(str);  // Take input from the user

    reverseString(str);

    printf("Reversed string: %s\n", str);
    
    return 0;
}
