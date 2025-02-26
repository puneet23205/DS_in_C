#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0, leftSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    // Iterate through the array and find the pivot index
    for (int i = 0; i < numsSize; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i; // Pivot index found
        }
        leftSum += nums[i]; // Update left sum for the next iteration
    }

    // No pivot index found
    return -1;
}

int main() {
    int nums[] = {1, 7, 3, 6, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = pivotIndex(nums, size);
    printf("Pivot index is: %d\n", result);

    return 0;
}
