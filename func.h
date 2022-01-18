#ifndef LINUX_PROJECT_FUNC_H
#define LINUX_PROJECT_FUNC_H

typedef enum {
    MERGE_SORT, QUICK_SORT, BUBBLE_SORT, INSERTION_SORT
} SORT_MODE;

typedef enum {
    ASC, DEC, RAND
} DATA_SET;


//merge sort
void mergeSort(int arr[], int start, int end);


//quick sort
void quickSort(int arr[], int low, int high);


//insertion sort
void insertSort(int arr[], int sizeOfElem);


//bubble sort
void bubbleSort(int arr[], int sizeOfElem);


//main func
void swap(int *x, int *y);

void createRandomNumber(int sizeOfArray, int arr[], DATA_SET dataSet);


//
void callRunMeasureFunctions();

void callSortFunctions();

//
double measureCpuRunTime(void (*pFunction)(int [], int, int), int arr[], int sizeOfArr, SORT_MODE sortMode);

//
void comparison();


#endif //LINUX_PROJECT_FUNC_H
