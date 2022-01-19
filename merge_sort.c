#include "func.h"

void merge(int arr[], int start, int mid, int end);



/** \file
 *
 */
/**
 * \brief it sorts an array of n size.
 * it merges two subarrays of arr[].
 * First subarray is arr[start..mid]
 * Second subarray is arr[mid+1..end]
 * it compares the two subarray and whichever one is smaller,
 * is going to be placed in this temp array and finally it will
 * copyArrayToList the temp array to the original array.
 *
 * \param int arr[]    The array to be sorted.
 * \param  int low     start index of the sub-array.
 * \param  int mid     index of last element of the left sub-array and the first element of the right sub-array.
 * \param  int high    last index of the sub-array .
 * \return i           the pivotIndex.
 */
void merge(int arr[], int start, int mid, int end) {
    int sizeOfTempArr = (end - start) + 1;
    /* build temp arrays to avoid modifying the original contents  */
    int tempArr[sizeOfTempArr];

    /*i variable is the left sub-array*/
    int i = start;
    /*j variable is the right sub-array*/
    int j = mid + 1;
    /* k is a tracker variable to keep track of the values that we put in the temp array */
    int k = 0;

    /*linear time comparisonBubble, at the values in the left array and the pointer on the right array*/
    /*whichever one is smaller is going to be placed in this temp array*/
    /*if both of the subarray have elements, then sort them and finally merge them back*/
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            tempArr[k++] = arr[i++];  // same as tempArr[k] = arr[i]; i++; k++;
        else
            tempArr[k++] = arr[j++];
    }

    /*if one of the sub-array ran out of values*/

    /*while is there values in the left sub-array then just assign them at the end of the temp array */
    while (i <= mid)
        tempArr[k++] = arr[i++];

    /*while is there values in the right sub-array then just assign them at the end of the temp array */
    while (j <= end)
        tempArr[k++] = arr[j++];

    /*copyArrayToList the temp array to the original array*/
    for (i = start; i <= end; i++)
        arr[i] = tempArr[i - start];

}

/* start is for left index and end is right index of the
sub-array of arr to be sorted */

/**
 * \brief it divides an array of n size according to the pivotIndex.
 *
 *  This function is recursive, it calls itself to divide
 *  the array into two sub-arrays according to the local mid variable
 *  then it call the function merge() to sort the created sub-arrays into one array.
 *
 * \param int arr[]      The array to be sorted.
 * \param  int start     start index of the sub-array ,for left index.
 * \param  int end       last index of the sub-array ,for right index .
 * \return None.
 */
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        /*sort the left and the right half till its only one element and then call merge */
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    } else
        return;
}