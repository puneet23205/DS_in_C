#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* root = NULL;


struct node* create_node(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


void insert(int val) {
    
    struct node* temp = create_node(val);


    if (root == NULL) {
        root = temp;
        return;
    }

    struct node* p = root;
    struct node* q = NULL;

   
    while (p != NULL) {
        q = p;
        if (val > p->data) {
            p = p->right;
        } else {
            p = p->left;
        }
    }

    if (val > q->data) {
        q->right = temp;
    } else {
        q->left = temp;
    }
}


void in_order(struct node* root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

int main() {
  
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

   
    printf("In-order Traversal of the BST:\n ");
    in_order(root);
    printf("\n");

    return 0;
}
