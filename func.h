//
// Created by ahmad on 12/01/2022.
//

#ifndef LINUX_PROJECT_FUNC_H
#define LINUX_PROJECT_FUNC_H


typedef enum {
    MERGE_SORT, QUICK_SORT, BUBBLE_SORT, INSERTION_SORT
} SORT_MODE;

typedef enum {
    ARRAY_SIZE_8 = 8, ARRAY_SIZE_16 = 16, ARRAY_SIZE_64 = 64
} SIZE_MODE;


//merge sort
void mergeSort(int arr[], int start, int end);


//quick sort
void quickSort(int arr[], int low, int high);


//insertion sort
void insertSort(int arr[], int sizeOfElem);


//bubble sort
void bubbleSort(int arr[], int sizeOfElem);


//
void swap(int *x, int *y);


#endif //LINUX_PROJECT_FUNC_H
