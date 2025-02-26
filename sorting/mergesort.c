#include <stdio.h>

void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int main() {
    int n, i;
    int a[50];

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter elements to be sorted:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        // Merge the sorted halves
        merge(a, left, mid, right);
    }
}

void merge(int a[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = left; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
