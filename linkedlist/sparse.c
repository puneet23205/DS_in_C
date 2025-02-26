#include <stdio.h>

int main() {
    int a[3][3], s[10][3], i, j, nz = 0, k = 0;

    // Input the matrix
    printf("Enter the elements of the matrix (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) {
                nz++;
            }
        }
    }

    printf("The matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Check if it's a sparse matrix
    if (nz > 3) {
        printf("Not a sparse matrix.\n");
        return 0;
    }

  // Construct sparse matrix representation
for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        if (a[i][j] != 0) {  // Store only non-zero elements
            s[k][0] = i;
            s[k][1] = j;
            s[k][2] = a[i][j];
            k++;
        }
    }
}

         
printf("\nSparse Matrix Representation:\n");
printf("Row\tCol\tValue\n");
for (i = 0; i < nz; i++) {
    for (j = 0; j < 3; j++) {
        printf("%d\t", s[i][j]);
    }
    printf("\n");
}

    return 0;
}
