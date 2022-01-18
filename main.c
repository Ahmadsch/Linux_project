#include <stdlib.h>
#include <time.h>
#include "func.h"


int main() {
    time_t t;
    srand((unsigned )time(&t));

    //callRunMeasureFunctions();
    //callSortFunctions();
    comparison();

}


void createRandomNumber(int sizeOfArray, int arr[], DATA_SET dataSet) {
    if (dataSet == DEC) {
        for (int i = sizeOfArray; i > 0; --i) {
            arr[i] = i;
        }
    }
    for (int i = 0; i < sizeOfArray; ++i) {
        if (dataSet == RAND) {
            int randomNumber;
            randomNumber = (rand() % 65534 + (-32767));
            arr[i] = randomNumber;
        } else if (dataSet == ASC)
            arr[i] = i;
    }
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