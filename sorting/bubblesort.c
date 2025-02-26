#include<stdio.h>

int main() {
    int i, j, temp;
    int n;
    int a[50];

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter elements to be sorted:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        int flag = 1; // Assume no swaps initially we are using flag to decrease the number of passes 
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 0; // A swap occurred
            }
        }
        if (flag == 1) { // No swaps in the inner loop
            break;
        }
    }

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
