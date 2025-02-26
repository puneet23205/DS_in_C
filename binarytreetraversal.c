#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
struct node* create(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main() {
    struct node* root = create(10);
    struct node* n1 = create(20);
    struct node* n2 = create(30);
    root->left = n1;
    root->right = n2;
    
    struct node* n3 = create(50);
    struct node* n4 = create(60);
    n1->left = n3;
    n1->right = n4;
    
    struct node* n5 = create(70);
    struct node* n6 = create(80);
    n2->left = n5;
    n2->right = n6;

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    return 0;
}


 