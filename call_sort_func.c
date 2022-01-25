#include "func.h"
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    ARRAY_SIZE_8 = 8, ARRAY_SIZE_16 = 16, ARRAY_SIZE_64 = 64
} SIZE_MODE;

static void prepareSortFunctions(SORT_MODE sortMode, SIZE_MODE sizeMode);

static bool isSorted(int sizeOfArray, const int arr[]);


void callSortFunctions() {
    prepareSortFunctions(QUICK_SORT, ARRAY_SIZE_8);
    prepareSortFunctions(MERGE_SORT, ARRAY_SIZE_8);
    prepareSortFunctions(INSERTION_SORT, ARRAY_SIZE_8);
    prepareSortFunctions(BUBBLE_SORT, ARRAY_SIZE_8);

    prepareSortFunctions(QUICK_SORT, ARRAY_SIZE_16);
    prepareSortFunctions(MERGE_SORT, ARRAY_SIZE_16);
    prepareSortFunctions(INSERTION_SORT, ARRAY_SIZE_16);
    prepareSortFunctions(BUBBLE_SORT, ARRAY_SIZE_16);

    prepareSortFunctions(QUICK_SORT, ARRAY_SIZE_64);
    prepareSortFunctions(MERGE_SORT, ARRAY_SIZE_64);
    prepareSortFunctions(INSERTION_SORT, ARRAY_SIZE_64);
    prepareSortFunctions(BUBBLE_SORT, ARRAY_SIZE_64);
}

static void prepareSortFunctions(SORT_MODE sortMode, SIZE_MODE sizeMode) {
    if (sortMode == MERGE_SORT) {
        if (sizeMode == ARRAY_SIZE_8) {
            int arr[ARRAY_SIZE_8];
            createRandomNumber(ARRAY_SIZE_8, &arr[0], RAND);
            printf("Merge sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_8);
            mergeSort(arr, 0, ARRAY_SIZE_8 - 1);
            isSorted(ARRAY_SIZE_8, arr);
            printf("after:\n");
            printArray(&arr[0], ARRAY_SIZE_8);
        } else if (sizeMode == ARRAY_SIZE_16) {
            int arr[ARRAY_SIZE_16];
            createRandomNumber(ARRAY_SIZE_16, &arr[0], RAND);
            printf("Merge sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_16);
            mergeSort(arr, 0, ARRAY_SIZE_16 - 1);
            isSorted(ARRAY_SIZE_16, arr);
            printf("after:\n");
            printArray(&arr[0], ARRAY_SIZE_16);
        } else if (sizeMode == ARRAY_SIZE_64) {
            int arr[ARRAY_SIZE_64];
            createRandomNumber(ARRAY_SIZE_64, &arr[0], RAND);
            printf("Merge sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_64);
            mergeSort(arr, 0, ARRAY_SIZE_64 - 1);
            isSorted(ARRAY_SIZE_64, arr);
            printf("after:\n");
            printArray(&arr[0], ARRAY_SIZE_64);
        }
    } else if (sortMode == QUICK_SORT) {
        if (sizeMode == ARRAY_SIZE_8) {
            int arr[ARRAY_SIZE_8];
            createRandomNumber(ARRAY_SIZE_8, &arr[0], RAND);
            printf("Quick sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_8);
            quickSort(arr, 0, ARRAY_SIZE_8 - 1);
            if (isSorted(ARRAY_SIZE_8, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_8);
            }
        } else if (sizeMode == ARRAY_SIZE_16) {
            int arr[ARRAY_SIZE_16];
            createRandomNumber(ARRAY_SIZE_16, &arr[0], RAND);
            printf("Quick sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_16);
            quickSort(arr, 0, ARRAY_SIZE_16 - 1);
            if (isSorted(ARRAY_SIZE_16, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_16);
            }

        } else if (sizeMode == ARRAY_SIZE_64) {
            int arr[ARRAY_SIZE_64];
            createRandomNumber(ARRAY_SIZE_64, &arr[0], RAND);
            printf("Quick sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_64);
            quickSort(arr, 0, ARRAY_SIZE_64 - 1);
            if (isSorted(ARRAY_SIZE_64, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_64);
            }
        }
    } else if (sortMode == INSERTION_SORT) {
        if (sizeMode == ARRAY_SIZE_8) {
            int arr[ARRAY_SIZE_8];
            createRandomNumber(ARRAY_SIZE_8, &arr[0], RAND);
            printf("insert sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_8);
            insertSort(arr, ARRAY_SIZE_8);
            if (isSorted(ARRAY_SIZE_8, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_8);
            }
        } else if (sizeMode == ARRAY_SIZE_16) {
            int arr[ARRAY_SIZE_16];
            createRandomNumber(ARRAY_SIZE_16, &arr[0], RAND);
            printf("insert sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_16);
            insertSort(arr, ARRAY_SIZE_16);
            if (isSorted(ARRAY_SIZE_16, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_16);
            }
        } else if (sizeMode == ARRAY_SIZE_64) {
            int arr[ARRAY_SIZE_64];
            createRandomNumber(ARRAY_SIZE_64, &arr[0], RAND);
            printf("insert sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_64);
            insertSort(arr, ARRAY_SIZE_64);
            if (isSorted(ARRAY_SIZE_64, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_64);
            }
        }
    } else if (sortMode == BUBBLE_SORT) {
        if (sizeMode == ARRAY_SIZE_8) {
            int arr[ARRAY_SIZE_8];
            createRandomNumber(ARRAY_SIZE_8, &arr[0], RAND);
            printf("Bubble sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_8);
            bubbleSort(arr, ARRAY_SIZE_8);
            if (isSorted(ARRAY_SIZE_8, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_8);
            }
        } else if (sizeMode == ARRAY_SIZE_16) {
            int arr[ARRAY_SIZE_16];
            createRandomNumber(ARRAY_SIZE_16, &arr[0], RAND);
            printf("Bubble sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_16);
            bubbleSort(arr, ARRAY_SIZE_16);
            if (isSorted(ARRAY_SIZE_16, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_16);
            }
        } else if (sizeMode == ARRAY_SIZE_64) {
            int arr[ARRAY_SIZE_64];
            createRandomNumber(ARRAY_SIZE_64, &arr[0], RAND);
            printf("Bubble sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_64);
            bubbleSort(arr, ARRAY_SIZE_64);
            if (isSorted(ARRAY_SIZE_64, arr)) {
                printf("after:\n");
                printArray(&arr[0], ARRAY_SIZE_64);
            }
        }
    }
}

void printArray(const int arr[], int arraySize) {
    int cntElements = 0;
    for (int i = 0; i < arraySize; ++i) {
        printf("%d\t", arr[i]);
        cntElements++;
        if ((cntElements % 15) == 0)
            printf("\n");
    }
    printf("\n\n");
}

static bool isSorted(int sizeOfArray, const int arr[]) {
    for (int i = 0; i < sizeOfArray; ++i) {
        for (int j = i + 1; j < sizeOfArray; ++j) {
            if (arr[i] > arr[j]) {
                printf("the array is not sorted. \n\n");
                return false;
            }
        }
    }
    printf("the array has been sorted. \n\n");
    return true;
}