#include <stdio.h>
#include <stdlib.h>

// Define structure for a BST node
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

// **Iterative function to search for a key in BST**
struct Node* searchBST(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->data) 
            return root;  // Key found
        
        if (key < root->data) 
            root = root->left;  // Search left
        
        else 
            root = root->right; // Search right
    }
    return NULL; // Key not found
}

// **Function to insert a node in BST**
struct Node* insertBST(struct Node* root, int data) {
    if (root == NULL) 
        return createNode(data);
    
    if (data < root->data) 
        root->left = insertBST(root->left, data);
    else 
        root->right = insertBST(root->right, data);
    
    return root;
}

// **Main Function**
int main() {
    struct Node* root = NULL;
    
    // Insert nodes into BST
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    int key = 40;
    struct Node* result = searchBST(root, key);
    
    if (result != NULL)
        printf("Key %d found in BST.\n", key);
    else
        printf("Key %d not found in BST.\n", key);

    return 0;
}
