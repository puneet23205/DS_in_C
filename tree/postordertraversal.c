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

// **Recursive Postorder Traversal**
void postorderRecursive(struct Node* root) {
    if (root == NULL)
        return;
    
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

// **Non-Recursive (Iterative) Postorder Traversal using Two Stacks**
void postorderIterative(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[100], *stack2[100]; // Two stacks
    int top1 = -1, top2 = -1;

    // Push root to Stack 1
    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* temp = stack1[top1--];
        stack2[++top2] = temp; // Store in second stack

        // Push left and right children to stack1
        if (temp->left)
            stack1[++top1] = temp->left;
        if (temp->right)
            stack1[++top1] = temp->right;
    }

    // Print from Stack 2 (which stores nodes in postorder)
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]);
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

    printf("Recursive Postorder Traversal: ");
    postorderRecursive(root);
    printf("\n");

    printf("Iterative Postorder Traversal: ");
    postorderIterative(root);
    printf("\n");

    return 0;
}
