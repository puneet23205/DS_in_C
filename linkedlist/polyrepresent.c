#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial node
struct node {
    float coeff; // Coefficient of the term
    int expo;    // Exponent of the term
    struct node* link; // Link to the next term
};

// Function to insert a term into the polynomial in descending order of exponents
struct node* insert(struct node* head, float coeff, int expo) {
    struct node* temp;
    struct node* newP = (struct node*)malloc(sizeof(struct node));

    newP->coeff = coeff;
    newP->expo = expo;
    newP->link = NULL;

    if (head == NULL || expo > head->expo) { // Insert at the beginning
        newP->link = head;
        head = newP;
    } else {
        temp = head;
        // Traverse the list to find the correct position
        while (temp->link != NULL && temp->link->expo > expo) {
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}
// Function to create a polynomial by inserting terms
struct node* create(struct node* head) {
    int n, i;
    float coeff;
    int expo;

    printf("Enter the number of terms:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo); // Insert the term into the polynomial
    }
    return head;
}
// Function to print the polynomial
void print(struct node* head) {
    if (head == NULL) {
        printf("The polynomial is empty.\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL) {
        printf("%.1fx^%d", temp->coeff, temp->expo);
        temp = temp->link;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}
int main() {
    struct node* head = NULL; // Initialize the polynomial as empty
    printf("Enter the polynomial:\n");
    head = create(head); // Create the polynomial
    printf("The polynomial is:\n");
    print(head); // Print the polynomial
    return 0;
}


