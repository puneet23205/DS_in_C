#include<stdio.h>

int main() {
    int i, j, temp, min;
    int n;
    int a[50];

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter elements to be sorted:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        min = i; // Assume the smallest element is at index i
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j; // Update index of the smallest element
            }
        }
        // Swap the smallest element with the current element
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
