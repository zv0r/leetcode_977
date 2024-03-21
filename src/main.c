#include <stdio.h>
#include <stdlib.h>

int* sortedSquares1(int* nums, int numsSize, int* returnSize);

int* sortedSquares2(int* nums, int numsSize, int* returnSize);

void printArrayOfInts(int* nums, int numsSize);

int main(void) {
    int input1[] = {-2};
    int input2[] = {-4, -1, 0, 3, 10};
    int output_size = 0;

    int* output1_1 = sortedSquares1(input1, 1, &output_size);
    int* output1_2 = sortedSquares2(input1, 1, &output_size);
    printArrayOfInts(input1, 1);
    printArrayOfInts(output1_1, output_size);
    printArrayOfInts(output1_2, output_size);

    int* output2_1 = sortedSquares1(input2, 5, &output_size);
    int* output2_2 = sortedSquares2(input2, 5, &output_size);
    printArrayOfInts(input2, 5);
    printArrayOfInts(output2_1, output_size);
    printArrayOfInts(output2_2, output_size);

    free(output1_1);
    free(output1_2);
    free(output2_1);
    free(output2_2);
    return 0;
}

void printArrayOfInts(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int* sortedSquares2(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int l = 0, r = numsSize - 1;
    for (int i = r; i >= 0; i--) {
        if (abs(nums[l]) > abs(nums[r])) {
            result[i] = nums[l] * nums[l];
            l++;
        } else {
            result[i] = nums[r] * nums[r];
            r--;
        }
    }

    return result;
}

int* sortedSquares1(int* nums, int numsSize, int* returnSize) {
    int* result = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    int positiveIndex = 0;

    while (positiveIndex < numsSize && nums[positiveIndex] < 0) {
        positiveIndex++;
    }
    int negativeIndex = positiveIndex - 1;

    for (int i = 0; i < numsSize; i++) {
        if ((negativeIndex >= 0 && positiveIndex >= numsSize) ||
            (negativeIndex >= 0 && positiveIndex < numsSize &&
             nums[negativeIndex] * nums[negativeIndex] <= nums[positiveIndex] * nums[positiveIndex])) {
            result[i] = nums[negativeIndex] * nums[negativeIndex];
            negativeIndex--;
        } else {
            result[i] = nums[positiveIndex] * nums[positiveIndex];
            positiveIndex++;
        }
    }

    return result;
}