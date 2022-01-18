#include "func.h"

/** \file
 *
 */
/**
 * \brief it sorts an array of n size.
 *
 * loop through the array and compares two elements
 * of the array if the array at index j is smaller than
 * at index j -1 then it will swap them.
 * the last element of the array will be compared with
 * every element of the sorted array.
 *
 * \param int arr[]    The array to be sorted.
 * \param  int sizeOfElem  The size of the array .
 * \return None.
 */
void insertSort(int arr[], int sizeOfElem) {
    for (int i = 1; i < sizeOfElem; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] > arr[j])
                swap(&arr[j - 1], &arr[j]);
        }
    }
}















/*  int key = arr[i];
  int j = i - 1;
  *//* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position *//*
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }*/
