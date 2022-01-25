#include <stdlib.h>
#include "func.h"


static int partition(int arr[], int low, int high);


/** \file
 *
 */
/**
 * \brief it sorts an array of n size.
 *
 *  This function takes random element as pivot, places
 *  the pivot element at the last position in the sorted
 *  sub-array, and places all smaller (smaller than pivot)
 *  to left of pivot and all greater elements to right
 *  of pivot
 *
 * \param int arr[]    The array to be sorted.
 * \param  int low     start index of the sub-array.
 * \param  int high    last index of the sub-array .
 * \return i           the pivotIndex.
 */
static int partition(int arr[], int low, int high) {

    int pivotIndex = low + rand() % (high - low);
    if (pivotIndex != high)
        swap(&arr[pivotIndex], &arr[high]);

    int pivotValue = arr[high]; // pivotValue
    int i = low; // Index of smaller element and indicates the right position of pivotValue found so far

    for (int j = low; j <= high; j++) {
        // If current element is smaller than the pivotValue
        if (arr[j] < pivotValue) {
            swap(&arr[i], &arr[j]);
            i++; // increment index of smaller element
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

/**
 * \brief it divides an array of n size according to the pivotIndex.
 *
 *  This function is recursive, it calls itself to divide
 *  the array into two sub-arrays according to the pivotIndex
 *  then it call the function partition() to sort the created sub-arrays.
 *
 * \param int arr[]    The array to be sorted.
 * \param  int low     start index of the sub-array.
 * \param  int high    last index of the sub-array .
 * \return None.
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pivotIndex is partitioning index, arr[p] is now
        at right place */
        int pivotIndex = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}