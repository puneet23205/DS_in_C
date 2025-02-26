#include <stdio.h>

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int n, i;
    int a[50];

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter elements to be sorted:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low]; // First element as pivot
    int i = low + 1;    // Start from the next element
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) {
            i++;
        }
        while (j >= low && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap elements that are out of place
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place the pivot in its correct position
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j; // Return the pivot index
}
