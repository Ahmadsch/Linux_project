#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "func.h"


void callFunctions(SORT_MODE sortMode, SIZE_MODE sizeMode);

void printArray(const int arr[], int arraySize);

bool isSorted(int sizeOfArray, const int arr[]);

void createRandomNumber(int sizeOfArray, int arr[]);


int main() {
    srand(time(0));

    callFunctions(MERGE_SORT, ARRAY_SIZE_8);
    callFunctions(QUICK_SORT, ARRAY_SIZE_8);
    callFunctions(INSERTION_SORT, ARRAY_SIZE_8);
    callFunctions(BUBBLE_SORT, ARRAY_SIZE_8);
}

void callFunctions(SORT_MODE sortMode, SIZE_MODE sizeMode) {
    if (sortMode == MERGE_SORT) {
        if (sizeMode == ARRAY_SIZE_8) {
            int arr[ARRAY_SIZE_8];
            createRandomNumber(ARRAY_SIZE_8, &arr[0]);
            printf("Merge sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_8);
            mergeSort(arr, 0, ARRAY_SIZE_8 - 1);
            isSorted(ARRAY_SIZE_8, arr);
            printf("after:\n");
            printArray(&arr[0], ARRAY_SIZE_8);
        } else if (sizeMode == ARRAY_SIZE_16) {
            int arr[ARRAY_SIZE_16];
            createRandomNumber(ARRAY_SIZE_16, &arr[0]);
            printf("Merge sorting ..\n\n");
            printf("before:\n");
            printArray(&arr[0], ARRAY_SIZE_16);
            mergeSort(arr, 0, ARRAY_SIZE_16 - 1);
            isSorted(ARRAY_SIZE_16, arr);
            printf("after:\n");
            printArray(&arr[0], ARRAY_SIZE_16);
        } else if (sizeMode == ARRAY_SIZE_64) {
            int arr[ARRAY_SIZE_64];
            createRandomNumber(ARRAY_SIZE_64, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_8, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_16, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_64, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_8, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_16, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_64, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_8, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_16, &arr[0]);
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
            createRandomNumber(ARRAY_SIZE_64, &arr[0]);
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


bool isSorted(int sizeOfArray, const int arr[]) {
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

void createRandomNumber(int sizeOfArray, int arr[]) {
    int randomNumber;
    for (int i = 0; i < sizeOfArray; ++i) {
        // randomNumber = rand() % 65534 + (-32767);
        // randomNumber = (rand() % 32767) * 2 + (-32767);
        randomNumber = (rand() % 65534 + (-32767));
        arr[i] = randomNumber;
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

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
void swap(int arr[], int *x, int *y, SORT_MODE sortMode) {
    if (sortMode == INSERTION_SORT) {
        int temp = arr[*x];
        arr[*x] = arr[*y];
        arr[*y] = temp;
    } else {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}
*/
/*  int n1 = mid - start + 1;
    int n2 = end - mid;


    int L[n1], R[n2];

    *//* Copy data to temp arrays L[] and R[] *//*
    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    *//* Merge the temp arrays back into arr[start..end]*//*
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = start; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    *//* Copy the remaining elements of L[], if there
    are any *//*
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    *//* Copy the remaining elements of R[], if there
    are any *//*
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}*/