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

// **Iterative Preorder Traversal Using One Stack**
void preorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100]; // Stack
    int top = -1;

    // Push root node
    stack[++top] = root;

    while (top >= 0) {
        struct Node* temp = stack[top--];
        printf("%d ", temp->data);

        // Push right child first (so left is processed first)
        if (temp->right) stack[++top] = temp->right;
        if (temp->left) stack[++top] = temp->left;
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

    printf("Iterative Preorder Traversal: ");
    preorderIterative(root);
    printf("\n");

    return 0;
}
