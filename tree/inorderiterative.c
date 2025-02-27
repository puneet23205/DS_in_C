#include <stdio.h>
#include <stdlib.h>

// Define structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// **Best Iterative Inorder Traversal (One Stack)**
void inorderIterative(struct Node* root) {
    struct Node* stack[100]; // Stack
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        // Step 1: Go to the leftmost node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Step 2: Process node (pop and print)
        current = stack[top--];
        printf("%d ", current->data);

        // Step 3: Move to the right subtree
        current = current->right;
    }
}

// **Main Function**
int main() {
    // Creating sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Iterative Inorder Traversal (Best Approach): ");
    inorderIterative(root);
    printf("\n");

    return 0;
}
