#include "func.h"



/** \file
 *
 */
/**
 * \brief it sorts an array of n size.
 *
 * loop through the array and moves the bigger element
 * at index j to the right till the biggest element of the array
 * is the last element
 *
 * \param int arr[]    The array to be sorted.
 * \param  int sizeOfElem  The size of the array .
 * \return None.
 */
void bubbleSort(int arr[], int sizeOfElem) {
    for (int i = 1; i < sizeOfElem; ++i) {
        for (int j = 0; j < sizeOfElem - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
