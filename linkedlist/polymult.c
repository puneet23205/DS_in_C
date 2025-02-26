#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial node
struct node {
    float coeff;       // Coefficient of the term
    int expo;          // Exponent of the term
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

// Function to multiply two polynomials
struct node* polyMult(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    if (head1 == NULL || head2 == NULL) {
        printf("Zero polynomial.\n");
        return NULL;
    }

    // Multiply each term of the first polynomial with each term of the second polynomial
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2; // Reset ptr2 to the start of the second polynomial
    }

    printf("\nBefore simplification:\n");
    print(head3);

    // Simplify the polynomial (combine like terms)
    struct node* ptr3 = head3;
    struct node* temp;
    while (ptr3 != NULL && ptr3->link != NULL) {
        if (ptr3->expo == ptr3->link->expo) {
            ptr3->coeff += ptr3->link->coeff;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp); // Free the memory of the removed node
        } else {
            ptr3 = ptr3->link;
        }
    }

    return head3;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;

    printf("Enter the first polynomial:\n");
    head1 = create(head1); // Create the first polynomial
    printf("First Polynomial: ");
    print(head1);

    printf("Enter the second polynomial:\n");
    head2 = create(head2); // Create the second polynomial
    printf("Second Polynomial: ");
    print(head2);

    // Multiply the two polynomials
    head3 = polyMult(head1, head2);

    printf("\nAfter simplification:\n");
    print(head3);

    return 0;
}

